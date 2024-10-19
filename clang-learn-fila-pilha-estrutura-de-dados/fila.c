#include <stdio.h>

#define MAX_SIZE 10 // tamanho máximo da fila

int queue[MAX_SIZE];
int front = -1; // índice da frente da fila
int rear = -1;  // índice do fim da fila

// Função para verificar se a fila está vazia
int isEmpty()
{
  if (front == -1 && rear == -1)
  {
    return 1; // fila vazia
  }
  else
  {
    return 0; // fila não vazia
  }
}

// Função para verificar se a fila está cheia
int isFull()
{
  if ((rear + 1) % MAX_SIZE == front)
  {
    return 1; // fila cheia
  }
  else
  {
    return 0; // fila não cheia
  }
}

// Função para adicionar um elemento à fila
void enqueue(int data)
{
  if (isFull())
  {
    printf("Erro: fila cheia\n");
    return;
  }
  else if (isEmpty())
  {
    front = rear = 0;
  }
  else
  {
    rear = (rear + 1) % MAX_SIZE;
  }
  queue[rear] = data;
}

// Função para remover o elemento da frente da fila
void dequeue()
{
  if (isEmpty())
  {
    printf("Erro: fila vazia\n");
    return;
  }
  else if (front == rear)
  {
    front = rear = -1;
  }
  else
  {
    front = (front + 1) % MAX_SIZE;
  }
}

// Função para exibir o conteúdo da fila
void display()
{
  if (isEmpty())
  {
    printf("Fila vazia\n");
    return;
  }
  printf("Conteúdo da fila: ");
  int i = front;
  while (i != rear)
  {
    printf("%d ", queue[i]);
    i = (i + 1) % MAX_SIZE;
  }
  printf("%d\n", queue[rear]);
}

int main()
{
  // Exemplo de uso da fila
  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);
  display(); // Saída esperada: Conteúdo da fila: 1 2 3 4
  dequeue();
  display(); // Saída esperada: Conteúdo da fila: 2 3 4
  return 0;
}