#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

struct ParPalabra {
    std::string palabra;
    int conteo;
};

int main() {
    std::vector<std::string> palabras = {"uno", "dos", "tres", "dos", "tres", "uno"};

    std::vector<ParPalabra> conteoVector;
    for (const std::string& w : palabras) {
        bool encontrada = false;
        for (auto& par : conteoVector) {
            if (par.palabra == w) {
                par.conteo++;
                encontrada = true;
                break;
            }
        }
        if (!encontrada) {
            conteoVector.push_back({w, 1});
        }
    }

    std::cout << "--- CON VECTOR ---\n";
    for (const auto& par : conteoVector) {
        std::cout << par.palabra << ": " << par.conteo << "\n";
    }

    std::map<std::string, int> conteoMap;
    for (const std::string& w : palabras) {
        conteoMap[w]++;
    }

    std::cout << "\n--- CON MAP ---\n";
    for (const auto& [palabra, cantidad] : conteoMap) {
        std::cout << palabra << ": " << cantidad << "\n";
    }

    std::set<std::string> distintas(palabras.begin(), palabras.end());

    std::cout << "\n--- CON SET ---\n";
    std::cout << "Cantidad de palabras distintas: " << distintas.size() << "\n";

    return 0;
}

//¿Cuál conviene?: std::map, ya que mantiene la relación clave-valor con una excelente eficiencia
//¿Cuándo cambiaría de opinión?:Usaría std::unordered_map si el volumen de datos fuera masivo y no me interesara 
//mantener las palabras ordenadas alfabéticamente, ya que reduce la búsqueda a promedio
// y usaría std::set si el requisito cambiara a únicamente saber cuántas palabras diferentes existen sin importar 
//cuántas veces se repiten.