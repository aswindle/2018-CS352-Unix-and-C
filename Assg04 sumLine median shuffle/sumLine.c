/*
 * File: sumLine.c
 *
 * Author: Alex Swindle (aswindle@email.arizona.edu)
 *
 * Purpose: Reads in lines of non-negative integers from stdin and prints the sum of the numbers on each line
 */

#include <stdio.h>
#include <stdlib.h>


int main(void) {
    // Flag errors
    int retVal = 0;
    // getline pointers
    char *line = NULL;
    size_t size = 0;

    // Process lines until EOF reached
    while (getline(&line, &size, stdin) != EOF) {
        // Memory error: line is NULL
        if (line == NULL) {
            fprintf(stderr, "Memory error reading in line.");
            exit(1);
        }
        // Blank line
        if(line[0] == '\n'){
            retVal++;
            fprintf(stderr, "Empty line.\n");
            continue;
        }

        // Successful read: parse the line
        int error = 0;
        int total = 0;
        char *curChar = line;
        int curNum;
        int charsRead;
        int scanResults = 0;

        // Scan the line for integers until the end of it is reached
        while (*curChar != '\0' && scanResults != EOF) {
            scanResults = sscanf(curChar, "%d%n", &curNum, &charsRead);
            if (scanResults == 0) {
                fprintf(stderr, "Error: didn't read a number.\n");
                retVal++;
                error = 1;
                break;
            }
            else if (scanResults == 1) {
                if (curNum < 0) {
                    fprintf(stderr, "Error: read a negative integer.\n");
                    retVal++;
                    error = 1;
                    break;
                }
                // Successful read: add curNum to the total
                else {
                    total += curNum;
                    // Increment the pointer by how many characters were taken off the line
                    curChar += charsRead;
                }
            }
        }
        // Only print the total if no errors were encountered
        if (error == 0) {
            printf("%d\n", total);
        }
    }
    free(line);

    return (retVal > 0);
}