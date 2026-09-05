struct Cuenta {
    void depositar(double x);
};

int main() {
    Cuenta c;
    c.depositar(50.0); // Declarado pero sin cuerpo definido
    return 0;
}