/**
 * @file bloc3_insertion_triee_double.c
 * @brief Insertion d'un élément dans une liste doublement chaînée triée.
 */

#include <stdio.h>
#include <stdlib.h>

// Structure d'un nœud de la liste double
typedef struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
} DNode;

DNode* creerDNode(int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    if (!newNode) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void afficherListeDouble(DNode* head) {
    DNode* temp = head;
    printf("NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/**
 * @brief Insère un nœud dans une liste doublement chaînée triée (ordre croissant).
 * @param head_ref Pointeur vers le pointeur de tête de la liste.
 * @param new_node Le nouveau nœud à insérer.
 */
void insertionTrieeDouble(DNode** head_ref, DNode* new_node) {
    // Cas 1 : La liste est vide ou insertion en tête.
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) {
        new_node->next = *head_ref;
        if (*head_ref != NULL) {
            (*head_ref)->prev = new_node; // Lier l'ancienne tête au nouveau nœud
        }
        *head_ref = new_node;
    } else {
        // Cas 2 : Parcourir la liste pour trouver l'emplacement.
        DNode* current = *head_ref;
        while (current->next != NULL && current->next->data < new_node->data) {
            current = current->next;
        }
        
        // Insertion du nouveau nœud après 'current'
        new_node->next = current->next;
        if (current->next != NULL) {
            current->next->prev = new_node; // Lier le nœud suivant au nouveau
        }
        current->next = new_node;
        new_node->prev = current; // Lier le nouveau nœud au précédent
    }
}

int main() {
    printf("--- Bloc 3: Insertion dans une liste double triée ---\n");
    DNode* head = NULL;
    
    insertionTrieeDouble(&head, creerDNode(20));
    insertionTrieeDouble(&head, creerDNode(10));
    insertionTrieeDouble(&head, creerDNode(30));
    insertionTrieeDouble(&head, creerDNode(25));
    
    printf("Liste doublement chaînée triée finale : ");
    afficherListeDouble(head);

    return 0;
}