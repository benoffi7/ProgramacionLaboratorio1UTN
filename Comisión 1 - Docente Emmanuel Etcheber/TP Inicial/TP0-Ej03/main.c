#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Un maestro desea saber que porcentaje de hombres y que porcentaje
    de mujeres\n y en un grupo de estudiantes*/

    int mujeres=0, hombres=0, totalEstudiantes = 0;
    float porMuj=0, porHom = 0;

    printf("Ingrese cantidad de hombres en el curso\n");
    scanf("%i",&hombres);

    printf("Ingrese cantidad de mujeres en el curso\n");
    scanf("%i",&mujeres);

    totalEstudiantes = hombres + mujeres;

    porHom = (float)hombres*100/(float)totalEstudiantes;
    porMuj = 100 - porHom;

    printf("\nEl porcentaje de hombres es: %.2f \nEl porcentaje de mujeres es: %.2f \n", porHom, porMuj);
    printf("Total de alumnos en el curso: %d\n", totalEstudiantes);

}
