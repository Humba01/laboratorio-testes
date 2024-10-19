#include <stdio.h>
#include <stdlib.h>

// Definição de estrutura do nó
struct Node {
    int data;               // Dados do nó
    struct Node* next;     // Ponteiro para o próximo nó
    struct Node* prev;     // Ponteiro para o nó anterior
};

// Função para criar um novo nó
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// Função para inserir um novo nó no início da lista
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Função para inserir um novo nó no final da lista
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Função para exibir a lista
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Lista: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Função principal
int main() {
    struct Node* head = NULL;   // Cabeça da lista
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    displayList(head);   // Exibir a lista: 1 2 3 4 5
    return 0;
}
