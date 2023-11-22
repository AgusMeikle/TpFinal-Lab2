#ifndef PLAYLIST_H_INCLUDED
#define PLAYLIST_H_INCLUDED
#include "canciones.h"


typedef struct{
    stCancion dato;
    struct listaCancion * siguiente;
}listaCancion;

typedef struct{
    listaCancion * tema;
    char nombreUser[30];
}playlist; // arreglo

typedef struct{
    char nombreUser[30];
    stCancion dato;
}simplificacion;

listaCancion * inicLista();
void inicArreglo(playlist arreglo[],int dim);
listaCancion * crearNodoCancion(stCancion dato);
listaCancion * agregarAlFinal(listaCancion * listita, listaCancion * nuevoNodo);
int deArchivoToArreglo(playlist arreglo[], int dimension);
int cargarPlaylist(playlist arreglo[], int validos, int dimension, char usuActual[]);
void cargarPlaylistArchivo(playlist arreglo[], int validos);
stCancion buscarCancionPorId(int id);
int verifiEnArr(playlist arreglo[],int validos,char nomUsuAbusc[]);
void recorrerListasDeArrgPlaylist(listaCancion * listita);
void recorrerArrPlaylist(playlist arreglo[], int validos, char usuario[]);

#endif // PLAYLIST_H_INCLUDED
