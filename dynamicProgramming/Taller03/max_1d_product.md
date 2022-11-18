
# Ejercicio 1

![Problem01](https://i.imgur.com/H5VIdP8.jpg)

El problema nos solicita encontrar el múltiplo máximo de subsecuencias de números consecutivos dentro de N secuencias principales de cantidades diferentes de números enteros.

> El rango definido para $X_i$ es: $$-99999 \le X_i \le 99999\quad\forall X_i\in\mathbb Z$$

## Pseudocódigo

> Working on it...

## Implementación en C++
La solución que se utilizo para este problema, tiene como base el ```max_1d_range_sum```. A partir de ahí, se le hicieron las modificaciones necesarias para poder retornar el dato solicitado. También se creo una función para generar el archivo que tiene las secuencias de números, que servirá como la entrada de datos a nuestro programa.

A continuación, las funciones implementadas en C++

### Función para generar archivo con números aleatorios
```c++
#include <time.h>
#include <fstream>

void create_rand_nums(string path, int lim, int subsequences)
{
    srand(time(NULL));
    fstream file(path, ios::out);
    for (int j = 0; j < subsequences; j++)
    {
        file << "{";
        for (int i = 0; i < lim; i++)
            file << -99999 + (rand() % ((2 * 99999) + 1)) << ",";
        file << -999999 << "}"
             << "\n";
    }
}
```
### Función principal

#### Instancia de ejemplo
```c++
    n = 10;
    int A[n] = {10, -31, 4, 9, 3, 20, 29, 2, -52, 8};
```

#### Código
```c++
int max_1d_range_product(int *A, int n)
{
    merge_sort(A, 0, n - 1);
    /*
    Se ordena primero el arreglo en el que se va a trabajar.
    Esto para poder determinar los números consecutivos de manera recursiva.
    En este caso, se utilizó merge_sort porque en el peor de los casos
    su tiempo de ejecución es O (n logn).
    */

    int M[n + 1], P = 0;
    /*
    Se inicializa el arreglo M que se va a utilizar, aplicando la Memoization.

    También la variable P, que almacenará temporalment el cálculo
    del mayor producto en el arreglo.
    */

    M[0] = 0;
    M[1] = A[0];
    /*
    Se queman la primera y segunda posición del arreglo A.

    Para este caso en particular, se quemara con un cero y con el primer elemento
    del arreglo original. Esto por si existe una secencia que contiene solamente uno
    o dos dígitos.
    */

    for (int i = 2; i <= n; i++)
    {
        /*
        La iteración de este algoritmo empezará en 2, puesto que se necesita saber las
        2 posiciones anteriores a la posicion del iterador para poder determinar el
        valor de P dependiendo de los casos que se presenten.
        */
        if (A[i - 1] == A[i - 2] + 1)
            /*
            Para saber si dos numeros son consecutivos en un arreglo A, basta con agregar
            una unidad a la posicion anterior de la actual y si los valores son los mismos,
            significa que uno va despues del otro, o sea, son consecutivos.
            */
            P = max(P * A[i - 1], A[i - 1] * A[i - 2]);
            /*
            En dado caso sí sean consecutivos, el nuevo valor de P viene designado por
            el valor máximo entre el valor actual de P multiplicado por el último dígito
            consecutivo conocido y el producto entre los dos últimos consecutivos.
    
            Esto se hace para saber si es mayor el producto entre dos números contiguos
            en el arreglo A después de que no sean consecutivos, o multiplicar el producto
            por el último consecutivo conocido.
    
            Por ejemplo, en la secuencia 4,5,6,9,10 el producto de 4*5*6 es mayor que
            el producto de 9*10, por tanto P = 4*5*6. Si la secuencia fuera 5,6,9,10
            P tendría un valor de P = 9*10, puesto que es mayor que 5*6.
            */
        else
            P = 0; // Si no son consecutivos, el producto total se reinicia a 0.

        M[i] = max(P, M[i - 1]);
        /*
        Finalmente, en la posicion i del arreglo M se almacenará el mayor
        entre el nuevo producto calculado o el anterior producto calculado.
        */
    }

    return M[n];
    /*
    Y retornamos el mayor producto calculado, que queda almacenado en la posición final
    del arreglo M.
    */
}

}
```

#### Arreglo 'M' instancia de ejemplo
|2|3|
|--|--|
|0|0|
