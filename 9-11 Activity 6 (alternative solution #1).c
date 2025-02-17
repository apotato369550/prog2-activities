// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverseString(char string[]);
int compareStrings(char firstString[], char secondString[]);

int main() {
    // Write C code here
    char firstString[100], secondString[100];
    printf("Enter String 1: ");
    gets(firstString);
    printf("Enter String 2: ");
    gets(secondString);
    
    reverseString(secondString);
    
    // printf("The reversed string is %s", secondString);
    
    if (compareStrings(firstString, secondString)) {
        printf("True: The second string is the reverse of the first string.");
    } else {
        printf("False: The second string is not the reverse of the first string.");
    }

    return 0;
}

void reverseString(char string[]) {
    int length = strlen(string);
    int i = 0, j = length - 1;
    while (i < j) {
        char temp = string[i];
        string[i] = string[j];
        string[j] = temp;
        i++;
        j--;
    }
}

int compareStrings(char firstString[], char secondString[]) {
	int i;
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
