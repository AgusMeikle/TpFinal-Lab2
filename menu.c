#include "menu.h"
#include "usuarios.h"


void iniciarMenu(){
    system("color A0");
    int salida = 1;
    do{
        system("cls");
        imprimirCabecera();
        printf("\n\n");
        imprimirOpcionesMenu1();
        salida = switchMenu1();
    }while(salida != 0);
}
void imprimirCabecera(){

        printf("      __________________________________________\n");
        printf("     |                                          |\n");
        printf("     |          << S P O O R I F Y >>           |\n");
        printf("     |__________________________________________|\n\n");
}
void imprimirOpcionesMenu1(){
    printf("   1. Iniciar sesion administrador\n");
    printf("   2. Iniciar sesion\n");
    printf("   3. Registrarse\n");
    printf("   0. Salir\n");
}
int ingresarOpcion(){
    int opcion;
    printf("\n\tIngrese opcion: ");
    fflush(stdin);
    scanf("%i", &opcion);
    return opcion;
}

int switchMenu1(){
    int op;
    char usuario[30];
    do{
        op = ingresarOpcion();
        switch(op){
            case 0:
                printf("\n\tSaliendo del sistema\n");
                break;
            case 1:
                system("cls");
                imprimirCabecera();
                printf("\n");
                int flag;
                flag = iniciarSesionAdmin();
                if(flag == 1){
                    printf("\n\t\t\t-Usted ha ingresado a su cuenta.\n");
                    printf("\n");
                    system("pause");
                    system("cls");
                    imprimirCabecera();
                    printf("\n\n");
                    imprimirMenuAdmin();
                    switchMenuAdmin();
                }else{
                    printf("\n\t\t\t-Usted no ha ingresado a su cuenta.\n");
                    printf("\n");
                    system("pause");
                    system("cls");
                    imprimirCabecera();
                    printf("\n\n");
                    imprimirOpcionesMenu1();
                }

                break;
            case 2:
                system("cls");
                imprimirCabecera();
                printf("\n");
                fflush(stdin);
                int verificar = iniciarSesionUsuario(&usuario);
                if(verificar == 1){
                    printf("\n\t\t\t-Usted ha ingresado a su cuenta.\n");
                    printf("\n");
                    system("pause");
                    system("cls");
                    imprimirCabecera();
                    printf("\n\n");
                    imprimirMenuUsuario();
                    switchMenuUsuario(usuario);
                }else{
                    printf("\n\t\t\t-Usted no ha ingresado a su cuenta.\n");
                    printf("\n");
                    system("pause");
                    system("cls");
                    imprimirCabecera();
                    printf("\n\n");
                    imprimirOpcionesMenu1();
                }
                break;
            case 3:
                system("cls");
                imprimirCabecera();
                printf("\n");
                altaUsuarios();

                printf("\n");
                system("pause");
                system("cls");
                imprimirCabecera();
                printf("\n\n");
                imprimirOpcionesMenu1();
                break;
            default:
                printf("\n\t\t\t\t-Opcion incorrecta.\n");
                printf("\n");
                system("pause");
                system("cls");
                imprimirCabecera();
                printf("\n\n");
                imprimirOpcionesMenu1();
        }
    }while(op != 0);
    return op;
}
void switchMenuAdmin(){
    int op;
    do{
        op = ingresarOpcion();
        switch(op){
        case 0:
            printf("\n\n");
            system("pause");
            system("cls");
            imprimirCabecera();
            printf("\n\n");
            imprimirOpcionesMenu1();
            break;
        case 1:
            system("cls");
            imprimirCabecera();
            printf("\n\n");
            imprimirMenuAdministrarUsuario();
            switchAdministrarUsuarios();
            break;
        case 2:
            system("cls");
            imprimirCabecera();
            printf("\n\n");
            imprimirMenuAdministrarMusica();
            switchAdministrarMusica();
            break;
        default:
            printf("\n\t\t\t\t-Opcion incorrecta.\n");
            printf("\n");
            system("pause");
            system("cls");
            imprimirCabecera();
            printf("\n\n");
            imprimirMenuAdmin();
        }
    }while(op != 0);
    return op;
}
void switchMenuUsuario(char usuario[]){

    int op, validos=0;
    playlist arreglo[10];
    inicArreglo(arreglo,10);
    validos = deArchivoToArreglo(arreglo,10);
    do{
        op = ingresarOpcion();
        switch(op){
        case 0:
            printf("\n\n");
            system("pause");
            system("cls");
            imprimirCabecera();
            printf("\n\n");
            imprimirOpcionesMenu1();
            break;
        case 1:
            system("cls");
            imprimirCabecera();
            printf("\n\n   -Mi perfil.\n");
            verPerfil();
            system("pause");
            system("cls");
            imprimirCabecera();
            printf("\n\n");
            imprimirMenuUsuario();
            break;
        case 2:
            system("cls");
            imprimirCabecera();
            recorrerArrPlaylist(arreglo,validos, usuario);
            system("pause");
            system("cls");
            imprimirCabecera();
            printf("\n\n");
            imprimirMenuUsuario();
            break;
        case 3:
            system("cls");
            imprimirCabecera();
            validos = cargarPlaylist(arreglo,validos,10,usuario);
            cargarPlaylistArchivo(arreglo, validos);
            system("pause");
            system("cls");
            imprimirCabecera();
            printf("\n\n");
            imprimirMenuUsuario();
            break;
        default:
            printf("\n\t\t\t\t-Opcion incorrecta.\n");
            printf("\n");
            system("pause");
            system("cls");
            imprimirCabecera();
            printf("\n\n");
            imprimirMenuUsuario();
        }
    }while(op != 0);
    return op;
}

