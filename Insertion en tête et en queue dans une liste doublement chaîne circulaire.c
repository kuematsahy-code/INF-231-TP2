/**
 * @file bloc5_insertion_circulaire_double.c
 * @brief Insertion en tête et en queue dans une liste doublement chaînée circulaire.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
} DNode;

DNode* creerDNode(int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    if (!newNode) exit(EXIT_FAILURE);
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void afficherListeCirculaireDouble(DNode* head) {
    if (head == NULL) {
        printf("Liste vide\n");
        return;
    }
    DNode* temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(retour à la tête: %d)\n", head->data);
}

/**
 * @brief Insère un élément en tête d'une liste circulaire double.
 * @param head_ref Pointeur vers le pointeur de tête.
 * @param data La valeur à insérer.
 */
void insertionTeteCirculaireDouble(DNode** head_ref, int data) {
    DNode* new_node = creerDNode(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    } else {
        DNode* last = (*head_ref)->prev; // Le dernier nœud est le précédent de la tête

        new_node->next = *head_ref;
        (*head_ref)->prev = new_node;

        new_node->prev = last;
        last->next = new_node;

        *head_ref = new_node; // La tête est mise à jour
    }
}

/**
 * @brief Insère un élément en queue d'une liste circulaire double.
 * @param head_ref Pointeur vers le pointeur de tête.
 * @param data La valeur à insérer.
 */
void insertionQueueCirculaireDouble(DNode** head_ref, int data) {
    DNode* new_node = creerDNode(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    } else {
        DNode* last = (*head_ref)->prev; // Le dernier nœud

        new_node->next = *head_ref;
        (*head_ref)->prev = new_node;

        new_node->prev = last;
        last->next = new_node;
        
        // Contrairement à l'insertion en tête, le pointeur head n'est pas modifié.
    }
}

int main() {
    printf("--- Bloc 5: Insertion dans une liste circulaire double ---\n");
    DNode* head = NULL;

    insertionTeteCirculaireDouble(&head, 10);
    printf("Après insertion 10 en tête : ");
    afficherListeCirculaireDouble(head);

    insertionTeteCirculaireDouble(&head, 5);
    printf("Après insertion 5 en tête  : ");
    afficherListeCirculaireDouble(head);

    insertionQueueCirculaireDouble(&head, 20);
    printf("Après insertion 20 en queue: ");
    afficherListeCirculaireDouble(head);

    return 0;
}