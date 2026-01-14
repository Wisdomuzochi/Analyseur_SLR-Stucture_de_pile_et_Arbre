/* Auteur: Wisdom MUONAKA */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Inclusion de nos modules  */
#include "read_file.h"
#include "Stack.h"
#include "Tree.h"



int main(int argc, char *argv[]) {
    //  VÉRIFICATIONS
    if (argc != 3) {
        printf("Usage incorrect.\n");
        printf("Exemple : %s test2 \"(())\"\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *input_string = argv[2];

    //  CHARGEMENT
    file_read data = read_file(filename);
    grammar G = data.G;
    table T = data.t;

    //  INITIALISATION
    Stack *pile = initStack();
    push(pile, 0, NULL); 
    
    int cursor = 0;
    int safety_counter = 0;
    const int MAX_ITERATIONS = 5000; 

    //  En-tête du tableau
    printf("Flot | Pile\n");
    printf("__________________________________\n");

    //  BOUCLE PRINCIPALE
    while (1) {
        if (safety_counter > MAX_ITERATIONS) {
            printf("\n!!! ARRET D'URGENCE !!!\n");
            return 1;
        }
        safety_counter++;

        //  AFFICHER LA TRACE (AVANT L'ACTION) 
        //  Le Flot (ce qu'il reste à lire)
        printf("%s", input_string + cursor);
        
        //  Le séparateur
        printf(" | ");
        
        //  La Pile (grâce à la fonction ajoutée au début)
        print_stack_trace(pile);
        
        //  Retour à la ligne pour afficher l'action en dessous (d3, r2...)
        printf("\n");

        // ÉTAPE A : Où suis-je ?
        int current_state = peekState(pile);

        // ÉTAPE B : Que lis-je ?
        unsigned char current_char_index;
        if (input_string[cursor] == '\0') {
            current_char_index = 0; 
        } else {
            current_char_index = (unsigned char)input_string[cursor];
        }

        // ÉTAPE C : Action ?
        int action = T.trans[256 * current_state + current_char_index];

        // CAS 1 : ERREUR
        if (action == 0) {
            printf("REJET (Erreur de syntaxe)\n"); 
            return 1;
        }

        // CAS 2 : ACCEPT
        else if (action == -127) {
            printf("accept\n"); // On affiche l'action finale
            
            // Affichage de l'arbre final  
            if (pile->top != NULL && pile->top->node != NULL) {
                printTree(pile->top->node); 
                printf("\n");
            }
            break; 
        }

        // CAS 3 : SHIFT
        else if (action > 0) {
            //  Afficher l'action shift 
            printf("d%d\n", action);

            int new_state = action;
            Node *leaf = createNode(input_string[cursor]); 
            push(pile, new_state, leaf);
            
            if (input_string[cursor] != '\0') {
                cursor++;
            }
        }

        // CAS 4 : REDUCE
        else {
            int rule_index = (-action) - 1;
            
            //  Afficher l'action reduce 
            // On met +1 car souvent les règles sont numérotées 1,2,3 à l'affichage
            printf("r%d\n", rule_index + 1); 

            char lhs_symbol = G.rules[rule_index].lhs;
            int rhs_len = strlen((char*)G.rules[rule_index].rhs);

            Node *parentNode = createNode(lhs_symbol);

            for (int i = 0; i < rhs_len; i++) {
                StackElement *popped = pop(pile); 
                addFirstChild(parentNode, popped->node);
                free(popped); 
            }

            int state_after_pop = peekState(pile);
            unsigned char goto_index = (unsigned char)(-lhs_symbol);
            int goto_state = T.trans[256 * state_after_pop + goto_index];
            
            if (goto_state == 0) {
                 printf("Erreur GOTO\n");
                 return 1;
            }

            push(pile, goto_state, parentNode);
        }
    }

    return 0;
}