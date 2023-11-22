#include "playlist.h"


listaCancion * inicLista()
{
    return NULL;
}

void inicArreglo(playlist arreglo[],int dim)
{
    for(int i=0;i<dim;i++)
    {
        arreglo[i].tema = inicLista();
    }
}

listaCancion * crearNodoCancion(stCancion dato)
{
    listaCancion * nuevoNodo = (listaCancion*)malloc(sizeof(listaCancion));

    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;

    return nuevoNodo;
}

listaCancion * agregarAlFinal(listaCancion * listita, listaCancion * nuevoNodo)
{
    if(listita==NULL)
    {
        listita=nuevoNodo;
    }
    else
    {
        listaCancion * aux = listita;

        while(aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }

        aux->siguiente = nuevoNodo;
    }

    return listita;
}

int deArchivoToArreglo(playlist arreglo[], int dimension){
    simplificacion c;
    stCancion dato;
    listaCancion *nuevoNodo;
    int pos,validos = 0;
    FILE *pArchPlaylist = fopen(arPlaylist, "rb");
    if(pArchPlaylist != NULL){
        while(fread(&c, sizeof(simplificacion), 1, pArchPlaylist) > 0 && validos<dimension){

            pos = verifiEnArr(arreglo, validos,c.nombreUser);

            if (pos == -1) /// si la playlist no existe la creamos
            {
                strcpy(arreglo[validos].nombreUser,c.nombreUser);
                pos = validos;
                validos ++;
            }
            dato = c.dato;
            nuevoNodo = crearNodoCancion(dato);
            arreglo[pos].tema = agregarAlFinal(arreglo[pos].tema, nuevoNodo);
        }
    fclose(pArchPlaylist);
    }
    return validos;
}

int cargarPlaylist(playlist arreglo[], int validos, int dimension, char usuActual[]){ /// FUNCION PRINCIPAL DE PLAYLIST

    int pos = verifiEnArr(arreglo,validos,usuActual);
    int id;
    stCancion cancion;
    listaCancion * nuevoNodo;

    if (pos == -1) /// si la playlist no existe la creamos
    {
        strcpy(arreglo[validos].nombreUser, usuActual);
        pos = validos;
        validos ++;
    }
    mostrarListadoCanciones();
    printf("\n Ingrese el id de la cancion que desea agregar.....: ");
    fflush(stdin);
    scanf("%i",&id);

    cancion = buscarCancionPorId(id);
    nuevoNodo = crearNodoCancion(cancion);
    arreglo[pos].tema = agregarAlFinal(arreglo[pos].tema, nuevoNodo);


    return validos;
}

void cargarPlaylistArchivo(playlist arreglo[], int validos)
{
    FILE *pArchPlaylist=fopen(arPlaylist,"wb");
    simplificacion dato;
    if(pArchPlaylist!=NULL){
        for(int i=0; i<validos; i++)
        {
            strcpy(dato.nombreUser,arreglo[i].nombreUser);
            listaCancion *aux = arreglo[i].tema;
            while(aux!=NULL) // recorremos la lista del arreglo[i]
            {
                dato.dato = aux->dato;
                fwrite(&dato,sizeof(simplificacion),1,pArchPlaylist);
                aux = aux->siguiente;
            }
        }
        fclose(pArchPlaylist);
    }
}

stCancion buscarCancionPorId(int id)
{
    stCancion c,rta;
    rta.idCancion =-1;
    FILE * pArchCanciones = fopen(arCanciones, "rb");
    if(pArchCanciones != NULL){
        while((rta.idCancion == -1) && (fread(&c, sizeof(stCancion), 1, pArchCanciones) > 0)){
            if(id == c.idCancion){
                rta = c;
            }
        }
    fclose(pArchCanciones);
    }
return rta;
}

int verifiEnArr(playlist arreglo[],int validos,char nomUsuAbusc[])
{
    int pos = -1;
    int i=0;
    while (i<validos)
    {
        if (strcmpi(arreglo[i].nombreUser,nomUsuAbusc)==0)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}

void recorrerListasDeArrgPlaylist(listaCancion* listita)
{
    listaCancion * aux = listita;
    while (aux!=NULL)
    {
        mostrarUnaCancion(aux->dato);
        aux = aux->siguiente;
    }

}
void recorrerArrPlaylist(playlist arreglo[],int validos, char usuario[])
{
    for (int i = 0; i < validos; i++)
    {
        if(strcmpi(arreglo[i].nombreUser,usuario)==0)
        {
        printf("Playlist de %s:\n",arreglo[i].nombreUser);
        recorrerListasDeArrgPlaylist(arreglo[i].tema);

        }
    }
}
