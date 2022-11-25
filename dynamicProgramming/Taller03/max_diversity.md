# Ejercicio #2
![img](https://i.imgur.com/TtT0xRj.png)
## Seudocódigo del ejercicio "maximizing the diversity of a melody"

```
function  Max 1D Range Diversity
  Input 
  N -> Lenght of the song
  A -> Sequence of notes

  // M is an array which is the implementation of memoization.
  M[n];
  // When only one element is analyzed, we consider it a trivial case because the number of different values for arrays of data, regardless of what that data is, is always 1.
  M[0] = 1;
  
  // The path goes from 1 to n-1 since we already defined the solution for the trivial case i=0 and both sets "A" & "M" have size n.
  for 1 to n-1
    // Case when we have two consecutive equal integers
    if (Previous note is same as current note) {
      // The current integer is increased by one
      Current note++;
      // In the memoization array we advance to the next solution which will be equal to the previous solution increased by one, which symbolizes that a new distinct integer was found.
      Current solution = Previous solution + 1;      
    } 
    // Case when the integer found is less than the previous one
    else if (Previous note is greater than current note) {
    	// The current integer is increased by one
        Current note++;
	// In the memoization array we advance to the next solution which will be the same as the previous solution.
        Current solution = Previous solution;        
      }
    // Case when the integer found is greater than the previous one
    else
      // In the memoization array we advance to the next solution which will be equal to the previous solution increased by one, which symbolizes that a new distinct integer was found.
      Current solution = Previous solution + 1; 
  }															
  // Being a solution by dp, the response after execution is in the last position of our memoization data structure
  return Last Solution; 		
}
```

## Implementación en c++ de "maximizing the diversity of a melody"
```c++
#include <bits/stdc++.h>
using namespace std;

// Function prototype declarations
int max_1d_range_diversity(int* A, int n);
void fill_array(int* A, int n);

int main() {
  int t;
	// The number of tests is requested
  cout << "Enter the number of test" << endl;
  cin >> t;

  // Cycle to repeat and test the algorithm 't' times
  for (int i = t; i > 0; i--) {
    int n = 0;
    cout << "Enter the size of the array (n)" << endl;
    cin >> n;
    int A[n]; // An array as a data structure
    fill_array(A, n); // Calling the function to fill the array
    cout << "Maximum diversity: " << max_1d_range_diversity(A, n) << endl; // Print solution
  }
}

// Function to fill the array
void fill_array(int* A, int n){
    // Filling the values for x1 <= x2 <= x3 <=...<= xn
    cout << "Fill the values ascendant (Array)" << endl;
    for (int i = 0; i < n; i++) {
      cin >> A[i];
    }
}

// Function with the algorithm to calculate the maximum of differents elements with the condition given.
int max_1d_range_diversity(int* A, int n){

  int M[n]; 			// A solution array that contains the answers, this array is the memoization array.
  M[0] = 1;			// When there is only one data it is a trivial case because our diversity value will also be 1 with a single data.
  
  /*
We compare the current one with the previous one and since we know that
for an array of data there will be only one different
data (the same one), therefore we start the 'for' at 1
  */
  for (int i = 1; i < n; i++) {
    if (A[i - 1] == A[i]) {	// When numbers are the same
      A[i]++;   	    	// Add one to the current number
      M[i] = M[i - 1] + 1;      // And now we have one more diferent number
    } 
    else if (A[i - 1] > A[i]) { // When the number before is higher than the current number
        A[i]++;                 // Add one to the current number
        M[i] = M[i - 1];        // But we copy the previous result
      }
    else			// When the number before is neither the same nor higher
      M[i] = M[i - 1] + 1;      // Only one is added to the result, since they are different and the current number is greater than the previous one, as requested.
  }															

  return M[n-1]; 		// The maximum value is at the end of the M array
}
```

### Escenario de ejemplo
#### Input
```
Number of test: 1
Size of the array (n): 6
Values ascendant (Array): 2 2 2 3 4 5
```
Arreglo solicitado:
| i  | 0 | 1 | 2 | 3 | 4 | 5 |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| A  | 2 | 2 | 2 | 3 | 4 | 5 |

Donde la fila de i son los indices en el recorrido y A es el arreglo ingresado por el usuario.

#### Output
```
Maximum diversity: 5
```
Arreglo solucionado:
| i  | 0 | 1 | 2 | 3 | 4 | 5 |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| A  | 2 | 2 | 2 | 3 | 4 | 5 |
| M  | 1 | 2 | 2 | 3 | 4 | 5 |
| A' | 2 | 3 | 3 | 4 | 5 | 6 |

Donde M es el arreglo por `Memoization` y A' es el arreglo final "A" tras sufrir los aumentos.

## Modificaciones del ejercicio
### Modificacion 1 
Como primera modificación propuesta tenemos que podríamos modificar una de las condiciones que dictan que es lo que se pueden hacer con cada uno de los enteros, es decir nuestras condiciones actuales para cada entero son que solo es válido sumarle una unidad o dejarlo como está. Por tanto, podemos solicitar un número natural `m` por cada test y que este sustituya el valor de la unidad. En otras palabras, para cada entero las nuevas condiciones son dejarlo como está ó sumarle el número `m` antes definido por el usuario.
El motivo de esta variación se basa en que ahora el usuario quien ayuda a calcular el máximo de la diversidad entre las notas, tambien puede recibir un parámetro `m` que provoque una diversidad más alta por cada cambio en las notas (que son representadas como enteros), ya que sumarle 1 a una nota la hace menos o a lo sumo igual de diversa que sumarle un `m | m ∈ ℕ`.

---
Para solucionar esto utilizando DP, se propone una solución similar a la solución del problema base pero con leves variaciones. Estos cambios surgirian en las acciones tras las comparaciones `if` y `else if` donde en estos casos incrementabamos el valor de la posición actual del `arreglo original A` en 1, sin ambargo ahora debemos incrementarlo por el nuevo valor `m`. Esto se haría para ambas condiciones ya que por supuesto que siempre seguimos mantemiendo el requisito de que permanezcan los números enteros ascendentemente. 

### Modificacion 2 
Como segunda modificación, propongo que ahora surge un compositor que es muy creativo por lo que sus melodias tienen demasiada diversidad en sus notas, y justo en ese momento se requiere una melodia lo más tranquila y menos variada posible, en otras palabras ahora se requiere lo opuesto al ejercicio base ya que ahora tener diversidad en las notas es negativo. Por tanto, se busca minimizar la diverisadad en las notas lo que implica que al tomar las notas como enteros, se solicita que se *maximice la cantidad de elementos repetidos* en el arreglo que representa la melodia completa, siempre manteniendo las dos condiciones de modificación de los enteros del problema base (sumarle uno al entero actual o dejarlo como está).

---
Para solucionar esto utilizando DP, se propone una solución muy similar a la del problema base, esto ya que se utilizarían los mismos criterios de evaluación pero cambiaría la acción a realizar en caso de que se cumpla cada uno de ellos. Nuestro anterior `else` de la función `max_1d_range_diversity()`, que se encargaba de ver si habian dos elementos distintos consecutivos, simplemente avanzaba el `arreglo solución M` con el valor de 1 más la respuesta acumulada en la posición anterior del arreglo `(M(i-1))`, ya que encontraba un elemento distinto en la posición actual `(A(i))`. Sin embargo, para esta modificación esta acción intercambiaría con la acción que se ejecuata cuando se encontraban dos enteros iguales en el problema base. Esto ocurrirá de esta manera ya que nos interesa ir guardadndo una nueva solución en `M` cuando encontremos un entero igual al anterior en el `arreglo A`.
