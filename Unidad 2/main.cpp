#include <iostream>
#include "CuentaBancaria.hpp"

int main() {
    CuentaBancaria cuentaA = CuentaBancaria::crearCuenta("Ana Perez", "0001");
    CuentaBancaria cuentaB = CuentaBancaria::crearCuenta("Luis Gomez", "0002");

    std::cout << "Cuenta A activa: " << cuentaA.estaActiva() << "\n";
    std::cout << "Cuenta B activa: " << cuentaB.estaActiva() << "\n\n";

    cuentaA.depositar(1000.0);
    cuentaA.extraer(200.0);
    cuentaA.transferir(cuentaB, 300.0);

    std::cout << "Saldo A: " << cuentaA.obtenerSaldo() << "\n";
    std::cout << "Saldo B: " << cuentaB.obtenerSaldo() << "\n\n";

    cuentaB.cerrarCuenta();
    bool depositoEnB = cuentaB.depositar(100.0); // Deberia fallar (cuenta cerrada)

    std::cout << "Cuenta B activa: " << cuentaB.estaActiva() << "\n";
    std::cout << "Deposito en B exitoso: " << depositoEnB << "\n";

    return 0;
}
