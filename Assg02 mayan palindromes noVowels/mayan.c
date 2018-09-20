/*
 * File: mayan.c
 *
 * Author: Alex Swindle (aswindle@email.arizona.edu)
 *
 * Purpose: Reads a base-20 number (digits of the form a through t) and prints out the base-10 representation of them
 */

#include <stdio.h>

/**
 * Prints out the base-10 representation of a base 20 number passed as a string
 * @param str: string to be parsed. Assumed to be only 'a'-'t', at most 6 characters long
 */
void mayan(char str[]) {
    int size;
    // Empty loop. Size will now store the number of digits of the number
    for (size = 0; str[size] != '\0'; size++) {}

    // str[size] will be the null terminator, meaning least-significant digit is at str[size-1], MSD is at size[0]
    int i;
    // Power of twenty. Will be increased at the end of each iteration
    int multiplier = 1;
    int total = 0;
    for (i = 1; i <= size; i++) {
        // digit is the character's offset from a
        int digit = str[size - i] - 'a';
        total += digit * multiplier;

        // Prep multiplier for next run
        multiplier *= 20;
    }
    printf("%d\n", total);
}

int main(void) {
    int retVal = 0;

    // Mayan numbers can be no longer than 6 characters, so make space for '\0'
    char str[7];
    while (scanf("%6s", str) != EOF) {
        int error = 0;
        int i;
        // Process string to prep for mayan. Non-valid chars will create an error and uppercase chars will be converted
        for (i = 0; str[i] != '\0'; i++) {
            // Convert uppercase chars to lowercase
            if (str[i] >= 'A' && str[i] <= 'T') {
                str[i] = 'a' + str[i] - 'A';
            }
            // If the character isn't lowercase, there's an error
            else if (!(str[i] >= 'a' && str[i] <= 't')) {
                fprintf(stderr, "ERROR: number contained an invalid character. Only a-t or A-T are valid.\n");
                retVal++;
                error++;
                break;
            }
        }
        // Only run mayan if the string is valid
        if (error == 0) {
            mayan(str);
        }
    }

    // Return 0 if retVal == 0, 1 otherwise
    return (retVal > 0);
}
