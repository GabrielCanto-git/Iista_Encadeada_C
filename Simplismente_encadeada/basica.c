#include <stdio.h>
#include <stdlib.h>
// Estrutura básica do nó
typedef struct Node {
 int data; // Armazena o valor (dado) do nó
 struct Node* next; // Ponteiro para o próximo nó da lista
} Node;
//Inserção no início da lista
void inserirInicio(Node** head, int valor) {
Node* novo = (Node*)malloc(sizeof(Node)); // Aloca memória para um novo nó
 novo->data = valor; // Define o valor do novo nó
 novo->next = *head; // Faz o novo nó apontar para o antigo primeiro nó
 *head = novo; // Atualiza o ponteiro da cabeça (head) para o novo nó
}

