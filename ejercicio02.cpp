#include "pch.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace System;

const int ANCHO = 80;
const int ALTO = 30;

// ----------------------------------
// UTILITARIOS DE CONSOLA
// ----------------------------------

void ubicar(int x, int y) {
    Console::SetCursorPosition(x, y);
}


void colorTexto(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void ventana() {
    Console::SetWindowSize(ANCHO, ALTO);
    Console::CursorVisible = false;
}

// ----------------------------------
// FUNCIONES DE JUEGO
// ----------------------------------

void borrar(int x, int y) {
    for (int i = 0; i < 4; i++) {
        ubicar(x, y + i);
        cout << "      ";
    }
}

// artId: 1 = bloque 1 (verde aleatorio), 2 = bloque 2 (rojo aleatorio)
void dibujar(int x, int y, int artId) {
    int color = (artId == 1) ? (10 + rand() % 5) : (12 + rand() % 2);
    colorTexto(color);
    for (int i = 0; i < 4; i++) {
        ubicar(x, y + i);
        cout << string(5, char(219));
    }
    colorTexto(7); // restaurar color
}

void moverManual(int& x, int& y, char tecla) {
    if (tecla == 'w' && y > 1) y--;
    else if (tecla == 's' && y < ALTO - 5) y++;
    else if (tecla == 'a' && x > 0) x--;
    else if (tecla == 'd' && x < ANCHO - 6) x++;
}

void moverAutomatico(int& x, int& y) {
    x++;
    if (x > ANCHO - 6) x = 0;
}

// ----------------------------------
// FUNCIONES VISUALES
// ----------------------------------

void cargando() {
    colorTexto(11);
    ubicar(30, 14); cout << "Cargando...";
    colorTexto(9);
    ubicar(30, 15);
    for (int i = 0; i < 30; i++) {
        cout << char(219);
        Sleep(60);
    }
    colorTexto(7);
    Sleep(500);
    system("cls");
}

void presentacion() {
    ventana();
    colorTexto(11);
    ubicar(25, 8);  cout << "BIENVENIDOS AL TALLER DE FUNCIONES";
    ubicar(25, 10);  cout << "Henry Antonio Mendoza Puerta (HAMP)";
    ubicar(20, 12); cout << "Simulador de movimiento de bloques en consola";
    ubicar(24, 14); cout << "Presiona cualquier tecla para comenzar...";
    colorTexto(7);
    _getch(); // espera de usuario
    system("cls");
    cargando();
}

// ----------------------------------
// FUNCION PRINCIPAL DE JUEGO
// ----------------------------------

void juego() {
    int x1 = 10, y1 = 10;
    int x2 = 50, y2 = 20;
    bool activo = false;

    while (true) {
        // BLOQUE 1 (Manual)
        if (_kbhit()) {
            char tecla = _getch();
            if (tecla == ' ') activo = true;
            borrar(x1, y1);
            moverManual(x1, y1, tecla);
        }

        // BLOQUE 2 (Automático)
        borrar(x2, y2);
        if (activo) moverAutomatico(x2, y2);

        // Dibujar ambos bloques
        dibujar(x1, y1, 1);
        if (activo) dibujar(x2, y2, 2);

        // Coordenadas
        colorTexto(14);
        ubicar(0, 0);
        cout << "BLOQUE 1 [WASD] - X1: " << x1 << "  Y1: " << y1 << "    ";
        ubicar(0, 1);
        cout << "BLOQUE 2 [Auto] - X2: " << x2 << "  Y2: " << y2 << "    ";
        colorTexto(7);

        Sleep(120);
    }
}

// ----------------------------------
// MAIN
// ----------------------------------

int main() {
    srand(time(0));    
    presentacion();    
    juego();  
    system("pause>NULL");  
    return 0;
}
