#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

void cargaPilaRandom(Pila *p, int limite);
void cargaPilaUsuario(Pila *p, char titulo[]);
int sumaElementosDePila(Pila p);
float promedio(int cant, int total);

int main()
{
    Pila uno, dos, tres, cuatro;
    inicpila(&uno);
    inicpila(&dos);
    inicpila(&tres);
    inicpila(&cuatro);
    int cantidad;
    int total;
    float prom;
    cargaPilaRandom(&uno, 5);

    cargaPilaUsuario(&uno,"Ingrese su edad: ");

    copiaPila(uno, &cuatro);

    mostrar(&uno);
    mostrar(&cuatro);

    cantidad = cuentaElementosEnPila(uno);
    total = sumaElementosDePila(uno);
    prom = promedio(cantidad,total);

    printf("\n La pila Uno tiene %d edades y suman %d y su promedio es %.2f", cuentaElementosEnPila(uno), sumaElementosDePila(uno), prom);

    cargaPilaRandom(&dos, 10);

    cargaPilaUsuario(&dos, "Ingrese su DNI: ");

    cargaPilaRandom(&tres, 15);

    cargaPilaUsuario(&tres, "Ingrese su temperatura: ");

    printf("Pila Uno");
    mostrar(&uno);

    printf("Pila Dos");
    mostrar(&dos);

    printf("Pila Tres");
    mostrar(&tres);


    return 0;
}

/************************************************************************************//**
 *
 * \brief  Esta funcion carga una pila con numeros aleatorios hasta el limite que recibe
 * \param  Pila * - Puntero a pila
 * \param  int limite - Es el limite de numeros a cargar
 * \return nada
 *
 ***************************************************************************************/
void cargaPilaRandom(Pila *p, int limite){
    for(int i=0; i<limite; i++){
        apilar(p, rand()%100);
    }
}

/**************************************************************//**
 * \brief    Carga una pila con intervencion del usuario
 * \param    Pila * - Puntero a pila
 * \param    char [] - El titulo como cadena de caracteres
 * \return   Nada
 ****************************************************************/
void cargaPilaUsuario(Pila *p, char titulo[]){
    int nro;
    char opcion;

    do{
        printf("\n %s", titulo);
        scanf("%d", &nro);

        apilar(p, nro);

        printf("\n ESC para salir - cualquier tecla para continuar ");
        opcion = getch();
        system("cls");
    }
    while(opcion!=27);
}

/************************************************************//**
 * \brief Cuenta los elementos de una pila
 * \param  Pila - Recibe una pila
 * \return int - La cantidad de elementos
 ****************************************************************/
int cuentaElementosEnPila(Pila p){
    Pila aux;
    inicpila(&aux);
    int cont=0;

    while(!pilavacia(&p)){
        cont++;
        apilar(&aux, desapilar(&p));
    }

    return cont;
}

/************************************************************//**
 * \brief Suma los elementos de una pila
 * \param  Pila - Recibe una pila
 * \return int - La suma de los elementos
 ****************************************************************/
int sumaElementosDePila(Pila p){
    Pila aux;
    inicpila(&aux);
    int total=0;

    while(!pilavacia(&p)){
        total = total + tope(&p);
        apilar(&aux, desapilar(&p));
    }

    return total;
}

/**
 * \brief Calcula el promedio
 * \param Int - Cantidad
 * \param Int - Total
 * \return Float - El promedio
 */
float promedio(int cant, int total){
    float prom = 0;
    if(cant>0){
        prom = (float)total/cant;
    }
    return prom;
}

int menor(int n1, int n2){
    int menor;
    if(n1<n2){
        menor = n1;
    }else{
        menor = n2;
    }
    return menor;
}

void copiaPila(Pila origen, Pila *destino){
    while(!pilavacia(&origen)){
        apilar(destino, desapilar(&origen));
    }
}
