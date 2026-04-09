#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s) {
    int length = strlen(s);
    int count = 0;
    int i = length - 1;
    
    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }
    
    // Count the length of the last word
    while (i >= 0 && s[i] != ' ') {
        count++;
        i--;
    }
    
    return count;
}

int main() {
    char s1[] = "Hello World";
    char s2[] = "   fly me   to   the moon  ";
    char s3[] = "luffy is still joyboy";
    
    printf("Length of last word in '%s': %d\n", s1, lengthOfLastWord(s1));
    printf("Length of last word in '%s': %d\n", s2, lengthOfLastWord(s2));
    printf("Length of last word in '%s': %d\n", s3, lengthOfLastWord(s3));
    
    return 0;
}
