// Assignment 1 20T3 COMP2521: Information Retrieval
// This program was written by Bejai Cobbing (z5313120)

// FileList.c
// This file contains functions relating to the FileList ADT

// This file has been adapted from InvertedIndexBST.c which was originally 
// adapted from  the week 3 tutorial and the week 3 lab: Binary Search Trees, 
// which can be accessed at 
// https://webcms3.cse.unsw.edu.au/COMP2521/20T3/resources/52974

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "invertedIndex.h"
#include "FileList.h"

// Create a new node containing the file name, return a pointer to it
FileList new_file_node(char *filename, char *word) {
    FileList new = malloc(sizeof(struct FileListNode));
    assert (new != NULL);
    
    // Malloc the file name string and then copy it across
    new->filename = malloc((strlen(filename) + 1) * sizeof(char));
    strcpy(new->filename, filename);
    
    // Calculate the relative term frequency of the word within the file
    int num_words_in_file = 0;
    int num_matches_in_file = 0; 
    char word_in_file[MAX_WORD_LENGTH]; 
    FILE *file_pntr = fopen(filename, "r"); 
    while (fscanf(file_pntr, "%s", word_in_file) == 1) {
        // Normalise the word
        strcpy(word_in_file, normaliseWord(word_in_file));
        if (strcmp(word_in_file, word) == 0)
            num_matches_in_file ++; 
        num_words_in_file ++;
    }
    fclose(file_pntr);

    new->tf = (num_matches_in_file * 1.0) / num_words_in_file;
    new->next = NULL;
    return new;
}

// Insert a node into the FileList, return the head of the updated list
FileList insertFileNode(FileList L, char* filename, char *word) {
    // If the list is empty then return a new list containing the node
    if (L == NULL) 
        return new_file_node(filename, word);
        
    // Find where in the linked list the new node should be inserted
    FileList curr = L; 
    FileList prev = NULL; 
    while (curr != NULL && strcmp(filename, curr->filename) >= 0) {
        if (strcmp(filename, curr->filename) == 0) {
            // Duplicate file names should not be added to the linked list
            return L;
        }
        prev = curr;
        curr = curr->next;
    } // prev is now pointing to the node we should insert after
    
    FileList new = new_file_node(filename, word);
        
    if (prev == NULL) { // Need to insert at the beginning of the linked list
        new->next = L;
        return new; 
    }
    if (curr == NULL) // Need to insert at the end of the linked list
        prev->next = new; 
    else { // Inserting in the middle
        new->next = curr;
        prev->next = new;
    }
    return L;
}
