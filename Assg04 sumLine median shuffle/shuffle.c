/*
 * File: sumLine.c
 *
 * Author: Alex Swindle (aswindle@email.arizona.edu)
 *
 * Purpose: Reads in lines of integers from stdin and prints a riffle-shuffle merged version of the two
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Package an integer array with its size to allow for easier calculations
 */
typedef struct intArray {
    int *array;
    int size;
} intArray;

/**
 * Return a pointer to an intArray containing the integers stored in a line of text
 * The program will exit if anything other than an integer is encountered
 * @param line: line to parse
 * @return pointer to intArray
 */
intArray *parseLine(char *line) {
    int size = 0;
    char *curChar = line;
    int charsRead;
    int curNum;
    int scanResults;

    // Loop through the line counting up how many successful int reads can be done.
    // Exit if an invalid entry found
    while (*curChar != '\0') {
        scanResults = sscanf(curChar, "%d%n", &curNum, &charsRead);
        if (scanResults == EOF) {
            break;
        }
            // Error if nothing was read or the character immediately after the end of an int that was read was '-'
            // Requires special check or 4-5 will be parsed as 4 and -5
        else if (scanResults == 0 || *(curChar + charsRead) == '-') {
            fprintf(stderr, "Line contained something other than an integer. Exiting.\n");
            exit(1);
        }
        else {
            curChar += charsRead;
            size++;
        }
    }

    // Allocate the int array
    int *array = malloc(size * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    // Loop through the line again, this time storing the ints in the array
    int i;
    curChar = line;
    for (i = 0; i < size; i++) {
        // Store the int in the array, increment pointer appropriately
        sscanf(curChar, "%d%n", &array[i], &charsRead);
        curChar += charsRead;
    }

    // Allocate the intArray to be returned, check for null
    intArray *retVal = malloc(sizeof(intArray));
    if (retVal == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    retVal->array = array;
    retVal->size = size;

    return retVal;
}

/**
 * Shuffle 2 intArrays together in the form a[0] b[0] a[1] b[1] etc. The longer list's extra elements go at the end
 * @param list1 : first intArray to shuffle
 * @param list2 : second intArray to shuffle
 * @return pointer to an int array
 */
intArray *shuffle(intArray *list1, intArray *list2) {
    int ptr1 = 0;
    int ptr2 = 0;
    // Allocated array space, check for null
    int size = list1->size + list2->size;
    int *shuffleArray = malloc(size * sizeof(int));
    if (shuffleArray == NULL) {
        fprintf(stderr, "Memory error.\n");
        exit(1);
    }

    // Find the smaller array. Process 2*smaller items, meaning 'smaller' items for each array
    int smaller = list1->size;
    if (list2->size < list1->size) {
        smaller = list2->size;
    }
    int i = 0;
    while (i < 2 * smaller) {
        if (i % 2 == 0) {
            shuffleArray[i] = list1->array[ptr1];
            ptr1++;
        }
        else {
            shuffleArray[i] = list2->array[ptr2];
            ptr2++;
        }
        i++;
    }

    // Process the rest of the larger array by adding it to the end of the shuffled one
    if (list1->size == smaller) {
        while (ptr2 < list2->size) {
            shuffleArray[i] = list2->array[ptr2];
            i++;
            ptr2++;
        }
    }
    else {
        while (ptr1 < list1->size) {
            shuffleArray[i] = list1->array[ptr1];
            i++;
            ptr1++;
        }
    }

    // Allocate the intArray to be returned, check for null
    intArray *retVal = malloc(sizeof(intArray));
    if (retVal == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    retVal->array = shuffleArray;
    retVal->size = size;
    return retVal;
}

int main(void) {
    int retVal = 0;

    // Declare the pointers and sizes for both lines
    char *line1 = NULL;
    char *line2 = NULL;
    size_t size1 = 0;
    size_t size2 = 0;

    // Get line 1. If the file is blank, exit.
    ssize_t results1 = getline(&line1, &size1, stdin);
    if (results1 == EOF) {
        exit(0);
    }

    // Get line 2.
    getline(&line2, &size2, stdin);

    // Allocate space for 2 intArrays and check for null
    intArray *int1 = malloc(sizeof(intArray));
    intArray *int2 = malloc(sizeof(intArray));
    if (int1 == NULL || int2 == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    // Parse both lines of text into intArrays
    int1 = parseLine(line1);
    int2 = parseLine(line2);

    // Shuffle the intArrays into a new intArray, print the result
    intArray *shuffledList = shuffle(int1, int2);
    int i;
    for (i = 0; i < shuffledList->size; i++) {
        printf("%d\n", shuffledList->array[i]);
    }

    return retVal > 0;
}