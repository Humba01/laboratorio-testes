#include <stdio.h>

#define MAX_SIZE 10 // Tamanho máximo da pilha

int stack[MAX_SIZE]; // Array que representa a pilha
int top = -1;        // Índice do topo da pilha

// Função para verificar se a pilha está vazia
int isEmpty()
{
  return (top == -1);
}

// Função para verificar se a pilha está cheia
int isFull()
{
  return (top == MAX_SIZE - 1);
}

// Função para adicionar um elemento à pilha
void push(int value)
{
  if (isFull())
  {
    printf("Erro: Pilha cheia\n");
  }
  else
  {
    top++;
    stack[top] = value;
    printf("Elemento %d adicionado à pilha\n", value);
  }
}

// Função para remover um elemento da pilha
int pop()
{
  if (isEmpty())
  {
    printf("Erro: Pilha vazia\n");
    return -1;
  }
  else
  {
    int value = stack[top];
    top--;
    return value;
  }
}

int main()
{
  // Exemplo de uso da pilha
  push(1);
  push(2);
  push(3);

  printf("Elemento removido: %d\n", pop());
  printf("Elemento removido: %d\n", pop());
  printf("Elemento removido: %d\n", pop());

  return 0;
}