/*
 * File: noVowels.c
 *
 * Author: Alex Swindle (aswindle@email.arizona.edu)
 *
 * Purpose: Reads from stdin and prints out all words that match the first word when the vowels are removed
 * (case insensitive)
 */

#include <stdio.h>
#include <ctype.h>

/**
 * Returns whether 2 strings have matching consonants
 * @param a: first string; all chars are a-z
 * @param b: second string; all chars are a-z
 * @return 1 if the two strings match with vowels removed, 0 otherwise
 */
int matchConsonants(char a[], char b[]) {
    // Track current location in both strings
    int aPos = 0;
    int bPos = 0;
    // Track current character in both strings
    char aChar = a[aPos];
    char bChar = b[bPos];
    while (aChar != '\0' || bChar != '\0') {
        // Increment aPos to skip over vowels
        if (aChar == 'a' || aChar == 'e' || aChar == 'i' || aChar == 'o' || aChar == 'u') {
            aPos++;
        }
            // Increment bPos to skip over vowels
        else if (bChar == 'a' || bChar == 'e' || bChar == 'i' || bChar == 'o' || bChar == 'u') {
            bPos++;
        }
            // Actually compare the two characters if neither is a vowel
        else {
            //Increment both positions, if not currently at the end
            if (aChar != '\0') {
                aPos++;
            }
            if (bChar != '\0') {
                bPos++;
            }
            // If any two characters don't match, the whole strings don't match
            if (aChar != bChar) {
                return 0;
            }
        }

        // Read next characters
        aChar = a[aPos];
        bChar = b[bPos];
    }
    return 1;
}

int main(void) {
    int retVal = 0;

    // 2 versions of each string are needed: the one originally entered and the one converted to lowercase
    char first[65];
    char firstProcessed[65];
    char cur[65];
    char curProcessed[65];

    // Store the first string
    scanf("%64s", first);
    // Check to see if it's a valid word with only alphabetical characters; store the lowercase version of it
    int i;
    for (i = 0; first[i] != '\0'; i++) {
        if (!isalpha(first[i])) {
            fprintf(stderr, "ERROR: First word contained a non-alphabetical character. Exiting.\n");
            return 1;
        } else {
            firstProcessed[i] = tolower(first[i]);
        }
    }
    // Null-terminate
    firstProcessed[i] = '\0';
    // Always print the first word
    printf("%s\n", first);

    // Read words from stdin, compare to first word
    while (scanf("%64s", cur) != EOF) {
        // Process the entered word. If it isn't entirely alphabetical, record an error. Otherwise, store the lowercase
        // version and then check if consonants match first's
        int i;
        int valid = 1;
        for (i = 0; cur[i] != '\0'; i++) {
            if (!isalpha(cur[i])) {
                fprintf(stderr, "ERROR: Entry word contained a non-alphabetical character %c.\n", cur[i]);
                retVal++;
                valid = 0;
                break;
            } else {
                curProcessed[i] = tolower(cur[i]);
            }
        }
        // Null-terminate
        curProcessed[i] = '\0';
        if (valid) {
            int result = matchConsonants(firstProcessed, curProcessed);
            // If the string matches the first string, print the original version of it before case changes
            if (result == 1) {
                printf("%s\n", cur);
            }
        }
    }

    // Return 0 if retVal == 0, 1 otherwise
    return (retVal > 0);
}
