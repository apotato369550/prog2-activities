#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *storeVowels(char x[]);

int main() {
    char x[] = "The Quick Brown Fox Jumped Over the Lazy Dog";
    
    printf("%s\n", x);
    char *vowelsString = storeVowels(x);
    printf("The vowels in the string are: %s", vowelsString);
    
    free(vowelsString);
    vowelsString = NULL;
    
    return 0;
}

char *storeVowels(char x[]) {
    int vowelCount = 0, i = 0;
    for(i = 0; x[i] != '\0'; i++) {
        if (x[i] == 'a' || x[i] == 'A' || x[i] == 'e' || x[i] == 'E' || x[i] == 'i' || x[i] == 'I' || x[i] == 'o' || x[i] == 'O' || x[i] == 'u' || x[i] == 'U') {
            vowelCount++;
        }
    }
    // not sure if the +1 is necessary. all strings should end with a terminating character, right?
    // so it should make sense to make the extra space.
    // yep. correct
    char *vowelsString = (char*) malloc(sizeof(char) * (vowelCount + 1));
    int j = 0;
    for(i = 0; x[i] != '\0'; i++) {
        if (x[i] == 'a' || x[i] == 'A' || x[i] == 'e' || x[i] == 'E' || x[i] == 'i' || x[i] == 'I' || x[i] == 'o' || x[i] == 'O' || x[i] == 'u' || x[i] == 'U') {
            vowelsString[j] = x[i];
            j++;
        }
    }
    
    return vowelsString;
}
