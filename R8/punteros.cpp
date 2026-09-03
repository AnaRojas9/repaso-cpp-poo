#include <iostream>

void intercambiar1(int a, int b) {
    int t = a; a = b; b = t;           // no cambia nada afuera
}
void intercambiar2(int* a, int* b) {
    int t = *a; *a = *b; *b = t;       // se llama: (&x, &y)
}
void intercambiar3(int& a, int& b) {
    int t = a; a = b; b = t;           // se llama: (x, y)
}

int main() {
    int x = 5, y = 10;

    std::cout << "Originales: x = " << x << ", y = " << y << "\n\n";

    //Por valor (NO cambia)
    intercambiar1(x, y);
    std::cout << "Tras intercambiar1 (valor):     x = " << x << ", y = " << y << "\n";

    // Por punteros (SÍ cambia)
    intercambiar2(&x, &y);
    std::cout << "Tras intercambiar2 (punteros):  x = " << x << ", y = " << y << "\n";

    //Por referencia (SÍ cambia)
    intercambiar3(x, y);
    std::cout << "Tras intercambiar3 (referencia): x = " << x << ", y = " << y << "\n";

    return 0;
}