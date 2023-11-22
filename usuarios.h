#define USUARIOS_H_INCLUDED
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define arUsuarios "Usuarios.dat" ///Constante utilizada en el nombre del archivo.
#define arLogeado "Logeado.dat"///Guarda el usuario que ha iniciado sesion

typedef struct{
    char nombreUsuario[30];
    char pass[20];
    int anioNacimiento;
    char genero;
    int admin;
}stUsuario;

typedef struct
{
    stUsuario dato;
    struct nodoArbol * izq;
    struct nodoArbol * der;
}nodoArbol;


///Prototipados:

void altaUsuarios();
int contarRegistros(char archivo[], int pesoDato);
int buscarUsuarioPorNombre(char nombre[]);
void guardarUsuario(stUsuario u);
void mostrarUsuarios();
void mostrarUnUsuario(stUsuario usuario);
void imprimirOpcionesIniciarSesionAdmin();
int iniciarSesionAdmin();
int iniciarSesionUsuario(char * usuario[]);
void verPerfil();
void listadosTodosOrdenadoXNombre();
void inorder(nodoArbol * arbolito);
nodoArbol *pasaUsuariosArbol(nodoArbol *arbol);
nodoArbol * inicArbol();
nodoArbol *crearNodoArbol(stUsuario dato);
nodoArbol * agregar(nodoArbol * arbolito, nodoArbol * nuevoNodo);
void siExisteEntoncesMostrar(char nombre[]);
