#include "canciones.h"

void altaCanciones(){   ///Dar de Alta canciones en el Sistema
    system("cls");
    imprimirCabecera();
    printf("\n\n");
    printf("\t\t\t\t\t  << Alta de canciones >>");
    int id = contarRegistros(arCanciones, sizeof(stCancion));
    id = id+1;
    stCancion cancion;

    printf("\n\n\t-Titulo...........: ");
    fflush(stdin);
    gets(cancion.titulo);
    if(buscarCancionPorTituloSiNo(cancion.titulo)==1){
        printf("\n\t\t\t\t-Ya se encuentra una cancion con el mismo titulo!");
    }
    else{
        cancion.idCancion = id;
        printf("\n\t-Artista..........: ");
        fflush(stdin);
        gets(cancion.artista);
        printf("\n\t-Duracion.........: ");
        fflush(stdin);
        scanf("%i",&cancion.duracion);
        printf("\n\t-Album............: ");
        fflush(stdin);
        gets(cancion.album);
        printf("\n\t-Anio..............: ");
        fflush(stdin);
        scanf("%i",&cancion.anio);
        printf("\n\t-Genero...........: ");
        fflush(stdin);
        gets(cancion.genero);
        guardarCancion(cancion);
        printf("\n\t\t\t-Cancion agregada exitosamente.\n");
    }
}

void guardarCancion(stCancion c){      ///Guarda canciones en el archivo Canciones.dat
    FILE *pArchCanciones=fopen(arCanciones,"ab");
    if(pArchCanciones!=NULL){
        fwrite(&c,sizeof(stCancion),1,pArchCanciones);
        fclose(pArchCanciones);
    }
}


int buscaPosicionTitulo(char titulo[]){   ///Se usa el nombre para buscar la posicion de la cancion
    stCancion cancion;
    int pos=-1;  /// Utiliza un numero negativo para que no corresponda a ninguna posicion
    int flag=0;
    FILE* archi=fopen(arCanciones,"rb");
    while(flag == 0 && fread(&cancion, sizeof(stCancion), 1,archi)>0)
        if(strcmpi(cancion.titulo,titulo) == 0){
            pos = (ftell(archi)/sizeof(stCancion))-1; ///ftell devuelve la posicion actual del cursor, se lo divide por la cantidad de bytes y se le resta 1 para saber la posicion anterior
            flag = 1;
        }
    fclose(archi);
    return pos;
}

int buscarCancionPorTituloSiNo(char titulo[]){ ///Comprueba si la cancion existe, retorna un flag
    int flag = 0;
    stCancion c;
    FILE *pArchCanciones=fopen(arCanciones,"rb");
    if(pArchCanciones!=NULL){
        while((fread(&c,sizeof(stCancion),1,pArchCanciones)>0)&&(flag==0)){
            if(strcmpi(c.titulo,titulo)==0){
                flag = 1;
            }
        }
        fclose(pArchCanciones);
    }
    return flag;
}

void mostrarListadoCanciones(){ ///Muestra todas las canciones
    stCancion c;
    FILE *pArchCanciones = fopen(arCanciones, "rb");
    if(pArchCanciones != NULL){
        while(fread(&c, sizeof(stCancion), 1, pArchCanciones) > 0){
            mostrarUnaCancion(c);
        }
    fclose(pArchCanciones);
    }
}

void mostrarUnaCancion(stCancion c){ ///Muestra una sola cancion
    printf("\n   -Id cancion........: %i", c.idCancion);
    printf("\n   -Titulo............: %s", c.titulo);
    printf("\n   -Artista...........: %s", c.artista);
    printf("\n   -Duracion..........: %i seg.", c.duracion);
    printf("\n   -Album.............: %s", c.album);
    printf("\n   -Anio..............: %i", c.anio);
    printf("\n   -Genero............: %s", c.genero);
    printf("\n______________________________________________________________________________\n");
}

void imprimirOpcionesListadoUsuarios(){///Muestra El menu de como vamos a ordenar a los usuarios
    printf("   1. Listado ordenado por titulo\n");
    printf("   2. Listado ordenado por genero\n");
    printf("   0. Volver\n");
}

