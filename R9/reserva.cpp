#include <iostream>
#include <string>

class Reserva {
public:
    bool asignarSala(const std::string& s) {
        if (s.empty()) return false;
        sala = s;
        return true;
    }

    bool asignarPersonas(int p) {
        if (p < 1 || p > 20) return false;
        personas = p; 
        return true;
    }

    bool asignarHorario(int ini, int fin) {   // los dos juntos
        if (ini < 0 || fin > 23 || ini >= fin) return false;
        horaInicio = ini; 
        horaFin = fin; 
        return true;
    }

    // Getters para consultar los datos
    void mostrarReserva() const {
        std::cout << "Sala: " << sala 
                  << " | Personas: " << personas 
                  << " | Horario: " << horaInicio << ":00 - " << horaFin << ":00\n";
    }

private:
    std::string sala = "A1";
    int personas = 1;
    int horaInicio = 8, horaFin = 9;
};

int main() {
    Reserva r;

    std::cout << "--- Estado inicial por defecto ---\n";
    r.mostrarReserva();
    std::cout << "\n";

    // Prueba 1: Asignación válida
    std::cout << "--- Intentando cambios validos ---\n";
    if (r.asignarPersonas(10) && r.asignarHorario(14, 16) && r.asignarSala("B-202")) {
        std::cout << "Reserva actualizada con exito.\n";
    } else {
        std::cout << "Error al actualizar la reserva.\n";
    }
    r.mostrarReserva();
    std::cout << "\n";

    // Prueba 2: Intento con datos inválidos (inv. 3: inicio > fin)
    std::cout << "--- Intentando horario invalido (18 a 15) ---\n";
    if (!r.asignarHorario(18, 15)) {
        std::cout << "[RECHAZADO] No se puede asignar inicio >= fin.\n";
    }
    
    // Prueba 3: Intento con personas fuera de rango (> 20)
    std::cout << "--- Intentando 30 personas ---\n";
    if (!r.asignarPersonas(30)) {
        std::cout << "[RECHAZADO] Las personas deben estar entre 1 y 20.\n";
    }

    std::cout << "\n--- Estado final (mantiene valores validos) ---\n";
    r.mostrarReserva();

    return 0;
}