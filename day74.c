// Day 74: Winner of an Election
// Problem: Determine the candidate with maximum votes, return lexicographically smallest in case of tie

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    
    char names[1000][100];
    int count[1000] = {0};
    int uniqueCount = 0;
    
    for (int i = 0; i < n; i++) {
        char name[100];
        scanf("%s", name);
        
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(names[j], name) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }
        
        if (!found) {
            strcpy(names[uniqueCount], name);
            count[uniqueCount] = 1;
            uniqueCount++;
        }
    }
    
    int maxVotes = 0;
    char winner[100];
    
    for (int i = 0; i < uniqueCount; i++) {
        if (count[i] > maxVotes || 
            (count[i] == maxVotes && strcmp(names[i], winner) < 0)) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        }
    }
    
    printf("%s %d\n", winner, maxVotes);
    
    return 0;
}
