#ifndef CUENTA_BANCARIA_HPP
#define CUENTA_BANCARIA_HPP

#include <string>

// TAD implementado con struct
struct CuentaBancaria {
    std::string titular;
    std::string numeroCuenta;
    double saldo;
    bool activa;
};

// Operaciones de interfaz del TAD
CuentaBancaria crearCuenta(const std::string& titular, const std::string& numeroCuenta);
bool depositar(CuentaBancaria& cuenta, double monto);
bool extraer(CuentaBancaria& cuenta, double monto);
bool transferir(CuentaBancaria& origen, CuentaBancaria& destino, double monto);
double obtenerSaldo(const CuentaBancaria& cuenta);
bool estaActiva(const CuentaBancaria& cuenta);
void cerrarCuenta(CuentaBancaria& cuenta);

#endif
