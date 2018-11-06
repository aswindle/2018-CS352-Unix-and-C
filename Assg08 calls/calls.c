/*
 * File: calls.c
 *
 * Author: Alex Swindle (aswindle@email.arizona.edu)
 *
 * Purpose: Reads lines containing 2 phone numbers from one or more files and adds them to a graph.
 * Then allows querying of pairs of numbers to find out how many times they called each other
 * or if they're indirectly connected in the graph.
 *
 * Basic structure of the code is reused from assg07
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Node for each phone number
 */
typedef struct numberNode {
    char *number;
    int BFSLevel;
    struct callNode *callsHead;
    struct numberNode *next;
    struct numberNode *queueptr;
} numberNode;

/*
 * Node for each call within a numberNode
 */
typedef struct callNode {
    numberNode *called;
    int count;
    struct callNode *next;
} callNode;

numberNode *head;
int errorSeen = 0;

/**
 * Allocate memory for and return pointer to a new call node that points to a particular numberNode
 * @param node : the node to point back to
 * @return pointer to a new callNode
 */
callNode *buildCallNode(numberNode *node) {
    callNode *retVal = malloc(sizeof(callNode));
    if (retVal == NULL) {
        fprintf(stderr, "Memory Error.\n");
        exit(1);
    }
    retVal->called = node;
    retVal->count = 1;
    retVal->next = NULL;
    return retVal;
}

/**
 * Allocate memory for and return pointer to a new numberNode
 * @param newNumber : phone number string
 * @return pointer to a new node
 */
numberNode *buildNumberNode(char *newNumber) {
    numberNode *retVal = malloc(sizeof(numberNode));
    if (retVal == NULL) {
        fprintf(stderr, "Memory Error.\n");
        exit(1);
    }
    retVal->number = strdup(newNumber);
    //Call list should initially be empty
    retVal->callsHead = NULL;
    retVal->next = NULL;
    retVal->queueptr = NULL;
    return retVal;
}

/**
 * Free all callNodes of a particular numberNode
 * @param numptr: numberNode to free
 */
void freeCallNodes(numberNode *numptr) {
    callNode *callptr = numptr->callsHead;
    // Handle empty call list
    if (callptr == NULL) {
        return;
    }
    callNode *next = callptr->next;
    free(callptr);
    callptr = next;
    while (callptr != NULL) {
        next = callptr->next;
        free(callptr);
        callptr = next;
    }
}

/**
 * Add a new phone number to the list of numberNodes
 * @param newNumber: phone number to add
 */
void addNumber(char *newNumber) {
    numberNode *numptr = head;
    // Navigate to the end of the list
    while (numptr->next != NULL) {
        numptr = numptr->next;
    }
    numptr->next = buildNumberNode(newNumber);
}

/**
 * Search for a numberNode that matches a particular phone number string.
 * @param number: string to search for, in DDD-DDD-DDDD form
 * @return pointer to a node if it exists, NULL if it doesn't.
 */
numberNode *findNumberNode(char *number) {
    numberNode *numptr = head;
    while (numptr != NULL) {
        if (strcmp(numptr->number, number) == 0) {
            return numptr;
        }
        else {
            numptr = numptr->next;
        }
    }
    return numptr;
}

/**
 * Add a call between 2 numberNodes.
 * Creates a new callNode if needed, or increases the count if that link already exists
 * @param source : numberNode 1
 * @param dest : numberNode 2
 */
void addCall(numberNode *source, numberNode *dest) {
    callNode *curCall = source->callsHead;
    // Add to empty list of calls
    if (curCall == NULL) {
        source->callsHead = buildCallNode(dest);
        return;
    }
    while (curCall->next != NULL) {
        if (curCall->called == dest) {
            curCall->count++;
            return;
        }
        else {
            curCall = curCall->next;
        }
    }
    // At the end of the list. Check for equality on last node
    if (curCall->called == dest) {
        curCall->count++;
        return;
    }
    else {
        curCall->next = buildCallNode(dest);
    }
}

/**
 * Print all the calls associated with a particular number
 * @param numptr
 */
