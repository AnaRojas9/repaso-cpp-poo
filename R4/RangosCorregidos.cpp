#include <iostream>

int main(){


const int N = 5;
int d[N] = {10, 20, 30, 40, 50};

int suma = 0;                            // A: sumar todo
    for (int i = 0; i < N; i++) suma += d[i];

int cuantos = 0;                         // B: contar > 25
    for (int i = 0; i < N; i++)
    if (d[i] > 25) cuantos++;

int k = 0;                               // C: imprimir todo
    while (k < N) { std::cout << d[k] << ' '; k++; }
    
std::cout << "\nSuma: " << suma << "\nCuantos: " << cuantos << "\n";
 return 0;

}