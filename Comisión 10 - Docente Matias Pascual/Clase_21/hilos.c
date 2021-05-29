#include <pthread.h> /// para usar hilos
#include <windows.h>
#include "../Librerias/utiles.h"

void* funcion_a()
{
    for(int i = 0; i < 100; i++)
    {
        Sleep(2);

        color(2);

        printf("A : %d \n", i);
    }

    //pthread_exit(0);
}

void* funcion_b()
{
    for(int i = 0; i < 100; i++)
    {
        Sleep(10);

        color(12);

        printf("B : %d \n", i);

        /// terminamos el hilo al llegar a i = 3
        if(i == 3)
        {
            pthread_exit(0);
        }
    }
}

void funcionPrincipal()
{
    /// declara el hilo
    pthread_t hiloA;
    pthread_t hiloB;

    printf("principio \n");

    /// crea el hilo y comienza su ejecucion
    pthread_create(&hiloA, NULL, funcion_a, NULL);
    pthread_create(&hiloB, NULL, funcion_b, NULL);

    /// freno esta funcion para darle tiempo a los hilos a terminar
    //Sleep(5000);

    /// espera a que termine el hilo para salir del programa
    pthread_join(hiloA, NULL);
    pthread_join(hiloB, NULL);

    //funcion_a();
    //funcion_b();

    color(7);

    printf("final \n");
}

