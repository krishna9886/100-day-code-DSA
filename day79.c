#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5

// Function to find the vertex with minimum distance value
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

// Dijkstra's algorithm for single source shortest path
void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices
        int u = minDistance(dist, sptSet);

        // If no reachable vertex, break
        if (u == -1) break;

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int main() {
    // Graph represented as adjacency matrix
    // 0 means no edge, other values represent edge weights
    int graph[V][V] = {
        {0, 10, 0, 0, 5},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0}
    };

    dijkstra(graph, 0);
    return 0;
}
