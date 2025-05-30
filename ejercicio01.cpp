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