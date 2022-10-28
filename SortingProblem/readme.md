## SortingProblem

#### General

```c++
int A[] = {8, 6, 5, 7, 3};
int n = sizeof(A) / sizeof(A[0]);

void swap(int *A, int i, int j) {
    if (i != j) {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }
}
```

### MergeSort

```c++
void mergeSort(int *A, int p, int r){
    if (p < r) {
        int q = floor((p + r) / 2);
        // Divide left section
        mergeSort(A, p, q);
        // Divide right section
        mergeSort(A, q+1, r);
        merge(A, p, q, r);
    }
}

void merge(int *A, int p, int q, int r){
    int n1 = q - p + 1; 
    int n2 = r - q;
    int L[n1 + 1], R[n2 + 1];
    int i, j, k; 

    // Fill L with left values
    for (i = 0; i < n1; i++)
        L[i] = A[p + i];
    // Fill R with right values
    for (j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    L[n1] = R[n2] = INFINITY;
    i = j = 0;
    // Compare values of L and R
    // then and rewrite original array
    for (k = p; k <= r; k++){
        if (L[i] < R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

mergeSort(A, 0, n-1);
```

### HeapSort

```c++
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

heap_sort(A, n);
```

### QuickSort

```c++
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

quicksort(A, 0, n-1);
```

### Resume

| Algorithm   | Best        | Worst       | Average     |
| ----------- | ----------- | ----------- | ----------- |
| MergeSort   |             | O(n log2(n))|             |
| HeapSort    |             | O(n log2(n))|             |
| QuickSort   | O(n log2(n))| O(n^2)      |             |
