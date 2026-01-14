/* Auteur: Wisdom MUONAKA */

/* Stack.c */
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


// FONCTIONS D'AFFICHAGE

// Fonction interne récursive
static void print_elements_recursive(StackElement *el) {
    if (el == NULL) return; // Fond de la pile

    // 1. On descend jusqu'au fond
    print_elements_recursive(el->next);

    // 2. On affiche en remontant
    if (el->node != NULL) {
        if (el->node->symbol > 0) printf("%c", el->node->symbol);
        else printf("%c", -el->node->symbol);
    }
    printf("%d", el->state);
}

// Fonction principale appelée par le main
void print_stack_trace(Stack *s) {
    if (s == NULL || s->top == NULL) return;
    print_elements_recursive(s->top);
}

// FONCTIONS DE MANIPULATION

Stack* initStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    if (!s) { perror("Erreur malloc initStack"); exit(1); }
    s->top = NULL;
    return s;
}

void push(Stack *s, int state, Node *node) {
    StackElement *newElem = (StackElement*)malloc(sizeof(StackElement));
    if (!newElem) { perror("Erreur malloc push"); exit(1); }

    newElem->state = state;
    newElem->node = node;
    newElem->next = s->top;
    s->top = newElem;
}

StackElement* pop(Stack *s) {
    if (s == NULL || s->top == NULL) return NULL;

    StackElement *elem = s->top;
    s->top = elem->next;
    elem->next = NULL;

    return elem;
}

int peekState(Stack *s) {
    if (s == NULL || s->top == NULL) return 0;
    return s->top->state;
}