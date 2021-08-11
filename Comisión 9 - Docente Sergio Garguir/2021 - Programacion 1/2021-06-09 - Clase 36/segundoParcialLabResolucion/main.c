#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
1.	Hacer una función que verifique si un dato existe en un archivo buscando por dni. Retornará v ó f.
10 pts.

2.	Hacer una función que cargue pacientes en un archivo validando que sean únicos y que la temperatura sea válida, también deberá generar un id único y autoincremental. Modularizar.
20 pts.

3.	Hacer una función que muestre los pacientes del archivo. Modularizar.
10 pts.

4.	Hacer una función que pase el archivo a un arreglo de Pacientes.
10 pts.

5.	Hacer una función que retorne la cantidad de pacientes existentes en un archivo.
10 pts.

6.	Hacer una función que pase del arreglo al archivo de sanos todos aquellos pacientes cuya temperatura sea menor o igual a un dato recibido (no usamos como límite una temperatura fija porque es un dato que puede variar) y el resto al archivo de enfermos.
20 pts.

7.	Hacer una función que muestre el porcentaje de sanos y enfermos, para ello deberá usar la función que calcula el total de pacientes para cada archivo.
20 pts.


*/

typedef struct
{
    int id;
    char nombre[30];
    char apellido[30];
    char dni[15];
    float temperatura;
} stPaciente;

int main()
{
    stPaciente pacientes[1500];


    printf("Hello world!\n");
    return 0;
}

int existeDNI(FILE *pArch, char dni[])
{
    stPaciente p;
    int existe = 0;

    rewind(pArch);
    ///fseek(pArch, 0,SEEK_SET);
    if(pArch)
    {
        while(existe == 0 && fread(&p,sizeof(stPaciente),1,pArch) > 0)
        {
            if(strcmp(p.dni,dni) == 0)
            {
                existe = 1;
            }
        }
    }

    return existe;
}

void cargaPacientes(char nombreArchivo[])
{
    stPaciente p;

    char opcion;
    int id = getLastId(nombreArchivo) + 1;
    int validar;

    FILE *archi = fopen(nombreArchivo,"ab");

    if(archi){
        do{

            p.id = id;
            printf("Nombre..........: ");
            fflush(stdin);
            scanf("%s", p.nombre);

            printf("Apellido........: ");
            fflush(stdin);
            scanf("%s", p.apellido);

            do
            {
                printf("DNI.............: ");
                scanf("%s", p.dni);

                validar = existeDNI(archi,p.dni);
                if(validar)
                {
                    printf("\nDNI ya ingresado, por favor, ingreselo nuevamente.\n\n");
                }
            }
            while(validar == 1);

            do
            {
                printf("Temperatura.....: ");
                scanf("%f", &p.temperatura);

                if(p.temperatura < 35 || p.temperatura > 40)
                {
                    printf("\nTemperatura incorecta, debe estar entre 35 y 40 grados.\n\n");
                }
            }
            while(p.temperatura < 35 || p.temperatura > 40);

            fwrite(&p,sizeof(stPaciente),1,archi);

            printf("ESC para salir - cualquier tecla para continuar: ");
            opcion = getch();

            id++;
            system("cls");

        }
        while(opcion != 27);

        fclose(archi);
    }
}

void muestraUnPaciente(stPaciente p){
    printf("\nId.............: %d", p.id);
    printf("\nNombre.........: %s", p.nombre);
    printf("\nApellido.......: %s", p.apellido);
    printf("\nDNI............: %s", p.dni);
    printf("\nTemperatura....: %.2f", p.temperatura);
}

void muestraArchivoPacientes(char nombreArchivo[]){
    stPaciente p;
    FILE *archi = fopen(nombreArchivo,"rb");

    if(archi){
        while(fread(&p,sizeof(stPaciente),1,archi) > 0){
            muestraUnPaciente(p);
            printf("\n----------------------------------\n");
        }
        fclose(archi);
    }
}

int getLastId(char nombreArchivo[]){
    stPaciente p;
    int id = 0;
    FILE *archi = fopen(nombreArchivo,"rb");

    if(archi){

        fseek(archi,sizeof(stPaciente) * -1,SEEK_END);

        if(fread(&p,sizeof(stPaciente),1,archi) > 0){
            id = p.id;
        }

        fclose(archi);
    }
    return id;
}

int archivoPaciente2arreglo(char nombreArchivo[], stPaciente p[], int dim){
    FILE *pArch = fopen(nombreArchivo, "rb");
    int i = 0;
    stPaciente paciente;

    if(pArch){
        while(i<dim && fread(&paciente, sizeof(stPaciente), 1, pArch)>0){
            p[i] = paciente;
            i++;
        }

        fclose(pArch);
    }
    return i;
}

int cuentaRegistros(char nombreArchivo[], int tamanio){
    FILE *pArch = fopen(nombreArchivo, "rb");
    int cantidad=0;

    if(pArch){
        fseek(pArch, 0, SEEK_END);
        cantidad = ftell(pArch) / tamanio;

        fclose(pArch);
    }

    return cantidad;
}

void arreglo2archivos(stPaciente pacientes[], int v, char archivoEnfermos[], char archivoSanos[], float tempLimite){
    FILE *pSanos = fopen(archivoSanos, "ab");
    FILE *pEnfermos = fopen(archivoEnfermos, "ab");

    if(pSanos && pEnfermos){
        for(int i=0; i<v; i++){
            if(pacientes[i].temperatura <= tempLimite){
                fwrite(&pacientes[i], sizeof(stPaciente), 1, pSanos);
            }else{
                fwrite(&pacientes[i], sizeof(stPaciente), 1, pEnfermos);
            }
        }

        fclose(pSanos);
        fclose(pEnfermos);
    }
}

void porcentajeSanosYenfermos(char archiPacientes[], char archiSanos[], char archiEnfermos[]){
    int cantPacientes = cuentaRegistros(archiPacientes, sizeof(stPaciente));
    int cantSanos = cuentaRegistros(archiSanos, sizeof(stPaciente));
    int cantEnfermos = cuentaRegistros(archiEnfermos, sizeof(stPaciente));

    float porcentajeSanos = (float)cantSanos * 100 / cantPacientes;
    float porcentajeEnfermos = (float)cantEnfermos * 100 / cantPacientes;

    printf("\n La cantidad de pacientes sanos %d sobre un total de %d y corresponde al %.2f%%", cantSanos, cantPacientes, porcentajeSanos);
    printf("\n La cantidad de pacientes enfermos %d sobre un total de %d y corresponde al %.2f%%", cantEnfermos, cantPacientes, porcentajeEnfermos);
}

float porcentajeDelTotal(char archiPacientes[], char otro[]){
    int cantPacientes = cuentaRegistros(archiPacientes, sizeof(stPaciente));
    int cantOtros = cuentaRegistros(otro, sizeof(stPaciente));

    float porcentaje = (float)cantOtros * 100 / cantPacientes;

    return porcentaje;
}














