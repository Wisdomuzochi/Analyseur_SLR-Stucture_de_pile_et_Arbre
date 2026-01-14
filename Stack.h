/* Auteur: Wisdom MUONAKA */

/* Stack.h */
#ifndef STACK_H
#define STACK_H

#include "Tree.h" //  pour que Stack connaisse 'Node'
#include "Tree.h" //  pour que Stack connaisse 'Node'

// DÉFINITION DES STRUCTURES

typedef struct StackElement {
    int state;                  // État
    Node *node;                 // Arbre associé
    struct StackElement *next;  // Maillon suivant
} StackElement;

typedef struct Stack {
    StackElement *top;          // Pointeur vers le sommet
} Stack;

// PROTOTYPES DES FONCTIONS

Stack* initStack();
void push(Stack *s, int state, Node *node);
StackElement* pop(Stack *s);
int peekState(Stack *s);
void print_stack_trace(Stack *s);

#endif