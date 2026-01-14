/* Auteur: Wisdom MUONAKA */

/* Tree.h */
#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>

// DÉFINITION DE LA STRUCTURE NODE 
typedef struct Node {
    int symbol;             // Code ASCII ou identifiant
    struct Node **children; // Tableau dynamique de fils
    int nbChildren;         // Nombre de fils
} Node;

// Prototypes des fonctions
Node* createNode(int symbol);
void addFirstChild(Node *parent, Node *child);
void printTree(Node *root);
void freeTree(Node *root);

#endif