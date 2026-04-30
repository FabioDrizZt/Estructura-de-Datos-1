#include <iostream>
#include "CuentaBancaria.hpp"

int main() {
    CuentaBancaria cuentaA = crearCuenta("Ana Perez", "0001");
    CuentaBancaria cuentaB = crearCuenta("Luis Gomez", "0002");

    std::cout << "Cuenta A activa: " << estaActiva(cuentaA) << "\n";
    std::cout << "Cuenta B activa: " << estaActiva(cuentaB) << "\n\n";

    depositar(cuentaA, 1000.0);
    extraer(cuentaA, 200.0);
    transferir(cuentaA, cuentaB, 300.0);

    std::cout << "Saldo A: " << obtenerSaldo(cuentaA) << "\n";
    std::cout << "Saldo B: " << obtenerSaldo(cuentaB) << "\n\n";

    cerrarCuenta(cuentaB);
    bool depositoEnB = depositar(cuentaB, 100.0); // Deberia fallar (cuenta cerrada)

    std::cout << "Cuenta B activa: " << estaActiva(cuentaB) << "\n";
    std::cout << "Deposito en B exitoso: " << depositoEnB << "\n";

    return 0;
}
