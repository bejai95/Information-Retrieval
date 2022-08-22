// Assignment 1 20T3 COMP2521: Information Retrieval
// This program was written by Bejai Cobbing (z5313120)

// invertedIndexBST.c 
// This file contains functions relating to invertedIndexBST ADT

// This file has been adapted from the week 3 tutorial and the 
// week 3 lab: Binary Search Trees, which can be accessed at 
// https://webcms3.cse.unsw.edu.au/COMP2521/20T3/resources/52974

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "invertedIndex.h"
#include "InvertedIndexBST.h"

// Create a new node containing the given word, return a pointer to it
InvertedIndexBST newNode(char *word) {
    InvertedIndexBST new = malloc(sizeof(struct InvertedIndexNode));
    assert (new != NULL);
    
    // Malloc the string and then copy it across
    new->word = malloc((strlen(word) + 1) * sizeof(char));
    strcpy(new->word, word);
    
    new->fileList = NULL;
    new->left = NULL;
    new->right = NULL;
    return new;
}

// Insert a node (containing a word) into the BSTree and return the 
// root of the updated BSTree.
InvertedIndexBST insertNode(InvertedIndexBST t, char *word) {
    // Base case
    if (t == NULL)
        return newNode(word);
        
    else if (strcmp(word, t->word) < 0)
        t->left = insertNode(t->left, word);
    else if (strcmp(word, t->word) > 0)
        t->right = insertNode(t->right, word);
    else // word must be the same word as t->word
        /* we shouldn't insert duplicates into the tree */;
    return t; 
}    

// Given a word, locates the word on the tree and returns a pointer to it. 
InvertedIndexBST findNode(InvertedIndexBST t, char *word) {
    // Base case: The root contains the word or the root is null
    if (strcmp(word, t->word) == 0) 
        return t; 
        
    // Word comes alphabetically before the node
    if (strcmp(word, t->word) < 0)
        return findNode(t->left, word);
        
    // Word comes alphabetically after the node
    return findNode(t->right, word);
}
