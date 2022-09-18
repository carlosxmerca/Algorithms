#include <iostream>
// #include <climits> INT_MAX
#include <cmath>
using namespace std;

void mergeSort(int *A, int p, int r);
void merge(int *A, int p, int q, int r);
void printArray(int *A, int n);

int main()
{
    cout << "Merge sort\n";
    
    int A[] = {8, 6, 5, 7, 3};
    int n = sizeof(A) / sizeof(A[0]);
    
    cout << "Arreglo original:\n";
    printArray(A, n);
    
    mergeSort(A, 0, n-1);
    cout << "Arreglo ordenado:\n";
    printArray(A, n);

    return 0;
}

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

void printArray(int *A, int n) {
    cout << "[";
    for(int i = 0; i < n; i++)
        cout << " " << A[i] << " ";
    cout << "]\n";
}