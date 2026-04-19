// Day 77 - Q1: Check if Graph is Connected
// Approach: Use DFS/BFS from any node and check if all nodes are visited.
// If all nodes are visited, the graph is connected.

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Adjacency list node
typedef struct AdjNode {
    int vertex;
    struct AdjNode* next;
} AdjNode;

// Graph structure
typedef struct {
    int numVertices;
    AdjNode** adjList;
} Graph;

AdjNode* createAdjNode(int v) {
    AdjNode* newNode = (AdjNode*)malloc(sizeof(AdjNode));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjList = (AdjNode**)malloc(vertices * sizeof(AdjNode*));
    for (int i = 0; i < vertices; i++)
        graph->adjList[i] = NULL;
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    AdjNode* newNode = createAdjNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    
    newNode = createAdjNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// DFS traversal
void DFS(Graph* graph, int v, int visited[]) {
    visited[v] = 1;
    AdjNode* temp = graph->adjList[v];
    while (temp) {
        if (!visited[temp->vertex])
            DFS(graph, temp->vertex, visited);
        temp = temp->next;
    }
}

// Check if graph is connected
int isGraphConnected(Graph* graph) {
    if (graph->numVertices == 0)
        return 1;  // Empty graph is considered connected
    
    int* visited = (int*)calloc(graph->numVertices, sizeof(int));
    
    // Start DFS from vertex 0
    DFS(graph, 0, visited);
    
    // Check if all vertices are visited
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            free(visited);
            return 0;  // Not connected
        }
    }
    
    free(visited);
    return 1;  // Connected
}

int main() {
    // Test case 1: Connected graph
    Graph* graph1 = createGraph(5);
    addEdge(graph1, 0, 1);
    addEdge(graph1, 1, 2);
    addEdge(graph1, 2, 3);
    addEdge(graph1, 3, 4);
    printf("Test 1 (5 vertices, chain 0-1-2-3-4): %s\n",
           isGraphConnected(graph1) ? "Connected" : "Not Connected");
    
    // Test case 2: Disconnected graph
    Graph* graph2 = createGraph(5);
    addEdge(graph2, 0, 1);
    addEdge(graph2, 1, 2);
    // Vertices 3 and 4 are isolated
    printf("Test 2 (5 vertices, 0-1-2, 3 and 4 isolated): %s\n",
           isGraphConnected(graph2) ? "Connected" : "Not Connected");
    
    // Test case 3: Single vertex
    Graph* graph3 = createGraph(1);
    printf("Test 3 (Single vertex): %s\n",
           isGraphConnected(graph3) ? "Connected" : "Not Connected");
    
    // Test case 4: Two vertices with no edge
    Graph* graph4 = createGraph(2);
    printf("Test 4 (2 isolated vertices): %s\n",
           isGraphConnected(graph4) ? "Connected" : "Not Connected");
    
    return 0;
}
