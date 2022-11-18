## Ejercicio #4
### Seudocódigo de Minimum Coin Change
...

### Implementación en c++ de Minimum Coin Change
```c++
// Retorna el numero mínimo de billetes necesarios (usando todas las denominaciones posibles)
// para devolver la suma de dinero solicitada.
int minBills(int* bills, int n, int m) {
    // Memoization
    // Estructura unidimensional de capacidad n+1 donde se alojarán
    // las respuestas de los escenarios ya calculados
    int dp[n+1] = {0};
    
    // Inicializar todos los valores a "infinito" en este caso representado por INT_MAX
    // En este escenario el mínimo de monedas para hacer cualquier cantidad de suma es "infinito"
    for(int i = 0; i <= n; i++)
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

### DP
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
#### Modificación #1
Se desea retirar una cantidad grande de dinero de un ATM, sin embargo, la cantidad de billetes de cada denominación `1, 5, 10, 20, 100`, están limitados (no se dispone de recursos infinitos). El número de billetes con los que se dispone de cada tipo están denotados por `v, w, x, y, z`, todos valores enteros positivos. 

Se tiene que indicar la cantidad mínima de billetes necesaria para retornar el valor especificado y en caso que no se pueda realizar con los billetes actuales indicarlo mostrando: `“No es posible”`.

#### Modificación #2
Un cliente muy importante del banco DP desea retirar una cantidad grande de dinero, para lo que contamos con billetes de cada denominación: `1, 5, 10, 20, 100`.

Se tendrá que encontrar la **diferencia** de billetes que existe entre devolver la cantidad *mínima* necesaria para entregar la suma de dinero al cliente y la cantidad *máxima* de billetes que se pueden usar para entregarle la suma de dinero al cliente. 

En caso que ambas soluciones sean iguales se deberá mostrar un mensaje que diga: `"Ambas soluciones son iguales"`. Como limitante, no se pueden devolver unicamente billetes de la denominación mas baja.
