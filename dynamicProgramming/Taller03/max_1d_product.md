# Ejercicio 1

![Problem01](https://i.imgur.com/H5VIdP8.jpg)

El problema nos solicita encontrar el múltiplo máximo de subsecuencias de números consecutivos dentro de N secuencias principales de cantidades diferentes de números enteros.

> El rango definido para $X_i$ es: $\quad-99999 \le X_i \le 99999\quad\forall X_i\in\mathbb Z$
---
## Pseudocódigo

```
    Function Max 1D Range Product
        Input: Array, Size
        Output: Maximun product in subsequence of consecutive numbers in Array
        
        Memoization [Size]
        Product = 0
        for 2 to Size+1 do
            if Numbers are consecutive then
                Product = MAX (Product * Array [One before] OR Array [One before] * Array [Two before] )
            else Product = 0
            End If
        Memoization [Current position] = MAX ( Product OR Memoization [One before])
        End For
        
    Return Memoization [Size] 
```
![Pseudocode](https://i.imgur.com/03kXIo9.png)

---
## Implementación en C++

La solución que se utilizo para este problema, tiene como base el `max_1d_range_sum`. A partir de ahí, se le hicieron las modificaciones necesarias para poder retornar el dato solicitado. También se creo una función para generar el archivo que tiene las secuencias de números, que servirá como la entrada de datos a nuestro programa.

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

#### Código

```c++
int max_1d_range_product(int *A, int n) {
	int M[n + 1], P = 0;
    /*
    Se inicializa el arreglo M que se va a utilizar, aplicando la Memoization.

    También la variable P, que almacenará temporalmente el cálculo
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

#### Instancias de ejemplo

```c++
    n = 10;
    int A[n] = {10, 1, -7, -6, 3, -9, 0, 2, -1, -5};
    int B[n] = {10, -31, 4, 9, 3, 20, 29, 2, -52, 8};
```

#### Main

```c++
int main() {

    cout << "El resultado maximo es: " << max_1d_range_product(A, n) << ".\n";
    cout << "El resultado maximo es: " << max_1d_range_product(B, n) << ".\n";

    return 0;
}
```

> El resultado maximo es: 42.  
> El resultado maximo es: 720.  
>   
> — Console Output   
---
## Modificaciones

### Modificacion 1 
El casino se ha dado cuenta que varios participantes aciertan muy facil la respuesta en este juego, por lo que deciden modificar las reglas.   

Ahora el limite de numeros en una secuencia dada es de 500 numeros. Ademas, los numeros solo pueden ser maximo de dos digitos. Para agregar una dificultad extra, ahora no es necesario que esten estrictamente consecutivos en el orden en el que aparecen en el arreglo original.

---
Para solucionarlo utilizando DP, se ordena el arreglo en una copia del original para no modificarlo, y a este arreglo ordenado se le pasa el mismo codigo. De esta forma, nos aseguramos de que si los numeros son consecutivos, esten juntos en el arreglo u se tomen en cuenta cuando el algoritmo se ejecute.
### Modificacion 2 
Bob esta sumamente agradecido contigo, gracias a tu solucion ha ganado mucho dinero, pero te contacta una vez mas. Le han ofrecido duplicar la cantidad que tiene si logra N instancias correctamente de nuevo, pero esta vez, tiene que indicar cual es la subsecuencia de numeros consecutivos que genera el resultado mayor.

---
Para resolverlo, se crea una estructura respuesta, en donde se guardaran cada uno de los valores que generen el mayor producto. Dicha string se modificara para sobreesrcibirse si el producto es mayor al actual. Si no, quedara igual.
