/* 
 * File:   Archivos.cpp
 * Author: mike
 * 
 * Created on September 17, 2014, 9:36 AM
 */

#include "Archivos.h"

Archivos::Archivos() {
}

Archivos::Archivos(const Archivos& orig) {
}

Archivos::~Archivos() {
}

void Archivos::mejorCaso(int &tamanio ) {
    char nombre[30];
    
    sprintf(nombre , "mejorCaso %d.txt" , tamanio );
    ofstream archivo(nombre , ios::app);
    
    for(register int i = 1; i < tamanio + 1 ; i++) {
        archivo.write((char*)&i , sizeof(int));
    }
    
    archivo.close();
}

void Archivos::peorCaso( int &tamanio ) {
    char nombre[30];
    
    sprintf(nombre , "peorCaso %d.txt" , tamanio );
    ofstream archivo(nombre , ios::app);
    
    for(register int i = tamanio ; i > 0 ; i--) {
        archivo.write((char*)&i , sizeof(int));
    }
    
    archivo.close();
}

int Archivos::archivosAleatorios(int &tamanio, int caso) {
    
    if( caso == 11) {
        return 0;
    }
    else {
        char nombre[30];
        int i , aleatorio;
        vector<int> lista;
        
        for(i = 0; i < tamanio ; i++) {
            lista.push_back(i);
        }

        sprintf(nombre , "aleatorio %d %d.txt" ,caso , tamanio );

        ofstream archivo(nombre , ios::app);
        
        for( i = 0; i < tamanio ; i++) {
            
            aleatorio = rand()%lista.size();
            
            archivo.write((char*)&lista.at(aleatorio) , sizeof(int));
            
            lista.erase( lista.begin() + aleatorio );
        }
        
        archivo.close();
        
        return archivosAleatorios( tamanio , caso + 1);
    }
}

void Archivos::leerArchivo(char nombre[], int *lista, vector<int> &muestra, int tamanio ) {
    int leer;
    
    ifstream archivo( nombre );
    muestra.clear();
    
    for(int i = 0; i < tamanio ; i++) {
        archivo.read((char*)&leer , sizeof(int));
        lista[ i ] = leer;
        muestra.push_back(leer);
    }
    
    archivo.close();
}
    
