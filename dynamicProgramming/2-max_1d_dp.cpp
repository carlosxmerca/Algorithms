#include <iostream>
using namespace std;

struct Response {
  int value;
  int i;
  int j;
};

Response max_1D(int* A, int n);

int main()
{
    cout << "Max 1D range sum\n";
    
    int n = 9;
    // int A[n] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // i: 3 j: 6
    int A[n] = {4, -5, 4, -3, 4, 4, -4, 4, -5};
    // i: 2 j: 5
    
    Response response = max_1D(A, n);
    cout << "Valor maximo: " << response.value << "\n";
    cout << "i: " << response.i << " j: " << response.j << "\n";

    return 0;
}

Response max_1D(int* A, int n) {
    int M[n+1];
    M[0] = 0;
    
    int s, o, p;
    s = o = p = 0;
    
    for (int i = 1; i <= n; i++) {
        // Reiniciar la suma y posiciones
        if (s + A[i-1] < A[i-1])
            o = p = i-1;
        
        s = max(s + A[i-1], A[i-1]);
        M[i] = max(s, M[i-1]);
        
        // Desplazar el limite superior
        if (s > M[i-1])
            p = i-1;
    }
    
    return { M[n], o, p };
}
