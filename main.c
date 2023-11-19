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
    //int eliminado; ///indica 1 o 0 si fue eliminado o no
}unaCancion;

typedef struct{
      unaCancion dato;
    struct stCancion * siguiente;
}stCancion;

typedef struct{
    stCancion * tema;
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

/// PROTOTIPADOS
stCancion * inicLista();
stCancion * crearNodoCancion(unaCancion dato);
stCancion * agregarAlFinal(stCancion * listita, stCancion * nuevoNodo);

void inicArreglo(celda arreglo[],int dim);
int verificarArreglo(celda arreglo[],int validos,char artista[]);
int cargarArreglo(celda arreglo[], int dim);
void muestraArreglo(celda arreglo[],int validos);
void recorrerYmostrar(stCancion * listita);
void escribir(stCancion * listita);
unaCancion cargarUnaCancion(unaCancion dato);

int main()
{
      int dim=10,validos=0;

      celda arreglo[dim];
      inicArreglo(arreglo,dim);

      validos = cargarArreglo(arreglo,dim);
      muestraArreglo(arreglo,validos);

    printf("Esto es un test\n");
    return 0;
}

/// FUNCIONES STCANCION
stCancion * inicLista()
{
      return NULL;
}

stCancion * crearNodoCancion(unaCancion dato)
{
      stCancion * nuevoNodo = (stCancion*)malloc(sizeof(stCancion));

      nuevoNodo->dato = dato;
      nuevoNodo->siguiente = NULL;

      return nuevoNodo;
}

stCancion * agregarAlFinal(stCancion * listita, stCancion * nuevoNodo)
{
      if(listita==NULL)
      {
            listita=nuevoNodo;
      }
      else
      {
            stCancion * aux = listita;

            while(aux->siguiente != NULL)
            {
                  aux = aux->siguiente;
            }

            aux->siguiente = nuevoNodo;
      }

      return listita;
}

/// FUNCIONES ARREGLO
void inicArreglo(celda arreglo[],int dim)
{
      for(int i=0;i<dim;i++)
      {
            arreglo[i].tema = inicLista();
      }
}

int verificarArreglo(celda arreglo[],int validos,char artista[]) /// verificamps que exista el artista en el arreglo (puede ser recursiva)
{
      int pos=-1;

      for(int i=0;i<validos;i++)
      {
            if(strcmpi(artista,arreglo[i].artista)==0)
            {
                  pos = i;
            }
      }

      return pos;
}

int cargarArreglo(celda arreglo[], int dim)
{
      char artista[30],seguir;
      int validos=0, pos;
      unaCancion dato;
      stCancion * nuevoNodo;

      do
      {
            printf("Ingrese el nombre del artista: ");
            fflush(stdin);
            gets(artista);

            pos = verificarArreglo(arreglo,validos,artista);

            dato = cargarUnaCancion(dato);
            nuevoNodo = crearNodoCancion(dato);

            if(pos==-1)
            {
                  strcpy(arreglo[validos].artista,artista);

                  arreglo[validos].tema = agregarAlFinal(arreglo[validos].tema,nuevoNodo);

                  validos++;
            }
            else
            {
                  arreglo[pos].tema = agregarAlFinal(arreglo[pos].tema,nuevoNodo);
            }

            printf("Desea cargar otro artista? s/n: ");
            fflush(stdin);
            scanf("%c",&seguir);

      }while(seguir=='s' && validos<dim);

      return validos;
}

void muestraArreglo(celda arreglo[],int validos)
{
      for(int i=0;i<validos;i++)
      {
            printf("Artista: %s\n",arreglo[i].artista);
            recorrerYmostrar(arreglo[i].tema);
      }
}

void recorrerYmostrar(stCancion * listita)
{
      while(listita!=NULL)
      {
            escribir(listita);
            listita = listita->siguiente;
      }
}

void escribir(stCancion * listita)
{
      printf("-------------------------\n");
      printf("ID de la cancion: %i\n",listita->dato.idCancion);
      printf("Titulo: %s\n",listita->dato.titulo);
      printf("Duracion (minutos): %i \n",listita->dato.duracion);
      printf("Album: %s\n",listita->dato.album);
      printf("Anio: %i\n",listita->dato.anio);
      printf("Genero: %s\n",listita->dato.genero);
      printf("Comentario: %s\n",listita->dato.comentario);
      printf("-------------------------\n");
}

unaCancion cargarUnaCancion(unaCancion dato)
{
      printf("Ingrese el ID de la cancion: ");
      fflush(stdin);
      scanf("%i",&dato.idCancion);

      printf("Ingrese el titulo: ");
      fflush(stdin);
      gets(dato.titulo);

      printf("Ingrese el genero: ");
      fflush(stdin);
      gets(dato.genero);

      printf("Ingrese el nombre del album: ");
      fflush(stdin);
      gets(dato.album);

      printf("Ingrese el anio de la cancion: ");
      fflush(stdin);
      scanf("%i",&dato.anio);

      printf("Ingrese cuanto dura la cancion (minutos): ");
      fflush(stdin);
      scanf("%i",&dato.duracion);

      printf("Deje un comentario sobre la cancion: ");
      fflush(stdin);
      gets(dato.comentario);

      return dato;
}





