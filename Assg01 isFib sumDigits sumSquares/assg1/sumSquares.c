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
#include <math.h>

/*
 * Prints an integer n if it can be written as the sum of 2 squares
 *
 */
void sumSquares(int n) {
    int i, j;
    int result = 0;
    for (i = 1; i <= (int) sqrt(n); i++) {
        for (j = 1; j <= (int) sqrt(n); j++) {
            if ((i * i + j * j) == n) {
                printf("%d\n", n);
                result++;
                return;
            }
        }
    }
}


int main(void) {
    int retVal = 0;

    int m, n, numScanned;
    numScanned = scanf("%d %d", &m, &n);
    // Invalid entry: non-integer or only 1 entered
    if (numScanned < 2) {
        fprintf(stderr, "Failed to read 2 numbers in a row.\n");
        return 1;
    }
    // Non-positive number
    else if (m <= 0 || n <= 0) {
        fprintf(stderr, "Only positive numbers are valid.\n");
        retVal++;
    }
    // Valid integers.
    else {
        int i;
        for (i = m; i <= n; i++) {
            sumSquares(i);
        }
    }

    // Return 0 if retVal == 0, 1 otherwise
    return (retVal > 0);
}
