#include "usuarios.h"

///Dar de Alta usuarios en el Sistema
void altaUsuarios(){
    system("cls");
    imprimirCabecera(" << M u s i c - F y >>");
    printf("\n\n");
    printf("\t\t\t\t\t    << Alta de Usuario >>");
    int id = contarRegistros(arUsuarios, sizeof(stUsuario));
    id = id + 1;
    stUsuario usuario;
    printf("\n\n\t-Nombre de Usuario......: ");
    fflush(stdin);
    scanf("%s",usuario.nombreUsuario);
    if(buscarUsuarioPorNombre(usuario.nombreUsuario)==1){
        printf("\n\t\t\t\t-El nombre de usuario ya se encuentra en uso.\n");
    }
    else{
        printf("\n\t-Contrasena.............: ");
        fflush(stdin);
        scanf("%s",&usuario.pass);
        printf("\n\t-Anio de Nacimiento......: ");
        fflush(stdin);
        scanf("%i",&usuario.anioNacimiento);
        printf("\n\t-Genero(m o f)..........: ");
        fflush(stdin);
        scanf("%c",&usuario.genero);
        usuario.admin = 0;
        guardarUsuario(usuario);
        printf("\n\t\t\t-Usuario creado exitosamente.\n");
    }
}

int contarRegistros(char archivo[], int pesoDato){
    int total = 0;
    FILE *pArchivo = fopen(archivo, "rb");
    if(pArchivo != NULL){
        fseek(pArchivo, 0, SEEK_END);
        total = ftell(pArchivo)/pesoDato;
        fclose(pArchivo);
    }
    return total;
}


int buscarUsuarioPorNombre(char nombre[]){  ///Comprueba si un usario existe por su nombre devuelve 1 si esta y 0 si no
    int flag = 0;
    stUsuario u;
    FILE *pArchUsuarios=fopen(arUsuarios,"rb");
    if(pArchUsuarios!=NULL){
        while((fread(&u,sizeof(stUsuario),1,pArchUsuarios)>0)&&(flag==0)){
            if(strcmpi(u.nombreUsuario,nombre)==0){
                flag=1;
            }
        }
        fclose(pArchUsuarios);
    }
    return flag;
}

void guardarUsuario(stUsuario u){  ///Guarda un usuario en usuarios.dat
    FILE *pArchUsuarios=fopen(arUsuarios,"ab");
    if(pArchUsuarios != NULL){
        fwrite(&u,sizeof(stUsuario),1,pArchUsuarios);
        fclose(pArchUsuarios);
    }
}


///FUNCIONES DE MOSTRAR
void mostrarUsuarios(){
    stUsuario usuario;
    FILE *pArchUsuarios=fopen(arUsuarios,"r+b");
    printf("\t\t\t\t\t    << Listado de usuarios >>");
    if(pArchUsuarios!=NULL){
        while(fread(&usuario,sizeof(stUsuario),1,pArchUsuarios)>0){
                mostrarUnUsuario(usuario);
        }
        fclose(pArchUsuarios);
    }
}


void mostrarUnUsuario(stUsuario usuario){


        printf("\n Nombre Usuario........: %s",usuario.nombreUsuario);
        printf("\n Contrasena............: %s",usuario.pass);
        printf("\n Anio de Nacimiento.....: %d",usuario.anioNacimiento);
        if(usuario.genero == 'm')
            printf("\n Genero................: Masculino");
        else
            printf("\n Genero................: Femenino");

        if(usuario.admin == 1)
        {
            printf("\nTipo de usuario: Administrador");
        }
        else
        {
            printf("\nTipo de usuraio: Basico");
        }
    printf("\n___________________________________________\n");

}

///FUNCIONES DE IMPRIMIR OPCIONES
void imprimirOpcionesIniciarSesionAdmin(){
    printf("   1. Nombre de usuario..............: \n");
    printf("   2. Ingrese password...............: \n");
}
void imprimirOpcionesIniciarSesion(){
    printf("   1. Nombre de usuario..............: \n");
    printf("   2. Ingrese password...............: \n");
}

