#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
    char opcion;
    do{
        muestraMenu();
        opcion=getch();
        switch(opcion){
            case 49:
                    system("cls");
                    printf("Ej 1");
                     /// aca va el codigo del ej 1
                    printf("\n\n\n");
                    system("pause");
                    break;
            case 50:
                    system("cls");
                    printf("Ej 2");
                    /// aca va el codigo del ej 2
                    printf("\n\n\n");
                    system("pause");
                    break;
            case 51 ... 53:

                    system("cls");
                    printf("Ej 3");
                    /// aca va el codigo del ej 3
                    printf("\n\n\n");
                    system("pause");
                    break;
            case 'a':
            case 'A':
                    printf("Ej a");
                    /// aca va el codigo del ej 3
                    printf("\n\n\n");
                    system("pause");
                    break;

        }
    }
    while(opcion!=27);
    printf("Hasta la vista Baby!!!!!\n");
    return 0;
}

void muestraMenu(){
    printf("\t\t\t<<< Primer Menu >>>");
    printf("\n\n");
    printf("\n\t 1 - Ejercicio 1");
    printf("\n\t 2 - Ejercicio 2");
    printf("\n\t 3 a 5 - Ejercicio 3 al 5");
    printf("\n\t a - Ejercicio a");
    printf("\n\n");
    printf("ESC para salir");
    printf("\n\n");
}
