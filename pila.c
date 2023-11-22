#include "pila.h"


void inicpila(P_Pila p)
{
       int *aux;
       aux = (int *)malloc(50*sizeof(int));
       p->valores = aux;
       p->postope=0;
}

void apilar(P_Pila p, int dato)
{
    int index = (*p).postope;
    (*p).valores[index]=dato;
    (*p).postope = (*p).postope + 1;
}

int desapilar(P_Pila p)
{
       int z = p->valores[p->postope -1];
       p->postope--;
       return z;
}

int tope(P_Pila p)
{
       return p->valores[p->postope - 1];
}

int pilavacia(P_Pila p)
{
       return (p->postope == 0);
}

void leer (P_Pila p)
{
    int aux = 0;
    if (p->postope < 50)
    {
        fflush(stdin);
        scanf("%d", &aux);
        apilar(p, aux);
    }
    else
        printf("Error: la pila esta llena");
}

void pilaToArchi(Pila *pilita)
{
    int aux;
    FILE * archi = fopen(arPila,"ab");
    if(archi)
    {
     while(!pilavacia(pilita))
   {
       aux = desapilar(pilita);
       fwrite(&aux,sizeof(int),1,archi);
   }
        fclose(archi);
    }
}

void cargarPila(Pila *pilita)
{
    int aux;
    FILE * archi = fopen(arPila,"rb");
    if(archi)
    {
    while(fread(&aux,sizeof(int),1,archi))
    {
        apilar(pilita,aux);
    }
    fclose(archi);
    }
}

void mostrar(P_Pila p)
{
    int i;
    printf("\nBase .............................................. Tope\n\n");
    for(i=0; i < p->postope; i++)
        printf("| %d ", p->valores[i]);
    printf("\n\nBase .............................................. Tope\n\n");
}
