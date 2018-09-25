/*
 * File: vowels.c
 *
 * Author: Alex Swindle (aswindle@email.arizona.edu)
 *
 * Purpose: Prints whether all the vowels of words read from stdin occur in alphabetical order
 */
#include <stdio.h>
#include <ctype.h>

/**
 * Check whether all vowels in a word occur in alphabetical order
 * @param str: string to check. Assumed to be lowercase and only containing a-z
 * @return: 1 if all vowels in order; 0 otherwise
 */
int checkVowels(char *str){
    char *ptr = str;
    int result = 1;
    // Store 'biggest' vowel seen
    char biggestVowel = 0;
    while(*ptr != '\0'){
        // If a vowel is encountered, check to see if a bigger one has been seen
        if(*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u'){
            if(biggestVowel > *ptr){
                // If so, not in order
                return 0;
            }
            else{
                biggestVowel = *ptr;
            }
        }
        ptr++;
    }
    return result;
}

int main(void) {
    int retVal = 0;
    char str[65];

    // Read words from stdin
    while (scanf("%64s", str) != EOF) {
        int i;
        // Convert the string to lowercase and check if it's valid (no non-alphabetical characters)
        int valid = 1;
        for (i = 0; str[i] != '\0'; i++) {
            // Uppercase get converted
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = tolower(str[i]);
            }
            // Anything that isn't lowercase is an error
            else if (!(str[i] >= 'a' && str[i] <= 'z')) {
                valid = 0;
                fprintf(stderr, "ERROR: Non-alphabetical character in the word.\n");
                retVal++;
                break;
            }
        }
        // Check the vowels on valid words
        if (valid) {
            printf("%d\n", checkVowels(str));
        }
    }
    // Return 0 if retVal == 0, 1 otherwise
    return (retVal > 0);
}


