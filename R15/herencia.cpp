#include <iostream>
#include <string>

// Clase Base 
class Persona {
protected:
    std::string nombre;

public:
    Persona(const std::string& n) : nombre(n) {
        std::cout << "Constructor Persona\n";
    }
    virtual ~Persona() { // Destructor virtual
        std::cout << "Destructor Persona\n";
    }
};

// Clase Derivada
class Empleado : public Persona {
protected:
    double salario;

public:
    Empleado(const std::string& n, double s) : Persona(n), salario(s) {
        std::cout << "Constructor Empleado\n";
    }
    ~Empleado() override {
        std::cout << "Destructor Empleado\n";
    }
};

// Clase Derivada
class Gerente : public Empleado {
private:
    int equipo;

public:
    Gerente(const std::string& n, double s, int eq) : Empleado(n, s), equipo(eq) {
        std::cout << "Constructor Gerente\n";
    }
    ~Gerente() override {
        std::cout << "Destructor Gerente\n";
    }
};

int main() {
    {
        // Se crea y se destruye al salir de las llaves {}
        Gerente g("Ana", 1000, 5);
    } 

    return 0;
}