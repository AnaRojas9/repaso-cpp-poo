#include <iostream>

void pedirNotas(double n[], int cuantas) {
    for (int i = 0; i < cuantas; i++) {
        std::cout << "Nota " << i + 1 << ": ";
        std::cin >> n[i];
    }
}

double promedio(const double n[], int cuantas) {
    double s = 0;
    for (int i = 0; i < cuantas; i++) s += n[i];
    return s / cuantas;
}

bool aprobado(double prom) { return prom >= 70.0; }

int main() {
    double notas[3];

    pedirNotas(notas, 3);
    
    double prom = promedio(notas, 3);
    std::cout << "Promedio: " << prom << '\n';

    if (aprobado(prom)) {
        std::cout << "Aprobado\n";
    } else {
        std::cout << "Reprobado\n";
    }

    return 0;
}