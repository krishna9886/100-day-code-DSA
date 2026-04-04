// Day 63 - Depth First Search (DFS)
// Problem: Perform DFS starting from a given source vertex using recursion

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Node* adjList[], int u, int v) {
    // Add edge from u to v
    struct Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;
    
    // Add edge from v to u (for undirected graph)
    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

// DFS function using recursion
void DFS(struct Node* adjList[], bool visited[], int vertex) {
    // Mark current vertex as visited and print it
    visited[vertex] = true;
    printf("%d ", vertex);
    
    // Traverse all adjacent vertices
    struct Node* temp = adjList[vertex];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFS(adjList, visited, adjVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m, start;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter number of edges: ");
    scanf("%d", &m);
    
    // Create adjacency list array
    struct Node* adjList[n];
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }
    
    printf("Enter %d edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adjList, u, v);
    }
    
    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);
    
    // Create visited array
    bool* visited = (bool*)calloc(n, sizeof(bool));
    
    printf("\nDFS Traversal Order: ");
    DFS(adjList, visited, start);
    printf("\n");
    
    free(visited);
    
    return 0;
}
