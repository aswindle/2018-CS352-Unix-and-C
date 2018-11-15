/*
 * File: graph.h
 *
 * Author: Alex Swindle (aswindle@email.arizona.edu)
 *
 * Purpose: Header file for graph.c giving public info about graph methods available
 */

#ifndef _GRAPH_H
#define _GRAPH_H

/*
 * Typedefs
 */
typedef struct targetNode {
    int isTarget;
    int visited;
    char *name;
    struct dependencyNode *depHead;
    struct commandNode *cmdHead;
    struct targetNode *next;

} tNode;

typedef struct dependencyNode {
    tNode *tptr;
    struct dependencyNode *next;
} dNode;

typedef struct commandNode {
    char *cmd;
    struct commandNode *next;
} cNode;

/*
 * Public Functions
 */

tNode *buildTNode(char *newTarget);

dNode *buildDNode(tNode *dest);

cNode *buildCNode(char *cmd);

tNode *findTNode(char *name);

void addCNode(tNode *source, char *cmd);

tNode *addTNode(char *newTarget);

void addDNode(tNode *target, char *depName);

void postOrder(tNode *targetNode);

void process(tNode *node);

void freeAll();

void printGraph();

/*
 * Globals
 */
extern tNode *tHead;

#endif
