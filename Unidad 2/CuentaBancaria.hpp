#ifndef CUENTA_BANCARIA_HPP
#define CUENTA_BANCARIA_HPP

#include <string>

class CuentaBancaria {
private:
    // Datos internos minimos del TAD
    std::string titular_;
    std::string numeroCuenta_;
    double saldo_;
    bool activa_;

    // Constructor privado para forzar la creacion mediante crearCuenta(...)
    CuentaBancaria(const std::string& titular, const std::string& numeroCuenta);

public:
    // Operacion de fabrica de la cuenta
    static CuentaBancaria crearCuenta(
        const std::string& titular,
        const std::string& numeroCuenta
    );

    // Operaciones principales del TAD
    bool depositar(double monto);
    bool extraer(double monto);
    bool transferir(CuentaBancaria& destino, double monto);
    double obtenerSaldo() const;
    bool estaActiva() const;
    void cerrarCuenta();

    // Consultas adicionales utiles para pruebas/impresion
    const std::string& obtenerTitular() const;
    const std::string& obtenerNumeroCuenta() const;
};

#endif
