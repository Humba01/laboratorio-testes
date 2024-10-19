#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Escolhe o último elemento como pivô
    int i = (low - 1);      // Índice do menor elemento

    for (int j = low; j < high; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivot) {
            i++;  // Incrementa o índice do menor elemento
            swap(&arr[i], &arr[j]);  // Troca os elementos
        }
    }
    swap(&arr[i + 1], &arr[high]);  // Coloca o pivô na posição correta
    return (i + 1);  // Retorna a posição do pivô
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Obtém a posição do pivô
        int pi = partition(arr, low, high);

        // Ordena os elementos antes e depois do pivô
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, n - 1);

    printf("Array ordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
