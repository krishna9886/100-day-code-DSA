// Day 78 - Q1: Minimum Spanning Tree using Prim's Algorithm
// Approach: Start from an arbitrary vertex. Repeatedly add the minimum
// weight edge that connects a vertex in the MST to a vertex outside.
// Time Complexity: O(V^2) for adjacency matrix, O(E log V) with min-heap.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

// Graph structure using adjacency matrix
typedef struct {
    int numVertices;
    int** adjMatrix;
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++)
            graph->adjMatrix[i][j] = INF;
    }
    return graph;
}

void addEdge(Graph* graph, int u, int v, int weight) {
    graph->adjMatrix[u][v] = weight;
    graph->adjMatrix[v][u] = weight;  // Undirected
}

// Find vertex with minimum key value, not yet in MST
int minKey(int key[], int mstSet[], int numVertices) {
    int min = INF;
    int minIndex = -1;
    
    for (int v = 0; v < numVertices; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Prim's algorithm to find MST
void primMST(Graph* graph) {
    int numVertices = graph->numVertices;
    int parent[MAX_VERTICES];  // Array to store MST
    int key[MAX_VERTICES];     // Key values for each vertex
    int mstSet[MAX_VERTICES];  // To track vertices in MST
    
    // Initialize all keys as INF and mstSet[] as false
    for (int i = 0; i < numVertices; i++) {
        key[i] = INF;
        mstSet[i] = 0;
        parent[i] = -1;
    }
    
    // Start from vertex 0
    key[0] = 0;
    parent[0] = -1;
    
    // MST will have numVertices vertices
    for (int count = 0; count < numVertices - 1; count++) {
        // Pick minimum key vertex not yet in MST
        int u = minKey(key, mstSet, numVertices);
        
        if (u == -1) {
            printf("Graph is disconnected!\n");
            return;
        }
        
        // Add picked vertex to MST
        mstSet[u] = 1;
        
        // Update key values of adjacent vertices
        for (int v = 0; v < numVertices; v++) {
            if (graph->adjMatrix[u][v] != INF && !mstSet[v] &&
                graph->adjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph->adjMatrix[u][v];
            }
        }
    }
    
    // Print MST edges and total weight
    printf("\nMST Edges:\n");
    int totalWeight = 0;
    for (int i = 1; i < numVertices; i++) {
        printf("%d - %d : %d\n", parent[i], i, graph->adjMatrix[i][parent[i]]);
        totalWeight += graph->adjMatrix[i][parent[i]];
    }
    printf("Total MST Weight: %d\n", totalWeight);
}

int main() {
    // Test case: Graph with 5 vertices
    Graph* graph = createGraph(5);
    
    // Add edges (u, v, weight)
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 4, 9);
    
    printf("Prim's MST Algorithm:\n");
    primMST(graph);
    
    return 0;
}
