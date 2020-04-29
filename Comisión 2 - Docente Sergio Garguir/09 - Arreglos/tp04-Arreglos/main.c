#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void muestraMenu();
int funcion01(int a[], int v, int dim);
void funcion02(int a[],int v);
int funcion03(int v);
int funcion04(char a[], int v, int dim);
void funcion05(char a[],int v);
void funcion06(int a[], int v);
int cargaArregloInt(int a[], int v, int dim);
void mostrarArregloInt(int a[], int v);
int cargaArregloChar(char a[], int v, int dim);
void mostrarArregloChar(char a[], int v);
int buscoInt(int a[], int v, int dato);
int buscaMenorInt(int a[], int v);
int buscaMenorPosInt(int a[], int v, int inicio);
void ordenarSelInt(int a[], int v);

#define DDNI 100
#define DLETRAS 24
const char ESC = 27;

int main(){
    char opcion;
    int a[]={1,2,2,3,5,3,3,3,3,3,3,3,5};
    int dni[DDNI];
    int vDni=0;
    char letras[DLETRAS];
    int vLetras=0;

    do{
        system("cls");
        muestraMenu();
        opcion=getch();
        system("cls");

        switch(opcion){
            case 49: /// 49 es el codigo ASCII de la tecla 1  - también pueden usar '1'
                    vDni = funcion01(dni, vDni, DDNI);
                    break;
            case 50:
                    funcion02(dni, vDni);
                    break;
            case 51:
                    vDni = funcion03(vDni);
                    ///vDni = 0;
                    break;
            case 52:
                    vLetras = funcion04(letras, vLetras, DLETRAS);
                    break;
            case 53:
                    funcion05(letras, vLetras);
                    break;
            case 54:
                    funcion06(dni, vDni);
                    break;
            case 55:
                    funcion07(dni, vDni);
                    break;
            case 'a': /// 97
                    break;
            case 'A': /// 65
                    break;
        }
        system("pause");
    }
    while(opcion!=ESC);

    printf("Hasta la vista Baby!!!!!\n");
    return 0;
}

void muestraMenu(){
    printf("\t\t\t<<< Mi Primer Menu >>>");
    printf("\n\n");
    printf("\n\t 1 - Carga un arreglo de enteros");
    printf("\n\t 2 - Muestra un arreglo de enteros");
    printf("\n\t 3 - Vacia un arreglo");
    printf("\n\t 4 - Carga un arreglo de letras");
    printf("\n\t 5 - Muestra un arreglo de letras");
    printf("\n\t 6 - Busco un dato en un arreglo de Int");
    printf("\n\t 7 - Ordena un arreglo de Int");
    printf("\n\n");
    printf("ESC para salir ");
}

int funcion01(int a[], int v, int dim){
    printf("\nCarga de Arreglo de numeros\n");
    v = cargaArregloInt(a, v, dim);
    printf("\n\n\n");

    return v;
}

void funcion02(int a[], int v){
    printf("\nMuestra el arreglo\n");
    mostrarArregloInt(a, v);
    printf("\n\n\n");
}

int funcion03(int v){
    printf("Vacia un arreglo");
    v = 0;
    printf("\n\n\n");
    return v;
}

int funcion04(char a[], int v, int dim){
    printf("\nCarga de Arreglo de letras\n");
    v = cargaArregloChar(a, v, dim);
    printf("\n\n\n");

    return v;
}

void funcion05(char a[], int v){
    printf("\nMuestra el arreglo de letras\n");
    mostrarArregloChar(a, v);
    printf("\n\n\n");
}

void funcion06(int a[], int v){
    int dato;
    int encontrado;

    printf("\n\n Busca un dato en el arrelgo de Int\n\n");
    printf("\n\n Ingrese el dato a buscar: ");
    scanf("%d", &dato);
    encontrado = buscoInt(a, v, dato);
    if(encontrado){  /// if(encontrado == 1)
        printf("\n\n El numero %d existe en el arreglo", dato);
    }else{
        printf("\n\n El numero %d NO existe en el arreglo", dato);
    }
}

void funcion07(int a[], int v){
    printf("\nOrdena el arreglo de menor a mayor\n");
    ordenarSelInt(a, v);
    printf("\n\nOrdenación terminada\n");
}

/**************************************************************
*
* \Carga un arreglo de tipo Int
* \param Recibo el arreglo de Int, sus validos y su dimension
* \return cantidad cargada
*
**************************************************************/
int cargaArregloInt(int a[], int v, int dim){
    char opcion;

    while(v<dim && opcion!=ESC){
        system("cls");
        printf("\n Ingrese un numero: ");
        scanf("%d", &a[v]);

        printf("\n\n\t ESC para salir ...");
        opcion=getch();
        v++;
    }
    return v;
}

/**************************************************************
*
* Muestra un arreglo de tipo Int
* Recibo el arreglo de Int y sus validos
*
**************************************************************/
void mostrarArregloInt(int a[], int v){
    for(int i=0;i<v;i++){
        printf("%d - ", a[i]);
    }
}

/**************************************************************
*
* Carga un arreglo de tipo Char
* Recibo el arreglo de Char, sus validos y su dimension
*
**************************************************************/
int cargaArregloChar(char a[], int v, int dim){
    char opcion;

    while(v<dim && opcion!=ESC){
        system("cls");
        printf("\n Ingrese una letra: ");
        fflush(stdin);
        scanf("%c", &a[v]);

        printf("\n\n\t ESC para salir ...");
        opcion=getch();
        v++;
    }
    return v;
}

/**************************************************************
*
* Muestra un arreglo de tipo Char
* Recibo el arreglo de Char y sus validos
*
**************************************************************/
void mostrarArregloChar(char a[], int v){
    for(int i=0;i<v;i++){
        printf("%c - ", a[i]);
    }
}

/**************************************************************
*
* Busca un dato en un arreglo de tipo Int
* Recibo el arreglo de int, sus validos y el dato
* Retorno un booleano - 0 es falso/false - 1 es verdadero/true
*
**************************************************************/
int buscoInt(int a[], int v, int dato){
    int flag=0;
    int i=0;

    while(i<v && flag==0){
        if(a[i]==dato){
            flag = 1;
        }
        i++;
    }

    return flag;
}

/**************************************************************
*
* Busca el menor elemento en un arreglo de tipo Int
* Recibo el arreglo de int y sus validos
* Retorno el dato menor
*
**************************************************************/
int buscaMenorInt(int a[], int v){
    int i=0;
    int menor = a[i];
    for(i=1;i<v;i++){
        if(a[i]<menor){
            menor=a[i];
        }
    }
    return menor;
}

/**********************************************************************************
*
* Busca el menor elemento en un arreglo de tipo Int
* Recibo el arreglo de int, sus validos y desde donde quiero comenzar la busqueda
* Retorna la posicion del menor elemento
*
***********************************************************************************/
int buscaMenorPosInt(int a[], int v, int inicio){
    int posMenor = inicio;
    int i=inicio+1;
    while(i<v){
        if(a[i]<a[posMenor]){
            posMenor = i;
        }
        i++;
    }

    return posMenor;
}

/**************************************************************
*
* Ordena un arreglo de tipo Int
* Recibo el arreglo de int y sus validos
* Lo ordena de menor a mayor
*
**************************************************************/
void ordenarSelInt(int a[], int v){
    int posMenor;
    int aux;
    int i = 0;

    while(i<v-1){
        posMenor = buscaMenorPosInt(a, v, i);
        aux = a[posMenor];
        a[posMenor] = a[i];
        a[i] = aux;
        i++;
    }
}
