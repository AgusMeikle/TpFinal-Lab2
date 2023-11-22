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

    int pos, id, flag=0;
    char seguir;
    stCancion cancion;
    listaCancion * nuevoNodo;
    mostrarListadoCanciones();
    do
    {
        pos = verifiEnArr(arreglo,validos,usuActual);
    if (pos == -1) /// si la playlist no existe la creamos
    {
        strcpy(arreglo[validos].nombreUser, usuActual);
        pos = validos;
        validos ++;
    }
    printf("\n Ingrese el id de la cancion que desea agregar.....: ");
    fflush(stdin);
    scanf("%i",&id);

    flag = buscarEnLista(arreglo[pos].tema,id);


    if(flag == 0)
    {
        cancion = buscarCancionPorId(id);
        nuevoNodo = crearNodoCancion(cancion);
        arreglo[pos].tema = agregarAlFinal(arreglo[pos].tema, nuevoNodo);
        printf("\nCancion agregada con exito. ");
        printf("\nDesea agregar otra? ");
        fflush(stdin);
        scanf("%c",&seguir);
    }
    else
    {
        printf("\nLa cancion ya se encuentra en su playlist, intente nuevamente\n");
    }

    }while(seguir=='s');
    return validos;
}

int buscarEnLista(listaCancion *lista, int id)
{
    listaCancion *aux = lista;
    int flag=0;
    while(aux!=NULL)
    {
        if(aux->dato.idCancion == id)
        {
            flag=1;
        }
        aux = aux->siguiente;
    }
    return flag;
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

/// FILA

void agregarMuchos(fila * filita, char nombreUser[])
{
      char seguir;
      stComentario dato;
      listaComentarios * nuevoNodo;

      do{

            strcpy(dato.nombreUser,nombreUser);

            printf("Ingrese la cancion que desea comentar: ");
            fflush(stdin);
            gets(dato.nombreCancion);

            printf("Ingrese su comentario: ");
            fflush(stdin);
            gets(dato.comentarios);

            nuevoNodo = crearNodoComentarios(dato);
            agregarFila(filita,nuevoNodo);

            printf("Desea cargar otro comentario? s/n: ");
            fflush(stdin);
            scanf("%c",&seguir);

      }while(seguir=='s');

      cargarComentariosArchi(filita->pri);
}

void cargarComentariosArchi(listaComentarios * listita)
{
      FILE * pArchComentarios = fopen(arComentarios,"wb");
      stComentario dato;
      listaComentarios * aux = listita;

      if(pArchComentarios!=NULL){

            while(aux!=NULL) // recorremos la lista
            {
                dato = aux->dato;
                fwrite(&dato,sizeof(stComentario),1,pArchComentarios);
                aux = aux->sig;
            }
        }
        fclose(pArchComentarios);
}

void archivoComenToFila(fila * filita)
{
      FILE * pArchComentarios = fopen(arComentarios, "rb");
      stComentario c;
      listaComentarios * nuevoNodo;
      if(pArchComentarios != NULL){

        while(fread(&c, sizeof(stComentario), 1, pArchComentarios) > 0)
        {
            nuevoNodo = crearNodoComentarios(c);
            agregarFila(filita,nuevoNodo);
        }
    fclose(pArchComentarios);
      }
}

void inicFila(fila* filita)
{
    filita->pri=inicListaComentarios();
    filita->ult=inicListaComentarios();
}

listaComentarios * inicListaComentarios()
{
      return NULL;
}

listaComentarios * crearNodoComentarios(stComentario dato)
{
      listaComentarios * nuevoNodo = (listaComentarios*)malloc(sizeof(listaComentarios));

      nuevoNodo->dato = dato;

      nuevoNodo->sig = NULL;

      return nuevoNodo;
}

void agregarFila(fila* filita, listaComentarios *nuevoNodo)
{
    filita->ult=agregarAlFinalCom(filita->ult, nuevoNodo);

    if(filita->pri==NULL)
    {
        filita->pri=filita->ult;
    }
    filita->ult=nuevoNodo;
}


listaComentarios * agregarAlFinalCom(listaComentarios * lista, listaComentarios* nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        listaComentarios * ultimo = buscarUltimoR(lista);
        ultimo->sig = nuevoNodo;
    }
    return lista;
}

listaComentarios * buscarUltimoR(listaComentarios * lista)
{
    listaComentarios * rta = NULL;
    if(lista!=NULL)
    {
        if(lista->sig==NULL)
        {
            rta=lista;
        }
        else
        {
            rta=buscarUltimoR(lista->sig);
        }
    }
    return rta;
}

listaComentarios * extraer(fila *filita)
{
    listaComentarios * resp;

    if(filita->pri!=NULL)
    {
        resp = filita->pri;

        filita->pri=borrarPrimero(filita->pri);

        if(filita->pri==NULL)
        {
            filita->ult=inicListaComentarios();
        }
    }
    return resp;
}

listaComentarios * borrarPrimero (listaComentarios * lista)
{
    listaComentarios * aux = lista;
    if (lista!=NULL)
    {
        lista=lista->sig;
        free(aux);
    }
    return lista;
}

void mostrarUnSoloComent(stComentario dato)
{
    printf("\tCancion: %s\n",dato.nombreCancion);
    printf("\tUsuario: %s\n", dato.nombreUser);
    printf("\tComentario: %s\n",dato.comentarios);
}

void mostrarFilaComents(fila* filita)
{
    listaComentarios* aux = filita->pri;
    printf("\tCOMENTARIOS:\n\n");
    while (aux != NULL)
    {
        mostrarUnSoloComent(aux->dato);
        aux = aux->sig;
    }

    printf("\n____________________________________________\n");
}
