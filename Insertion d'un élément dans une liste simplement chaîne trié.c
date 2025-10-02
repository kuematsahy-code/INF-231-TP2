/**
 * @file bloc2_insertion_triee_simple.c
 * @brief Insertion d'un élément dans une liste simplement chaînée triée.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* creerNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void afficherListe(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/**
 * @brief Insère un nœud dans une liste simplement chaînée triée (ordre croissant).
 * @param head_ref Pointeur vers le pointeur de tête de la liste.
 * @param new_node Le nouveau nœud à insérer.
 */
void insertionTrieeSimple(Node** head_ref, Node* new_node) {
    // Cas 1 : La liste est vide ou le nouvel élément est plus petit que la tête.
    // Le nouveau nœud devient la nouvelle tête.
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        // Cas 2 : Parcourir la liste pour trouver le bon emplacement.
        // On s'arrête lorsque le nœud suivant est plus grand que le nouveau nœud.
        Node* current = *head_ref;
        while (current->next != NULL && current->next->data < new_node->data) {
            current = current->next;
        }
        // Insérer le nouveau nœud entre 'current' et 'current->next'
        new_node->next = current->next;
        current->next = new_node;
    }
}

int main() {
    printf("--- Bloc 2: Insertion dans une liste simple triée ---\n");
    Node* head = NULL;
    
    printf("Insertion de 20...\n");
    insertionTrieeSimple(&head, creerNode(20));
    afficherListe(head);

    printf("Insertion de 10 (au début)...\n");
    insertionTrieeSimple(&head, creerNode(10));
    afficherListe(head);
    
    printf("Insertion de 30 (à la fin)...\n");
    insertionTrieeSimple(&head, creerNode(30));
    afficherListe(head);
    
    printf("Insertion de 15 (au milieu)...\n");
    insertionTrieeSimple(&head, creerNode(15));
    afficherListe(head);
    
    printf("Liste triée finale : ");
    afficherListe(head);
    
    return 0;
}