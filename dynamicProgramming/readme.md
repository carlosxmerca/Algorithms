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
    
    int s, o, p, q, r;
    s = o = p = q = r = 0;
    // o, p -> respuesta temporal
    // q, r -> respuesta global
    
    for (int i = 1; i <= n; i++) {
        // Reiniciar la suma y posiciones
        if (s + A[i-1] < A[i-1]) {
            o = p = i-1;
        }
        
        s = max(s + A[i-1], A[i-1]);
        M[i] = max(s, M[i-1]);
        
        // Desplazar el limite superior
        if (s > M[i-1])
            p = i-1;
            
        // Cambiar respuesta temporal por global
        if (M[i] > M[i-1]) {
            q = o;
            r = p;
        }
    }
    
    return { M[n], q, r };
}
```

#### 0/1 Knapsack
```c++
// O(n*k) 
// n y k: nunca seran valores demasiado grandes
int knapsack(int k, int* W, int* V, int n) {
    int M[n+1][k+1];
    
    for (int i = 0; i <= n; i++)
        M[i][0] = 0;
    for (int j = 1; j <= k; j++)
        M[0][j] = 0;
        
    // Llenar matriz
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

##### Show elements in 0/1 Knapsack
```c++
// O(n*k) 
void knapsack(int k, int* W, int* V, int n) {
    int M[n+1][k+1];
    
    for (int i = 0; i <= n; i++)
        M[i][0] = 0;
    for (int j = 1; j <= k; j++)
        M[0][j] = 0;
        
    // Llenar matriz
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
##### Minimum Coin Change
```c++
// Retorna el numero mínimo de billetes necesarios (usando todas las denominaciones posibles)
// para devolver la suma de dinero solicitada.
int minBills(int* bills, int n, int m) {
    // n —> suma de dinero solicitada
    // m —> número de difernetes denominaciones de billetes 

    // Memoization
    // Estructura unidimensional de capacidad n+1 donde se alojarán
    // las respuestas de los escenarios ya calculados
    int dp[n+1];
    
    // Inicializar todos los valores, menos el caso base a "infinito" en este caso representado por INT_MAX
    // En este escenario el mínimo de monedas para hacer cualquier cantidad de suma es "infinito"
    for(int i = 1; i <= n; i++)
        dp[i] = INT_MAX;
  
    // Caso base
    // El mínimo de billetes necesarios para sumar 0 dólares es 0
    dp[0] = 0;
  
    // El primer ciclo itera desde 1 hasta n, tomando en cuenta todas las posibles sumas entre
    // estos valores ya que muy probablemente la solución final o cualquier
    // otra solución intermedia podría depender de cualquiera de estos valores
    for(int i = 1; i <= n; i++) {
        // El segundo bucle proporciona los índices del array de billetes
        // Ya que se revisa la posibilidad de sumar todos los billetes de la manera más optima
        for(int j = 0; j < m; j++) {
            // i —> representa el valor de la suma de billetes
            // j —> índice de los billetes a evaluar
            // Se tiene que validar que el billete en cuestión se pueda agregar en el espacio disponible
            if(bills[j] <= i) {
                // Validar si es más optimo incluir o no el billete en cuestión
                // Por un lado: Se suma el billete + la cantidad de billetes necesarias para el "peso" restante
                // es decir el peso original j menos el peso del billete recién incluido
                // Por otra parte: No se modifica la respuesta actual
                // Se elige la opción en donde se utilizan menos billetes "la más optima"
                dp[i] = min(dp[i], 1 + dp[i - bills[j]]);
            }
        }   
    }
  
    // En la última casilla de la memoria esta la solución más optima.
    return dp[n];
}
```

##### Coin change

```c++
// Numero de formas posibles de devolver un resultado
int count(int coins[], int n, int sum)
{
    int i, j, x, y;

    // We need sum+1 rows as the table
    // is constructed in bottom up
    // manner using the base case 0
    // value case (sum = 0)
    int table[sum + 1][n];
 
    // Fill the entries for 0
    // value case (sum = 0)
    for (i = 0; i < n; i++)
        table[0][i] = 1;
 
    // Fill rest of the table entries
    // in bottom up manner
    for (i = 1; i < sum + 1; i++) {
        for (j = 0; j < n; j++) {
            // Count of solutions including coins[j]
            x = (i - coins[j] >= 0) ? table[i - coins[j]][j] : 0;
 
            // Count of solutions excluding coins[j]
            y = (j >= 1) ? table[i][j - 1] : 0;
 
            // total count
            table[i][j] = x + y;
        }
    }
    return table[sum][n - 1];
}
```

##### LCS - Longest Common Subsecuence

```c++
// O(nA * nB)
// A -> Rows, B -> Columns
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
    
    return M[nA][nB];
}
```

##### LCS - Longest Common Subsecuence full
```c++
Answer LCS(string A, string B){ 
    int nA = A.length(), nB = B.length();
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
```