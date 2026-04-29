# Ejercicios Resueltos - Unidad 2 (Punteros y TAD)

## Nivel 1 - Conceptos rapidos

### 1) Verdadero o falso (justifica)
1. **Falso**. Un puntero guarda una **direccion**, no el valor directo.
2. **Falso**. `*p` devuelve/accede al **valor apuntado**, no a la direccion.
3. **Verdadero**. La memoria dinamica se reserva durante la ejecucion.
4. **Verdadero** (en direccion). Si `p1 == p2`, apuntan a la misma direccion.
5. **Verdadero**. Un TAD define operaciones y comportamiento, no detalles internos.

### 2) Completa los espacios
1. El operador `&` obtiene la direccion de una variable.
2. El operador `*` accede al valor apuntado.
3. En C++, la memoria dinamica se libera con `delete`.
4. Un TAD se divide en `interfaz` e `implementacion`.

### 3) Relaciona columnas
- Arreglo -> Implementacion con memoria contigua.
- Lista enlazada -> Estructura concreta de tamano dinamico.
- TAD -> Tipo conceptual con operaciones.
- `int **pp` -> Direccion de un puntero.

---

## Nivel 2 - Traza y razonamiento

### 4) Rastreo de punteros
Codigo:
```cpp
int x = 10;
int *p = &x;
int **pp = &p;
*p = 20;
```
Respuestas:
1. Valor de `x`: **20**
2. Valor de `*p`: **20**
3. Valor de `**pp`: **20**
4. `pp` representa la direccion de `p` (puntero a puntero).

### 5) Error spotting
Codigo:
```cpp
int *p;
*p = 5;
delete p;
```
Respuestas:
1. `p` no esta inicializado; desreferenciarlo (`*p = 5`) es comportamiento indefinido.
2. `delete p` es riesgoso porque `p` no apunta a memoria reservada con `new`.
3. Correccion minima:
```cpp
int *p = new int;
*p = 5;
delete p;
p = nullptr;
```

### 6) Estatica vs dinamica
1. Vector de 100 notas fijo -> **Estatica** (tamano conocido y constante).
2. Lista de usuarios variable -> **Dinamica** (tamano cambia en ejecucion).
3. Matriz de tamano desconocido -> **Dinamica** (se conoce luego de leer datos).

---

## Nivel 3 - Diseno de TAD

### 7) TAD `CuentaBancaria`
#### Datos internos minimos
- `titular`
- `cbu` o `numeroCuenta`
- `saldo`
- `activa` (bool)

#### Operaciones de interfaz (ejemplo)
- `crearCuenta(...)`
- `depositar(...)`
- `extraer(...)`
- `transferir(...)`
- `obtenerSaldo(...)`
- `estaActiva(...)`
- `cerrarCuenta(...)`

#### Especificacion sintactica (3 operaciones)
1. `void depositar(CuentaBancaria &c, double monto);`
2. `bool extraer(CuentaBancaria &c, double monto);`
3. `double obtenerSaldo(const CuentaBancaria &c);`

#### Especificacion semantica (3 operaciones)
1. `depositar`: suma `monto` al saldo si `monto > 0` y cuenta activa.
2. `extraer`: resta `monto` si hay fondos suficientes y cuenta activa; retorna `true` si pudo.
3. `obtenerSaldo`: devuelve el saldo actual sin modificar estado.

### 8) Encapsulamiento
1. Evita que codigo externo rompa invariantes internas (ej: saldo negativo sin control).
2. Si todo es publico, cualquier parte del sistema puede dejar el objeto inconsistente.
3. Eso complica mantenimiento, pruebas y depuracion por acoplamiento alto.

### 9) Elegir estructura
1. Historial atras/adelante -> **Dos pilas**.
2. Cola de impresion -> **Cola (FIFO)**.
3. Jerarquia de carpetas -> **Arbol**.
4. Red de ciudades y rutas -> **Grafo**.

---

## Nivel 4 - Programacion (C/C++)

