#include <stdio.h>
#include <stdlib.h>

void cualquiernombrevalidosincaracteresrarosniespacios ();//prototipo
void ejercicioDescuento();
void porcentajeHombreMujeres();
void ejercicioCamisas();
void piezas();
void piezas2();


// int suma ; //NO si lo hacen , hola marzo 2050

int main()
{
    int op  = 1;

    do
    {
        system("cls");//limpia la pantalla
        printf("1-suma\n");
        printf("2-descuento\n");
        printf("3-porcentaje\n");
        printf("4-camisas\n");
        printf("5-piezas\n");
        printf("6-piezas 2\n");
        printf("7-salir\n");

        printf("ingrese un numero\n");
        fflush(stdin);
        scanf("%d",&op);

        switch (op)
        {
            case 1: cualquiernombrevalidosincaracteresrarosniespacios (); //invocacion
                    break;
            case 2: ejercicioDescuento();
                    break;
            case 3:  porcentajeHombreMujeres();
                    break;
            case 4: ejercicioCamisas();
                    break;
            case 5: piezas();
                    break;
            case 6: piezas2();
                    break;
            case 7: printf("\ngracias\n");
                    break;
            default: printf("nada que ver!");
        }


    }

    while (op < 7);



    return 0;
}
//alias esta
void cualquiernombrevalidosincaracteresrarosniespacios () //implementacion
{
    int numero1 = 0;
    int numero2 = 0;
    int suma = 0;

    printf("ingrese un numero\n");
    fflush(stdin);
    scanf("%d",&numero1);

    printf("ingrese un numero\n");
    fflush(stdin);
    scanf("%d",&numero2);

    system("cls"); //limpia

    suma = numero1  + numero2;

    printf("la suma es ... %d\n",suma);
}

void ejercicioDescuento()
{


    float descuento = 0;
    int descuentoAAplicar = 15;
    float compra = 0;
    float total = 0; // double
    printf("cuanto gastaste?\n");
    fflush(stdin);
    scanf("%f",&compra);

    //100 -> compra
    // 15 -> 15*compra /100
    descuento =  (descuentoAAplicar * compra)/100;
    total = compra - descuento;
    printf("el total es ...%2.f", total);
}
void porcentajeHombreMujeres()
{

    int cantidadHombres = 0;
    int cantidadMujeres = 0;
    int total = 0;
    float porcentajeMujeres = 0;
    float porcentajeHombres = 0;

    printf("ingrese cantidad de hombres\n");
    scanf("%d",&cantidadHombres);
    printf("ingrese cantidad de mujeres\n");
    scanf("%d",&cantidadMujeres);

    total = cantidadHombres + cantidadMujeres;

    //total -> 100
    // cantidadHombres -> cantidadHombres*100/total

    porcentajeHombres = (cantidadHombres*100/total);
    porcentajeMujeres = (cantidadMujeres*100/total);

    printf("los porcentajes son...hombres %f y mujeres %f\n",porcentajeHombres,porcentajeMujeres);
    system("pause");

}

void ejercicioCamisas()
{
    int cantidadCamisas = 0;
    int descuentoAAplicar = 10;
    int subTotal = 0;
    float descuento = 0;
    float total = 0;
    printf("ingrese cantiad de camisas");
    fflush(stdin);
    scanf("%d",&cantidadCamisas);
    if (cantidadCamisas >= 3)
    {
        descuentoAAplicar = 20;
    }
    /*
    else
        {
            descuentoAAplicar = 10;
        }
        */
    printf("ingrese total de la compra");
    fflush(stdin);
    scanf("%d",&subTotal);
    //100 -> sub
    //descuentoAAplicar -> descuentoAAplicar*sub/100
    descuento = (descuentoAAplicar*subTotal/100);
    total =  subTotal - descuento;
    printf("el total es ... %f",total);
    system("pause");

}

void piezas()
{
    char seguir = 's';
    float perfil = 0;
    int cantidadAptas = 0;
    while (seguir == 's')
    {

        printf("ingrese el perfil");
        scanf("%f",&perfil);

        if ((perfil>=1.20) && (perfil<=1.30))
        {
            cantidadAptas++; //incrementa y suma
        }

        printf("ingrese S para seguir");
        fflush(stdin);
        scanf("%c",&seguir);
    }
    printf("tus aptas son ... %d",cantidadAptas);
    system("pause");
}

void piezas2()
{

    float perfil = 0;
    int cantidadAptas = 0;
    int cantidadPiezas = 0;
    int contador = 1;

      printf("ingrese cantidad de piezas");
        scanf("%d",&cantidadPiezas);

    while (contador <= cantidadPiezas)
    {

        printf("ingrese el perfil de la pieza %d de %d",contador,cantidadPiezas);
        scanf("%f",&perfil);

        if ((perfil>=1.20) && (perfil<=1.30))
        {
            cantidadAptas++; //incrementa y suma
        }

        contador = contador + 1;


    }
    printf("tus aptas son ... %d",cantidadAptas);
    system("pause");
}

