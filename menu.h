#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include <windows.h>
#include "playlist.h"

void imprimirCabecera();
void imprimirOpcionesSubMenu1();
void imprimirOpcionesMenu1();
void imprimirMenuAdmin();
void imprimirMenuUsuario();
int iniciarSesionUsuario();
int iniciarSesionAdmin();
int ingresarOpcion();
void switchSubMenu1();
int switchMenu1();
void switchMenuAdmin();
void iniciarMenu();


#endif // MENU_H_INCLUDED
