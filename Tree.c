/* Auteur: Wisdom MUONAKA */

/* Tree.c */
#include "Tree.h"


Node* createNode(int symbol) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Erreur allocation noeud");
        exit(1);
    }
    newNode->symbol = symbol;
    newNode->children = NULL;
    newNode->nbChildren = 0;
    return newNode;
}

void addFirstChild(Node *parent, Node *child) {
    // 1. On agrandit le tableau de fils (+1 place)
    parent->nbChildren++;
    parent->children = (Node**)realloc(parent->children, parent->nbChildren * sizeof(Node*));
    if (parent->children == NULL) exit(1);

    // 2. On décale tout le monde vers la droite pour libérer la place 0
    // (Car on veut ajouter au début)
    for (int i = parent->nbChildren - 1; i > 0; i--) {
        parent->children[i] = parent->children[i-1];
    }

    // 3. On met le nouveau fils en position 0
    parent->children[0] = child;
}

void printTree(Node *root) {
    if (root == NULL) return;

    // Affiche le père
    if (root->symbol > 0) printf("%c", root->symbol);
    else printf("Rule"); // ou gestion des non-terminaux

    // Affiche les fils entre parenthèses
    printf("(");
    for (int i = 0; i < root->nbChildren; i++) {
        printTree(root->children[i]);
    }
    printf(")");
}