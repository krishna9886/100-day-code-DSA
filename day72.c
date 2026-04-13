#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char firstRepeatedChar(char* s) {
    int count[26] = {0};
    int firstIndex[26];
    
    // Initialize first index array with -1
    for (int i = 0; i < 26; i++) {
        firstIndex[i] = -1;
    }
    
    int len = strlen(s);
    int minSecondIndex = len;
    char result = '\0';
    
    // First pass: count occurrences and track first occurrence
    for (int i = 0; i < len; i++) {
        int index = s[i] - 'a';
        count[index]++;
        
        if (firstIndex[index] == -1) {
            firstIndex[index] = i;
        }
    }
    
    // Second pass: find first repeated character
    for (int i = 0; i < len; i++) {
        int index = s[i] - 'a';
        
        // If character appears more than once
        if (count[index] > 1) {
            // Check if this is the second occurrence
            if (firstIndex[index] < i) {
                if (i < minSecondIndex) {
                    minSecondIndex = i;
                    result = s[i];
                }
                break; // Found the first repeated character
            }
        }
    }
    
    return result;
}

int main() {
    char s[1001];
    scanf("%s", s);
    
    char result = firstRepeatedChar(s);
    
    if (result == '\0') {
        printf("-1\n");
    } else {
        printf("%c\n", result);
    }
    
    return 0;
}
