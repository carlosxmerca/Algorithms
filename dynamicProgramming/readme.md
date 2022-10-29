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