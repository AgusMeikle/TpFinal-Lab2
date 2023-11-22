#define PLAYLIST_H_INCLUDED
#include "canciones.h"
#define arComentarios "Comentarios.dat"


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

typedef struct{
      char nombreUser[30];
      char comentarios[100];
      char nombreCancion[30];
}stComentario;

typedef struct{
      stComentario dato;
      struct listaComentarios * sig;
}listaComentarios;

typedef struct{
      struct listaComentarios * pri;
      struct listaComentarios * ult;
}fila;

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
int buscarEnLista(listaCancion *lista, int id);
listaComentarios * inicListaComentarios();
void inicFila(fila* filita);
void agregarFila(fila* filita, listaComentarios *nuevoNodo);
listaComentarios * agregarAlFinalCom(listaComentarios * lista, listaComentarios * nuevoNodo);
listaComentarios * buscarUltimoR(listaComentarios * lista);
listaComentarios * extraer(fila *filita);
listaComentarios * borrarPrimero (listaComentarios * lista);
listaComentarios * crearNodoComentarios(stComentario dato);
void mostrarFilaComents(fila* filita);
void mostrarUnSoloComent(stComentario dato);
