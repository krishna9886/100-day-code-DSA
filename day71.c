#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define EMPTY -1
#define DELETED -2

typedef struct {
    int *table;
    int size;
} HashTable;

int hash(int key, int m) {
    return key % m;
}

void initHashTable(HashTable *ht, int m) {
    ht->size = m;
    ht->table = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        ht->table[i] = EMPTY;
    }
}

void insert(HashTable *ht, int key) {
    int m = ht->size;
    int hashValue = hash(key, m);
    int i = 0;
    
    while (i < m) {
        int index = (hashValue + i * i) % m;
        if (ht->table[index] == EMPTY || ht->table[index] == DELETED) {
            ht->table[index] = key;
            return;
        }
        i++;
    }
}

bool search(HashTable *ht, int key) {
    int m = ht->size;
    int hashValue = hash(key, m);
    int i = 0;
    
    while (i < m) {
        int index = (hashValue + i * i) % m;
        if (ht->table[index] == EMPTY) {
            return false;
        }
        if (ht->table[index] == key) {
            return true;
        }
        i++;
    }
    return false;
}

int main() {
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    
    HashTable ht;
    initHashTable(&ht, m);
    
    for (int i = 0; i < n; i++) {
        char operation[10];
        int key;
        scanf("%s %d", operation, &key);
        
        if (strcmp(operation, "INSERT") == 0) {
            insert(&ht, key);
        } else if (strcmp(operation, "SEARCH") == 0) {
            if (search(&ht, key)) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }
    
    free(ht.table);
    return 0;
}
