#include <iostream>
#include <cstddef>

class Arreglo {
private:
    std::size_t n;
    int* datos;

public:
    explicit Arreglo(std::size_t tam) : n(tam), datos(new int[tam]()) {}

    // Constructor de copia (mismo orden que en los atributos privados)
    Arreglo(const Arreglo& otro) : n(otro.n), datos(new int[otro.n]) {
        for (std::size_t i = 0; i < n; ++i) {
            datos[i] = otro.datos[i];
        }
    }

    // Operador de asignacion
    Arreglo& operator=(const Arreglo& otro) {
        if (this == &otro) return *this;
        delete[] datos;
        n = otro.n;
        datos = new int[n];
        for (std::size_t i = 0; i < n; ++i) {
            datos[i] = otro.datos[i];
        }
        return *this;
    }

    ~Arreglo() {
        delete[] datos;
    }

    void set(std::size_t idx, int val) { datos[idx] = val; }
    int get(std::size_t idx) const { return datos[idx]; }
    std::size_t tam() const { return n; }
};

int main() {
    Arreglo a(5);
    a.set(0, 10);

    Arreglo b = a;  // Copia profunda
    b.set(0, 99);

    std::cout << "a[0]: " << a.get(0) << " (debe ser 10)\n";
    std::cout << "b[0]: " << b.get(0) << " (debe ser 99)\n";

    return 0;
}