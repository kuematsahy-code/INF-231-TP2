/**
 * @file bloc1_supprimer_occurrences.c
 * @brief Supprime toutes les occurrences d'un élément dans une liste simplement chaînée.
 * @author VotreNom
 * @version 1.0
 * @date 2025-10-02
 *
 * Ce programme démontre comment parcourir une liste chaînée et supprimer
 * tous les nœuds contenant une valeur spécifique.
 */

#include <stdio.h>
#include <stdlib.h>

// Structure d'un nœud de la liste
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour créer un nouveau nœud (utilitaire)
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

// Fonction pour afficher la liste (utilitaire)
void afficherListe(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/**
 * @brief Supprime toutes les occurrences d'une valeur (key) dans une liste.
 * @param head_ref Un pointeur vers le pointeur de tête de la liste.
 *                  Permet de modifier la tête de la liste si nécessaire.
 * @param key La valeur entière à supprimer.
 */
void supprimerToutesOccurrences(Node** head_ref, int key) {
    Node* temp = *head_ref;
    Node* prev = NULL;

    // 1. Gérer les cas où la clé se trouve en tête de liste
    while (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // La nouvelle tête devient le nœud suivant
        free(temp);             // Libérer l'ancienne tête
        temp = *head_ref;       // Mettre à jour le pointeur de parcours
    }

    // 2. Parcourir le reste de la liste
    while (temp != NULL) {
        // Avancer jusqu'à trouver la prochaine occurrence de la clé
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        // Si la fin de la liste est atteinte, il n'y a plus rien à faire
        if (temp == NULL) {
            return;
        }

        // 'temp' pointe maintenant sur un nœud à supprimer.
        // On le détache de la liste en reliant le nœud précédent au suivant.
        prev->next = temp->next;
        free(temp); // Libérer la mémoire du nœud supprimé

        // Continuer la recherche à partir du nœud suivant celui qui a été supprimé
        temp = prev->next;
    }
}

// Programme principal pour tester la fonctionnalité
int main() {
    printf("--- Bloc 1: Suppression de toutes les occurrences ---\n");
    
    // Création d'une liste de test : 2 -> 5 -> 2 -> 8 -> 2 -> 9
    Node* head = creerNode(2);
    head->next = creerNode(5);
    head->next->next = creerNode(2);
    head->next->next->next = creerNode(8);
    head->next->next->next->next = creerNode(2);
    head->next->next->next->next->next = creerNode(9);

    printf("Liste originale : ");
    afficherListe(head);

    int element_a_supprimer = 2;
    printf("Suppression de toutes les occurrences de %d...\n", element_a_supprimer);
    supprimerToutesOccurrences(&head, element_a_supprimer);

    printf("Liste après suppression : ");
    afficherListe(head);

    return 0;
}