void printCalls(numberNode *numptr) {
    callNode *callptr = numptr->callsHead;
    printf("%s called to: ", numptr->number);
    while (callptr != NULL) {
        printf("%s %d times ", callptr->called->number, callptr->count);
        callptr = callptr->next;
    }
    printf("\n");
}

/**
 * Print all the numbers and call counts present in the list of numberNodes
 */
void printNumbers() {
    // Skip over dummy head node
    numberNode *numptr = head->next;
    while (numptr != NULL) {
        printCalls(numptr);
        numptr = numptr->next;
    }
}

/**
 * Checks to see if a string is a valid phone number of the form 'DDD-DDD-DDDD'
 * @param number: string to check
 * @return 1 if it's valid, 0 otherwise
 */
int isValidNumber(char *number) {
    // Check length first
    if (strlen(number) != 12) {
        return 0;
    }
    // Check the actual content of the number
    int i = 0;
    while (i < 12) {
        // DDD-DDD-DDDD
        // 012345678901
        if (i == 3 || i == 7) {
            if (number[i] != '-') {
                return 0;
            }
        }
        else {
            if (number[i] < '0' || number[i] > '9') {
                return 0;
            }
        }
        i++;
    }
    return 1;
}

/**
 * Check to see if 2 numberNodes have directly called each other
 * @param source : numberNode 1
 * @param dest : numberNode 2
 * @return the count of how many times they called; -1 if they never did
 */
int isDirectlyConnected(numberNode *source, numberNode *dest) {
    callNode *callptr = source->callsHead;
    while (callptr != NULL) {
        if(callptr->called == dest){
            return callptr->count;
        }
        callptr = callptr->next;
    }
    return -1;
}

/**
 * Clear all BFSLevel values and return queueptrs to NULL in the list of numberNodes
 */
void clearLevelsAndQueuePtrs(){
    numberNode *numptr = head;
    while(numptr != NULL){
        numptr->BFSLevel = -1;
        numptr->queueptr = NULL;
        numptr = numptr->next;
    }
}

/**
 * Prints the current state of the queue during BFS. Only used for debugging
 * @param queueHead
 */
void printQueue(numberNode *queueHead){
    numberNode *qptr = queueHead;
    printf("Current queue:\n");
    while(qptr != NULL){
        printf("%s level %d\t", qptr->number, qptr->BFSLevel);
        qptr = qptr->queueptr;
    }
    printf("\n");
}

/**
 * Perform a BFS to see if 2 numberNodes are indirectly connected
 * @param start
 * @param target
 * @return the number of links between the 2 nodes, or -1 if they're not connected
 */
int BFS(numberNode *start, numberNode *target){
    clearLevelsAndQueuePtrs();
    numberNode *queueHead = start;
    numberNode *queueTail = start;
    start->BFSLevel = 0;
    start->queueptr = NULL;

    // Queue up all the children
    while(queueHead != NULL){
        // Check to see if target reached
        if(queueHead == target){
            return queueHead->BFSLevel - 1;
        }
        // Add the head's call connections to the queue if they haven't been already
        callNode *callptr = queueHead->callsHead;
        while(callptr != NULL){
            // Add if the BFSLevel is still negative
            numberNode *curNum = callptr->called;
            if(curNum->BFSLevel < 0){
                queueTail->queueptr = curNum;
                queueTail = curNum;
                queueTail->queueptr = NULL;
                curNum->BFSLevel = queueHead->BFSLevel + 1;
            }
            callptr = callptr->next;
        }

        // Pop the head off the list, move to next element
        queueHead = queueHead->queueptr;
    }
    return -1;
}

/**
 * Parse a line to make sure it's of the form 'DDD-DDD-DDDD DDD-DDD-DDDD'
 * If the line is blank, ignore it
 * If it isn't valid, print an error
 * If it is valid, add the call between the numbers if the mode flag is 'i' (inserting)
 * Otherwise, run queries if the mode flag is 'q' (querying)
 *
 * @param line: string to check for validity
 * @param mode: either 'i' or 'q' for insertion of data or querying of data
 */
