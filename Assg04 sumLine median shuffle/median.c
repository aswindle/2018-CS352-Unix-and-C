/*
 * File: median.c
 *
 * Author: Alex Swindle (aswindle@email.arizona.edu)
 *
 * Purpose: Reads in a positive integer followed by that many more numbers and prints the median
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int retVal = 0;

    // Read in the number of elements of the array
    int size;
    if (scanf("%d", &size) != 1 || size < 0) {
        fprintf(stderr, "Error: The line didn't start with a positive number.\n");
        exit(1);
    }

    // Allocate memory
    int *array = malloc(size * sizeof(int));
    // Check for memory error
    if(array == NULL){
        fprintf(stderr, "Error: out of memory.\n");
        exit(1);
    }

    // Read in the values
    int i;
    for (i = 0; i < size; i++) {
        if (scanf("%d", &array[i]) != 1) {
            fprintf(stderr, "Error reading index %d.\n", i);
            exit(1);
        }
    }

    // Sort the array using a simple bubble sort
    int j;
    for (i = 0; i < size-1; i++) {
        for (j = i+1; j < size; j++) {
            if (array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    // Find and print the median. Different for even and odd length arrays
    float median;
    if (size % 2 == 1) {
        median = array[size / 2];
    }
    else {
        median = (float) (array[size / 2 - 1] + array[size / 2]) / 2;
    }
    printf("%.1f\n", median);


    return (retVal > 0);
}