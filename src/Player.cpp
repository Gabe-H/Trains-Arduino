#include "Player.h"

Player::Player()
{
    for (int i = 0; i < NUM_CITIES; i++)
    {
        visited[i] = false;
        for (int j = 0; j < NUM_CITIES; j++)
        {
            cities[i][j] = 0;    // Initialize the adjacency matrix with 0s (no connections).
            distances[i][j] = 0; // Initialize the distance matrix with 0s.
        }
    }
}

void Player::addConnection(int city1, int city2, int distance)
{
    cities[city1][city2] = 1;
    cities[city2][city1] = 1;
    distances[city1][city2] = distance;
    distances[city2][city1] = distance;
}

void Player::addRoute(Route route)
{
    addConnection(route.start, route.end, route.distance);
    addConnection(route.end, route.start, route.distance);
}

void Player::DFS(int currentCity, int currentRouteLength, int currentRouteDistance)
{
    visited[currentCity] = true;
    currentRouteLength++;

    for (int i = 0; i < NUM_CITIES; i++)
    {
        if (cities[currentCity][i] && !visited[i])
        {
            currentRouteDistance += distances[currentCity][i]; // Add distance between cities.
            DFS(i, currentRouteLength, currentRouteDistance);
        }
    }

    visited[currentCity] = false;
    if (currentRouteLength > maxRouteLength)
    {
        maxRouteLength = currentRouteLength;
        maxRouteDistance = currentRouteDistance; // Track the longest route's distance.
    }
}

int Player::findLongestRoute()
{
    maxRouteLength = 0;
    maxRouteDistance = 0;

    for (int i = 0; i < NUM_CITIES; i++)
    {
        DFS(i, 0, 0);
    }

    return maxRouteDistance; // Return the longest route's distance.
}