### 10) Lista enlazada simple (solucion ejemplo)
```cpp
#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* sig;
};

void insertarInicio(Nodo*& head, int v) {
    Nodo* n = new Nodo{v, head};
    head = n;
}

bool eliminarPrimeraOcurrencia(Nodo*& head, int v) {
    Nodo* ant = nullptr;
    Nodo* act = head;
    while (act) {
        if (act->dato == v) {
            if (ant) ant->sig = act->sig;
            else head = act->sig;
            delete act;
            return true;
        }
        ant = act;
        act = act->sig;
    }
    return false;
}

bool buscar(Nodo* head, int v) {
    while (head) {
        if (head->dato == v) return true;
        head = head->sig;
    }
    return false;
}

void imprimir(Nodo* head) {
    while (head) {
        cout << head->dato << " -> ";
        head = head->sig;
    }
    cout << "NULL\n";
}

void liberar(Nodo*& head) {
    while (head) {
        Nodo* t = head;
        head = head->sig;
        delete t;
    }
}

int main() {
    Nodo* head = nullptr;
    insertarInicio(head, 10);
    insertarInicio(head, 20);
    insertarInicio(head, 30);
    imprimir(head);                 // 30 -> 20 -> 10 -> NULL
    cout << buscar(head, 20) << "\n"; // 1
    cout << buscar(head, 99) << "\n"; // 0
    eliminarPrimeraOcurrencia(head, 20);
    imprimir(head);                 // 30 -> 10 -> NULL
    eliminarPrimeraOcurrencia(head, 30);
    imprimir(head);                 // 10 -> NULL
    liberar(head);
}
```

### 11) Matriz dinamica con `int **` (solucion ejemplo)
```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 3, m = 4;
    int** mat = new int*[n];
    for (int i = 0; i < n; i++) mat[i] = new int[m];

    int val = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mat[i][j] = val++;

    for (int i = 0; i < n; i++) {
        int suma = 0;
        for (int j = 0; j < m; j++) suma += mat[i][j];
        cout << "Suma fila " << i << ": " << suma << "\n";
    }

    for (int i = 0; i < n; i++) delete[] mat[i];
    delete[] mat;
    mat = nullptr;
}
```

### 12) TAD `Auto` (solucion base)
```cpp
#include <iostream>
#include <cstring>
using namespace std;

struct Auto {
    char marca[50];
    char modelo[50];
    double nivelCombustible;
    double velocidad;
    bool motorEncendido;
};

void inicializarAuto(Auto &a, const char* marca, const char* modelo) {
    strncpy(a.marca, marca, sizeof(a.marca));
    a.marca[sizeof(a.marca)-1] = '\0';
    strncpy(a.modelo, modelo, sizeof(a.modelo));
    a.modelo[sizeof(a.modelo)-1] = '\0';
    a.nivelCombustible = 0;
    a.velocidad = 0;
    a.motorEncendido = false;
}

void encenderMotor(Auto &a) { a.motorEncendido = true; }
void apagarMotor(Auto &a) {
    a.motorEncendido = false;
    a.velocidad = 0;
}

void repostar(Auto &a, double cantidad) {
    if (cantidad > 0) a.nivelCombustible += cantidad;
    if (a.nivelCombustible > 100) a.nivelCombustible = 100;
}

void acelerar(Auto &a, double cantidad) {
    if (!a.motorEncendido) return;
    if (a.nivelCombustible <= 0) return;
    if (cantidad > 0) {
        a.velocidad += cantidad;
        a.nivelCombustible -= cantidad * 0.1;
        if (a.nivelCombustible < 0) a.nivelCombustible = 0;
    }
}

void frenar(Auto &a, double cantidad) {
    if (cantidad > 0) {
        a.velocidad -= cantidad;
        if (a.velocidad < 0) a.velocidad = 0;
    }
}

int main() {
    Auto a;
    inicializarAuto(a, "Ford", "Fiesta");
    acelerar(a, 20); // no acelera (motor apagado)
    encenderMotor(a);
    acelerar(a, 20); // no acelera (sin combustible)
    repostar(a, 40);
    acelerar(a, 30);
    frenar(a, 10);
    apagarMotor(a);

    cout << "Velocidad final: " << a.velocidad << "\n";
    cout << "Combustible final: " << a.nivelCombustible << "\n";
    cout << "Motor encendido: " << a.motorEncendido << "\n";
}
```

---

## Desafios extra (resueltos)

### 13) Complejidad
- Acceso por indice en arreglo: **O(1)**.
- Busqueda lineal en lista: **O(n)**.
- Insercion al inicio en lista: **O(1)**.

### 14) Refactor a TAD (idea de solucion)
- Tomar variables globales y moverlas a una `struct`/`class`.
- Exponer solo funciones de interfaz.
- Ocultar detalles internos y validar precondiciones en cada operacion.

### 15) Respuesta oral modelo (2 minutos)
1. **TAD vs estructura**: TAD dice que operaciones existen y su comportamiento; estructura define como se guarda en memoria.
2. **Utilidad de `**`**: permite modificar un puntero desde una funcion y crear estructuras dinamicas de mas de un nivel.
3. **Bug tipico**: fuga de memoria (olvidar `delete`/`free`) o acceso a puntero no inicializado; se previene inicializando, liberando y usando `nullptr`.

---

## Consejo final de estudio
Si dominas esta cadena, ya estas muy bien:  
**direccion -> puntero -> memoria dinamica -> TAD -> estructura concreta -> complejidad**.