void switchAdministrarUsuarios(){
    int op;
    do{
        op = ingresarOpcion();
        switch(op){
        case 0:
            printf("\n\n");
            system("pause");
            system("cls");
            imprimirCabecera();
            printf("\n\n");
            imprimirMenuAdmin();
            break;
        case 1:
            system("cls");
            imprimirCabecera();
            printf("\n");
            altaUsuarios();
            printf("\n");
            system("pause");
            system("cls");
            imprimirCabecera();
            printf("\n\n");
            imprimirMenuAdministrarUsuario();
            break;
        case 2:
            system("cls");
            imprimirCabecera();
            char nombre[20];
            int flag;
            printf("\n\n   -Ingrese el usuario que desea consultar: ");
            fflush(stdin);
            gets(nombre);
            flag = buscarUsuarioPorNombre(nombre);
            if(flag == 1){
                printf("___________________________________________");
                siExisteEntoncesMostrar(nombre);
                printf("\n\n");
                system("pause");
                system("cls");
                imprimirCabecera();
                printf("\n\n");
                imprimirMenuAdministrarUsuario();
            }else{
                printf("\n\t\t\t\t-El usuario no existe.");
                printf("\n\n");
                system("pause");
                system("cls");
                imprimirCabecera();
                printf("\n\n");
                imprimirMenuAdministrarUsuario();
            }
            break;
        case 3:
            system("cls");
            imprimirCabecera();
            printf("\n\n");
            listadosTodosOrdenadoXNombre();
            printf("\n\n");
            system("pause");
            system("cls");
            imprimirCabecera();
            printf("\n\n");
            imprimirMenuAdministrarUsuario();
            break;
        default:
            printf("\n\t\t\t\t-Opcion incorrecta.\n");
            printf("\n");
            system("pause");
            system("cls");
            imprimirCabecera();
            printf("\n\n");
            imprimirMenuAdministrarUsuario();
        }
    }while(op != 0);
    return op;
}
void switchAdministrarMusica(){
    int op;
    do{
        op = ingresarOpcion();
        switch(op){
        case 0:
            printf("\n\n");
            system("pause");
            system("cls");
            imprimirCabecera();
            printf("\n\n");
            imprimirMenuAdmin();
            break;
        case 1:
            system("cls");
            imprimirCabecera();
            printf("\n\n");
            altaCanciones();
            printf("\n\n");
            system("pause");
            system("cls");
            imprimirCabecera();
            printf("\n\n");
            imprimirMenuAdministrarMusica();
            break;
        case 2:
            system("cls");
            imprimirCabecera();
            char nombre1[20];
            int banderita;
            printf("\n\n   -Ingrese la cancion que desea consultar: ");
            fflush(stdin);
            gets(nombre1);
            banderita = consultaCancion(nombre1);
            if(banderita == 1){
                printf("\n__________________________________________");
                siExisteEntoncesMostrarCancion(nombre1);
                printf("\n\n");
                system("pause");
                system("cls");
                imprimirCabecera();
                printf("\n\n");
                imprimirMenuAdministrarMusica();
            }else{
                printf("\n\t\t\t\t-La cancion no existe.");
                printf("\n\n");
                system("pause");
                system("cls");
                imprimirCabecera();
                printf("\n\n");
                imprimirMenuAdministrarMusica();
            }
            break;
        case 3:
            system("cls");
            imprimirCabecera();
            printf("\n\n");
            imprimirMenuOrdenacionCanciones();
            switchMenuOrdenacionCanciones();
            break;
        default:
            printf("\n\t\t\t\t-Opcion incorrecta.\n");
            printf("\n");
            system("pause");
            system("cls");
            imprimirCabecera();
            printf("\n\n");
            imprimirMenuAdministrarMusica();
        }
    }while(op != 0);
    return op;
}
void switchMenuOrdenacionCanciones(){
    int op;
    do{
        op = ingresarOpcion();
        switch(op){
        case 0:
            printf("\n\n");
            system("pause");
            system("cls");
            imprimirCabecera();
            printf("\n\n");
            imprimirMenuAdministrarMusica();
            break;
        case 1:
            printf("\n\n");
            system("pause");
            system("cls");
            imprimirCabecera();
            printf("\n\n");
            printf("\n______________________________________________\n");
            listadosTodosOrdenadoXTitulo();
            printf("\n\n");
            system("pause");
            system("cls");
            imprimirCabecera();
            printf("\n\n");
            imprimirMenuOrdenacionCanciones();
            break;
        case 2:
            printf("\n\n");
            system("pause");
            system("cls");
            imprimirCabecera();
            listadosTodosOrdenadoXGenero();
            printf("\n\n");
            system("pause");
            system("cls");
            imprimirCabecera();
            printf("\n\n");
            imprimirMenuOrdenacionCanciones();
        default:
            printf("\n\t\t\t\t-Opcion incorrecta.\n");
            printf("\n");
            system("pause");
            system("cls");
            imprimirCabecera();
            printf("\n\n");
            imprimirMenuOrdenacionCanciones();
        }
    }while(op != 0);
    return op;
}
void imprimirMenuOrdenacionCanciones(){
    printf("   1. Ordenar por titulo\n");
    printf("   2. Ordenar por genero\n");
    printf("   0. Volver\n");
}
void imprimirMenuAdministrarUsuario(){
    printf("   1. Alta de usuario\n");
    printf("   2. Consulta\n");
    printf("   3. Listado de usuarios\n");
    printf("   0. Volver\n");
}
void imprimirMenuAdministrarMusica(){
    printf("   1. Alta de cancion\n");
    printf("   2. Consulta\n");
    printf("   3. Listado de canciones\n");
    printf("   0. Volver\n");
}
void imprimirMenuAdmin(){
    printf("   1. Administrar Usuarios\n");
    printf("   2. Administrar Musica\n");
    printf("   0. Salir\n");
}
void imprimirMenuUsuario(){
    printf("   1. Ver mi perfil\n");
    printf("   2. Ver mi playlist\n");
    printf("   3. Crear playlist\n");
    printf("   0. Salir\n");
}

