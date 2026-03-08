#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int queue[MAX];
    int n, m, value;
    int front = -1, rear = -1;

    // 1. Input number of elements to enqueue
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        if (front == -1) {
            front = 0;
        }
        // Circular increment of rear
        rear = (rear + 1) % n; 
        queue[rear] = value;
    }

    // 2. Input number of dequeue operations
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        if (front == -1) break; // Queue Empty
        
        if (front == rear) { // Last element being removed
            front = rear = -1;
        } else {
            front = (front + 1) % n; // Circular increment of front
        }
    }

    // 3. Output remaining elements from front to rear
    if (front != -1) {
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % n;
        }
    }
    
    return 0;
}