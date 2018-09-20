/*
 * File: sumDigits.c
 *
 * Author: Alex Swindle (aswindle@email.arizona.edu)
 *
 * Purpose: reads integers and prints the sum of their digits on new lines.
 *  Negative numbers result in an error return code of 1
 *  Non-integer characters result in exiting.
 */

#include <stdio.h>

/*
 * Prints the sum of the digits of n
 */
void sumDigits(int n) {
    int total = 0;
    int curDigit;
    // Pick off one digit, add it to the total, drop a digit from n
    while (n > 0) {
        curDigit = n % 10;
        total += curDigit;
        n = n / 10;
    }
    printf("%d\n", total);
}


int main(void) {
    int retVal = 0;

    int cur, numScanned;
    numScanned = scanf("%d", &cur);
    while (numScanned != -1) {
        // Invalid entry
        if (numScanned == 0) {
            fprintf(stderr, "Failed to read the next number.\n");
            return 1;
        }
        // Non-positive number
        else if (cur <= 0) {
            fprintf(stderr, "Only positive numbers are valid.\n");
            retVal++;
        }
        // Valid integer. Run sumDigits on it
        else {
            sumDigits(cur);
        }
        numScanned = scanf("%d", &cur);
    }

    // Return 0 if retVal == 0, 1 otherwise
    return (retVal > 0);
}
