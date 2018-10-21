/*
 * File: wordCount.c
 *
 * Author: Alex Swindle (aswindle@email.arizona.edu)
 *
 * Purpose: Reads in text from stdin, processes each word slightly, and displays a count of each word present
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

typedef struct word {
    char *str;
    int count;
    struct word *next;
} word;

// Define a global list head to save on # of parameters needed for functions
word *head;

/**
 * Print out all strings and their counts in the linked list
 */
void printList() {
    word *cur = head;
    while (cur != NULL) {
        printf("%s %d\n", cur->str, cur->count);
        cur = cur->next;
    }
}

/**
 * Add a string to the list of words. If it's already present, increase the count by 1. Otherwise, add a new node
 * @param newWord : string to add to the list
 */
void add(char *newWord) {
    if (strcmp(head->str, "\0") == 0) {
        head->count = 1;
        head->str = malloc(strlen(newWord) + 1);
        if (head->str == NULL) {
            fprintf(stderr, "Memory error.\n");
            exit(1);
        }
        strcpy(head->str, newWord);
        head->next = NULL;
        return;
    }
    word *curNode = head;
    // Loop through the list. If newWord is found anywhere, increase that node's count and return
    while (curNode->next != NULL) {
        // Compare to this node
        if (strcmp(curNode->str, newWord) == 0) {
            curNode->count++;
            return;
        }
        else {
            curNode = curNode->next;
        }
    }
    // Reached the end of the list. Do one last comparison to see if it's a match
    if (strcmp(curNode->str, newWord) == 0) {
        curNode->count++;
        return;
    }
        // If not, create a new node with newWord as the string
    else {
        word *newNode = malloc(sizeof(word));
        if (newNode == NULL) {
            fprintf(stderr, "Memory error.\n");
            exit(1);
        }

        // Fill in the new node, connect it to the end of the list
        newNode->count = 1;

        newNode->str = malloc(strlen(newWord) + 1);
        if (newNode->str == NULL) {
            fprintf(stderr, "Memory error.\n");
            exit(1);
        }
        strcpy(newNode->str, newWord);

        newNode->next = NULL;
        curNode->next = newNode;
    }
}

/**
 * Get the node at index i of a linked list
 * @param i : index to retrieve
 * @return pointer to that node
 */
word *getNode(int i) {
    int count = 0;
    word *retVal = head;
    while (count < i) {
        retVal = retVal->next;
        count++;
    }
    return retVal;
}

/**
 * Bubble-sort the items in a linked list of word objects
 */
void sortList() {
    word *iptr, *jptr;

    // Find the size of the linked list
    int size = 0;
    iptr = head;
    while (iptr != NULL) {
        size++;
        iptr = iptr->next;
    }

    // Sort the linked list using a simple bubble sort
    int i, j;
    for (i = 0; i < size - 1; i++) {
        iptr = getNode(i);
        for (j = i + 1; j < size; j++) {
            jptr = getNode(j);
            if (strcmp(iptr->str, jptr->str) > 0) {
                int tempCount = iptr->count;
                char *tempString = iptr->str;
                iptr->str = jptr->str;
                iptr->count = jptr->count;
                jptr->str = tempString;
                jptr->count = tempCount;
            }
        }
    }
}

/**
 * Free the nodes (and strings) of the linked list
 */
void freeAll(){
    word *temp = malloc(sizeof(word));
    if(temp == NULL){
        fprintf(stderr, "Memory error\n");
        exit(1);
    }

    temp = head;
    while(head != NULL){
        head = head->next;
        free(temp->str);
        free(temp);
        temp = head;
    }
}

/**
 * Convert all letters to lowercase and remove leading and trailing numbers and special characters
 * @param string
 */
char *process(char *string) {
    char *newWord = malloc(strlen(string) * sizeof(char) + 1);
    if (newWord == NULL) {
        fprintf(stderr, "Memory error.\n");
        exit(1);
    }

    char *sptr = string;
    char *nptr = newWord;
    char *lastLetter = newWord;

    // Skip leading non-alphabetical characters
    while (!isalpha(*sptr) && *sptr != '\0') {
        sptr++;
    }
    // Deal with empty string
    if (*sptr == '\0') {
        *newWord = '\0';
    }
    else {
        // Process all letters and keep track of last letter to remove trailing special characters
        while (*sptr != '\0') {
            if (isalpha(*sptr)) {
                *nptr = tolower(*sptr);
                lastLetter = nptr;
                nptr++;
            }
            sptr++;
        }
        // Remove trailing special characters by null-terminating after the last letter seen.
        *(lastLetter + 1) = '\0';
    }
    return newWord;
}


int main(void) {
    // Create the first node
    head = malloc(sizeof(word));
    if (head == NULL) {
        fprintf(stderr, "Memory error.\n");
        exit(1);
    }
    head->str = "\0";
    head->count = 0;
    head->next = NULL;

    // Flag to prevent sorting and printing an empty list
    int wordsAdded = 0;

    // Read in strings, process them, add them to the list until EOF reached, unless they're empty when processed
    char buff[129];
    while (scanf("%128s", buff) != EOF) {
        char *newWord = process(buff);
        if (strlen(newWord) > 0) {
            add(newWord);
            wordsAdded = 1;
        }
    }

    if (wordsAdded != 0) {
        // Sort and print the list
        sortList();
        printList();
    }
    // Free memory
    freeAll();
    return 0;
}
