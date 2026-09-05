#include <iostream>
#include <vector>

void probar(bool usarReserve) {
    std::vector<int> v;

    if (usarReserve) {
        v.reserve(1000);
        std::cout << " CON v.reserve(1000)";
    } else {
        std::cout << "SIN reserve ";
    }

    std::size_t cap = v.capacity();
    std::cout << "size 0 -> capacity " << cap << '\n';

    int reasignaciones = 0;
    int copiasTotales = 0;

    for (int i = 0; i < 1000; ++i) {
        v.push_back(i);
        if (v.capacity() != cap) {
            // El número de elementos copiados equivale a la cantidad que ya existía antes de hacer push_back
            copiasTotales += (v.size() - 1);
            reasignaciones++;

            cap = v.capacity();
            std::cout << "size " << v.size()
                      << " -> capacity " << cap << '\n';
        }
    }

    std::cout << "Reasignaciones: " << reasignaciones << '\n';
    std::cout << "Elementos copiados: " << copiasTotales << '\n';
}

int main() {
    probar(false); // Caso sin reserve
    probar(true);  // Caso con reserve
    return 0;
}