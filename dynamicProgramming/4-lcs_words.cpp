#include <iostream>

using namespace std;

typedef struct{
    int max_length;
    string max_seq;
} Answer;

// Para usar LCS con palabras se utilizan arreglos de palabras
Answer LCS(string* A, int nA, string* B, int nB){ 
    int M[nA+1][nB+1];
    string R[nA+1][nB+1];

    for(int i = 0; i <= nA; i++){
        M[i][0] = 0;
        R[i][0] = "";
    }
    for(int j = 1; j <= nB; j++){
        M[0][j] = 0;
        R[0][j] = "";
    }

    for(int i = 1; i <= nA; i++)
        for(int j = 1; j <= nB; j++)
            if( A[i-1] == B[j-1] ){
                M[i][j] = 1 + M[i-1][j-1];
                R[i][j] = R[i-1][j-1] + A[i-1] + " ";
            }else{
                M[i][j] = max( M[i-1][j] , M[i][j-1] );
                if( M[i-1][j] > M[i][j-1] )
                    R[i][j] = R[i-1][j];
                else
                    R[i][j] = R[i][j-1];
            }

    Answer res;
    res.max_length = M[nA][nB];
    res.max_seq = R[nA][nB];
    return res;
}

int main(void) {
    int nA = 4;
    string A[nA] = {"die", "einkommen", "der", "landwrite"};
    int nB = 6;
    string B[nB] = {"die", "steuern", "auf", "vermoegen", "und", "einkommen"};
    //  die einkommen

    Answer respuesta = LCS(A, nA, B, nB);
    cout << "La longitud de la Longest Common Subsequence es: " << respuesta.max_length << "\n";
    cout << "y la secuencia correspondiente es: [ "<< respuesta.max_seq <<"]\n";

    return 0;
}