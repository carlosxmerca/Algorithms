#include <iostream>
using namespace std;

void selectionSort(int *nums, int n);
void printArray(int *nums, int n);

int main()
{
    cout << "Selection sort\n";
    
    int nums[] = {8, 6, 5, 7, 3};
    int n = sizeof(nums) / sizeof(nums[0]);
    
    cout << "Arreglo original:\n";
    printArray(nums, n);
    
    selectionSort(nums, n);
    cout << "Arreglo ordenado:\n";
    printArray(nums, n);

    return 0;
}

void selectionSort(int *nums, int n){
    int j, i, min, tmp;
    // Ends before the last position
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++) {
            if (nums[j] < nums[min])
                min = j;
        }

        // If positions change 
        // then exchange values
        if (min != i) {
            tmp = nums[min];
            nums[min] = nums[i];
            nums[i] = tmp;
        }
    }
}

void printArray(int *nums, int n) {
    cout << "[";
    for(int i = 0; i < n; i++)
        cout << " " << nums[i] << " ";
    cout << "]\n";
}