///FUNCIONES DE INICIAR SESION
int iniciarSesionAdmin(){
    stUsuario c;
    int flag = 0;
    FILE *pArchUsuario = fopen(arUsuarios, "rb");
    char nombre[20];
    char pass[20];

    printf("\n   1. Nombre de usuario..............: ");
    fflush(stdin);
    gets(nombre);
    printf("\n   2. Password.......................: ");
    fflush(stdin);
    gets(pass);

    if(pArchUsuario != NULL){
        while((flag == 0) && (fread(&c, sizeof(stUsuario), 1, pArchUsuario) > 0)){
            if((strcmpi(nombre, c.nombreUsuario) == 0) && (strcmpi(pass, c.pass) == 0) && (c.admin == 1)){
                flag = 1;
            }
        }
    fclose(pArchUsuario);
    }
    return flag;
}
int iniciarSesionUsuario(char * usuario[]){
    stUsuario c;
    int flag = 0;
    FILE *pArchUsuario = fopen(arUsuarios, "rb");
    FILE *pArchLogeado = fopen(arLogeado, "wb");
    char nombre[20];
    char pass[20];
    printf("\n   1. Nombre de usuario..............: ");
    fflush(stdin);
    gets(nombre);
    printf("\n   2. Password.......................: ");
    fflush(stdin);
    gets(pass);
    if(pArchUsuario != NULL){
        while((flag == 0) && (fread(&c, sizeof(stUsuario), 1, pArchUsuario) > 0)){
            if((strcmpi(nombre, c.nombreUsuario) == 0) && (strcmpi(pass, c.pass) == 0)){
                flag=1;
                strcpy(usuario,nombre);
                fwrite(&c, sizeof(stUsuario), 1, pArchLogeado);
            }
        }
    fclose(pArchUsuario);
    fclose(pArchLogeado);
    }

    return flag;
}


void verPerfil(){
    stUsuario usuario;
    FILE *pArchiLogeado = fopen(arLogeado, "rb");
    if(pArchiLogeado != NULL){
        fread(&usuario, sizeof(stUsuario), 1, pArchiLogeado);
        mostrarUnUsuario(usuario);
        fclose(pArchiLogeado);
    }
}

void listadosTodosOrdenadoXNombre(){ ///Muestra los usuarios ordenados alfabeticamente.
    stUsuario usuario[100];
    int validos;
    nodoArbol *arbol;
    arbol = inicArbol();
    arbol = pasaUsuariosArbol(arbol);
    inorder(arbol);
}

void inorder(nodoArbol * arbolito)
{
    if(arbolito)
    {
    inorder(arbolito->izq);
    mostrarUnUsuario(arbolito->dato);
    inorder(arbolito->der);
    }
}

nodoArbol *pasaUsuariosArbol(nodoArbol *arbol){ ///Pasa la estructura usuario a un arreglo.

    stUsuario usuario;
    nodoArbol *nuevoNodo;
    FILE * archi=fopen(arUsuarios,"rb");
    while(fread(&usuario,sizeof(stUsuario),1,archi)>0){
            nuevoNodo = crearNodoArbol(usuario);
            arbol = agregar(arbol,nuevoNodo);
    }
    fclose(archi);
    return arbol;
}

nodoArbol * inicArbol()
{
    return NULL;
}

nodoArbol *crearNodoArbol(stUsuario dato)
{
    nodoArbol *nuevoNodo = (nodoArbol*)malloc(sizeof(nodoArbol));
    nuevoNodo->dato = dato;
    nuevoNodo->der = NULL;
    nuevoNodo->izq = NULL;

    return nuevoNodo;
}

nodoArbol * agregar(nodoArbol * arbolito, nodoArbol * nuevoNodo){

    if(arbolito==NULL)
    {
        arbolito = nuevoNodo;
    }
    else{
        if(strcmpi(arbolito->dato.nombreUsuario, nuevoNodo->dato.nombreUsuario)==1){
            arbolito->izq = agregar(arbolito->izq,nuevoNodo);
        }
        else{
            arbolito->der = agregar(arbolito->der,nuevoNodo);
        }
    }
    return arbolito;
}

void siExisteEntoncesMostrar(char nombre[]){
    stUsuario c;
    int flag = 0;
    FILE *pArchUsuarios = fopen(arUsuarios, "rb");
    if(pArchUsuarios != NULL){
        while((flag == 0) && (fread(&c, sizeof(stUsuario), 1, pArchUsuarios) > 0)){
            if(strcmpi(nombre, c.nombreUsuario) == 0){
                mostrarUnUsuario(c);
            }
        }
    fclose(pArchUsuarios);
    }
}
