// Day 75 - Q1: Largest Subarray with Zero Sum
// Approach: Use a hash map to store prefix sum and its first index.
// If the same prefix sum appears again, the subarray between those indices has zero sum.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define HASH_SIZE 10007

// Hash map node
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

// Hash map
typedef struct {
    Node* buckets[HASH_SIZE];
} HashMap;

int hash(int key) {
    return ((key % HASH_SIZE) + HASH_SIZE) % HASH_SIZE;
}

HashMap* createMap() {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    for (int i = 0; i < HASH_SIZE; i++)
        map->buckets[i] = NULL;
    return map;
}

void insert(HashMap* map, int key, int value) {
    int idx = hash(key);
    Node* node = map->buckets[idx];
    while (node) {
        if (node->key == key) {
            // Don't update, keep the first occurrence
            return;
        }
        node = node->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = map->buckets[idx];
    map->buckets[idx] = newNode;
}

int find(HashMap* map, int key, int* found) {
    int idx = hash(key);
    Node* node = map->buckets[idx];
    while (node) {
        if (node->key == key) {
            *found = 1;
            return node->value;
        }
        node = node->next;
    }
    *found = 0;
    return -1;
}

int largestZeroSumSubarray(int arr[], int n, int* start, int* end) {
    HashMap* map = createMap();
    int prefixSum = 0;
    int maxLen = 0;
    *start = -1;
    *end = -1;
    
    // Insert prefix sum 0 at index -1
    insert(map, 0, -1);
    
    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        int found;
        int prevIdx = find(map, prefixSum, &found);
        
        if (found) {
            int len = i - prevIdx;
            if (len > maxLen) {
                maxLen = len;
                *start = prevIdx + 1;
                *end = i;
            }
        } else {
            insert(map, prefixSum, i);
        }
    }
    
    return maxLen;
}

int main() {
    // Test case 1
    int arr1[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int start1, end1;
    int len1 = largestZeroSumSubarray(arr1, n1, &start1, &end1);
    printf("Test 1: Largest zero sum subarray length = %d\n", len1);
    if (start1 != -1) {
        printf("Subarray: ");
        for (int i = start1; i <= end1; i++)
            printf("%d ", arr1[i]);
        printf("\n");
    }
    
    // Test case 2
    int arr2[] = {1, 2, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int start2, end2;
    int len2 = largestZeroSumSubarray(arr2, n2, &start2, &end2);
    printf("\nTest 2: Largest zero sum subarray length = %d\n", len2);
    
    // Test case 3
    int arr3[] = {0, 0, 0, 0};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int start3, end3;
    int len3 = largestZeroSumSubarray(arr3, n3, &start3, &end3);
    printf("\nTest 3: Largest zero sum subarray length = %d\n", len3);
    if (start3 != -1) {
        printf("Subarray: ");
        for (int i = start3; i <= end3; i++)
            printf("%d ", arr3[i]);
        printf("\n");
    }
    
    return 0;
}
