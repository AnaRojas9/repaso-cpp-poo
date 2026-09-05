#ifndef ARREGLO_H
#define ARREGLO_H

class Arreglo {
private:
    int* datos;
    int tam;

public:
    // 1. Constructor
    Arreglo(int t) : tam(t), datos(new int[t]) {}

    // 2. Destructor
    ~Arreglo() { delete[] datos; }

    // 3. Constructor de copia
    Arreglo(const Arreglo& otro) : tam(otro.tam), datos(new int[otro.tam]) {
        for (int i = 0; i < tam; ++i) datos[i] = otro.datos[i];
    }

    // 4. Operador de asignacion
    Arreglo& operator=(const Arreglo& otro) {
        if (this != &otro) {
            delete[] datos;
            tam = otro.tam;
            datos = new int[tam];
            for (int i = 0; i < tam; ++i) datos[i] = otro.datos[i];
        }
        return *this;
    }
};

#endif