#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
struct Node {
    int value;               // Valor do nó
    struct Node* next;      // Ponteiro para o próximo nó
};

// Função para criar um novo nó
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        return NULL;
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um novo nó no início da lista
struct Node* insertNode(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (newNode == NULL) {
        return head;
    }
    newNode->next = head;
    return newNode;
}

// Função para imprimir os elementos da lista
void printList(struct Node* head) {
    printf("Lista Encadeada: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// Função para liberar a memória alocada pela lista
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    // Criação da lista vazia
    struct Node* head = NULL;

    // Inserção de elementos na lista
    head = insertNode(head, 3);
    head = insertNode(head, 5);
    head = insertNode(head, 7);
    head = insertNode(head, 9);

    // Impressão dos elementos da lista
    printList(head);

    // Liberação da memória alocada pela lista
    freeList(head);

    return 0;
}
