#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#define CANT_MAX 100

/** EJERCICIO 1
    Hacer una función que inserte los datos de cada producto ordenados por id_producto de menor a
    mayor.
*/

int insertarOrdenadoIdProducto(int arr[], int ultimaPos, int dato){

    int i = ultimaPos;
    while (i >= 0 && dato < arr[i]){
        arr[i+1] = arr[i];
        i--;
    }
    arr[i+1] = dato;
    return i+1;     //Retorna la posición donde se insertó
}


int cargarProductos(int id_productos[], float precios[], char estantes[], int cantidades[]){

    int i = 0;
    int val = 0;
    int dato_id;
    float precio;
    char estante;
    int cantidad;
    char op;
    int pos_insertar;
    do{
        printf("Ingrese el id del producto: ");
        scanf("%i", &dato_id);
        pos_insertar = insertarOrdenadoIdProducto(id_productos, val-1, dato_id);

        printf("\nIngrese el precio: ");
        scanf("%f", &precio);

        printf("\nIngrese el estante: ");
        fflush(stdin);
        scanf("%c", &estante);

        printf("\nIngrese la cantidad: ");
        scanf("%i", &cantidad);

        i = val-1;
        while(i >= pos_insertar){       //Se busca para insertar en la misma posición que se insertó en ids_producto para que mantengan la relación
            precios[i+1] = precios[i];  //Se van moviendo para hacer el hueco donde insertar, si insertaran directamente en precios[pos_insertar] se pueden pisar y perder valores
            estantes[i+1] = estantes[i];
            cantidades[i+1] = cantidades[i];
            i--;
        }

        precios[i+1] = precio;
        estantes[i+1] = estante;
        cantidades[i+1] = cantidad;

        val++;
        printf("\nDesea seguir cargando? s/n");
        fflush(stdin);
        scanf("%c", &op);

    }while (op == 's' || op == 'S' && val < CANT_MAX);

    return val;
}

//Función auxiliar
void mostrarArreglos(int productos[], float precios[], char estantes[], int cantidades[], int val){

    for(int i = 0; i < val; i++){
        printf("\n------------------");
        printf("\nid Producto: %i", productos[i]);
        printf("\nPrecio: %f", precios[i]);
        printf("\nEstante: %c", estantes[i]);
        printf("\nCantidad: %i", cantidades[i]);
        printf("\n------------------");

    }
}


/**
    EJERCICIO 2
    Hacer una función que reciba una pila ‘estante_b’ por parámetro y la cargue con todos los id de
    productos del estante ‘b’.
*/

void cargarIdsEstanteB (int ids_productos[], char estantes[], int val, Pila * p){

    for(int i = 0; i < val; i++){
        if (estantes[i] == 'b' || estantes[i] == 'B'){
            apilar(p, ids_productos[i]);
        }
    }
}

/**
    EJERCICIO 3
    Hacer una función que retorne el estante con la mayor cantidad de productos.
*/


char estanteConMasProductos (char estantes[], int cantidades[], int val){
    int totalA = 0, totalB = 0, totalC = 0, totalD = 0, totalE = 0;

    for(int i = 0; i < val; i++){

        switch(estantes[i]){

            case 'a':
                totalA += cantidades[i];
                break;
            case 'b':
                totalB += cantidades[i];
                break;
            case 'c':
                totalC += cantidades[i];
                break;
            case 'd':
                totalD += cantidades[i];
                break;
            case 'e':
                totalE += cantidades[i];
                break;
        }
    }

    printf("\n CANTIDAD DE PRODUCTOS POR ESTANTE: A = %i B = %i C = %i D = %i  E =%i \n", totalA, totalB, totalC, totalD, totalE);

    if (totalA > totalB && totalA > totalC && totalA > totalD && totalA > totalE){

        return 'a';
    }else if (totalB > totalC && totalB > totalD && totalB > totalE){

        return 'b';
    }else if (totalC > totalD && totalC > totalE){

        return 'c';
    }else if (totalD > totalE){

        return 'd';
    }else{

        return 'e';
    }
}

