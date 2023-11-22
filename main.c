#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "menu.h"



/// PROTOTIPADOS

void escribir(stCancion dato);
void mostrarArchivoDeCanciones(char archivo[]);
stCancion cargarUnaCancion(stCancion dato);
void cargarArchivoDeCanciones(char archivo[]);

int main()
{


      //validos = cargarArreglo(arreglo,dim);
      //muestraArreglo(arreglo,validos);

      /// cargarArchivoDeCanciones("Canciones.dat");
     // mostrarArchivoDeCanciones("Canciones.dat");
      iniciarMenu();

    printf("Esto es un test\n");
    return 0;
}



stCancion cargarUnaCancion(stCancion dato)
{
      printf("Ingrese el ID de la cancion: ");
      fflush(stdin);
      scanf("%i",&dato.idCancion);

      printf("Ingrese el artista: ");
      fflush(stdin);
      gets(dato.artista);

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

      strcpy(dato.comentario,"Sin comentarios aun.");

      return dato;
}

void cargarArchivoDeCanciones(char archivo[])
{
      FILE * archi = fopen(archivo,"ab");
        stCancion dato;
        int a=10;
      if(archi)
      {
        for(int i=0; i<a; i++)
        {

            dato = cargarUnaCancion(dato);

            fwrite(&dato,sizeof(stCancion),1,archi);

      }
            fclose(archi);
        }
}


void mostrarArchivoDeCanciones(char archivo[])
{
      FILE * archi = fopen(archivo,"rb");
        stCancion dato;
      if(archi)
      {

      while(fread(&dato,sizeof(stCancion),1,archi))
      {
            escribir(dato);
      }
            fclose(archi);
      }
}

void escribir(stCancion dato)
{
      printf("-------------------------\n");
      printf("ID de la cancion: %i\n",dato.idCancion);
      printf("Titulo: %s\n",dato.titulo);
      printf("Duracion (segundos): %i \n",dato.duracion);
      printf("Album: %s\n",dato.album);
      printf("Anio: %i\n",dato.anio);
      printf("Genero: %s\n",dato.genero);
      printf("Comentario: %s\n",dato.comentario);
      printf("-------------------------\n");
}
