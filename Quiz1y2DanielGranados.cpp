/* Quiz #1 y #2 Estructuras de Datos
Nombre: Daniel Granados Retana
Carné: 2022104692
Profesor: Rodrigo Núñez
Fecha: 11 de agosto 2022
Utilizando arreglos en C++ escriba una estructura de datos que le permita modelar un tren de N vagones 
y escriba una función que reciba el tren por parámetro, luego liste los 10 primeros y los 10 últimos 
asientos disponibles. Eso hace que el tren por definición tenga alguna forma de marcar los asientos ya ocupados.*/

#include <iostream>
#include <algorithm>

/* La estructura de datos para modelar del tren es un arreglo.

   Definición de dimensiones del tren:
   El tren tiene tres dimensiones. La primera es para la cantidad de vagones, la segunda para la cantidad de filas
   y la tercera para la cantidad de asientos por fila, entonces se define un arreglo tridimensional para representar la estructura 
   de datos del tren. Este arreglo es de valores de tipo booleano, entonces un true sería que el asiento está ocupado y un false sería
   que el asiento está desocupado. 
*/

#define VAGONES 5
#define FILAS 3
#define ASIENTOS_FILA 4

using namespace std;

/* Función que recibe el arreglo del tren e imprime los 10 primeros asientos disponibles y los 10 últimos asientos disponibles.
Entrada: Arreglo del tren
Salidas: Asientos disponibles */
void asientosDisponibles(bool arreglo[VAGONES][FILAS][ASIENTOS_FILA]){
    cout << "Primeros asientos disponibles:" << endl;
    int contador = 0; // Variable para contar los asientos disponibles.

    // Se recorre el arreglo para imprimir los primeros 10 asientos disponibles.
    for (int vagon = 0; vagon < VAGONES; vagon++){ // Ciclo para los vagones
        for (int fila = 0; fila < FILAS; fila++){ // ciclo para las filas

            if (count(arreglo[vagon][fila], arreglo[vagon][fila] + ASIENTOS_FILA, false) == 0){
                // Se cuentan la cantidad de veces que hay un false en la fila.
                // Si esta cantidad es 0, es que la fila está llena, entonces no se recorre.
                continue;
            }
            for (int asiento = 0; asiento < ASIENTOS_FILA; asiento++){ // ciclo para los asientos
                if (arreglo[vagon][fila][asiento] == false){
                    // Si el elemento que está revisando está desocupado, lo imprime e incrementa el contador.
                    cout << "Vagón: " << vagon << "  Fila: " << fila  << "  Asiento: " << asiento << endl;
                    contador++;
                }
                if (contador == 10){
                    // si el contador es 10, iguala vagon y filas a sus constantes respectivas para
                    // hacer que se salga de los 3 for loops.
                    vagon = VAGONES;
                    fila = FILAS;
                    break;
                }
            }
        }
    }

    cout << "\nÚltimos asientos disponibles:" << endl;
    contador = 0; // se reinicia el contador

    // Ciclo para encontrar los últimos 10 espacios disponibles
    for (int vagon = VAGONES - 1; vagon >= 0; vagon--){ // Ciclo para vagones
        for (int fila = FILAS - 1; fila >= 0; fila--){ // Ciclo para filas
            if (count(arreglo[vagon][fila], arreglo[vagon][fila] + ASIENTOS_FILA, false) == 0){
                // Se cuentan la cantidad de veces que hay un false en la fila.
                // Si esta cantidad es 0, es que la fila está llena, entonces no se recorre.
                continue;
            }
            for (int asiento = ASIENTOS_FILA - 1; asiento >= 0; asiento--){ // Ciclo para asientos
                if (arreglo[vagon][fila][asiento] == false){
                    // Si el elemento que está revisando está desocupado, lo imprime e incrementa el contador.
                    cout << "Vagón: " << vagon << "  Fila: " << fila << "  Asiento: " << asiento << endl;
                    contador++;
                }
                if (contador == 10){ // Si el contador es 10, sale de la función.
                    return;
                }
            }
        }
    }
}

int main(){
    bool tren [VAGONES][FILAS][ASIENTOS_FILA] = {false}; // Se crea el tren con las dimensiones de las constantes y se llena con falsos.

    // tren[][][] = true;
    // Se asignan espacios ocupados del tren.
    tren[0][0][0] = true;
    tren[0][0][1] = true;
    tren[0][0][3] = true;
    tren[0][1][1] = true;
    tren[0][1][2] = true;
    tren[0][2][3] = true;
    tren[0][2][0] = true;
    tren[0][2][1] = true;
    tren[0][2][2] = true;
    tren[1][1][1] = true;
    tren[1][1][3] = true;
    tren[1][2][0] = true;
    tren[1][2][2] = true;
    tren[2][0][1] = true;
    tren[2][0][0] = true;
    tren[2][0][2] = true;
    tren[2][0][3] = true;
    tren[2][2][2] = true;
    tren[2][2][1] = true;
    tren[2][2][3] = true;
    tren[3][1][0] = true;
    tren[3][1][3] = true;
    tren[3][2][3] = true;
    tren[4][0][0] = true;
    tren[4][2][0] = true;
    tren[4][2][1] = true;
    tren[4][2][2] = true;
    tren[4][2][3] = true;

    asientosDisponibles(tren);
}
