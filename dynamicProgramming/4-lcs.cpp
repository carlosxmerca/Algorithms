#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Longest Common Subsecuence 
int lcs(string A, string B) {
    int nA = A.length(), nB = B.length();
    int M[nA+1][nB+1];
    
    for(int i = 0; i <= nA; i++)
        M[i][0] = 0;
    for(int j = 1; j <= nB; j++)
        M[0][j] = 0;
    
    for(int i = 1; i <= nA; i++)
        for(int j = 1; j <= nB; j++) {
            if (A[i-1] == B[j-1])
                M[i][j] = 1 + M[i-1][j-1];
            else
                M[i][j] = max( M[i-1][j], M[i][j-1] );
        }
    
    // Verificar matriz de respuesta
    for(int i = 0; i <= nA; i++) {
        for(int j = 0; j <= nB; j++)
            cout << M[i][j] << " - ";
        cout << "\n";
    }
    
    return M[nA][nB];
}

int main()
{
    cout << "LCS\n";
    
    /*
    string A = "stone";
    string B = "longest";
    */
    string A = "agcga";
    string B = "cagatagag";
    
    int response = lcs(A, B);

    cout << "Valor maximo: " << response << "\n";

    return 0;
}
