#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void muestraMenu();
int funcion01(int a[], int v, int dim);
void funcion02(int a[], int v);
int funcion03(char a[], int v, int dim);
void funcion04(char a[], int v);
void funcion05(int a[], int v);
void funcion06(int a[], int v);
void funcion07(int a[], int v);
int funcion08(int a[], int v, int dim);
int cargaArreglo(int a[], int v, int dim);
void muestraArreglo(int a[], int v);
int buscaInt(int a[], int v, int dato);
int cargaArregloChar(char a[], int v, int dim);
void muestraArregloChar(char a[], int v);
int buscaInt(int a[], int v, int dato);
int buscaMenorInt(int a[], int v);
int buscaPosMenorInt(int a[], int v, int c);
void ordenaSelInt(int a[], int v);
int busquedaBinariaInt(int arreglo[], int validos, int dato);
int cargoArregloIntRandom(int a[], int v, int dim, int min, int max);

#define D_PRIMER_ARREGLO 100
#define D_LETRAS 24
const char ESC = 27;

int main(){
    int primerArreglo[D_PRIMER_ARREGLO];
    int paValidos = 0;

    char letras[D_LETRAS];
    int leValidos = 0;

    char opcion;

    do{
        system("cls");
        muestraMenu();
        opcion=getch();
        system("cls");
        switch(opcion){
            case 49: /// 49 es el numero ASCII de la tecla 1
                    paValidos = funcion01(primerArreglo, paValidos, D_PRIMER_ARREGLO);
                    break;
            case 50:
                    funcion02(primerArreglo,paValidos);
                    break;
            case 51:
                    leValidos = funcion03(letras, leValidos, D_LETRAS);
                    break;
            case 52:
                    funcion04(letras, leValidos);
                    break;
            case 53:
                    funcion05(primerArreglo, paValidos);
                    break;
            case 54:
                    funcion06(primerArreglo, paValidos);
                    break;
            case 55:
                    funcion07(primerArreglo, paValidos);
                    break;
            case 56:
                    paValidos=funcion08(primerArreglo, paValidos, D_PRIMER_ARREGLO);
        }
        printf("\n\n\n");
        system("pause");
    }
    while(opcion!=ESC);

    printf("\n\n Hasta la vista Baby!!!!!\n");
    return 0;
}

void muestraMenu(){
    printf("\t\t\t<<< TP04 - Arreglos >>>");
    printf("\n\n");
    printf("\n\t 1 - Cargo el Arreglo de enteros");
    printf("\n\t 2 - Muestro el Arreglo de enteros");
    printf("\n\t 3 - Cargo el Arreglo de caracteres");
    printf("\n\t 4 - Muestro el Arreglo de caracteres");
    printf("\n\t 5 - Buscar un dato entero");
    printf("\n\t 6 - Buscar el menor elemento del arreglo de tipo Int");
    printf("\n\t 7 - Ordena por Seleccion un arreglo de tipo Int");
    printf("\n\t 8 - Carga arreglo aleatorio");
    printf("\n\n");
    printf("\t ESC para salir");
    printf("\n\n");
}

int funcion01(int a[], int v, int dim){
    printf("\nEj 1\n");
    v = cargaArreglo(a, v, dim);
    return v;
}

void funcion02(int a[], int v){
    printf("\nEj 2\n");
    muestraArreglo(a,v);
}

int funcion03(char a[], int v, int dim){
    printf("\nCarga un arreglo de caracteres\n");
    v = cargaArregloChar(a, v, dim);
    printf("\n\n\n");
    return v;
}

void funcion04(char a[], int v){
    printf("\nMuestro el arreglo de caracteres\n");
    muestraArregloChar(a,v);
}

void funcion05(int a[], int v){
    int dato;
    int encontrado;
    printf("\n Busca datos enteros\n\n");
    printf("\n Ingrese el dato a buscar: ");
    scanf("%d",&dato);
    encontrado = buscaInt(a, v, dato);
    if(encontrado){ /// es igual a poner (encontrado == 1)
        printf("El dato %d se encuentra en el arreglo",dato);
    }else{
        printf("El dato %d NO se encuentra en el arreglo",dato);
    }
/**
    if(buscaInt(a, v, dato)){ /// es igual a poner (encontrado == 1)
        printf("El dato %d se encuentra en el arreglo %d", dato");
    }else{
        printf("El dato %d NO se encuentra en el arreglo",dato);
    }
*/
    printf("\n\n\n");
}

