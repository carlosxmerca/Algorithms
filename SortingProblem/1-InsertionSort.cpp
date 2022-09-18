#include <iostream>
using namespace std;

void insertionSort(int *nums, int n);
void printArray(int *nums, int n);

int main()
{
    cout << "Insertion sort\n";
    
    int nums[] = {8, 6, 5, 7, 3};
    int n = sizeof(nums) / sizeof(nums[0]);
    
    cout << "Arreglo original:\n";
    printArray(nums, n);
    
    insertionSort(nums, n);
    cout << "Arreglo ordenado:\n";
    printArray(nums, n);

    return 0;
}

void insertionSort(int *nums, int n){
    int j, i, key;
    // Starts in the second position
    for (j = 1; j < n; j++) {
        key = nums[j];
        i = j - 1;
        // backtracking
        while(i > -1 && nums[i] > key) {
            nums[i + 1] = nums[i];
            i--;
        }
        nums[i + 1] = key;
    }
}

void printArray(int *nums, int n) {
    cout << "[";
    for(int i = 0; i < n; i++)
        cout << " " << nums[i] << " ";
    cout << "]\n";
}