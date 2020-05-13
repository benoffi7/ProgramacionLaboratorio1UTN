#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>

#define ESC 27
#define DIM_CLI 100

typedef struct {
    int nroCliente;
    char nombre[30];
    char apellido[30];
    int dni;
    char calle[50];
    int nro;
}stCliente;


void muestraMenu();
stCliente cargaUnCliente();
int cargaClientes(stCliente c[], int v, int dim);
void muestraClientes(stCliente c[], int v);
void muestraUnCliente(stCliente c);
int buscaUnCliente(stCliente c[], int v, char apellido[]);


int main(){
    char opcion;
    stCliente clientes[DIM_CLI];
    int vClientes=0;

    do{
        system("cls");
        muestraMenu();
        opcion=getch();
        system("cls");

        switch(opcion){
            case 49:
                    vClientes=cargaClientes(clientes, vClientes, DIM_CLI);
                    break;
            case 50:
                    muestraClientes(clientes, vClientes);
                    break;
        }
        system("pause");
    }
    while(opcion!=ESC);

    printf("Hasta la vista Baby!!!!!\n");

    return 0;
}

void muestraMenu(){
    printf("\t\t\t<<< TP 5 - Esctructuras >>>");
    printf("\n\n");
    printf("\n\t 1 - Carga un arreglo de Clientes");
    printf("\n\t 2 - Muestra un arreglo de Clientes");

    printf("\n\n\n");
    printf("ESC para salir ");
}

/*********************************************************//**
*
* \brief Funcion de carga de un Cliente
* \return stCliente
*
*************************************************************/
stCliente cargaUnCliente(){
    stCliente c;

    printf("\n Ingrese el nro de Cliente..........: ");
    scanf("%d", &c.nroCliente);
    printf(" Ingrese el Nombre..................: ");
    fflush(stdin);
    gets(c.nombre);
    printf(" Ingrese el Apellido................: ");
    fflush(stdin);
    gets(c.apellido);
    printf(" Ingrese el DNI.....................: ");
    scanf(" %d", &c.dni);
    printf(" Ingrese la Calle...................: ");
    fflush(stdin);
    gets(c.calle);
    printf(" Ingrese el Nro.....................: ");
    scanf("%d", &c.nro);

    return c;
}

/*********************************************************//**
*
* \brief Funcion de carga de un arreglo de Clientes
* \param arreglo stCliente
* \param int validos
* \param int dimension
* \return int validos
*
*************************************************************/
int cargaClientes(stCliente c[], int v, int dim){
    char opcion=0;

    while(v<dim && opcion!=27){
        system("cls");
        printf("\n Carga de Clientes \n");
        c[v]=cargaUnCliente();
        v++;

        printf("\n\n ESC para salir ");
        opcion=getch();
    }
    return v;
}

/*********************************************************//**
*
* \brief Funcion que muestra un arreglo de Clientes
* \param arreglo stCliente
* \param int validos
* \return void
*
*************************************************************/
void muestraClientes(stCliente c[], int v){
    printf("\n\t\t Listado de Clientes");
    for(int i=0;i<v;i++){
        muestraUnCliente(c[i]);
    }
    printf("\n");
}

/*********************************************************//**
*
* \brief Funcion que muestra un Cliente
* \param arreglo stCliente
* \param int validos
* \return void
*
*************************************************************/
void muestraUnCliente(stCliente c){
    printf("\n  -----------------------------------------------------------------");
    printf("\n  nro de Cliente..........: %d", c.nroCliente);
    printf("\n  Nombre..................: %s", c.nombre);
    printf("\n  Apellido................: %s", c.apellido);
    printf("\n  DNI.....................: %d", c.dni);
    printf("\n  Calle...................: %s", c.calle);
    printf("\n  Nro.....................: %d", c.nro);
}

/*********************************************************//**
*
* \brief Funcion que busca un Cliente en el arreglo
* \param arreglo stCliente
* \param int validos
* \param char apellido[]
* \return int la posición o -1 si no lo encuentra
*
*************************************************************/
int buscaUnCliente(stCliente c[], int v, char apellido[]){
    int i=0;
    int flag=-1;
    while(i<v && flag==-1){
        if(strcmp(apellido, c[i].apellido)==0){
            flag=i;
        }
        i++;
    }
    return flag;
}
