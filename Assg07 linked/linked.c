/*
 * File: linked.c
 *
 * Author: Alex Swindle (aswindle@email.arizona.edu)
 *
 * Purpose: Reads commands from either a file or stdin to create pages, create links between them, and determine
 * if 2 pages are connected using DFS.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pageNode {
    char *pageName;
    struct linkNode *linkHead;
    struct pageNode *next;
    int visited;
} pageNode;

typedef struct linkNode {
    pageNode *linkedTo;
    struct linkNode *next;
} linkNode;

pageNode *head;
int errorSeen = 0;

/**
 * Clear the visited flag of every node in the list at the start of DFS
 */
void clearAllVisited() {
    pageNode *curPage = head;
    while (curPage != NULL) {
        curPage->visited = 0;
        curPage = curPage->next;
    }
}

/**
 * Allocate memory for and return pointer to a new linkNode that points to a pageNode
 * @param node: pageNode to point to
 * @return a pointer to the new node
 */
linkNode *buildLinkNode(pageNode *node) {
    linkNode *retVal = malloc(sizeof(linkNode));
    if (retVal == NULL) {
        fprintf(stderr, "Memory Error.\n");
        exit(1);
    }
    retVal->linkedTo = node;
    retVal->next = NULL;
    return retVal;
}

/**
 * Allocate memory for and return pointer to a new pageNode that has a page name and links to itself
 * @param pageName: name of the page
 * @return point to the new node
 */
pageNode *buildPageNode(char *pageName) {
    pageNode *retVal = malloc(sizeof(pageNode));
    if (retVal == NULL) {
        fprintf(stderr, "Memory Error.\n");
        exit(1);
    }
    retVal->pageName = strdup(pageName);
    retVal->linkHead = buildLinkNode(retVal);
    retVal->next = NULL;

    return retVal;
}

/**
 * Frees the entire linked list of linkNodes for a particular pageNode
 * @param pageptr: page to free linkNodes on
 */
void freeLinkNodes(pageNode *pageptr) {
    linkNode *linkptr = pageptr->linkHead;
    linkNode *next = linkptr->next;
    free(linkptr);
    linkptr = next;
    while (linkptr != NULL) {
        next = linkptr->next;
        free(linkptr);
        linkptr = next;
    }
}

/**
 * Add a new page to the linked list of pageNodes. Print an error if a page with that name exists
 * Also links the page to itself when initializing the linkNode list
 * @param pageName: name of page to be stored
 */
void addPage(char *pageName) {
    pageNode *pageptr = head;
    // Navigate to the end of the list, checking if the page already exists
    while (pageptr->next != NULL) {
        if (strcmp(pageName, pageptr->pageName) == 0) {
            fprintf(stderr, "Error: page %s already exists\n", pageName);
            errorSeen++;
            return;
        }
        else {
            pageptr = pageptr->next;
        }
    }
    // At the end of the list. Do one last check for equality, then create a new page node
    if (strcmp(pageName, pageptr->pageName) == 0) {
        fprintf(stderr, "Error: page %s already exists\n", pageName);
        errorSeen++;
        return;
    }
    else {
        pageptr->next = buildPageNode(pageName);
    }
}

/**
 * Searches the list of pageNodes for one matching a string. Returns that node if not, NULL otherwise
 * @param pageName : string to search for
 * @return pointer to the pageName's node, or NULL if not found
 */
pageNode *findPageNode(char *pageName) {
    pageNode *pageptr = head;
    while (pageptr != NULL) {
        if (strcmp(pageptr->pageName, pageName) == 0) {
            return pageptr;
        }
        else {
            pageptr = pageptr->next;
        }
    }
    return pageptr;
}

/**
 * Add a link in source's linked list of linkNodes to dest. Skips adding repeat nodes, but no error reported
 * @param source : source pageNode
 * @param dest : destination pageNode
 */
void addLink(pageNode *source, pageNode *dest) {
    linkNode *curLink = source->linkHead;
    while (curLink->next != NULL) {
        if (curLink->linkedTo == dest) {
            return;
        }
        else {
            curLink = curLink->next;
        }
    }
    // At the end of the list. Check for equality on last node
    if (curLink->linkedTo == dest) {
        return;
    }
    else {
        curLink->next = buildLinkNode(dest);
    }
}

/**
 * Print all the links within a page
 * @param pageptr
 */
void printLinks(pageNode *pageptr) {
    linkNode *linkptr = pageptr->linkHead;
    printf("%s links to: ", pageptr->pageName);
    while (linkptr != NULL) {
        printf("%s ", linkptr->linkedTo->pageName);
        linkptr = linkptr->next;
    }
    printf("\n");
}

/**
 * Print a list of all pages and all of the links within those pages
 */
void printPages() {
    // Skip over dummy head node
    pageNode *pageptr = head->next;
    while (pageptr != NULL) {
        printLinks(pageptr);
        pageptr = pageptr->next;
    }
}