void siExisteEntoncesMostrarCancion(char nombre[]){///Muestra una cancion si existe
    stCancion c;
    int flag = 0;
    FILE *pArchCanciones = fopen(arCanciones, "rb");
    if(pArchCanciones != NULL){
        while((flag == 0) && (fread(&c, sizeof(stCancion), 1, pArchCanciones) > 0)){
            if(strcmpi(nombre, c.titulo) == 0){
                mostrarUnaCancion(c);
            }
        }
    fclose(pArchCanciones);
    }
}




void listadosTodosOrdenadoXTitulo(){ ///Muestra las canciones ordenadas alfabeticamente.
    stCancion cancion[100];
    int validos;
    validos=pasaCancionesArreglo(cancion);
    ordenacionSeleccion(cancion,validos);
    mostrarArreglo(cancion,validos);
}

int pasaCancionesArreglo(stCancion arreglo[100]){ ///Pasa la estructura cancion a un arreglo.
    int i=0;
    stCancion cancion;
    FILE * archi=fopen(arCanciones,"rb");
    while(fread(&cancion,sizeof(stCancion),1,archi)>0){
            arreglo[i]=cancion;
            i++;
    }
    fclose(archi);
    return i;
}

void ordenacionSeleccion(stCancion arreglo[100],int validos){ ///Ordena alfabeticamente los titulos.
    int posmenor=0;
    stCancion aux;
    int i=0;
    for(i=0;i<validos;i++){
        posmenor=buscarMenorTitulo(arreglo,i,validos);
        aux=arreglo[posmenor];
        arreglo[posmenor]=arreglo[i];
        arreglo[i]=aux;
    }
}

int buscarMenorTitulo(stCancion arreglo[100],int pos,int validos){ //Busca la posicion donde se encuentra el menor.
    stCancion menor=arreglo[pos];
    int posmenor=pos;
    int i=pos+1;
    while(i<validos){
        if (strcmpi(menor.titulo,arreglo[i].titulo)>0){
            menor=arreglo[i];
            posmenor=i;
        }
        i++;
    }
    return posmenor;
}

void mostrarArreglo(stCancion arreglo[100],int validos){ //Muestra los datos del paciente.
    int i=0;
    for(i=0;i<validos;i++){
        printf("\n   -Id cancion........: %i", arreglo[i].idCancion);
        printf("\n   -Titulo............: %s", arreglo[i].titulo);
        printf("\n   -Artista...........: %s", arreglo[i].artista);
        printf("\n   -Duracion..........: %i segundos.", arreglo[i].duracion);
        printf("\n   -Album.............: %s", arreglo[i].album);
        printf("\n   -Anio..............: %i", arreglo[i].anio);
        printf("\n   -Genero............: %s", arreglo[i].genero);
        printf("\n______________________________________________________________________________\n");
    }
}

void listadosTodosOrdenadoXGenero(){ ///Muestra las canciones ordenadas alfabeticamente.
    stCancion cancion[100];
    int validos;
    validos=pasaCancionesArreglo(cancion);
    ordenacionSeleccionGenero(cancion,validos);
    mostrarArreglo(cancion,validos);
}

void ordenacionSeleccionGenero(stCancion arreglo[100],int validos){ ///Ordena alfabeticamente los generos.
    int posmenor=0;
    stCancion aux;
    int i=0;
    for(i=0;i<validos;i++){
        posmenor=buscarMenorGenero(arreglo,i,validos);
        aux=arreglo[posmenor];
        arreglo[posmenor]=arreglo[i];
        arreglo[i]=aux;
    }
}

int buscarMenorGenero(stCancion arreglo[100],int pos,int validos){ ///Busca la posicion donde se encuentra el menor.
    stCancion menor=arreglo[pos];
    int posmenor=pos;
    int i=pos+1;
    while(i<validos){
        if (strcmpi(menor.genero,arreglo[i].genero)>0){
            menor=arreglo[i];
            posmenor=i;
        }
        i++;
    }
    return posmenor;
}

int consultaCancion(char nombre[]){///Comprueba si la cancion existe, retorna un flag
    stCancion c;
    int flag = 0;
    FILE *pArchCanciones = fopen(arCanciones, "rb");
    if(pArchCanciones != NULL){
        while((flag == 0) && (fread(&c, sizeof(stCancion), 1, pArchCanciones)) > 0){
            if(strcmpi(nombre, c.titulo) == 0){
                flag = 1;
            }
        }
    fclose(pArchCanciones);
    }
    return flag;
}
