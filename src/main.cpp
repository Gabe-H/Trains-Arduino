#include <Arduino.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "routes.h"

// Structure to represent each city and its neighbors with respective distances
struct CityData
{
  std::map<City, int> neighbors; // Neighbor city and distance
  bool visited;                  // Flag to check if city has been visited by the player

  CityData() : visited(false) {}

  // Distance = number of trains to neighbor
  void addNeighbor(City neighbor, int distance)
  {
    neighbors[neighbor] = distance;
  }
};

// Function to add connections between cities
void addConnection(std::map<City, CityData> &cities, Route route)
{
  cities[route.from].addNeighbor(route.to, route.distance);
  cities[route.to].addNeighbor(route.from, route.distance); // connections are bidirectional
}

// Depth-First Search function to find the longest continuous route
void DFS(const std::map<City, CityData> &cities, City currentCity, std::set<City> &visitedCities, int currentDistance, int &maxLength, std::vector<City> &currentRoute, std::vector<City> &longestRoute, int &longestDistance)
{
  visitedCities.insert(currentCity); // Mark city as visited
  currentRoute.push_back(currentCity);

  for (const auto &neighbor : cities.at(currentCity).neighbors)
  {
    if (!cities.at(neighbor.first).visited && visitedCities.find(neighbor.first) == visitedCities.end())
    {
      currentDistance += neighbor.second; // Add distance to the current route
      DFS(cities, neighbor.first, visitedCities, currentDistance, maxLength, currentRoute, longestRoute, longestDistance);
      currentDistance -= neighbor.second; // Remove distance when backtracking
    }
  }

  if (currentDistance > longestDistance)
  {
    maxLength = currentRoute.size();
    longestRoute = currentRoute;
    longestDistance = currentDistance;
  }

  visitedCities.erase(currentCity);
  currentRoute.pop_back();
}

// Find the indices of the routes that make up the longest route based on the cities
std::vector<int> rebuildConnections(std::vector<City> &longestRoute, std::vector<int> &connections)
{
  std::vector<int> connectionsRebuilt;

  // Check each pair of cities in the longest route
  for (int i = 0; i < longestRoute.size() - 1; i++)
  {
    City city1 = longestRoute[i];
    City city2 = longestRoute[i + 1];

    // Instead of iterating through all routes, we'll only check the routes that the player used
    for (int connection : connections)
    {
      // See if the route matches the pair of cities. Checks bidirectionally
      if ((routes[connection].from == city1 && routes[connection].to == city2) || (routes[connection].from == city2 && routes[connection].to == city1))
      {
        // Serial.printf("Found %s -> %s at Route index %d\n", CityNames[static_cast<int>(city1)].c_str(), CityNames[static_cast<int>(city2)].c_str(), connection);

        connectionsRebuilt.push_back(connection);
        break;
      }
      else if (connection == connections[connections.size() - 1])
      {
        // cout << "Could not find: " << CityNames[static_cast<int>(city1)] << " -> " << CityNames[static_cast<int>(city2)] << endl;
        Serial.printf("ERROR! Could not find: %s -> %s\n", CityNames[static_cast<int>(city1)].c_str(), CityNames[static_cast<int>(city2)].c_str());
      }
    }
  }

  return connectionsRebuilt;
}

void setup()
{
  Serial.begin(115200);
  // Create cities and add connections
  std::map<City, CityData> cities;

  // std::vector<int> connections = {29, 22, 55, 54, 73, 15, 1, 21, 5, 56, 10, 4, 13, 23};
  // std::vector<int> connections = {0, 12, 26, 77, 50, 51, 74, 76, 71, 59, 48, 33, 24, 9, 63};
  std::vector<int> connections = {14, 15, 16, 11, 27, 31, 49, 33, 60, 61, 71, 47, 46, 45, 37, 21, 40};

  unsigned long start = millis(); // Debugging, start timer

  // Add connections to cities from player input
  for (int connection : connections)
  {
    addConnection(cities, routes[connection]);
  }

  int maxLength = 0;                            // Number of cities in the longest route
  std::vector<City> currentRoute, longestRoute; // Vectors to store the current and longest routes during DFS
  std::set<City> visitedCities;                 // Set to keep track of visited cities during DFS
  int longestDistance = 0;                      // Distance of the longest route in trains

  // Perform DFS from each city to find the longest continuous route
  for (int i = 0; i < static_cast<int>(City::NUM_CITIES); i++)
  {
    City city = static_cast<City>(i);

    // Only check cities that the player visited
    if (!cities[city].visited)
    {
      int currentDistance = 0;
      DFS(cities, city, visitedCities, currentDistance, maxLength, currentRoute, longestRoute, longestDistance);
    }
  }

  // Rebuild the connections after finding the longest route. To be used with LEDs.
  std::vector<int> rebuilt = rebuildConnections(longestRoute, connections);

  int rdist = 0;
  // Double check the total length of the rebuilt route
  for (int r : rebuilt)
  {
    rdist += routes[r].distance;
  }

  // Output the longest route and stats
  Serial.print("Longest route: ");
  for (const City &city : longestRoute)
  {
    Serial.print(CityNames[city].c_str());
    Serial.print(" -> ");
  }
  Serial.println("End");

  Serial.print("Connections: ");
  for (int i = 0; i < rebuilt.size(); i++)
  {
    Serial.printf("%d -> ", rebuilt[i]);
  }
  Serial.println("End");

  Serial.printf("Actual:  Number of connections: %d, length: %d\n", maxLength - 1, longestDistance);
  Serial.printf("Rebuilt: Number of connections: %d, length: %d\n", rebuilt.size(), rdist);
  Serial.println("(These numbers should match!)");

  unsigned long end = millis(); // Stop debugging timer, print results
  Serial.printf("Time taken: %lu ms\n", end - start);
}

void loop()
{
  delay(10000); // Do nothing
}