// Day 61 - Graph Representation Using Adjacency Matrix
// Problem: Build a graph with n vertices and m edges using adjacency matrix representation

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter number of edges: ");
    scanf("%d", &m);
    
    // Create adjacency matrix initialized with 0
    int **adjMatrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adjMatrix[i] = (int*)calloc(n, sizeof(int));
    }
    
    printf("Enter %d edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        // For undirected graph, mark both adjMatrix[u][v] and adjMatrix[v][u]
        // For directed graph, mark only adjMatrix[u][v]
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Remove this line for directed graph
    }
    
    // Print the adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
    
    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    
    return 0;
}
