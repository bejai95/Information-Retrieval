// Assignment 1 20T3 COMP2521: Information Retrieval
// This program was written by Bejai Cobbing (z5313120)

// invertedIndexBST.h
// Header file for InvertedIndexBST.c

#ifndef _INVERTEDINDEXBST_GUARD
#define _INVERTEDINDEXBST_GUARD

// Creates a new InvertedIndexBST node containing the given word
// Returns a pointer to the new node
InvertedIndexBST newNode(char *word);

// Inserts an InvertedIndexBST node (containing a word) into the BSTree
// and returns a pointer to the updated BSTree. Inserts in ascending 
// alphabetical order
InvertedIndexBST insertNode(InvertedIndexBST t, char *word);

// Given a word, locates the word on the tree and returns a pointer to it. 
// If the word is not in a node contained by the tree, return NULL.
InvertedIndexBST findNode(InvertedIndexBST t, char *word);

#endif