void funcion06(int a[], int v){
    printf("\nBusca el menor elemento de un arreglo de Int\n");
    printf("\nEl menor elemento del arreglo es: %d usando la funcion buscaMenorInt",buscaMenorInt(a,v));
    int i = buscaPosMenorInt(a, v, 0);
    printf("\nEl menor elemento del arreglo es: %d usando la funcion buscaPosMenorInt",a[i]);
}

void funcion07(int a[], int v){
    printf("\nOrdena por Seleccion un arreglo de tipo int\n");
    ordenaSelInt(a,v);
    printf("\nArreglo ordenado...\n");
}

int funcion08(int a[], int v, int dim){
    printf("\nCargo de manera aleatoria un arreglo de tipo int\n");
    v=cargoArregloIntRandom(a,v,dim,0,100);
    printf("\nArreglo cargado...\n");
    return v;
}

/************************************************************************//**
*
* \brief Funcion que carga un arreglo es de tipo int por el usuario
* \param el arreglo
* \param validos
* \param dimension
* \return validos
*
***************************************************************************/
int cargaArreglo(int a[], int v, int dim){
    char opcion = 0;

    while(v<dim && opcion!=27){
        system("cls");
        printf("\n\n Cargando Arreglo de INT......");
        printf("\n Ingrese un numero: ");
        scanf("%d",&a[v]);

        v++;
        printf("\n\n\t ESC para salir .....");
        opcion=getch();
    }
    return v;
}

/************************************************************************//**
*
* \brief Funcion que muestra un arreglo es de tipo int
* \param el arreglo
* \param validos
* \return void
*
***************************************************************************/
void muestraArreglo(int a[], int v){
    printf("\n Muestro arreglo \n");
    for(int i=0;i<v;i++){
        if(i%10==0){
            printf("\n");
        }
        printf("%d - ", a[i]);
    }
}

/************************************************************************//**
*
* \brief Funcion que busca un dato en un arreglo de enteros
* \param el arreglo
* \param validos
* \param dato a buscar
* \return bool - 0 si no existe - 1 si el dato existe
*
***************************************************************************/
int buscaInt(int a[], int v, int dato){
    int flag=0; ///0 es false - falso / 1 es true - verdadero
    int i=0;

    while(i<v && flag==0){
        if(a[i] == dato){
            flag = 1;
        }
        i++;
    }

    return flag;
}


/************************************************************************//**
*
* \brief Funcion que carga un arreglo es de tipo char por el usuario
* \param el arreglo
* \param validos
* \param dimension
* \return validos
*
***************************************************************************/
int cargaArregloChar(char a[], int v, int dim){
    char opcion = 0;

    while(v<dim && opcion!=27){    /// for(i=0;i<dim && opcion!=27;i++)
        system("cls");
        printf("\n\n Cargando Arreglo de CHAR ......");
        printf("\n Ingrese un caracter: ");
        fflush(stdin);
        scanf("%c",&a[v]);

        v++;
        printf("\n\n\t ESC para salir .....");
        opcion=getch();
    }
    return v;
}

/************************************************************************//**
*
* \brief Funcion que muestra un arreglo es de tipo char
* \param el arreglo
* \param validos
* \return void
*
*****************************************************************************/
void muestraArregloChar(char a[], int v){
    for(int i=0;i<v;i++){
        printf("%c", a[i]);
    }
}

/*************************************************************************************//**
*
* \brief Funcion busca y retorna el menor elemento de un arreglo de tipo Int
* \param el arreglo
* \param validos
* \return el menor elemento
*
*****************************************************************************************/
int buscaMenorInt(int a[], int v){
    int i=0;
    int menor=a[i];
    for(i=1;i<v;i++){
        if(a[i]<menor){
            menor=a[i];
        }
    }

    return menor;
}

/***************************************************************************************//**
*
* \brief Funcion busca y retorna la posicion del menor elemento de un arreglo de tipo Int
* \param el arreglo
* \param validos
* \param el comienzo del arreglo
* \return la posicion del menor elemento
*
********************************************************************************************/
int buscaPosMenorInt(int a[], int v, int c){
    int i = c;
    int posMenor = i;
    i++;
    while(i<v){
        if(a[i]<a[posMenor]){
            posMenor = i;
        }
        i++;
    }

    return posMenor;
}

