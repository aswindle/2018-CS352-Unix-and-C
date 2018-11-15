/*
 * File: graph.c
 *
 * Author: Alex Swindle (aswindle@email.arizona.edu)
 *
 * Purpose: Implementation of graph functions for target, dependency, and command nodes for myMake
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"

/*
 * GLOBAL LIST HEAD
 */
tNode *tHead = NULL;

/*
 * BUILD FUNCTIONS
 */

/**
 * malloc memory for a new tNode and initialize all of its fields appropriately
 * @param newTarget : name for the node
 * @return pointer to the new node
 */
tNode *buildTNode(char *newTarget) {
    tNode *newNode = malloc(sizeof(tNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory error.\n");
        exit(1);
    }
    newNode->name = strdup(newTarget);
    if (newNode->name == NULL) {
        fprintf(stderr, "Memory error. Exiting.\n");
        freeAll();
        exit(1);
    }
    newNode->visited = 0;
    newNode->isTarget = 0;
    newNode->cmdHead = NULL;
    newNode->depHead = NULL;
    newNode->next = NULL;
    return newNode;
}

/**
 * malloc memory for a new dNode and initialize all of its fields appropriately
 * @param dest : node that the dependency points to
 * @return pointer to the new node
 */
dNode *buildDNode(tNode *dest) {
    dNode *newNode = malloc(sizeof(dNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory error.\n");
        freeAll();
        exit(1);
    }
    newNode->tptr = dest;
    newNode->next = NULL;
    return newNode;
}

/**
 * malloc memory for a new command node and the string it contains
 * @param cmd : string command
 * @return pointer to the new node
 */
cNode *buildCNode(char *cmd) {
    cNode *newNode = malloc(sizeof(cNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory error.\n");
        freeAll();
        exit(1);
    }
    newNode->cmd = strdup(cmd);
    if (newNode->cmd == NULL) {
        fprintf(stderr, "Memory error. Exiting.\n");
        freeAll();
        exit(1);
    }
    newNode->next = NULL;
    return newNode;
}

/**
 * Search for a node by name. Returns a pointer to that node if it exists or NULL otherwise
 * @param name : target name to search for
 * @return
 */
tNode *findTNode(char *name) {
    tNode *tptr = tHead;
    while (tptr != NULL) {
        if (strcmp(tptr->name, name) == 0) {
            return tptr;
        }
        tptr = tptr->next;
    }
    return tptr;
}

/**
 * Add a new command node to a particular target node
 * @param source : node to add to
 * @param cmd : new command string to add
 */
void addCNode(tNode *source, char *cmd) {
    cNode *cptr = source->cmdHead;
    if (cptr == NULL) {
        source->cmdHead = buildCNode(cmd);
        return;
    }
    while (cptr->next != NULL) {
        cptr = cptr->next;
    }
    cptr->next = buildCNode(cmd);
}

/**
 * Add a new target node to the list, or return a pointer to the node if that target already exists
 * @param newTarget : name of target to add
 * @return pointer to new node or existing node with that name
 */
tNode *addTNode(char *newTarget) {
    // If target already in list, ignore it
    tNode *newNode = findTNode(newTarget);
    if (newNode != NULL) {
        return newNode;
    }
        // Otherwise, build a new node and add it to the end of the list
    else {
        newNode = buildTNode(newTarget);
        tNode *curTNode = tHead;
        while (curTNode->next != NULL) {
            curTNode = curTNode->next;
        }
        curTNode->next = newNode;
        return newNode;
    }
}

/**
 * Add a new dependency node to a target node
 * @param target : node to add dependency to
 * @param depName : name of dependency to add
 */
void addDNode(tNode *target, char *depName) {
    // Find or create a new target node for the dependency name
    tNode *depNode = addTNode(depName);
    // Create the head of the dependencies if this is the first one
    dNode *dptr = target->depHead;
    if (dptr == NULL) {
        target->depHead = buildDNode(depNode);
        return;
    }
    // Navigate to the end of the list, checking to see if the dependency already exists
    while (dptr->next != NULL) {
        if (dptr->tptr == depNode) {
            fprintf(stderr, "Error: %s already has dependency %s\n", target->name, depNode->name);
            freeAll();
            exit(1);
        }
        dptr = dptr->next;
    }
    // Check last node
    if (dptr->tptr == depNode) {
        fprintf(stderr, "Error: %s already has dependency %s\n", target->name, depNode->name);
        freeAll();
        exit(1);
    }
    dptr->next = buildDNode(depNode);
}

/*
 * SEARCH FUNCTIONS
 */

/**
 * Perform a postOrder traversal of the graph starting at a particular node, then process the target node
 * @param targetNode
 */
void postOrder(tNode *targetNode) {
    // If target visited, return
    if (targetNode->visited == 1) {
        return;
    }
    // If not, mark it visited then perform postOrder on all of its children
    targetNode->visited = 1;
    dNode *curDep = targetNode->depHead;
    while (curDep != NULL) {
        postOrder(curDep->tptr);
        curDep = curDep->next;
    }
    // Process this node
    process(targetNode);
}

/**
 * Process a node at the end of the postOrder search:
 * Print the name followed by each command associated with it
 * @param node
 */
void process(tNode *node) {
    // Print the node's name followed by all of its commands
    printf("%s\n", node->name);
    cNode *cptr = node->cmdHead;
    while (cptr != NULL) {
        printf("  %s\n", cptr->cmd);
        cptr = cptr->next;
    }
}


/*
 * FREE FUNCTIONS
 */

/**
 * Free the interior pieces of an individual tNode
 * @param target
 */
void freeTNodeInnards(tNode *target) {
    // Free all of the dependency and command nodes, including the string inside the command nodes
    dNode *dptr = target->depHead;
    while (dptr != NULL) {
        dNode *temp = dptr->next;
        free(dptr);
        dptr = temp;
    }
    cNode *cptr = target->cmdHead;
    while (cptr != NULL) {
        cNode *temp = cptr->next;
        free(cptr->cmd);
        free(cptr);
        cptr = temp;
    }
    // Free the string inside the tNode
    free(target->name);
}

/**
 * Free all memory associated with the dependency graph
 */
void freeAll() {
    tNode *tptr = tHead;
    while (tptr != NULL) {
        tNode *temp = tptr->next;
        freeTNodeInnards(tptr);
        free(tptr);
        tptr = temp;
    }
}

/**
 * Print the complete state of the graph with all targets, dependencies, and commands
 */
void printGraph() {
    tNode *tptr = tHead;
    while (tptr != NULL) {
        printf("%s:\nDependencies: ", tptr->name);
        dNode *dptr = tptr->depHead;
        while (dptr != NULL) {
            printf("%s ", dptr->tptr->name);
            dptr = dptr->next;
        }
        printf("\nCommands: ");
        cNode *cptr = tptr->cmdHead;
        while (cptr != NULL) {
            printf("%s ", cptr->cmd);
            cptr = cptr->next;
        }
        printf("\n");
        tptr = tptr->next;
    }
}

