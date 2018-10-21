/*
 * File: median2.c
 *
 * Author: Alex Swindle (aswindle@email.arizona.edu)
 *
 * Purpose: Reads in integers from stdin, creates a linked list of the values, and computes the median of them
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Nodes of the linked list: need an int and a next pointer
 */
typedef struct node {
    int val;
    struct node *next;
} node;

/**
 * Get the node at index i of a linked list
 * @param i : index to retrieve
 * @return pointer to that node
 */
node *getNode(node *head, int i) {
    int count = 0;
    node *retVal = head;
    while (count < i) {
        retVal = retVal->next;
        count++;
    }
    return retVal;
}

/**
 * Return the median of a linked list
 * @param head : head of linked list
 * @return median as a float
 */
float computeMedian(node *head) {
    node *ptr = head;
    int size = 0;

    // Find the size of the list
    while (ptr != NULL) {
        size++;
        ptr = ptr->next;
    }

    // Find the median
    float retVal;
    // Odd: middle number
    if (size % 2 == 1) {
        retVal = getNode(head, size / 2)->val;
    }
        // Odd: average of two middle values
    else {
        retVal = (float) (getNode(head, size / 2 - 1)->val + getNode(head, size / 2)->val) / 2;
    }
    return retVal;
}

/**
 * Bubble-sort the items in a linked list
 * @param head : head of linked list to sort
 */
void sortList(node *head) {
    node *iptr, *jptr;

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
        iptr = getNode(head, i);
        for (j = i + 1; j < size; j++) {
            jptr = getNode(head, j);
            if (iptr->val > jptr->val) {
                int temp = iptr->val;
                iptr->val = jptr->val;
                jptr->val = temp;
            }
        }
    }
}

int main(void) {
    int retVal = 0;
    int scanResults;
    node *nodeptr;

    // Create the linked list, read in first value
    node *head = malloc(sizeof(node));
    if (head == NULL) {
        fprintf(stderr, "Memory error\n");
        exit(1);
    }
    head->next = NULL;

    scanResults = scanf("%d", &head->val);
    if (scanResults < 1) {
        fprintf(stderr, "Error: first value wasn't an integer.\n");
        exit(1);
    }

    // Keep adding to the linked list until EOF reached
    nodeptr = head;
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory error\n");
        exit(1);
    }
    newNode->next = NULL;

    while ((scanResults = scanf("%d", &newNode->val)) != EOF) {
        //Indicate errors if needed
        if (scanResults == 0) {
            fprintf(stderr, "Error: didn't read an integer. Finding median of what was input.\n");
            retVal++;
            break;
        }
        else {
            // Add newNode to the linked list
            nodeptr->next = newNode;
            nodeptr = newNode;
        }

        // malloc a new node for the next iteration
        newNode = malloc(sizeof(node));
        if (newNode == NULL) {
            fprintf(stderr, "Memory error\n");
            exit(1);
        }
        newNode->next = NULL;
    }

    // Sort and then find the median
    sortList(head);
    printf("%.1f\n", computeMedian(head));

    return (retVal > 0);
}