#include <iostream>
using namespace std;

int fibonacci(int n);

int main()
{
    cout << "Fibonacci DP\n";
    cout << "Result: " << fibonacci(5);

    return 0;
}

int fibonacci(int n) {
    int A[n+1];
    A[0] = A[1] = 1;
    
    for(int i = 2; i <= n; i++)
        A[i] = A[i-1] + A[i-2];

    return A[n];
}