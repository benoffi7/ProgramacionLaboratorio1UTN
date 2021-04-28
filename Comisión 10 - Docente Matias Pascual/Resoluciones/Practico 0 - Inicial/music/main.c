#include <time.h>// Para time()
#include <stdlib.h> // Para rand() y srand(unsigned int seed)
#include <stdio.h> // Para rand() y srand(unsigned int seed)
#include <windows.h> // Para rand() y srand(unsigned int seed)

long int ID_random()
{
    struct tm tiempo;

    int anio = tiempo.tm_year +1900; /**El anio se le agrega 1900 ya que la estructura determinada por la libreria cuenta desde el anio 1900 en adelante*/
    int mes = tiempo.tm_mon;
    int dia = tiempo.tm_mday;
    int hs = tiempo.tm_hour;
    int min = tiempo.tm_min;
    int seg = tiempo.tm_sec;

    long int ID = (anio*1000000)+(mes*100000)+(dia*10000)+(hs*1000)+(min*100)+(seg);

    return ID;
}

int main()
{
    long n;
    int i=0;
    srand(time(NULL)+i);


    printf("%ld\n", ID_random());
    for(; ;)
    {
        Beep(rand()%9*100,rand()%5*100);
         printf("%ld\n", ID_random());
    }
    system("pause");
}