/**
    EJERCICIO 4
    Hacer una función que retorne el estante con el valor de inventario más alto. (la suma del precio *
    cantidad de TODOS los productos)
*/

char estanteMayorInventario(char estantes[], float precios[], int cantidades[], int val){

    int totalA = 0, totalB = 0, totalC = 0, totalD = 0, totalE = 0;
    for(int i = 0; i < val; i++){
        switch(estantes[i]){

            case 'a':
                totalA += precios[i] * cantidades[i];
                break;
            case 'b':
                totalB += precios[i] * cantidades[i];
                break;
            case 'c':
                totalC += precios[i] * cantidades[i];
                break;
            case 'd':
                totalD += precios[i] * cantidades[i];
                break;
            case 'e':
                totalE += precios[i] * cantidades[i];
                break;
        }
    }

    printf("\nVALOR DE INVENTARIO POR ESTANTE: A = %i B = %i C = %i D = %i  E =%i \n ", totalA, totalB, totalC, totalD, totalE);

    if (totalA > totalB && totalA > totalC && totalA > totalD && totalA > totalE){

        return 'a';
    }else if (totalB > totalC && totalB > totalD && totalB > totalE){

        return 'b';
    }else if (totalC > totalD && totalC > totalE){

        return 'c';
    }else if (totalD > totalE){

        return 'd';
    }else{

        return 'e';
    }
}

/**
    EJERCICIO 5
    Hacer una función que busque un id_producto recibido por parámetro y retorne el índice al cual
    pertenece (puede no existir).
*/

int buscarIdProducto(int ids_productos[], int val, int dato){

    for (int i = 0; i < val; i++){
        if (ids_productos[i] == dato){
            return i;
        }
    }
    return -1;
}

/**
    EJERCICIO 6
    Hacer una función que reciba la pila ‘estante_b’,el arreglo de id_productos, de precios y cantidades,
    para informar por cada id_producto en la pila el valor total por la cantidad almacenada.
*/

void valorTotalProductosB(int ids_productos[], float precios[], int cantidades[], int val, Pila pilita){

    int indice;
    int descarte;
    while(!pilavacia(&pilita)){
        indice = buscarIdProducto(ids_productos, val, tope(&pilita));
        if (indice != -1){
            printf("\nEl valor total del producto id nro %i es: %f", tope(&pilita), precios[indice] * cantidades[indice]);
        }
        descarte = desapilar(&pilita);
    }
}

int main()
{
    int ids_productos[CANT_MAX] = {1,2,3,4,5,6,7,8,9,10};
    float precios[CANT_MAX] = {10.0,0.25,16.30,2.00,17.20,4.50,8.20,10.30,14.40,17.10};
    char estantes[CANT_MAX] = {'a','b','e','b','e','c','b','d','c','e'};
    int cantidades[CANT_MAX] = {200,100,240,150,40,80,220,110,95,70};

//    int ids_productos[CANT_MAX];
//    float precios[CANT_MAX];
//    char estantes[CANT_MAX];
//    int cantidades[CANT_MAX];
    int val = 10;

    Pila estante_b;
    inicpila(&estante_b);

//    val = cargarProductos(ids_productos, precios, estantes, cantidades);
//    mostrarArreglos(ids_productos, precios, estantes, cantidades, val);


    mostrarArreglos(ids_productos, precios, estantes, cantidades, val);


    printf("\nEl estante con mayor cantidad de productos es el estante %c.", estanteConMasProductos(estantes, cantidades, val));
    printf("\nEl estante con el inventario más alto es el estante %c.", estanteMayorInventario(estantes, precios, cantidades, val));

    cargarIdsEstanteB(ids_productos, estantes, val, &estante_b);
    mostrar(&estante_b);
    valorTotalProductosB(ids_productos, precios, cantidades, val, estante_b);
    return 0;
}
