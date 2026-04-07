#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Function to perform DFS and detect cycle using recursion stack
bool dfsCycle(int node, int graph[MAX][MAX], bool visited[], bool recStack[], int n) {
    visited[node] = true;
    recStack[node] = true;
    
    // Visit all adjacent nodes
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1) {  // If there is an edge
            // If adjacent node is not visited, recursively call DFS
            if (!visited[i]) {
                if (dfsCycle(i, graph, visited, recStack, n))
                    return true;
            }
            // If adjacent node is in recursion stack, cycle exists
            else if (recStack[i]) {
                return true;
            }
        }
    }
    
    // Remove from recursion stack before returning
    recStack[node] = false;
    return false;
}

// Function to detect cycle in directed graph
bool detectCycle(int graph[MAX][MAX], int n) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};
    
    // Check for cycle in different connected components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfsCycle(i, graph, visited, recStack, n))
                return true;
        }
    }
    return false;
}

int main() {
    int n;
    int graph[MAX][MAX];
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    if (detectCycle(graph, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
