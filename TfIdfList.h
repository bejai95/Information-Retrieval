// Assignment 1 20T3 COMP2521: Information Retrieval
// This program was written by Bejai Cobbing (z5313120)

// TfIdfList.h
// Header file for TfIdfList.c 

#ifndef _TFIDFLIST_GUARD
#define _TFIDFLIST_GUARD

// Creates a new node containing the file name, returns a pointer to it
TfIdfList new_TfIdfList_node(char *filename, double tfIdfSum);

// Inserts a new node (containing a file name) into the TfIdfList,
// needs to be in descending order of tf-idf value. Returns the head 
// of the updated list
TfIdfList insert_TfIdfList_node(TfIdfList L, char *filename, double tfIdfSum);

// Helper function. Finds the location in the linked list where the node should
// be inserted. Returns a pointer to the node that comes before
// where the node should be inserted
TfIdfList find_node(TfIdfList L, char *filename, double tfIdfSum);

#endif


