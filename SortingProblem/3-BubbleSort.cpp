#include <iostream>
using namespace std;

void bubbleSort(int *nums, int n);
void printArray(int *nums, int n);

int main()
{
    cout << "Bubble sort\n";
    
    int nums[] = {8, 6, 5, 7, 3};
    int n = sizeof(nums) / sizeof(nums[0]);
    
    cout << "Arreglo original:\n";
    printArray(nums, n);
    
    bubbleSort(nums, n);
    cout << "Arreglo ordenado:\n";
    printArray(nums, n);

    return 0;
}

void bubbleSort(int *nums, int n){
    int j, i, tmp;
    // Ends before the last element
    for (i = 0; i < n-1; i++)
        // Starts in the lasth element
        // Ends before i position
        for (j = n-1; j > i; j--)
            if (nums[j] < nums[j - 1]) {
                tmp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = tmp;
            }
}

void printArray(int *nums, int n) {
    cout << "[";
    for(int i = 0; i < n; i++)
        cout << " " << nums[i] << " ";
    cout << "]\n";
}