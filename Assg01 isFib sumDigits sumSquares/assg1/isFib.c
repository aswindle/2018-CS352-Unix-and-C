/*
 * File: isFib.c
 *
 * Author: Alex Swindle (aswindle@email.arizona.edu)
 *
 * Purpose: reads integers and prints if each one is a Fibonacci number or not.
 *  Negative numbers result in an error return code of 1
 *  Non-integer characters result in exiting.
 */

#include <stdio.h>

/*
 * Returns fibonacci number n
 * Assumes that n is >= 0
 */
int fib(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    else{
        return fib(n-1) + fib(n-2);
    }
}


int main(void){
    int retVal = 0;

    int cur, numScanned;
    numScanned = scanf("%d", &cur);
    while(numScanned != -1){
        // Invalid entry
        if(numScanned==0){
            fprintf(stderr, "Failed to read the next number.\n");
            return 1;
        }
        // Non-positive number
        else if(cur <= 0){
            fprintf(stderr, "Only positive numbers are valid.\n");
            retVal++;
        }
        // Valid integer. Check if it's a fibonacci number or not
        else{
            int i = 0;
            int curFib = fib(i);
            while(curFib<cur){
                i++;
                curFib = fib(i);
            }
            // Found Fibonacci number
            if(curFib == cur){
                printf("%d is fib\n", cur);
            }
            // Didn't find Fibonacci number
            else{
                printf("%d is not fib\n", cur);
            }
        }
        numScanned = scanf("%d", &cur);
    }

    // Return 0 if retVal == 0, 1 otherwise
    return (retVal > 0);
}
