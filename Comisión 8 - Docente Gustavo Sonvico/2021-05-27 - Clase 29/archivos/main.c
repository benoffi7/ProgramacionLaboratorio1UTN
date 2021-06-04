#include <stdio.h>
#include <stdlib.h>

const char ARCH_ALUMNOS[]="alumnos.dat";

typedef struct{
    int id;
    int legajo;
    int dni;
    char apellido[30];
    char nombre[30];
}stAlumno;



int main()
{


    cargaAlumnos(ARCH_ALUMNOS);

    printf("\nListado de alumnos! cantidad: %d\n", cuentaRegistros(ARCH_ALUMNOS, sizeof(stAlumno)));
    muestraArchivo(ARCH_ALUMNOS);


    return 0;
}


void cargaAlumnos(char archivo[]){
    char opcion;
    int i=ultimoId(archivo);
    stAlumno a;

    FILE *pArchiAlumnos = fopen(archivo, "ab");

    if(pArchiAlumnos!=NULL){ /// if(pArchiAlumnos)

        do{
            printf("\n");

            printf("Legajo.............: ");
            scanf("%d", &a.legajo);

            do{
                printf("DNI................: ");
                scanf("%d", &a.dni);
            }while(buscaDNI(archivo, a.dni));

            fflush(stdin);
            printf("Apellido...........: ");
            scanf("%s", a.apellido);

            fflush(stdin);
            printf("Nombre.............: ");
            scanf("%s", a.nombre);

            i++;
            a.id = i;

            fwrite(&a, sizeof(stAlumno), 1, pArchiAlumnos);

            printf("\n ESC para salir - cualquier tecla para continuar ");
            opcion = getch();
            system("cls");

        }while(opcion != 27);

        fclose(pArchiAlumnos);
    }
}

void muestraArchivo(char archivo[]){
    FILE *pArchi = fopen(archivo, "rb");
    stAlumno a;

    if(pArchi){
        while(fread(&a, sizeof(stAlumno), 1, pArchi)>0){
            muestraUnAlumno(a);
        }

        fclose(pArchi);
    }
}

void muestraUnAlumno(stAlumno a){
    printf("\nId.....................: %d", a.id);
    printf("\nLegajo.................: %d", a.legajo);
    printf("\nDNI....................: %d", a.dni);
    printf("\nApellido...............: %s", a.apellido);
    printf("\nNombre.................: %s", a.nombre);
    printf("\n---------------------------------------------------");
}

int ultimoId(char archivo[]){
    FILE *pArchi = fopen(archivo, "r+b");
    stAlumno a;
    int ultimoId=0;

    if(pArchi){
        fseek(pArchi, -1 * sizeof(stAlumno), SEEK_END);
        if(fread(&a, sizeof(stAlumno), 1, pArchi)>0){
            ultimoId = a.id;
        }

        fclose(pArchi);
    }
    return ultimoId;
}

int cuentaRegistros(char archivo[], int tamanioSt){
    int cantidad = 0;
    FILE *pArchi = fopen(archivo, "r+b");
    if(pArchi){
        fseek(pArchi, 0, SEEK_END);
        cantidad = ftell(pArchi)/tamanioSt;
        fclose(pArchi);
    }

    return cantidad;
}

int buscaDNI(char archivo[], int dni){
    int flag = 0;
    stAlumno a;
    FILE *pArchi = fopen(archivo, "rb");

    if(pArchi){
        while(flag == 0 && fread(&a, sizeof(stAlumno), 1, pArchi)>0){
            if(a.dni == dni){
                flag = 1;
            }
        }

        fclose(pArchi);
    }

    return flag;
}










