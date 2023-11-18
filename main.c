#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// estrucutras
typedef struct{
    int idCancion;
    char titulo[30];
    int duracion;
    char album[20];
    int anio;
    char genero[20];
    char comentario[100];
    int eliminado; ///indica 1 o 0 si fue eliminado o no
    struct stCancion* siguiente;
}stCancion;

typedef struct{
    stCancion tema;
    char artista[20];
}celda;

typedef struct{
    int idUsuario;
    char nombreUsuario[30];
    char pass[20];
    int anioNacimiento;
    char genero;
    char pais[20];
    int playlist[50];
    int cantidad;
    int eliminado;
    int admin;
}stUsuario;

int main()
{
    
    return 0;
}
