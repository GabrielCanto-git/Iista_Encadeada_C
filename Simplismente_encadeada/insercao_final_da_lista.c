#include <stdio.h>
#include <stdlib.h>

void inserirFim(Node** head, int valor) {
 Node* novo = (Node*)malloc(sizeof(Node)); // Cria um novo nó
 novo->data = valor; // Define o valor do nó
 novo->next = NULL; // O último nó sempre aponta para NULL
 // Se a lista estiver vazia, o novo nó vira o primeiro
 if (*head == NULL) {
 *head = novo;
 return;
 }
 Node* temp = *head; // Cria um ponteiro auxiliar para percorrer a lista
 while (temp->next != NULL) // Percorre até o último nó
 temp = temp->next;
 temp->next = novo; // Faz o último nó apontar para o novo nó
}