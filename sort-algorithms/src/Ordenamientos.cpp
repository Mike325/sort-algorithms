/*
 * File:   Ordenamientos.cpp
 * Author: Miguel Ochoa Hernández
 *
 * Created on 29 de septiembre de 2014, 01:41
 */

#include "../include/Ordenamientos.h"

#define IMPRIMIR(compararciones_arreglo, asignaciones_arreglo) {            \
    cout<<"Comparaciones del arreglo:   "<<compararciones_arreglo<<endl;    \
    cout<<"Asignaciones al arreglo:     "<<asignaciones_arreglo<<endl;      \
}                                                                           \

Ordenamientos::Ordenamientos() {
}

Ordenamientos::Ordenamientos(const Ordenamientos& orig) {
}

Ordenamientos::~Ordenamientos() {
}

void Ordenamientos::reLlenar(int *lista , vector<int> &muestra , int tamanio) {
    for(int i = 0 ; i < tamanio; i++ ) {
        lista[ i ] = muestra.at( i );
    }
}

void Ordenamientos::burbuja(int *lista, int tamanio) {

    cout<<"BURBUJA"<<endl<<endl;

    register int auxiliar = 0;
    unsigned long int compararciones_arreglo = 0, asignaciones_arreglo = 0;

    for(register int i = 0; i < tamanio - 1; i++) {

        for(register int j = i + 1; j < tamanio ; j++) {

            if(lista[ i ] > lista[j]) {
                auxiliar                = lista[ i ];
                lista[ i ]              = lista[ j ];
                lista[ j ]              = auxiliar;
                asignaciones_arreglo   += 2;
            }
            compararciones_arreglo += 1;
        }

    }

    IMPRIMIR(compararciones_arreglo, asignaciones_arreglo)
}

void Ordenamientos::seleccion(int *lista, int tamanio) {
    cout<<"SELECCION"<<endl<<endl;
    register int menor, auxiliar;
    unsigned long int compararciones_arreglo = 0, asignaciones_arreglo = 0;


    for(register int i = 0; i < tamanio - 1; i++) {
        menor = i;

        for(register int j = i + 1; j < tamanio; j++) {

            if (lista[ j ] < lista[ menor ] ) {
                menor                   = j;
            }
            compararciones_arreglo += 1;
        }

        if (i != menor) {
            auxiliar                = lista[ i ];
            lista[ i ]              = lista[ menor ];
            lista[ menor ]          = auxiliar;
            asignaciones_arreglo   += 2;
        }
    }

    IMPRIMIR(compararciones_arreglo, asignaciones_arreglo)
}

void Ordenamientos::insercion(int *lista, int tamanio) {
    cout<<"INSERCION"<<endl<<endl;
    register int j, auxiliar;
    unsigned long int compararciones_arreglo = 0, asignaciones_arreglo = 0;

    for (register int i = 1; i < tamanio; i++) {
        auxiliar = lista[ i ];
        j = i - 1;

        while (j >= 0 && auxiliar < lista[ j ] ) {
            lista[ j + 1 ] = lista[ j ];
            j--;

            compararciones_arreglo += 1;
            asignaciones_arreglo   += 1;
        }

        compararciones_arreglo += 1;

        lista[ j + 1 ]          = auxiliar;

        asignaciones_arreglo   += 1;
    }

    IMPRIMIR(compararciones_arreglo, asignaciones_arreglo)
}

void Ordenamientos::shellSort( int *lista, int tamanio) {
    cout<<"SHELL SORT"<<endl<<endl;
    register int i, j, incremento, auxiliar;
    unsigned long int compararciones_arreglo = 0, asignaciones_arreglo = 0;

    incremento = tamanio / 2;

    while (incremento > 0) {

        for (i = incremento; i < tamanio ; i++) {
            j        = i;
            auxiliar = lista[ i ];

            while (j >= incremento && lista[ j - incremento ] > auxiliar )   {

                compararciones_arreglo += 1;
                lista[ j ]              = lista[ (j - incremento ) ];
                asignaciones_arreglo   += 1;
                j                      -= incremento;

            }
            compararciones_arreglo   += 1;
            lista[ j ]                = auxiliar;
            asignaciones_arreglo     += 1;
        }
        incremento               /= 2;
    }

    IMPRIMIR(compararciones_arreglo, asignaciones_arreglo)
}

void Ordenamientos::inicioQuickSort(int *lista , int tamanio) {
    cout<<"QUICK SORT"<<endl<<endl;
    unsigned long int compararciones_arreglo = 0, asignaciones_arreglo = 0;

    quickSort(lista, 0, tamanio - 1 , compararciones_arreglo, asignaciones_arreglo);

    IMPRIMIR(compararciones_arreglo, asignaciones_arreglo)
}

void Ordenamientos::quickSort(int *lista, int primero, int ultimo, unsigned long int &compararciones_arreglo,
                                unsigned long int &asignaciones_arreglo) {

    register int i, j, auxiliar, pivote;

    i = primero;
    j = ultimo;
    pivote = lista[ (primero + ultimo) / 2];

    do
    {
        while( lista[ i ] < pivote ) {
            compararciones_arreglo += 1;
            i++;
        }
        compararciones_arreglo += 1;
        while( lista[ j ] > pivote ) {
            compararciones_arreglo += 1;
            j--;
        }
        compararciones_arreglo += 1;
        if (i <= j) {
            auxiliar = lista[ i ];
            lista[ i ] = lista[ j ];
            lista[ j ] = auxiliar;

            asignaciones_arreglo += 2;

            i++;
            j--;
        }
    } while (i <= j);

    if(primero < j) {
        quickSort(lista, primero, j,compararciones_arreglo,asignaciones_arreglo);
    }
    if(ultimo > i) {
        quickSort(lista, i, ultimo, compararciones_arreglo,asignaciones_arreglo);
    }
}
