/*
 * File: palindromes.c
 *
 * Author: Alex Swindle (aswindle@email.arizona.edu)
 *
 * Purpose: Determines whether strings are palindromes or not
 */

#include <stdio.h>
#include <ctype.h>

/**
 * Determines whether a string is a palindrome or not. Prints 1 if it is, 0 if it isn't
 * @param str: string to check
 */
void palindrome(char str[]) {
    int result = 1;

    // Empty loop to get the size of the string
    int size;
    for (size = 0; str[size] != '\0'; size++) {}
    // str[size] == '\0'

    // Loop through the string. i only has to go to size/2, since odd numbers will skip the middle character,
    // which is guaranteed to be palindromic
    int i;
    for (i = 0; i < size / 2; i++) {
        // Check matching letters at start and end of word, need offset since size is 1 past the end of the word
        if(str[i] != str[size - (i + 1)]){
            result = 0;
        }
    }
    printf("%d\n", result);
}

int main(void) {
    int retVal = 0;

    // Strings can be no longer than 64 chars
    char str[65];
    while (scanf("%64s", str) != EOF) {
        // Convert str to uppercase
        int i;
        for(i = 0; str[i] != '\0'; i++){
            str[i] = toupper(str[i]);
        }
        palindrome(str);
    }

    // Return 0 if retVal == 0, 1 otherwise
    return (retVal > 0);
}
