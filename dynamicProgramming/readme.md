## Dynamic programming

### Introduction

¿Cual fue la motivación para hacer los modelos recursivos? 
R// La naturaleza es recursiva y este es un intento del ser humano por entender y utilizar este conocimiento a su favor.

#### Overlaping subproblems

Repetición de problemas anidados como subproblemas.

#### Substructure optimization

Se da cuando una estructura se puede optimizar, concretamente al tener traslape en los sub problemas. Ya que al tener la respuesta de una ocurrencia se tiene la respuesta de las demás ocurrencias.

#### Fibonacci 

Solucion recursiva, algoritmo recursivo
```c++
int fibonacci(int n) {
    if (n == 0 || n == 1) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);
}
```
Orden de magnitud:`O(n^2)` *Los ordenes de magnitud exponenciales deben de ser evitados a toda costa*.

Solucion recursiva, algoritmo **no** recursivo

```c++
int fibonacci(int n) {
    int A[n+1];
    A[0] = A[1] = 1;
    
    for(int i = 2; i <= n; i++)
        A[i] = A[i-1] + A[i-2];

    return A[n];
}
```
Orden de magnitud:`O(n)` :0, se hace uso de la tecnica **memoization**, donde se implementa una estructura de datos lineal como memoria de las ejecuciones anteriores.

**Transferencia de la recursión**
La recursion se movio del codigo a la estructura de datos.

#### MAX 1D RANGE SUM

```c++
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
```

#### Knapsack
```c++
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
```

##### Show elements in Knapsack
```c++
// O(n*k) 
void knapsack(int k, int* W, int* V, int n) {
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
    
    int res = M[n][k];
    int w = k; 
    
    cout << "Items included: \n";
    for (int i = n; i > 0 && res > 0; i--) {
        // if different from above element is included
        if (res == M[i - 1][w])
            continue;   
        else {
            // This item is included.
            cout << " [ v: " << V[i - 1] << ", W: " << W[i - 1] << "] \n";
            // Since this weight is included its
            // value is deducted
            res = res - V[i - 1];
            w = w - W[i - 1];
        }
    }
    
    cout << "Value: " << M[n][k];
}
```
