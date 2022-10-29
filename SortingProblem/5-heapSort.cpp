#include <iostream>
#include <cmath>
using namespace std;

int left(int i);
int right(int i);
void max_heapify(int *A, int i, int heap_size);
void build_max_heap(int *A, int heap_size);
void heap_sort(int *A, int n);

void swap(int *A, int i, int j);
void printArray(int *A, int n);

int main()
{
    cout << "Heap sort\n";
    
    int A[] = {8, 6, 5, 7, 3};
    int n = sizeof(A) / sizeof(A[0]);
    
    cout << "Arreglo original:\n";
    printArray(A, n);
    
    heap_sort(A, n);
    cout << "Arreglo ordenado:\n";
    printArray(A, n);

    return 0;
}

int left(int i) {
    return 2*i + 1;
}

int right(int i) {
    return 2*i + 2;
}

void max_heapify(int *A, int i, int heap_size) {
    int largest = i;
    int l = left(i);
    int r = right(i);

    if (l < heap_size && A[l] > A[i])
        largest = l;
    if (r < heap_size && A[r] > A[largest])
        largest = r;

    if (largest != i) {
        // Intercambiar padre con ganador
        swap(A, i, largest);
        // Parchar monticulos
        max_heapify(A, largest, heap_size);
    }
}

void build_max_heap(int *A, int heap_size) {
    for(int i = floor(heap_size/2)-1; i >= 0; i--)
        max_heapify(A, i, heap_size);
}

void heap_sort(int *A, int n) {
    int heap_size = n;
    build_max_heap(A, heap_size);
    // Recorrido desde la ultima hasta la segunda pos
    for(int i = n-1; i > 0; i--) {
        // Intercambiar primera con ultima pos
        swap(A, 0, i);
        heap_size--;
        // Reordenar heap desde el nuevo padre
        max_heapify(A, 0, heap_size);
    }
}

// Aux functions
void swap(int *A, int i, int j) {
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

void printArray(int *A, int n) {
    cout << "[";
    for(int i = 0; i < n; i++)
        cout << " " << A[i] << " ";
    cout << "]\n";
}
