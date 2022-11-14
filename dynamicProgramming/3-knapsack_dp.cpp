#include <iostream>
using namespace std;

int knapsack(int K, int* W, int* V, int n);

int main()
{
    cout<<"Knapsack\n";
    int k = 15;
    int n = 5;
    int W[n] = {1, 12, 2, 1, 4};
    int V[n] = {2, 4, 2, 1, 10};
    
    cout << "Value: " << knapsack(k, W, V, n);

    return 0;
}

// O(n*k) 
// n y k: nunca seran valores demasiado grandes
int knapsack(int k, int* W, int* V, int n) {
    int M[n+1][k+1];
    
    for (int i = 0; i <= n; i++)
        M[i][0] = 0;
    for (int j = 1; j <= k; j++)
        M[0][j] = 0;
        
    // Recorrer matriz
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            // V[i-1] -> Valor de obj actual (ajuste)
            // W[i-1] -> Valor del peso actual
            if (j >= W[i-1]) // Verificar si cabe
                M[i][j] = max( V[i-1] + M[i-1][ j - W[i-1] ], M[i-1][j] );
            else 
                M[i][j] = M[i-1][j];
        }
    }
    
    return M[n][k];
}
