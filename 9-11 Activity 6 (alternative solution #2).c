// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char *getReversedString(char *string);
int compareStrings(char firstString[], char secondString[]);

int main() {
    // Write C code here
    char firstString[100], secondString[100];
    printf("Enter String 1: ");
    gets(firstString);
    printf("Enter String 2: ");
    gets(secondString);
    
    char *reversedString = getReversedString(secondString);
    
    printf("The reversed string is %s", reversedString);
    
    if (compareStrings(firstString, reversedString)) {
        printf("True: The second string is the reverse of the first string.");
    } else {
        printf("False: The second string is not the reverse of the first string.");
    }

    return 0;
}

char *getReversedString(char string[]) {
	int i = 0;
    int length = strlen(string);
    char *reversedString = malloc((sizeof(char) * length) + 1);
    for (i = 0; i < length; i++) {
        reversedString[i] = string[length - i - 1];
    }
    
    return reversedString;
}

int compareStrings(char firstString[], char secondString[]) {
	int i = 0;
    if (strlen(firstString) != strlen(secondString)) {
        return 0;
    }
    for (i = 0; i < strlen(firstString); i++) {
        if (tolower(firstString[i]) != tolower(secondString[i])) {
            return 0;
        }
    }
    
    return 1;
}
