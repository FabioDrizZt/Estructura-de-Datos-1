#include "CuentaBancaria.hpp"

CuentaBancaria::CuentaBancaria(const std::string& titular, const std::string& numeroCuenta)
    : titular_(titular), numeroCuenta_(numeroCuenta), saldo_(0.0), activa_(true) {}

CuentaBancaria CuentaBancaria::crearCuenta(const std::string& titular, const std::string& numeroCuenta) {
    return CuentaBancaria(titular, numeroCuenta);
}

bool CuentaBancaria::depositar(double monto) {
    if (!activa_ || monto <= 0.0) {
        return false;
    }
    saldo_ += monto;
    return true;
}

bool CuentaBancaria::extraer(double monto) {
    if (!activa_ || monto <= 0.0 || monto > saldo_) {
        return false;
    }
    saldo_ -= monto;
    return true;
}

bool CuentaBancaria::transferir(CuentaBancaria& destino, double monto) {
    if (&destino == this) {
        return false;
    }

    if (!activa_ || !destino.activa_ || monto <= 0.0 || monto > saldo_) {
        return false;
    }

    saldo_ -= monto;
    destino.saldo_ += monto;
    return true;
}

double CuentaBancaria::obtenerSaldo() const {
    return saldo_;
}

bool CuentaBancaria::estaActiva() const {
    return activa_;
}

void CuentaBancaria::cerrarCuenta() {
    activa_ = false;
}

const std::string& CuentaBancaria::obtenerTitular() const {
    return titular_;
}

const std::string& CuentaBancaria::obtenerNumeroCuenta() const {
    return numeroCuenta_;
}
