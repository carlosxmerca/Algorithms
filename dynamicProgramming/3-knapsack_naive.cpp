#include <iostream>
using namespace std;

int naiveKnapsack(int K, int* W, int* V, int n, int i);

int main()
{
    cout<<"Knapsack\n";
    int k = 15;
    int n = 5;
    int W[n] = {1, 12, 2, 1, 4};
    int V[n] = {2, 4, 2, 1, 10};
    
    cout << "Value: " << naiveKnapsack(k, W, V, n, 0);

    return 0;
}

// O(2^n)
int naiveKnapsack(int k, int* W, int* V, int n, int i) {
    if (i == n) return 0;
    
    int res1, res2;
    
    // Encontrar resultado sin tomar en cuenta el elemento actual
    res1 = naiveKnapsack(k, W, V, n, i+1);
    
    // Tomando en cuenta el elemento actual
    if (W[i] <= k)
        res2 = V[i] + naiveKnapsack(k - W[i], W, V, n, i+1);
    else
        res2 = 0;
        
    return max(res1, res2);
}
