#include <iostream>
#include <string>
#include "arreglo.hpp"

int main() {
    // Prueba con double
    Arreglo<double> arrDouble(2);
    arrDouble[0] = 10.5;
    arrDouble[1] = 20.7;

    // Verificación de copia profunda con double
    Arreglo<double> copiaDouble = arrDouble;
    copiaDouble[0] = 99.9; // Se modifica la copia

    std::cout << "Original double[0]: " << arrDouble[0] << " (Debe ser 10.5)\n";
    std::cout << "Copia double[0]:    " << copiaDouble[0] << " (Debe ser 99.9)\n\n";

    // Prueba con std::string
    Arreglo<std::string> arrString(2);
    arrString[0] = "Hola";
    arrString[1] = "Mundo";

    // Verificación de copia profunda con std::string
    Arreglo<std::string> copiaString = arrString;
    copiaString[0] = "C++"; // Se modifica la copia

    std::cout << "Original string[0]: " << arrString[0] << " (Debe ser Hola)\n";
    std::cout << "Copia string[0]:    " << copiaString[0] << " (Debe ser C++)\n";

    return 0;
}