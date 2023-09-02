#ifndef PLAYER_H
#define PLAYER_H

#include "Routes.h"

class Player
{
public:
    Player();
    void addRoute(Route route);
    int findLongestRoute();

private:
    void addConnection(int city1, int city2, int distance);
    void DFS(int currentCity, int currentRouteLength, int currentRouteDistance);

    bool visited[NUM_CITIES];
    int cities[NUM_CITIES][NUM_CITIES];    // Adjacency matrix representing city connections.
    int distances[NUM_CITIES][NUM_CITIES]; // Matrix representing distances between cities.
    int maxRouteLength = 0;
    int maxRouteDistance = 0;
};

#endif