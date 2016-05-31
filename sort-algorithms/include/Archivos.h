/*
 * File:   Archivos.h
 * Author: Miguel Ochoa Hernández
 *
 * Created on September 17, 2014, 9:36 AM
 */

#ifndef ARCHIVOS_H
#define	ARCHIVOS_H

#include <math.h>
#include <time.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

class Archivos {
public:
    Archivos();
    Archivos(const Archivos& orig);
    virtual ~Archivos();

    void peorCaso( int &tamanio );
    void mejorCaso( int &tamanio );
    int archivosAleatorios( int &tamanio, int i);
    void leerArchivo(char nombre[], int *lista, vector<int> &muestra , register int tamanio );


private:

};

#endif	/* ARCHIVOS_H */

