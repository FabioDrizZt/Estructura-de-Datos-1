#include "CuentaBancaria.hpp"

CuentaBancaria crearCuenta(const std::string& titular, const std::string& numeroCuenta) {
    CuentaBancaria cuenta;
    cuenta.titular = titular;
    cuenta.numeroCuenta = numeroCuenta;
    cuenta.saldo = 0.0;
    cuenta.activa = true;
    return cuenta;
}

bool depositar(CuentaBancaria& cuenta, double monto) {
    if (!cuenta.activa || monto <= 0.0) {
        return false;
    }
    cuenta.saldo += monto;
    return true;
}

bool extraer(CuentaBancaria& cuenta, double monto) {
    if (!cuenta.activa || monto <= 0.0 || monto > cuenta.saldo) {
        return false;
    }
    cuenta.saldo -= monto;
    return true;
}

bool transferir(CuentaBancaria& origen, CuentaBancaria& destino, double monto) {
    if (&origen == &destino) {
        return false;
    }

    if (!origen.activa || !destino.activa || monto <= 0.0 || monto > origen.saldo) {
        return false;
    }

    origen.saldo -= monto;
    destino.saldo += monto;
    return true;
}

double obtenerSaldo(const CuentaBancaria& cuenta) {
    return cuenta.saldo;
}

bool estaActiva(const CuentaBancaria& cuenta) {
    return cuenta.activa;
}

void cerrarCuenta(CuentaBancaria& cuenta) {
    cuenta.activa = false;
}
