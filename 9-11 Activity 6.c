// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isReverse(char firstString[], char secondString[]);

int main() {
    // Write C code here
    char firstString[100], secondString[100];
    printf("Enter String 1: ");
    gets(firstString);
    printf("Enter String 2: ");
    gets(secondString);
    
    if (isReverse(firstString, secondString)) {
        printf("True: The second string is the reverse of the first string.");
    } else {
        printf("False: The second string is not the reverse of the first string.");
    }

    return 0;
}

int isReverse(char firstString[], char secondString[]) {
	int i = 0;
    if (strlen(firstString) != strlen(secondString)) {
        return 0;
    }
    int length = strlen(firstString);
    for (i = 0; i < length; i++) {
        if (tolower(firstString[i]) != tolower(secondString[length - i - 1])) {
            return 0;
        }
    }
    return 1;
}
