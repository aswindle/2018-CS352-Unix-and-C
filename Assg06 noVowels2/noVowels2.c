/*
 * File: noVowels2.c
 *
 * Author: Alex Swindle (aswindle@email.arizona.edu)
 *
 * Purpose: Reads from stdin and prints out groups of words that match when the vowels are removed
 */
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <ctype.h>

/**
 * One node of a linked list of strings
 */
typedef struct stringNode {
    char *string;
    struct stringNode *next;
} stringNode;

/**
 * One node of a linked list of groups of strings
 */
typedef struct groupNode {
    struct stringNode *strings;
    struct groupNode *next;
} groupNode;

/**
 * Print out an error and exit in the event a malloc fails
 */
void memError() {
    fprintf(stderr, "Memory error.\n");
    exit(1);
}

/**
 * RE-USED FROM ASSG2
 * Returns whether 2 strings have matching consonants (will check lowercase version of strings)
 * Assumes they only contain alphabetical characters
 * @param a: first string
 * @param b: second string
 * @return 1 if the two strings match with vowels removed, 0 otherwise
 */
int matchConsonants(char a[], char b[]) {
    // Track current location in both strings
    int aPos = 0;
    int bPos = 0;
    // Track current character in both strings
    char aChar = tolower(a[aPos]);
    char bChar = tolower(b[bPos]);
    while (aChar != '\0' || bChar != '\0') {
        // Increment aPos to skip over vowels
        if (aChar == 'a' || aChar == 'e' || aChar == 'i' || aChar == 'o' || aChar == 'u') {
            aPos++;
        }
            // Increment bPos to skip over vowels
        else if (bChar == 'a' || bChar == 'e' || bChar == 'i' || bChar == 'o' || bChar == 'u') {
            bPos++;
        }
            // Actually compare the two characters if neither is a vowel
        else {
            //Increment both positions, if not currently at the end
            if (aChar != '\0') {
                aPos++;
            }
            if (bChar != '\0') {
                bPos++;
            }
            // If any two characters don't match, the whole strings don't match
            if (aChar != bChar) {
                return 0;
            }
        }

        // Read next characters
        aChar = tolower(a[aPos]);
        bChar = tolower(b[bPos]);
    }
    return 1;
}

/**
 * Creates a new stringNode, checks that malloc was successful, and fills in its string field
 * @param word
 * @return
 */
stringNode *buildStringNode(char *word) {
    stringNode *newNode = malloc(sizeof(stringNode));
    if (newNode == NULL) {
        memError();
    }
    else {
        newNode->string = strdup(word);
        newNode->next = NULL;
    }
    return newNode;
}

/**
 * Returns whether a string contains only alphabetical characters
 * @param word : string to check
 * @return 1 if only letters, 0 otherwise
 */
int isLegal(char *word) {
    char *ptr;
    for (ptr = word; *ptr != '\0'; ptr++) {
        if (!isalpha(*ptr)) {
            return 0;
        }
    }
    return 1;
}

/**
 * Add a string to the linked list of groupNodes
 * If it matches one of the existing nodes' strings, add it to that list
 * Otherwise, create a new node and store the string there
 * @param word : string to add
 * @param head : head of linked list of groupNodes
 */
void add(char *word, groupNode *head) {
    groupNode *gptr = head;
    while (gptr->next != NULL) {
        // Add to an existing list of string if a match is found
        if (matchConsonants(word, gptr->strings->string)) {
            stringNode *sptr = gptr->strings;
            while (sptr->next != NULL) {
                sptr = sptr->next;
            }
            sptr->next = buildStringNode(word);
            return;
        }
            // Continue to the next node if not
        else {
            gptr = gptr->next;
        }
    }
    // At the end of the list. Check again to see if it matches the last one
    if (matchConsonants(word, gptr->strings->string)) {
        stringNode *sptr = gptr->strings;
        while (sptr->next != NULL) {
            sptr = sptr->next;
        }
        sptr->next = buildStringNode(word);
        return;
    }
        // Add a new node to the end of the list
    else {
        groupNode *newGroup = malloc(sizeof(groupNode));
        if (newGroup == NULL) {
            memError();
        }
        else {
            newGroup->strings = buildStringNode(word);
            newGroup->next = NULL;
            gptr->next = newGroup;
        }
    }
}

/**
 * Print the contents of a linked list of stringNodes
 * @param start : head of list
 */
void printStringList(stringNode *start) {
    stringNode *ptr = start;
    while (ptr != NULL) {
        printf("%s ", ptr->string);
        ptr = ptr->next;
    }
    printf("\n");
}

/**
 * Print the contents of all groupNodes
 * @param head
 */
void printAll(groupNode *head) {
    groupNode *ptr = head;
    while (ptr != NULL) {
        printStringList(ptr->strings);
        ptr = ptr->next;
    }
}

int main(void) {
    int retVal = 0;

    groupNode *head = malloc(sizeof(groupNode));
    if (head == NULL) {
        memError();
        exit(1);
    }
    head->strings = malloc(sizeof(stringNode));
    if (head->strings == NULL) {
        memError();
    }
    // First node will hold an empty string, which will also catch all words that are only vowels
    head->strings->string = "";
    head->strings->next = NULL;
    head->next = NULL;

    char buff[65];
    while (scanf("%64s", buff) != EOF) {
        if (isLegal(buff)) {
            add(buff, head);
        }
        else {
            fprintf(stderr, "Error: input contained non-alphabetical character.\n");
            retVal++;
        }
    }
    // Print all, skipping over the first node which contains only blank and all-vowel strings
    if (head->next != NULL) {
        printAll(head->next);
    }

    return (retVal > 0);
}