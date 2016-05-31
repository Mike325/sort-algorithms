/*
 * File:   main.cpp
 * Author: Miguel Ochoa Hernández
 *
 * Created on September 17, 2014, 9:35 AM
 */

#include <string.h>
#include <sstream>
#include <stdio.h>
#include <stdio.h>

#ifdef WIN32

#include "../include/Archivos.cpp"
#include "../include/Ordenamientos.cpp"
#include <windows.h>

#define STRING_COMPARE(a, b,result) {result=strcmpi(a,b);}

#define TIME(X)   {                                                                  \
    LARGE_INTEGER t_ini, t_fin , freq;                                               \
    QueryPerformanceCounter(&t_ini);                                                 \
    X;                                                                               \
    QueryPerformanceCounter(&t_fin);                                                 \
    QueryPerformanceFrequency(&freq);                                                \
    double secs = (double)(t_fin.QuadPart - t_ini.QuadPart) / (double)freq.QuadPart; \
    cout<<"Tiempo:                      "<<secs;                                     \
    cout<<SEPARACION;                                                                \
  }

#else

#include "../include/Archivos.h"
#include "../include/Ordenamientos.h"

#define STRING_COMPARE(a, b,result) {result=strcasecmp(a,b);}

#define TIME(X)   {                                             \
    struct timespec ts1, ts2;                                   \
    clock_gettime( CLOCK_REALTIME, &ts1 );                      \
    X;                                                          \
    clock_gettime( CLOCK_REALTIME, &ts2 );                      \
    cout<<"Tiempo:                      "<<                     \
        (float) ( 1.0*(1.0*ts2.tv_nsec - ts1.tv_nsec*1.0)*1e-9  \
            + 1.0*ts2.tv_sec - 1.0*ts1.tv_sec );                \
    cout<<SEPARACION;                                           \
  }

#endif

using namespace std;

void seccion(int tamanio);
void todo();
void llamarMetodos(int *listaDesordenada , vector<int> muestra , int tamanio);

int main(int argc, char** argv) {
    int tamanio = 5;
    char nombre[30] , opcion;

    Archivos *crear = new Archivos();

    sprintf(nombre , "mejorCaso %d.txt" , tamanio );

    ifstream archivo(nombre);

    if( !archivo.good() ) {
        archivo.close();

        for( ; tamanio <= 100000 ; tamanio *= 10) {
            crear->mejorCaso(tamanio);
            crear->peorCaso(tamanio);
            crear->archivosAleatorios(tamanio , 1);

            if( tamanio == 5 ) {
                tamanio = 1;
            }
        }
        cout<<"\nArchivos Listos"<<endl;
        cout<<SEPARACION;
    }

    archivo.close();


    do {
        cout << "Seleccione la opcion para probar todos los metodos de ordenamiento"<<endl;
        cout << "\t1) Un tamaño de arreglo"<<endl;
        cout << "\t2) Todos los archivos"<<endl;
        cout << "\t3) Salir"<<endl;
        cout << "Opcion:    ";
        cin >> opcion;

        switch(opcion) {
            case '1':
                do {
                    cout << "Seleccione el tamaño del arreglo( 5, 10 , 100 , 1000, 10000 o 100000)";
                    cout << "Tamaño:    ";
                    cin >> tamanio;

                    if(!cin.good()) {
                        cout << "\nERROR: no ingreso un numero"<<endl<<endl;
                    }
                    else if(tamanio != 5 && tamanio != 10 && tamanio != 100 && tamanio != 1000
                            && tamanio !=10000 && tamanio != 100000){
                        cout << "\nERROR: no ingreso un tamaño valido"<<endl<<endl;
                    }
                }while(tamanio != 5 && tamanio != 10 && tamanio != 100 && tamanio != 1000
                        && tamanio !=10000 && tamanio != 100000);

                seccion(tamanio);

                break;

            case '2':
                todo();
                break;

            case '3':

                break;

            default:
                cout << "ERROR: Opcion incorrecta"<<endl<<endl;
                break;
        }

    }while(opcion != '3');

    return EXIT_SUCCESS;
}

void seccion(int tamanio) {
    char nombre[30];
    int *listaDesordenada;

    vector<int> muestra;
    Archivos *crear = new Archivos();

    listaDesordenada = new int[tamanio];

    cout<<"******************* Peor caso tamaño     "<<tamanio<<" *******************"<<endl;
    sprintf(nombre , "peorCaso %d.txt" , tamanio );
    crear->leerArchivo(nombre , listaDesordenada, muestra , tamanio);

    llamarMetodos(listaDesordenada , muestra , tamanio);

    nombre[0] = '\0';

    cout<<"******************* Mejor caso tamaño     "<<tamanio<<" *******************"<<endl;
    sprintf(nombre , "mejorCaso %d.txt" , tamanio );
    crear->leerArchivo(nombre , listaDesordenada, muestra , tamanio);

    llamarMetodos(listaDesordenada , muestra , tamanio);

    nombre[0] = '\0';

    for(int j = 1 ; j < 11 ; j++) {

        cout<<"******************* Aleatorio caso  "<< j <<" tamaño     "<<tamanio<<" *******************"<<endl;
        sprintf(nombre , "aleatorio %d %d.txt" , j , tamanio );
        crear->leerArchivo(nombre , listaDesordenada, muestra , tamanio);

        llamarMetodos(listaDesordenada , muestra , tamanio);

        nombre[0] = '\0';
    }

    delete[] listaDesordenada;
    delete crear;

}

void llamarMetodos(int *listaDesordenada, vector<int> muestra , int tamanio) {
    Ordenamientos *ordenar = new Ordenamientos();

    TIME(ordenar->burbuja(listaDesordenada, tamanio));

    ordenar->reLlenar(listaDesordenada , muestra , tamanio);
    TIME(ordenar->seleccion(listaDesordenada, tamanio));

    ordenar->reLlenar(listaDesordenada , muestra , tamanio);
    TIME(ordenar->insercion(listaDesordenada, tamanio));

    ordenar->reLlenar(listaDesordenada , muestra , tamanio);
    TIME(ordenar->shellSort(listaDesordenada, tamanio));

    ordenar->reLlenar(listaDesordenada , muestra , tamanio);
    TIME(ordenar->inicioQuickSort(listaDesordenada , tamanio));

    delete ordenar;
}

void todo() {
    int tamanio = 5;

    for(tamanio = 5; tamanio < 1000000 ; tamanio *= 10) {

        seccion(tamanio);

        if( tamanio == 5 ) {
            tamanio = 1;
        }
    }
}
