/*
 * File:   Ordenamientos.h
 * Author: Miguel Ochoa Hernández
 *
 * Created on 29 de septiembre de 2014, 01:41
 */

#ifndef ORDENAMIENTOS_H
#define	ORDENAMIENTOS_H

#include <time.h>
#include <cstdlib>
#include <iostream>
#include <vector>

#define SEPARACION "\n---------------------------------------------------------------------------------------------------------------\n\n"

using namespace std;

class Ordenamientos {
public:
    Ordenamientos();
    Ordenamientos(const Ordenamientos& orig);
    virtual ~Ordenamientos();

    void burbuja(int *lista, int tamanio);
    void insercion(int *lista, int tamanio);
    void seleccion(int *lista, int tamanio);
    void shellSort(int *lista, int tamanio);

    void inicioQuickSort(int *lista , int tamanio);
    void quickSort(int *lista, int primero, int ultimo, unsigned long int &compararciones_arreglo,
                                unsigned long int &asignaciones_arreglo);

    void reLlenar(int *lista , vector<int> &muestra , int tamanio);

private:

};

#endif	/* ORDENAMIENTOS_H */

