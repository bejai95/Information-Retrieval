// Assignment 1 20T3 COMP2521: Information Retrieval
// This program was written by Bejai Cobbing (z5313120)

// TfIdfList.c
// This file contains functions relating to the TfIdf ADT

// This file has been adapted from InvertedIndexBST.c which was originally 
// adapted from  the week 3 tutorial and the week 3 lab: Binary Search Trees, 
// which can be accessed at 
// https://webcms3.cse.unsw.edu.au/COMP2521/20T3/resources/52974

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "invertedIndex.h"
#include "TfIdfList.h"

// Create a new node containing the file name, return a pointer to it
TfIdfList new_TfIdfList_node(char *filename, double tfIdfSum) {
    TfIdfList new = malloc(sizeof(struct TfIdfNode));
    assert (new != NULL);
    
    // Malloc the file name string and then copy it across
    new->filename = malloc((strlen(filename) + 1) * sizeof(char));
    strcpy(new->filename, filename);
    
    new->tfIdfSum = tfIdfSum;
    new->next = NULL;
    return new;
}
    
// Insert a node into the TfIdfList, return the head of the updated list
TfIdfList insert_TfIdfList_node(TfIdfList L, char *filename, double tfIdfSum) {
    // If the list is empty then return a new list containing the node
    if (L == NULL) 
        return new_TfIdfList_node(filename, tfIdfSum); 
        
    // Check whether this filename is already in the list. Duplicates aren't added
    TfIdfList current = L;
    while (current != NULL) {
        if (strcmp(filename, current->filename) == 0) 
            return L;
        current = current->next;
    }
    TfIdfList new = new_TfIdfList_node(filename, tfIdfSum); 
    
    // Find where in the linked list the node should be inserted 
    TfIdfList prev = find_node(L, filename, tfIdfSum);
    
    if (prev == NULL) { // Need to insert at the start of the linked list
        new->next = L;
        return new; 
    }
    TfIdfList curr = prev->next; 
    
    if (curr == NULL) // Need to insert at the end of the linked list
        prev->next = new; 
    else { // Inserting in the middle
        new->next = curr;
        prev->next = new;
    }
    return L;
}

// Find the location in the linked list where the new node should be inserted
TfIdfList find_node(TfIdfList L, char *filename, double tfIdfSum) {
    TfIdfList curr = L;     
    TfIdfList prev = NULL; 
    while (curr != NULL && tfIdfSum <= curr->tfIdfSum) {
        if (tfIdfSum == curr->tfIdfSum) {
            // If the tfIdfSum's are equal then sort alphabetically
            while (curr != NULL && tfIdfSum == curr->tfIdfSum && strcmp(filename, curr->filename) >= 0) {
                prev = curr;
                curr = curr->next;
            }
            return prev; 
        }
        prev = curr;
        curr = curr->next;
    }
    return prev; 
}
