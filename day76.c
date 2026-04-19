// Day 76 - Q1: Count Connected Components (Undirected Graph)
// Approach: Use DFS or BFS to traverse the graph. Each time we start
// a new traversal from an unvisited node, we found a new component.

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
    // Add edge from src to dest
    AdjNode* newNode = createAdjNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    
    // Add edge from dest to src (undirected)
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

// Count connected components
int countConnectedComponents(Graph* graph) {
    int* visited = (int*)calloc(graph->numVertices, sizeof(int));
    int count = 0;
    
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited);
            count++;
        }
    }
    
    free(visited);
    return count;
}

int main() {
    // Test case 1: Graph with 2 components
    Graph* graph1 = createGraph(5);
    addEdge(graph1, 0, 1);
    addEdge(graph1, 1, 2);
    // Component 1: 0-1-2, Component 2: 3, Component 3: 4
    int comp1 = countConnectedComponents(graph1);
    printf("Test 1 (5 vertices, edges: 0-1, 1-2): Components = %d\n", comp1);
    
    // Test case 2: Fully connected graph
    Graph* graph2 = createGraph(4);
    addEdge(graph2, 0, 1);
    addEdge(graph2, 1, 2);
    addEdge(graph2, 2, 3);
    int comp2 = countConnectedComponents(graph2);
    printf("Test 2 (4 vertices, fully connected): Components = %d\n", comp2);
    
    // Test case 3: All isolated vertices
    Graph* graph3 = createGraph(4);
    int comp3 = countConnectedComponents(graph3);
    printf("Test 3 (4 isolated vertices): Components = %d\n", comp3);
    
    return 0;
}
