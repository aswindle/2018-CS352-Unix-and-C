/*
 * File: splitString.c
 *
 * Author: Alex Swindle (aswindle@email.arizona.edu)
 *
 * Purpose: Reads from stdin and splits all strings on the '-' character, ignoring leading and trailing ones
 */
#include <stdio.h>

/**
 * Print out all pieces of a string separated by the dash characters
 * Ignores leading and trailing dashes and treats multiple dashes in a row as one
 * Prints all separated pieces on a new line
 * @param str: pointer to string to split
 */
void split(char *str) {
    int printed = 0;
    // Iterate through the string until a null terminator is found
    if (*str == '\0') {
        return;
    }
    else {
        // Skip over any leading dashes
        while (*str == '-') {
            str++;
        }
        // Prints characters until another - or null terminator is found
        while (*str != '\0' && *str != '-') {
            printf("%c", *str);
            printed++;
            str++;
        }
        // Don't print a new line if nothing was printed during this use of the function
        if (printed > 0) {
            printf("\n");
        }
        // Split again, starting where this run left off
        split(str);
    }
}

int main(void) {
    int retVal = 0;
    char str[256];
    // Read words from stdin
    while (scanf("%255s", str) != EOF) {
        split(str);
    }
    // Return 0 if retVal == 0, 1 otherwise
    return (retVal > 0);
}


