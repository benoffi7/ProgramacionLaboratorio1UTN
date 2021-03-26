#include <stdio.h>
#include <stdlib.h>

///muestre los numeros naturales desde 1 hasta que el usuario diga basta.

//definir i como Entero //contador
//definir seguir como Caracter //condicion de corte cuando ingresemos un valor distinto de s
//i=1
//seguir = 's'
//MIENTRAS seguir = 's' HACER
//  escribir i
//  i=i+1
//  escribir "desea seguir viendo otro numero natural? s/n"
//  leer seguir
//FIN-MIENTRAS



int main()
{
    int i; //contador
    char seguir; ///char solo almacenan UN caracter
    i=1;
//    seguir = 's';
//    while (seguir == 's')
//    {
//        printf("%i\n",i);
//        i++; ///incrementa en uno
//        printf("desea seguir viendo otro numero natural? s/n \n");
//        fflush(stdin);
//        scanf("%c", &seguir);
//    }
    do {
        printf("%i\n", i);
        i++;
        printf("desea ver otro numero natural?\n");
        fflush(stdin); ///limpia el buffer de entrada
        scanf("%c", &seguir);
        system("cls"); /// limpia la consola de caracteres
    }while(seguir == 's');

    return 0;
}
///do while se ejecuta al menos una vez.
///las sentencias de codigo dentro del cuerpo del bucle al menos una vez se van a recorrer.



//HACER
//..
//..
//MIENTRAS-QUE CONDICION
