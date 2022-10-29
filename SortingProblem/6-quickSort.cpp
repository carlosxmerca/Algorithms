#include <iostream>
#include <cmath>
using namespace std;

int partition(int *A, int p, int r);
void quicksort(int *A, int p, int r);

void swap(int *A, int i, int j);
void printArray(int *A, int n);

int main()
{
    cout << "Quick sort\n";
    
    int A[] = {8, 6, 5, 7, 3};
    int n = sizeof(A) / sizeof(A[0]);
    
    cout << "Arreglo original:\n";
    printArray(A, n);
    
    quicksort(A, 0, n-1);
    cout << "Arreglo ordenado:\n";
    printArray(A, n);

    return 0;
}

int partition(int *A, int p, int r) {
    int pivot = A[r];
    // Siempre empieza antes que p
    int tracker = p - 1;

    for(int j = p; j < r; j++)
        if (A[j] <= pivot) {
            tracker++;
            swap(A, j, tracker);
        }

    // Intercambiar el pivote
    tracker++;
    swap(A, r, tracker);
    return tracker; // Valor de q
}

void quicksort(int *A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        // En las llamadas recursivas no se envia q
        // Xq q ya esta ordenado
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}

// Aux functions
void swap(int *A, int i, int j) {
    if (i != j) {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }
}

void printArray(int *A, int n) {
    cout << "[";
    for(int i = 0; i < n; i++)
        cout << " " << A[i] << " ";
    cout << "]\n";
}