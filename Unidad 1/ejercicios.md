# Ejercicios - Unidad 2 (Punteros y TAD)

## Indicaciones generales
- Intenta resolver sin mirar apuntes en la primera pasada.
- En cada ejercicio explica brevemente *por que* elegiste esa solucion.
- Si programas en C/C++, valida casos borde.

---

## Nivel 1 - Conceptos rapidos

### 1) Verdadero o falso (justifica)
1. Un puntero guarda directamente el valor de una variable.
2. `*p` devuelve una direccion de memoria.
3. La memoria dinamica se reserva en tiempo de ejecucion.
4. Dos punteros iguales (`p1 == p2`) siempre apuntan al mismo valor logico.
5. Un TAD define operaciones independientemente de su implementacion.

### 2) Completa los espacios
1. El operador `___` obtiene la direccion de una variable.
2. El operador `___` accede al valor apuntado.
3. En C++, la memoria dinamica se libera con `___`.
4. Un TAD se divide en `___` e `___`.

### 3) Relaciona columnas
- Columna A: Arreglo, Lista enlazada, TAD, `int **pp`
- Columna B:
  - Estructura concreta de tamano dinamico.
  - Direccion de un puntero.
  - Implementacion con memoria contigua.
  - Tipo conceptual con operaciones.

---

## Nivel 2 - Traza y razonamiento

### 4) Rastreo de punteros
Dado:
```cpp
int x = 10;
int *p = &x;
int **pp = &p;
*p = 20;
```
Responde:
1. Valor de `x`
2. Valor de `*p`
3. Valor de `**pp`
4. Que representa `pp`

### 5) Error spotting (detectar errores)
Analiza y marca errores conceptuales:
```cpp
int *p;
*p = 5;
delete p;
```
Preguntas:
1. Que problema hay antes de `*p = 5`?
2. Que riesgo existe en `delete p`?
3. Como deberia corregirse minimamente?

### 6) Estatica vs dinamica
Para cada caso, indica si conviene memoria estatica o dinamica y por que:
1. Vector de 100 notas siempre fijo.
2. Lista de usuarios cuyo tamano cambia constantemente.
3. Matriz de tamano desconocido hasta leer archivo.

---

## Nivel 3 - Diseno de TAD

### 7) Diseña el TAD `CuentaBancaria`
Define:
- Datos internos minimos.
- Operaciones de interfaz (al menos 6).
- Especificacion sintactica de 3 operaciones.
- Especificacion semantica de esas 3 operaciones.

### 8) Encapsulamiento
Explica con tus palabras:
1. Que problema evita ocultar la implementacion.
2. Que pasaria si todos los atributos fueran publicos.
3. Por que eso afecta mantenimiento y pruebas.

### 9) Elegir estructura
Elige y justifica estructura para cada caso:
1. Historial de navegacion (atras/adelante).
2. Cola de impresion.
3. Jerarquia de carpetas.
4. Red de ciudades conectadas por rutas.

---

## Nivel 4 - Programacion (C/C++)

### 10) Implementa lista enlazada simple
Requisitos:
- Nodo con `dato` y `siguiente`.
- Operaciones: insertar al inicio, eliminar primer ocurrencia, buscar, imprimir.
- Incluye pruebas con al menos 8 operaciones combinadas.

### 11) Matriz dinamica con puntero de puntero
Implementa:
1. Reserva dinamica de matriz `n x m` con `int **`.
2. Carga de valores.
3. Suma por filas.
4. Liberacion completa de memoria sin fugas.

### 12) TAD `Auto` (basado en clase)
Implementa interfaz y uso:
- `inicializarAuto`, `encenderMotor`, `apagarMotor`, `acelerar`, `frenar`, `repostar`.
- Reglas:
  - no acelerar con motor apagado,
  - no acelerar sin combustible,
  - velocidad no negativa.
- Muestra salida de prueba paso a paso.

---

## Desafios extra (opcional)

### 13) Complejidad
Compara costo temporal (aprox.) de:
- acceso por indice en arreglo,
- busqueda lineal en lista,
- insercion al inicio en lista.

### 14) Refactor TAD
Toma un programa procedural que use variables globales y conviertelo en un TAD con interfaz clara.

### 15) Pregunta oral corta (autoevaluacion)
Explica en 2 minutos:
1. Diferencia entre TAD y estructura de datos.
2. Por que `**` es util en funciones.
3. Un bug tipico de memoria dinamica y como prevenirlo.

---

## Mini guia de correccion (para autoevaluarte)
- Solucion correcta tecnicamente.
- Justificacion clara de decisiones.
- Uso coherente de punteros y memoria dinamica.
- Respeto de encapsulamiento en TAD.
- Casos borde contemplados.
