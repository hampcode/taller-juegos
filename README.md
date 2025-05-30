
# Taller de Funciones en Visual C++
![Visual C++](https://img.shields.io/badge/C%2B%2B-Visual%20C%2B%2B-blue)
![Status](https://img.shields.io/badge/Status-Stable-brightgreen)
![License](https://img.shields.io/badge/License-MIT-yellow)

**Autor:** Henry Antonio Mendoza Puerta (HAMP)  
**YouTube:** [https://www.youtube.com/hampcode](https://www.youtube.com/hampcode)  
**LinkedIn:** [www.linkedin.com/in/hampcode](https://www.linkedin.com/in/hampcode)



---

## Objetivo del Taller

El propósito de este taller es reforzar el uso de funciones en Visual C++ a través de ejercicios teórico-prácticos. El estudiante:

* Comprende la diferencia entre paso por valor y paso por referencia.
* Aprende a organizar la lógica de un programa en funciones.
* Aplica funciones para diseñar un simulador interactivo.
* Se prepara para extender proyectos usando arreglos, matrices y estructuras.

---

## Ejercicio 1 - Paso por Valor y Paso por Referencia

### Enunciado

Analizar el comportamiento de una variable al ser pasada a una función por valor y por referencia.

![Paso por valor vs referencia](https://i0.wp.com/somoshackersdelaprogramacion.es/wp-content/uploads/2022/05/java-reference-value.gif?resize=500%2C241&ssl=1)

### Código

```cpp
#include "pch.h"
#include <iostream>
using namespace std;
using namespace System;

// Paso por valor
void recibirNumeroValor(int a) {
    a = 200;
    cout << "[VALOR] a en recibirNumeroValor: " << a << " Direccion = " << &a << endl;
}

// Paso por referencia
void recibirNumeroReferencia(int& a) {
    a = 200;
    cout << "[REFERENCIA] a en recibirNumeroReferencia: " << a << " Direccion = " << &a << endl;
}

int main() {
    int a = 10;

    cout << "== PASO POR VALOR ==\n";
    recibirNumeroValor(a);
    cout << "a en main: " << a << " Direccion = " << &a << endl;

    cout << "\n== PASO POR REFERENCIA ==\n";
    recibirNumeroReferencia(a);
    cout << "a en main: " << a << " Direccion = " << &a << endl;

    system("pause>NULL");
    return 0;
}
```

### Resultado Esperado

* En el paso por valor, el valor de `a` dentro de la función cambia, pero en `main` permanece igual.
* En el paso por referencia, el valor de `a` cambia tanto dentro como fuera de la función, compartiendo dirección de memoria.

---

## Ejercicio 2 - Simulador de Movimiento de Bloques

### Enunciado

Crear un juego en consola que simule el movimiento de dos bloques usando funciones:

* Bloque 1: controlado por el jugador con las teclas `W`, `A`, `S`, `D`.
* Bloque 2: movimiento automático tras presionar la barra espaciadora.
* Los bloques cambian de color aleatoriamente.
* Se incluye presentación, barra de carga y coordenadas visibles.

### Código resumido

> El código completo se encuentra en `ejercicio01.cpp`. A continuación, un resumen de las funcionalidades clave.

```cpp
void presentacion();       // Muestra pantalla inicial y autor
void cargando();           // Simula barra de carga animada
void juego();              // Ejecuta el simulador completo

void dibujar(int x, int y, int artId);          // Dibuja el bloque
void borrar(int x, int y);                      // Borra el bloque anterior
void moverManual(int& x, int& y, char tecla);   // Movimiento por teclado
void moverAutomatico(int& x, int& y);           // Movimiento automático
```

---

## Funcionalidades del Juego y Funciones Asociadas

| Funcionalidad que el juego permite realizar                          | Función y parámetros                      | Descripción de la función                                            |
| -------------------------------------------------------------------- | ----------------------------------------- | -------------------------------------------------------------------- |
| El jugador podrá mover el bloque 1 con WASD                          | `moverManual(int& x, int& y, char tecla)` | Cambia coordenadas del bloque según la tecla presionada              |
| El bloque 2 se moverá automáticamente tras presionar espacio         | `moverAutomatico(int& x, int& y)`         | Desplaza el bloque automáticamente hacia la derecha                  |
| Los bloques se dibujan visualmente en consola con colores aleatorios | `dibujar(int x, int y, int artId)`        | Representa un bloque gráfico con color según su tipo                 |
| El juego borra la posición anterior del bloque antes de moverlo      | `borrar(int x, int y)`                    | Limpia la región ocupada por el bloque antes del siguiente dibujo    |
| El jugador verá una pantalla inicial con título del taller           | `presentacion()`                          | Muestra un mensaje de bienvenida con pausa antes de empezar el juego |
| Se mostrará una barra animada de "cargando"                          | `cargando()`                              | Simula un proceso de carga visual con bloques                        |
| Se ejecutará todo el flujo del juego                                 | `juego()`                                 | Contiene el ciclo principal, dibujo, entrada y lógica de bloques     |
| Se configurará la consola para el entorno visual                     | `ventana()`                               | Establece dimensiones y oculta el cursor para mejor visualización    |

---

## Controles del Usuario

* `W` - Mover bloque 1 hacia arriba
* `S` - Mover bloque 1 hacia abajo
* `A` - Mover bloque 1 hacia la izquierda
* `D` - Mover bloque 1 hacia la derecha
* `ESPACIO` - Activar bloque 2 (automático)

---

## Requisitos Técnicos

* Sistema operativo: Windows
* IDE: Visual Studio Community
* Nivel: Principiante - Intermedio (ideal para reforzar funciones y lógica estructurada)

---

