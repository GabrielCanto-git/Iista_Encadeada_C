#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
 int data; 
 struct Node* next; 
} Node;

void inserirInicio(Node** head, int valor) {
Node* novo = (Node*)malloc(sizeof(Node)); 
 novo->data = valor; 
 novo->next = *head; 
 *head = novo; 
}

void inserirFim(Node** head, int valor) {
 Node* novo = (Node*)malloc(sizeof(Node)); 
 novo->data = valor; 
 novo->next = NULL; 
 
 if (*head == NULL) {
 *head = novo;
 return;
 }
 Node* temp = *head; 
 while (temp->next != NULL) 
 temp = temp->next;
 temp->next = novo; 
}

void removerValor(Node** head, int valor) {
 Node* temp = *head; 
 Node* anterior = NULL; 

 while (temp != NULL && temp->data != valor) {
 anterior = temp; 
 temp = temp->next; 
 }
 if (temp == NULL) return; 

 if (anterior == NULL)
 *head = temp->next; 
 else
 anterior->next = temp->next; 

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
 while (temp != NULL) { 
 printf("%d -> ", temp->data); 
 temp = temp->next; 
 }
 printf("NULL\n");
}


int main() {
 Node* head = NULL; 
 inserirInicio(&head, 10);
 inserirInicio(&head, 20);
 inserirFim(&head, 30);
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
