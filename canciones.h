#define CANCIONES_H_INCLUDED
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define arCanciones "Canciones.dat" ///Constante utilizada en el nombre del archivo.
#define arPlaylist "Playlist.dat"
#define MAX 150 ///Se utiliza para la cantidad maxima que puede almacenar un arreglo.

typedef struct{
    int idCancion;
    char titulo[30];
    char artista[30];
    int duracion;
    char album[30];
    int anio;
    char genero[30];
    char comentario[100];
}stCancion;


void altaCanciones();
void guardarCancion(stCancion c);
int buscaPosicionTitulo(char titulo[]);
int buscarCancionPorTituloSiNo(char titulo[]);
void mostrarListadoCanciones();
void mostrarUnaCancion(stCancion c);
void imprimirOpcionesListadoUsuarios();
void siExisteEntoncesMostrarCancion(char nombre[]);
void listadosTodosOrdenadoXTitulo();
int pasaCancionesArreglo(stCancion arreglo[100]);
void ordenacionSeleccion(stCancion arreglo[100],int validos);
int buscarMenorTitulo(stCancion arreglo[100],int pos,int validos);
void mostrarArreglo(stCancion arreglo[100],int validos);
void listadosTodosOrdenadoXGenero();
void ordenacionSeleccionGenero(stCancion arreglo[100],int validos);
int buscarMenorGenero(stCancion arreglo[100],int pos,int validos);
int consultaCancion(char nombre[]);
