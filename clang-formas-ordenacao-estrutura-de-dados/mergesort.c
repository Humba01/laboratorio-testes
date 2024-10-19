// Função auxiliar para mesclar dois subvetores ordenados
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Cria vetores temporários para armazenar os elementos dos subvetores
    int L[n1], R[n2];

    // Copia os elementos para os vetores temporários
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Mescla os vetores temporários de volta ao vetor original
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal de mergesort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Encontra o ponto médio para dividir o vetor em subvetores
        int m = l + (r - l) / 2;

        // Ordena recursivamente os subvetores
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Mescla os subvetores ordenados para obter o vetor final ordenado
        merge(arr, l, m, r);
    }
}


int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor original: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("\nVetor ordenado: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
