/*
 * File: cipher.c
 *
 * Author: Alex Swindle (aswindle@email.arizona.edu)
 *
 * Purpose: Reads in a number and a string. Rotates all letters by that number and prints out the rotated string.
 * Digits are unaffected. Ex: 2 aB1Z would print cE1B
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * Perform a cipher rotation on the letters in a string, leaving digits unchanged and preserving case.
 *  Prints rotated version.
 * @param n: number of spaces to rotate. Assumed to be in the range [0, 26)
 * @param str: string to process.
 */
void rotate(int n, char *str) {
    // Create a new pointer to iterate through the string
    char *ptr = str;
    while (*ptr != '\0') {
        // Rotate lowercase characters
        if (*ptr >= 'a' && *ptr <= 'z') {
            int offset = *ptr - 'a';
            *ptr = 'a' + (offset + n) % 26;
        }
            // Rotate uppercase characters
        else if (*ptr >= 'A' && *ptr <= 'Z') {
            int offset = *ptr - 'A';
            *ptr = 'A' + (offset + n) % 26;
        }
        ptr++;
    }
    printf("%s\n", str);
}

int main(void) {
    int retVal = 0;
    int n;
    char str[256];
    // Read in the size of the rotation
    if (scanf("%d", &n) < 1) {
        fprintf(stderr, "ERROR: First entry must be an integer. Exiting.\n");
        exit(1);
    }
    // Get n to be in range [0, 26)
    // Do %26 to get to 0-25
    // Add 26 to force it to be a positive integer
    // %26 again to force it back to 0-26
    n = (n%26 + 26) % 26;

    // Read words from stdin
    while (scanf("%255s", str) != EOF) {
        int i;
        // Check that the string is valid: no non-alphanumeric characters
        int valid = 1;
        for (i = 0; str[i] != '\0'; i++) {
            if (!isalnum(str[i])) {
                retVal++;
                fprintf(stderr, "ERROR: Input string contained a non-alphanumeric character.\n");
                valid = 0;
                break;
            }
        }
        // Do the rotation if the string is valid
        if (valid) {
            rotate(n, str);
        }
    }
    // Return 0 if retVal == 0, 1 otherwise
    return (retVal > 0);
}