/**
 * Perform a recursive DFS to see if two nodes are connected
 * @param source : source pageNode
 * @param dest : destination pageNode
 * @return 1 if there's a page from 'source' to 'dest', 0 otherwise
 */
int DFS(pageNode *source, pageNode *dest) {
    if (source == dest) {
        return 1;
    }
    else {
        if (source->visited == 1) {
            return 0;
        }
        source->visited = 1;
        linkNode *curLink = source->linkHead;
        while (curLink != NULL) {
            if (DFS(curLink->linkedTo, dest) == 1) {
                return 1;
            }
            curLink = curLink->next;
        }
        return 0;
    }
}

/**
 * Parse a line of commands. Must start with @addPages, @addLinks, or @isConnected to avoid an error
 * Each of those 3 commands is checked for the proper number of arguments and then that function is performed
 * @param line : line to parse
 */
void processLine(char *line) {
    char *lineptr = line;
    char buff[65] = "";
    int charsRead = 0;
    // Check for a valid operation as first argument on the line
    int result = sscanf(lineptr, "%64s%n", buff, &charsRead);
    lineptr += charsRead;
    /*
     * SPECIAL CASE: BLANK LINE
     */
    if(result == 0){
        return;
    }
    /*
     * ADD PAGES
     */
    if (strcmp(buff, "@addPages") == 0) {
        // Keep reading page names until sscanf doesn't update buff
        while (sscanf(lineptr, "%64s%n", buff, &charsRead) == 1) {
            lineptr += charsRead;
            addPage(buff);
        }
    }
        /*
         * ADD LINKS
         */
    else if (strcmp(buff, "@addLinks") == 0) {
        // Read the source page as the next string
        if (sscanf(lineptr, "%64s%n", buff, &charsRead) != 1) {
            fprintf(stderr, "Error: no source page could be read to add links to.\n");
            errorSeen++;
        }
        else {
            // Find the source page
            lineptr += charsRead;
            pageNode *sourcePage = findPageNode(buff);
            if (sourcePage == NULL) {
                fprintf(stderr, "Error: source page %s does not exist.\n", buff);
                errorSeen++;
            }
            else {
                while (sscanf(lineptr, "%64s%n", buff, &charsRead) == 1) {
                    lineptr += charsRead;
                    pageNode *dest = findPageNode(buff);
                    if (dest == NULL) {
                        fprintf(stderr, "Error: tried to link to %s, which doesn't exist.\n", buff);
                        errorSeen++;
                    }
                    else {
                        addLink(sourcePage, dest);
                    }
                }
            }
        }
    }
        /*
         * IS CONNECTED
         */
    else if (strcmp(buff, "@isConnected") == 0) {
        // Add a dummy string to catch more than 2 args to isConnected
        char start[65], end[65], dummy[65];
        if (sscanf(lineptr, "%64s %64s %64s", start, end, dummy) != 2) {
            fprintf(stderr, "Error: there weren't exactly 2 page names to check for connectedness.\n");
            errorSeen++;
        }
        else {
            pageNode *source = findPageNode(start);
            pageNode *dest = findPageNode(end);
            if (source == NULL || dest == NULL) {
                fprintf(stderr, "Error: one of the two nodes doesn't exist.\n");
                errorSeen++;
            }
            else {
                clearAllVisited();
                int connected = DFS(source, dest);
                printf("%d\n", connected);
            }
        }
    }
    else {
        fprintf(stderr, "Error: invalid operation at start of line.\n");
        errorSeen++;
    }
}

int main(int argc, char **argv) {
    // Build the head of the list
    head = malloc(sizeof(pageNode));
    head->next = NULL;
    head->pageName = strdup("head");
    head->linkHead = buildLinkNode(head);

    // Determine input stream: defaults to stdin then checks for filename command-line argument
    // flag for closing the file at the end
    int fromFile = 0;
    FILE *fileptr = stdin;
    if (argc > 1) {
        char *filename = argv[1];
        fromFile = 1;
        fileptr = fopen(filename, "r");
        if (fileptr == NULL) {
            fprintf(stderr, "Error opening file. Exiting.\n");
            exit(1);
        }
        // Extra command-line args should produce an error
        if(argc > 2){
            fprintf(stderr, "Error: only one command-line argument (filename) allowed.\n");
            errorSeen++;
        }
    }

    // Set up getline pointers
    char *line = NULL;
    size_t size = 0;

    // Keep parsing lines until EOF reached
    while (getline(&line, &size, fileptr) != EOF) {
        processLine(line);
    }
    free(line);

    // Free everything
    pageNode *pageptr = head;
    pageNode *temp;
    while (pageptr != NULL) {
        temp = pageptr->next;
        freeLinkNodes(pageptr);
        free(pageptr->pageName);
        free(pageptr);
        pageptr = temp;
    }

    //Close the file, if something other than stdin was used
    if (fromFile) {
        fclose(fileptr);
    }
    return errorSeen > 0;
}