/************************************************************************************//**
*
* \brief Funcion que ordena un arreglo de tipo Int
* \param el arreglo
* \param validos
* \return es de tipo void
*
****************************************************************************************/
void ordenaSelInt(int a[], int v){
    int posMenor=0;
    int aux;
    for(int i=0;i<v-1;i++){
        posMenor=buscaPosMenorInt(a,v,i);
        aux=a[posMenor];
        a[posMenor]=a[i];
        a[i]=aux;
    }
}

/************************************************************************************//**
*
* \brief Funcion que retorna un entero aleatorio entre min y max
* \param minimo
* \param maximo
* \return un int aleatorio
*
****************************************************************************************/
int randomRango(int min, int max){
    return rand()%(max-min)+min;
}

/************************************************************************************//**
*
* \brief Funcion que carga un arreglo de tipo Int aleatorio entre min y max
* \param el arreglo
* \param validos
* \param la dimension
* \param min
* \param max
* \return validos
*
****************************************************************************************/
int cargoArregloIntRandom(int a[], int v, int dim, int min, int max){
    int i;
    for(i=v; i<dim; i++){
        a[i]=randomRango(min,max);
    }
    return i;
}

/************************************************************************************//**
*
* \brief Funcion que realiza una busqueda binaria en un arreglo ordenado de tipo Int
* \param el arreglo
* \param validos
* \param el dato a buscar
* \return Si encuentro el dato retorno el subíndice y si no lo encuentro retorno -1
*
****************************************************************************************/
int busquedaBinariaInt(int arreglo[], int validos, int dato){
    int medio, pri, ult, encontrado;
    encontrado = -1; ///Asumo que no lo encontré asignando -1
    pri = 0; ///primer índice será el 0
    ult = validos-1; ///inicializo con el último índice válido de mi arreglo
    medio = (pri + ult) / 2; ///Partimos el arreglo a la mitad
    while ( (pri < ult) && (arreglo[medio] != dato) ){
        if (arreglo[medio] > dato){
            ult = medio - 1;///descarto la mitad derecha del arreglo
        } else {
            pri = medio + 1; ///descarto la mitad izquierda
        }
        medio=(pri+ult) / 2; ///vuelvo a partir a la mitad
    }
    if (arreglo[medio] == dato){
        encontrado = medio; /// si lo encuentro retorno el subindice
    }
    return encontrado;
}

/************************************************************************************//**
*
* \brief Funcion que inserta un elemento en un arreglo ordenado de tipo Int
* \brief Es responsabilidad del programador verificar que hay espacio en el arreglo
* \param el arreglo
* \param validos
* \param el dato a insertar
* \return validos
*
****************************************************************************************/
int insertaArrInt(int a[], int v, int dato){
    int i = v-1;
    while(i>=0 && a[i]>dato){
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=dato;

    return i;
}

/************************************************************************************//**
*
* \brief Funcion que inserta un elemento en un arreglo ordenado de tipo CHAR
* \brief Es responsabilidad del programador verificar que hay espacio en el arreglo
* \param el arreglo
* \param validos
* \param el dato a insertar
* \return validos
*
****************************************************************************************/
int insertaArrChar(char a[], int v, char dato){
    int i = v-1;
    while(i>=0 && a[i]>dato){
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=dato;

    return i;
}

/************************************************************************************//**
*
* \brief Funcion que inserta un elemento en un arreglo ordenado de tipo INT
* \brief Para ser usada con el algoritmo de Ordenacion por Insercion
* \param el arreglo
* \param ultima posicion
* \param el dato a insertar
* \return void
*
****************************************************************************************/
void insertaOrdenadoInt(int a[], int v, int dato){
    int i = v;
    while(i>=0 && a[i]>dato){
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=dato;
}

/************************************************************************************//**
*
* \brief Funcion que ordena por Insercion un arreglo de tipo INT
* \param el arreglo
* \param validos
* \return void
*
****************************************************************************************/
void ordenaInsInt(int a[], int v){
    int i=0;
    while(i<v-1){
        insertaOrdenadoInt(a,i,a[i+1]);
        i++;
    }
}
