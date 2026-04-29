# Cheatsheet - Unidad 2 (Punteros y TAD)

## 1) Punteros: idea central
- Un **puntero** es una variable que guarda una **direccion de memoria** de otra variable.
- Permite acceder y modificar datos sin copiarlos.
- Es clave para:
  - memoria dinamica,
  - estructuras de datos complejas,
  - paso eficiente de parametros,
  - programacion de bajo nivel.

## 2) Operadores fundamentales
- `&x` -> obtiene la direccion de `x`.
- `*p` -> accede al valor apuntado por `p` (indireccion).
- `p2 = p1` -> ambos punteros apuntan a la misma direccion.
- `p1 == p2` / `p1 != p2` -> compara direcciones, no valores.

## 3) Memoria estatica vs dinamica
### Estatica
- Se reserva en compilacion.
- Tamano fijo.
- Ejemplos: `int x;`, `int arr[10];`
- Gestionada automaticamente por el compilador.

### Dinamica
- Se reserva en ejecucion.
- Tamano flexible.
- C++: `new` / `delete`
- C: `malloc()` / `free()`
- Requiere gestion manual (evitar fugas y accesos invalidos).

## 4) Puntero de puntero (`**`)
- `int **pp` guarda la direccion de un `int *`.
- Niveles:
  - `p` -> direccion de `x`
  - `pp` -> direccion de `p`
  - `**pp` -> valor final (`x`)
- Usos:
  - modificar punteros en funciones,
  - matrices dinamicas,
  - estructuras jerarquicas (arboles, grafos).

## 5) Tipos de datos: mapa mental
- **Tipos elementales**: `int`, `float/double`, `char`, `bool`.
- **TAD (Tipo Abstracto de Datos)**: define *que* operaciones existen, no *como* se implementan.
  - Ej: Pila (LIFO), Cola (FIFO), Conjunto.
- **Estructura de datos**: implementacion concreta del TAD en memoria.
  - Ej: arreglos, listas enlazadas, arboles, tablas hash, grafos.

## 6) Que es un TAD
- Combina:
  - datos (estructura propia),
  - operaciones (funciones/metodos sobre esos datos).
- Se separa en:
  - **Interfaz** (publica): lo que el usuario puede usar.
  - **Implementacion** (privada): como esta hecho internamente.

## 7) Caracteristicas clave de los TAD
- **Encapsulamiento**: ocultar detalles internos.
- **Proteccion**: acceso solo via operaciones definidas.
- **Abstraccion**: modela lo relevante del problema.
- **Compilacion separada**: interfaz e implementacion desacopladas.

## 8) Especificacion de operaciones en un TAD
Para cada operacion hay que definir:
- **Sintaxis**:
  - nombre,
  - parametros de entrada/salida,
  - tipos,
  - valor retornado.
- **Semantica**:
  - efecto que produce la operacion.

## 9) Ventajas de trabajar con TAD
- Modularidad.
- Mejor legibilidad y mantenimiento.
- Reuso y extensibilidad.
- Facilita pruebas y verificacion.
- Permite prototipar primero y optimizar despues.
- Menor dependencia de una implementacion puntual.

## 10) Estructuras de datos vistas
### Arreglos
- Memoria contigua.
- Acceso por indice en `O(1)`.
- Tamano fijo (si son estaticos).

### Listas enlazadas
- Nodos con dato + puntero.
- Tamano dinamico.
- Insercion/eliminacion eficiente sin mover bloques grandes.

### Arboles y grafos
- Nodos con punteros a varios nodos.
- Modelan jerarquias y redes.
- Base de busquedas eficientes.

## 11) Relacion jerarquica importante
1. Tipos elementales (`int`, `char`, etc.).
2. TAD conceptuales (Pila, Cola, Conjunto).
3. Estructuras concretas (arreglo, lista, arbol, etc.) que implementan esos TAD.

## 12) Checklist para examen / practica
- [ ] Diferencio puntero, direccion y valor apuntado.
- [ ] Uso correctamente `&` y `*`.
- [ ] Distingo memoria estatica y dinamica.
- [ ] Entiendo `puntero a puntero` y cuando usarlo.
- [ ] Puedo explicar que es un TAD con interfaz e implementacion.
- [ ] Puedo justificar ventajas de encapsulamiento.
- [ ] Se elegir estructura segun necesidad (`O(1)` acceso vs inserciones dinamicas).

## 13) Mini ejemplo conceptual (TAD Auto)
- **Atributos**: marca, modelo, combustible, velocidad, estado motor.
- **Operaciones**: encender, apagar, acelerar, frenar, repostar, consultar estado.
- La idea TAD: el usuario usa operaciones, no manipula libremente el estado interno.
