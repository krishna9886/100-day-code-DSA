#include <stdio.h>
#include <string.h>

int main() {
    char s[1001];
    scanf("%s", s);
    
    int freq[26] = {0};
    int len = strlen(s);
    
    // Count frequency of each character
    for(int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }
    
    // Find first non-repeating character
    for(int i = 0; i < len; i++) {
        if(freq[s[i] - 'a'] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }
    }
    
    // If no non-repeating character found
    printf("$\n");
    return 0;
}
