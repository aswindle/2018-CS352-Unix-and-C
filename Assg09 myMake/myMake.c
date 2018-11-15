/*
 * File: myMake.c
 *
 * Author: Alex Swindle (aswindle@email.arizona.edu)
 *
 * Purpose: creates a basic version of a make clone. Reads in a makefile composed of target and command lines,
 * then builds a dependency graph based on the file and prints the targets in the graph starting at a target
 * specified as a command line argument
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "graph.h"

extern tNode *tHead;

// Make the file and line pointers global to allow for memory cleanup before exiting on an error
FILE *fileptr;
char *line;

/**
 * Clean up memory before exiting after an error. The error message will be printed before
 * calling this function, and then the makefile will be closed and all memory will be freed.
 */
void errorExit(){
    fclose(fileptr);
    free(line);
    freeAll();
    exit(1);
}

/**
 * Return if a string represent a make command line
 * @param line : line to check
 * @return 1 if line is a command; 0 if not
 */
int isCommmand(char *line) {
    return line[0] == '\t';
}

/**
 * Check if a line is only whitespace
 * @param line : getline line to check
 * @return 1 if the line is only whitespace, 0 otherwise
 */
int isBlank(char *line){
    char *ptr = line;
    while(*ptr){
        if(!isspace(*ptr)){
            return 0;
        }
        ptr++;
    }
    return 1;
}

/**
 * Process a line that isn't a command line
 * Check for proper formatting, then add the new target, all dependencies, and all commands
 * @param line : line to parse
 * @return : pointer to the target node created
 */
tNode *processTargetLine(char *line) {
    // Parse the beginning of the line, up through the ':' character
    char *lineptr = line;
    char colon;
    char buff[65];
    int charsRead;
    if (sscanf(lineptr, "%64[^:]%[:]%n", buff, &colon, &charsRead) != 2 || colon != ':') {
        fprintf(stderr, "Error: target line must contain a string followed by a colon.\n");
        errorExit();
    }
    lineptr += charsRead;
    // Trim spaces from the target name, which contains everything until ':'
    char *fixedTarget = buff;
    if(sscanf(buff, "%s", fixedTarget) != 1){
        fprintf(stderr, "Error: empty target specified. Exiting.\n");
        errorExit();
    }
    // Find or add the target as a new tNode to the end of the list, mark it as a target
    tNode *targetNode = addTNode(fixedTarget);
    if (targetNode->isTarget == 1) {
        fprintf(stderr, "Error: %s is already a target. Exiting.\n", buff);
        errorExit();
    }
    targetNode->isTarget = 1;
    // Add the various dependencies
    while (sscanf(lineptr, "%64s%n", buff, &charsRead) == 1) {
        addDNode(targetNode, buff);
        lineptr += charsRead;
    }
    return targetNode;
}

int main(int argc, char **argv) {
    /*
     * Check command-line args, open makefile
     */
    if (argc != 3) {
        fprintf(stderr, "Error: incorrect number of arguments.\n");
        freeAll();
        exit(1);
    }
    char *filename = argv[1];
    char *makeTarget = argv[2];
    fileptr = fopen(filename, "r");
    if (fileptr == NULL) {
        fprintf(stderr, "Error opening file. Exiting.\n");
        freeAll();
        exit(1);
    }

    /*
     * Set up list and getline pointers
     */

    // buildTNode checks for memory errors
    tHead = buildTNode("DUMMY NODE");

    line = NULL;
    size_t size = 0;

    /*
     * Process the makefile and build the graph
     */


    // Skip over blank lines
    ssize_t lineResults = getline(&line, &size, fileptr);
    while(lineResults != EOF && isBlank(line)){
        lineResults = getline(&line, &size, fileptr);
    }

    // First line needs to be a target line
    if (isCommmand(line)) {
        fprintf(stderr, "Error: first line must be a target. Exiting.\n");
        errorExit();
    }
    tNode *curTarget = processTargetLine(line);

    while ((lineResults = getline(&line, &size, fileptr)) != EOF) {
        // Commands need to be trimmed of leading and trailing whitespace
        if(isBlank(line)){
            continue;
        }
        if (isCommmand(line)) {
            char *cmdStart = line;
            // Trim the start
            while (isspace(*cmdStart)) {
                cmdStart++;
            }
            // Check for blank lines: ignore them
            if (*cmdStart == '\0') {
                continue;
            }
            // Trim the end
            char *cmdEnd = line + strlen(line) - 1;
            while (isspace(*cmdEnd)) {
                *cmdEnd = '\0';
                cmdEnd--;
            }
            // Add the command to the current target
            addCNode(curTarget, cmdStart);
        }
            // Target lines get processed, update the current target
        else {
            curTarget = processTargetLine(line);
        }
    }
    free(line);

    /*
     * Process the target specified at the command line
     */
    tNode *targetNode = findTNode(makeTarget);
    if (targetNode == NULL || targetNode->isTarget == 0) {
        fprintf(stderr, "Error: make target %s not found. Exiting.\n", makeTarget);
        errorExit();
    }
    postOrder(targetNode);

    /*
     * Free memory, close file
    */
    fclose(fileptr);
    freeAll();

    return 0;
}