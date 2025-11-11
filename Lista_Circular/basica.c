#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
 int data; 
 struct Node* next; 
} Node;


void inserirInicio(Node** head, int valor) {
 Node* novo = (Node*)malloc(sizeof(Node)); 
 novo->data = valor; 
 
 if (*head == NULL) {
 novo->next = novo; 
 *head = novo; 
 return;
 }

 Node* temp = *head;
 while (temp->next != *head) 
 temp = temp->next;
 novo->next = *head; 
 temp->next = novo; 
 *head = novo; 
}

void inserirFim(Node** head, int valor) {
 Node* novo = (Node*)malloc(sizeof(Node)); 
 novo->data = valor; 

 if (*head == NULL) {
 novo->next = novo; 
 *head = novo; 
 return;
 }
 Node* temp = *head;
 while (temp->next != *head) 
 temp = temp->next;
 temp->next = novo; 
 novo->next = *head; 
}


void removerValor(Node** head, int valor) {
 
 if (*head == NULL) return;
 Node* temp = *head;
 Node* anterior = NULL;

 if (temp->data == valor) {
 
 if (temp->next == *head) {
 free(temp);
 *head = NULL; 
 return;
 }

 Node* ultimo = *head;
 while (ultimo->next != *head) 
 ultimo = ultimo->next;
 ultimo->next = temp->next; 
 *head = temp->next; 
 free(temp); 
 return;
 }
 
 do {
 anterior = temp;
 temp = temp->next;
 } while (temp != *head && temp->data != valor);

 if (temp == *head) return;

 anterior->next = temp->next;
 free(temp);
}

Node* buscar(Node* head, int valor) {
 if (head == NULL) return NULL; 
 Node* temp = head;
 do {
 if (temp->data == valor) 
 return temp;
 temp = temp->next;
 } while (temp != head); 
 return NULL; 
}


void imprimir(Node* head) {
 if (head == NULL) {
 printf("Lista vazia.\n");
 return;
 }
 Node* temp = head;
 printf("Lista circular: ");
 do {
 printf("%d -> ", temp->data); 
 temp = temp->next;
 } while (temp != head); 
 printf("(volta ao início)\n");
}

int main() {
 Node* head = NULL; 
 inserirInicio(&head, 10);
 inserirInicio(&head, 20);
 inserirFim(&head, 30);
 inserirFim(&head, 40);
 imprimir(head); 
 removerValor(&head, 10);
 imprimir(head); 
 Node* achado = buscar(head, 30);
 if (achado != NULL)
 printf("Valor %d encontrado!\n", achado->data);
 else
 printf("Valor não encontrado.\n");
 return 0;
}