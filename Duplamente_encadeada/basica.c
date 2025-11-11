#include <stdio.h>
#include <stdlib.h>
// Estrutura básica do nó da lista duplamente encadeada
typedef struct Node {
 int data; // Valor armazenado no nó
 struct Node* next; // Ponteiro para o próximo nó
 struct Node* prev; // Ponteiro para o nó anterior
} Node;

void inserirInicio(Node** head, int valor) {
 Node* novo = (Node*)malloc(sizeof(Node)); 
 novo->data = valor; 
 novo->next = *head; 

 novo->prev = NULL; 
 
 if (*head != NULL)
 (*head)->prev = novo;
 *head = novo; 
}

void inserirFim(Node** head, int valor) {
 Node* novo = (Node*)malloc(sizeof(Node));
 novo->data = valor; 
 novo->next = NULL; 
 
 if (*head == NULL) {
 novo->prev = NULL;
 *head = novo;
 return;
 }
 Node* temp = *head; 
 while (temp->next != NULL) 
 temp = temp->next;
 temp->next = novo; 
 novo->prev = temp; 
}

void removerValor(Node** head, int valor) {
 Node* temp = *head; 
 
 while (temp != NULL && temp->data != valor)
 temp = temp->next;
 if (temp == NULL) return;
 if (temp->prev == NULL)
 *head = temp->next; 
 else
 temp->prev->next = temp->next; 
 
 if (temp->next != NULL)
 temp->next->prev = temp->prev;
 free(temp); 
}

Node* buscar(Node* head, int valor) {
 Node* temp = head; 
 while (temp != NULL) { 
 if (temp->data == valor)
 return temp;
 temp = temp->next;
 }
 return NULL; 
}

void imprimir(Node* head) {
 Node* temp = head; 
 printf("Lista (sentido normal): ");
 while (temp != NULL) {
 printf("%d <-> ", temp->data); 
 temp = temp->next;
 }
 printf("NULL\n");
}

void imprimirReverso(Node* head) {
 Node* temp = head;

 while (temp != NULL && temp->next != NULL)
 temp = temp->next;
 printf("Lista (sentido reverso): ");
 
 while (temp != NULL) {
 printf("%d <-> ", temp->data);
 temp = temp->prev;
 }
 printf("NULL\n");
}