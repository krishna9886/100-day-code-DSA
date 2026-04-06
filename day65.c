#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Function to perform DFS and detect cycle
bool dfs(int node, int parent, int graph[MAX][MAX], bool visited[], int n) {
    visited[node] = true;
    
    // Visit all adjacent nodes
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1) {  // If there is an edge
            if (!visited[i]) {
                // If adjacent node is not visited, recursively call DFS
                if (dfs(i, node, graph, visited, n))
                    return true;
            }
            // If adjacent node is visited and not parent, cycle exists
            else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}

// Function to detect cycle in undirected graph
bool detectCycle(int graph[MAX][MAX], int n) {
    bool visited[MAX] = {false};
    
    // Check for cycle in different connected components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, graph, visited, n))
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
