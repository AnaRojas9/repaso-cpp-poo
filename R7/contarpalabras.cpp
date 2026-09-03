#include <iostream>
#include <string>

int contarPalabras(const std::string& s) {
    int n = 0; bool dentro = false;
    for (char c : s) {
        if (c == ' ') dentro = false;
        else if (!dentro) { dentro = true; n++; }
    }
    return n;
}
std::string voltear(const std::string& s) {
    std::string r;
    for (std::size_t i = s.size(); i > 0; i--)
        r += s[i - 1];
    return r;
}

int main(){
    std::string texto;

    std::cout << "Ingresa una frase: ";
    std::getline(std::cin, texto);

    int totalPalabras = contarPalabras(texto);
    std::string textoInvertido = voltear(texto);

    std::cout << "Cantidad de palabras: " << totalPalabras << '\n';
    std::cout << "Cadena invertida: " << textoInvertido << '\n';

    return 0;

}