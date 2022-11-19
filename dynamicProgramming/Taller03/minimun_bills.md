## Ejercicio #4
![EJ4](https://i.imgur.com/29Rw1My.jpg)

### Seudocódigo de Minimum Coin Change
```
// Encuentra el numero mínimo de billetes necesarios (usando todas las denominaciones posibles)
// para devolver la suma de dinero solicitada.
minBills(B, n, m)
    // n —> suma de dinero solicitada
    // m —> número de difernetes denominaciones de billetes 

    // Estructura unidimensional donde se alojarán
    // las respuestas de los escenarios ya calculados
    // En este escenario el mínimo de monedas para hacer cualquier cantidad de suma es ∞
    let DP[1..n+1] new array of ∞

    // Caso base
    // El mínimo de billetes necesarios para sumar 0 dólares es 0
    DP[0] = 0;

    // El primer ciclo itera desde 1 hasta n, tomando en cuenta todas las posibles sumas entre
    // estos valores ya que muy probablemente la solución final o cualquier
    // otra solución intermedia podría depender de cualquiera de estos valores

    // El segundo bucle proporciona los índices del array de billetes
    // Ya que se revisa la posibilidad de sumar todos los billetes de la manera más optima
    for i = 1 to n
        for j = 0 to m-1
            // Se tiene que validar que el billete en cuestión se pueda agregar en el espacio disponible
            if bills[j] <= i
                // Validar si es más optimo incluir o no el billete en cuestión
                // Por un lado: Se suma el billete + la cantidad de billetes necesarias para el "peso" restante
                // es decir el peso original j menos el peso del billete recién incluido
                // Por otra parte: No se modifica la respuesta actual
                // Se elige la opción en donde se utilizan menos billetes "la más optima"
                DP[i] = Min Between DP[i] And 1 + DP[i - bills[j]]
    
    // En la última casilla de la memoria esta la solución más optima.
    Answer is DP[n]
```

### Implementación en c++ de Minimum Coin Change
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

### Escenario de ejemplo
```c++
int n_bills = 5;
int bills[n_bills] = {1, 2, 3, 4, 5}; 
int sum = 11;
```

### Respuesta esperada
```
Outpu: 3
Explanation: {5, 5, 1}
```

### Vista de los diferentes estados de la memoria 
| i | 0 | 1 | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9    | 10  | 11  |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | 0 | 1 | max | max | max | max | max | max | max | max  | max | max | 
| 2 | 0 | 1 | 1   | max | max | max | max | max | max | max  | max | max | 
| 3 | 0 | 1 | 1   | 1   | max | max | max | max | max | max  | max | max |
| 4 | 0 | 1 | 1   | 1   | 1   | max | max | max | max | max  | max | max | 
| 5 | 0 | 1 | 1   | 1   | 1   | 1   | max | max | max | max  | max | max | 
| 6 | 0 | 1 | 1   | 1   | 1   | 1   | 2   | max | max | max  | max | max | 
| 7 | 0 | 1 | 1   | 1   | 1   | 1   | 2   | 2   | max | max  | max | max | 
| 8 | 0 | 1 | 1   | 1   | 1   | 1   | 2   | 2   | 2   | max  | max | max | 
| 9 | 0 | 1 | 1   | 1   | 1   | 1   | 2   | 2   | 2   | 2    | max | max | 
| 10 | 0 | 1 | 1   | 1   | 1   | 1   | 2   | 2   | 2   | 2    | 2   | max | 
| 11 | 0 | 1 | 1   | 1   | 1   | 1   | 2   | 2   | 2   | 2    | 2   | 3   |

### Modificaciones del ejercicio
### Modificación #1
Se desea retirar una cantidad grande de dinero de un ATM, sin embargo, la cantidad de billetes de cada denominación `1, 5, 10, 20, 100`, están limitados (no se dispone de recursos infinitos). El número de billetes con los que se dispone de cada tipo están denotados por `v, w, x, y, z`, todos valores enteros positivos. 

Se tiene que determinar si con los recursos que se dispone se puede o no retornar el valor especificado. En caso que no se pueda realizar con los billetes actuales indicarlo mostrando: `“No es posible”`. Y si es posible mostrar: `“Si es posible”`

```
Example:

Input: sum = 16, coins[] = {1, 3, 4}, quantity[] = {2, 2, 1}
Output: No es posible
Explanation: 
The max sum posible using...
2 of 1, 2 of 3 and 1 of 4 is 12, so its not possible
```

#### Explicación
Para resolver este problema se tiene que aplicar el algoritmo *Knapsack* utilizando *DynamicProgramming*.

Al igual que en el problema original utilizaremos un arreglo que contendrá las diferentes denominaciones de billetes y además otro arreglo que contendrá la cantidad de billetes de cada denominación con las que se puede trabajar.

Este algoritmo hará uso de una estructura bi-dimensional o matriz para almacenar los distintos estados (posibilidades) que ya hayan sido calculados, sus dimensiones serán: `table[n + 1][k + 1]` donde `k` es la cantidad de dinero especificada y `n` es la cantidad de distintas denominaciones de billetes.

Se recorre la matriz utilizando un doble bucle que itera: Los índices de las denominaciones de los billetes y la suma o cantidad de dinero.

Para cada casilla o estado de la matriz se deberá de hacer lo siguientes:
1. Identificar si el billete actual cabe en el espacio disponible
    - En el caso que el billete quepa identificar cuántos se pueden utilizar respetando el máximo de billetes de este tipo que contiene el arreglo (cantidad de billetes)
    - Determinar si  es más conveniente llenar la casilla con el valor que aporta utilizar los billetes en cuestión más la cantidad previamente calculada para el espacio faltante o simplemente utilizar el valor de la iteración anterior.
2. En el caso que el billete no quepa en el espacio disponible se deberá utilizar el valor de la iteración anterior es decir la casilla superior a la actual.

En la última casilla de la matriz `table[n][k]` está almacenada nuestra respuesta en el caso que esta sea diferente a `k` concluimos que la cantidad de dinero solicitada no se puede entregar con los billetes y la cantidad de ellos con las que podemos trabajar.

En el caso que la respuesta sea igual a `k` podremos afirmar que si podemos entregar una combinación de billetes que satisfaga esta suma de dinero. 


### Modificación #2
Un cliente muy importante del banco DP desea retirar una cantidad grande de dinero, para lo que contamos con billetes de cada denominación: `1, 5, 10, 20, 100`.

Se tendrá que encontrar el número de formas posibles en las que se le puede devolver la cantidad especificada.

```
Example:

Input: sum = 10, coins[] = {2, 5, 3, 6}
Output: 5
Explanation: There are five solutions: 
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.
```

#### Explicación
Para solventar esta problemática se tiene que aplicar el algoritmo *Coin Change* utilizando *DynamicProgramming*.

Al igual que en el problema original utilizaremos un arreglo que contendrá las diferentes denominaciones de billetes.

Este algoritmo hará uso de una estructura bi-dimensional o matriz para almacenar los distintos estados (posibilidades) que ya hayan sido calculados, sus dimensiones serán: `table[sum + 1][n]` donde *sum* es la cantidad de dinero especificada y *n* es la cantidad de distintas denominaciones de billetes.

La primera fila de la matriz tendrá todos los estados base es decir: 0.

Se recorrerá la matriz utilizando un doble bucle que itera: la suma o el peso y los índices de las denominaciones de billetes .

Para cada casilla o estado de la matriz se deberán de hacer dos cálculos:
1. La cantidad de soluciones utilizando la moneda actual.
2. La cantidad de soluciones sin utilizar la moneda actual.

Ambas soluciones se sumarán y almacenarán en la casilla actual. Al final la respuesta estará almacenada en la última casilla de la matriz es decir: `table[sum][n - 1]`.