void processLine(char *line, char mode) {
    /*
     * Line must be in the form "NUMBER NUMBER"
     * Where NUMBER = DDD-DDD-DDDD, D being a digit
     * Anything other than 2 inputs is illegal, as is any line with a number that's invalid
     */
    char num1[14], num2[14], dummy[2];
    int scanResult = sscanf(line, "%13s %13s %1s", num1, num2, dummy);
    // Blank line
    if (scanResult <= 0) {
        return;
    }
    else if (scanResult != 2) {
        fprintf(stderr, "Error: invalid number of arguments on a line in the file.\n");
        errorSeen++;
        return;
    }
    else {
        // Check the two numbers for validity
        if (!isValidNumber(num1) || !isValidNumber(num2)) {
            fprintf(stderr, "Error: at least one of the numbers was invalid.\n");
            errorSeen++;
            return;
        }
        // Check to see if the two numbers are equal
        if (strcmp(num1, num2) == 0) {
            fprintf(stderr, "Error: a number can't call itself.\n");
            errorSeen++;
            return;
        }
        // Both numbers are valid.

        // 'i' mode for inserting numbers from files
        if(mode == 'i') {
            // Both numbers are good. Actually process the line
            // Get the nodes representing each number, or create them if the numbers haven't been added yet
            numberNode *numNode1 = findNumberNode(num1);
            if (numNode1 == NULL) {
                addNumber(num1);
                numNode1 = findNumberNode(num1);
            }
            numberNode *numNode2 = findNumberNode(num2);
            if (numNode2 == NULL) {
                addNumber(num2);
                numNode2 = findNumberNode(num2);
            }
            // Add calls in both directions
            addCall(numNode1, numNode2);
            addCall(numNode2, numNode1);
        }
        //'q' mode for running queries
        else{
            numberNode *numNode1 = findNumberNode(num1);
            numberNode *numNode2 = findNumberNode(num2);
            if(numNode1 == NULL || numNode2 == NULL){
                fprintf(stderr, "Error: one or both of the entered numbers doesn't exist.\n");
                errorSeen++;
                return;
            }
            // Check for direct connection
            int connectResult = isDirectlyConnected(numNode1, numNode2);
            if(connectResult != -1){
                printf("Talked %d times\n", connectResult);
                return;
            }
            // If no direct connection, do a BFS
            else{
                connectResult = BFS(numNode1, numNode2);
                if(connectResult == -1){
                    printf("Not connected\n");
                }
                else{
                    printf("Connected through %d numbers\n", connectResult);
                }
            }
        }
    }
}

int main(int argc, char **argv) {
    // Build the head of the list
    head = malloc(sizeof(numberNode));
    if(head == NULL){
        fprintf(stderr, "Memory error. Exiting.\n");
        exit(1);
    }
    head->next = NULL;
    head->number = strdup("head");
    head->callsHead = NULL;
    head->queueptr = NULL;

    /*
     * ###################
     * INSERT DATA SECTION
     * ###################
     */

    // Requires at least 1 file to be read in
    if (argc == 1) {
        fprintf(stderr, "Error: at least 1 input file must be specified. Exiting.\n");
        exit(1);
    }

    // Read each input file
    int fileNum;
    for (fileNum = 1; fileNum < argc; fileNum++) {
        char *filename = argv[fileNum];
        FILE *fileptr = fopen(filename, "r");
        if (fileptr == NULL) {
            fprintf(stderr, "Error opening file. Moving to next file.\n");
            errorSeen++;
            continue;
        }
        // Set up getline pointers
        char *line = NULL;
        size_t size = 0;
        // Keep parsing lines until EOF reached
        while (getline(&line, &size, fileptr) != EOF) {
            // Process the line in insert mode
            processLine(line, 'i');
        }
        free(line);
        fclose(fileptr);
    }

    /*
     * #############
     * QUERY SECTION
     * #############
     */

    char *line = NULL;
    size_t size = 0;
    while(getline(&line, &size, stdin) != EOF){
        // Process each line in query mode
        processLine(line, 'q');
    }
    free(line);

    /*
     * ############
     * FREE SECTION
     * ############
     */

    numberNode *numptr = head;
    numberNode *temp;
    while (numptr != NULL) {
        temp = numptr->next;
        freeCallNodes(numptr);
        free(numptr->number);
        free(numptr);
        numptr = temp;
    }

    return errorSeen > 0;
}