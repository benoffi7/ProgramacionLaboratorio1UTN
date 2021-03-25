#include <stdio.h>
#include <stdlib.h>

///todas las funciones que correspondan a pila llevan ampersand (&)
int main()
{
    int descarte;
    ///crear la pila - declarla
    Pila p;

    ///iniciar las variables internas que indican que la pila esta vacia
    inicpila(&p);

    ///FUNCIONES QUE APILAN
    apilar(&p, ALGUNVALOR); ///algunvalor puede ser un numero,3..4, u otra variable

    ///leer un valor desde el usuario
    ///muestra texto pidiendo el valor
    ///el usuario ingresa unvalor
    ///se apila en la pila correspondiente
    leer(&p);

    ///FUNCION QUE DESAPILA
    ///desapilar nos devuelve el valor que quita, por lo tanto debemos almacenarlo en algun lado
    descarte = desapilar(&p);

    ///funcion que nos devolvia quien estaba en el tope (no lo quita)
    descarte= tope(&p); ///debemos o almacenarlo, o mostrarlo, lo que querramos

    ///funcion que nos indica si la pila esta vacia o no
    ///forma parte SIEMPRE de alguna condicion en un if.. bucle..
    if (!pilavacia(&p)); /// 1: vacia 0: con datos

    ///nos muestra por pantalla los valores que hay dentro de la pila
    mostrar(&p);

}
