// Day 62 - Graph Representation Using Adjacency List
// Problem: Build a graph with adjacency list representation using linked lists or dynamic arrays

#include <stdio.h>
#include <stdlib.h>

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

// Function to print the adjacency list
void printGraph(struct Node* adjList[], int n) {
    printf("\nAdjacency List Representation:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i);
        struct Node* temp = adjList[i];
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n, m;
    
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
    
    printGraph(adjList, n);
    
    return 0;
}
