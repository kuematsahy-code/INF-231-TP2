/**
 * @file bloc4_insertion_circulaire_simple.c
 * @brief Insertion en tête et en queue dans une liste simplement chaînée circulaire.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* creerNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) exit(EXIT_FAILURE);
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void afficherListeCirculaire(Node* head) {
    if (head == NULL) {
        printf("Liste vide\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(retour à la tête: %d)\n", head->data);
}

/**
 * @brief Insère un élément en tête d'une liste circulaire simple.
 * @param head_ref Pointeur vers le pointeur de tête.
 * @param data La valeur à insérer.
 */
void insertionTeteCirculaire(Node** head_ref, int data) {
    Node* new_node = creerNode(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = *head_ref; // Boucle sur lui-même
    } else {
        Node* last = *head_ref;
        while (last->next != *head_ref) { // Trouver le dernier nœud
            last = last->next;
        }
        new_node->next = *head_ref;
        last->next = new_node;
        *head_ref = new_node; // La nouvelle tête est le nouveau nœud
    }
}

/**
 * @brief Insère un élément en queue d'une liste circulaire simple.
 * @param head_ref Pointeur vers le pointeur de tête.
 * @param data La valeur à insérer.
 */
void insertionQueueCirculaire(Node** head_ref, int data) {
    // Une insertion en queue est une insertion en tête
    // sans changer le pointeur de tête final.
    insertionTeteCirculaire(head_ref, data);
    
    // Pour que ce soit une vraie insertion en queue, la tête doit rester la même.
    // On fait donc avancer le pointeur de tête pour qu'il pointe sur l'ancienne tête.
    if (*head_ref != NULL && (*head_ref)->next != *head_ref) {
        *head_ref = (*head_ref)->next;
    }
}

int main() {
    printf("--- Bloc 4: Insertion dans une liste circulaire simple ---\n");
    Node* head = NULL;
    
    insertionTeteCirculaire(&head, 10);
    printf("Après insertion 10 en tête : ");
    afficherListeCirculaire(head);

    insertionTeteCirculaire(&head, 5);
    printf("Après insertion 5 en tête  : ");
    afficherListeCirculaire(head);
    
    insertionQueueCirculaire(&head, 20);
    printf("Après insertion 20 en queue: ");
    afficherListeCirculaire(head);

    return 0;
}