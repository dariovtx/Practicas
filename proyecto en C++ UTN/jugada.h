#ifndef JUGADA_H
#define JUGADA_H

#include <iostream>
#include <windows.h>
#include <stdio.h> 
#include <sstream>
#include <cctype>
#include <ctime>
#include <cstdlib>
#define Tam 3
#define filasT 16
#define columnasT 30
#include <string>
using namespace std;



int aleatorioEnRango(int minimo, int maximo);
int valorValido (string a);
void colocarMinasAleatoriamente(char tablero[filasT][columnasT],int maximofila, int maximocolumna, int cantidadminas);
void colocarMina(int fila, int columna, char tablero[filasT][columnasT]);
void jugada (char matriz[filasT][columnasT], char matrizvisible[filasT][columnasT], int maximofila, int maximocolumna, int minas, int contadorPart[Tam],int &tiempo);
void mostrarMatriz (char matriz[filasT][columnasT], int fila, int columna);

#endif
