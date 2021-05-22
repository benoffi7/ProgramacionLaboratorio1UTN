#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define DIM_ALUMNOS 100

typedef struct{
    char calle[30];
    int nro;
    char cpos[8];
    char localidad[50];
    char provincia[50];
}stDomicilio;

typedef struct{
    int id;
    int legajo;
    int dni;
    char genero;
    char apellido[30];
    char nombre[30];
    stDomicilio domicilio;
}stAlumno;

int cargaArregloAlumnos(stAlumno a[], int dim);
void muestraAlumnos(stAlumno a[], int v);
void muestraUnAlumno(stAlumno a);
stAlumno buscaApellido(stAlumno a[], int v, char ape[]);

int main()
{
    stAlumno alumnos[DIM_ALUMNOS];
    int vAlumnos=0;
    stAlumno a;

    vAlumnos=cargaArregloAlumnos(alumnos, DIM_ALUMNOS);

    printf("\n Listado de Alumnos\n");
    muestraAlumnos(alumnos, vAlumnos);

    a = buscaApellido(alumnos, vAlumnos, "Argento");
    muestraUnAlumno(a);

    return 0;
}

int cargaArregloAlumnos(stAlumno a[], int dim){
    char opcion=0;
    int i=0;
    int dni;

    while(i<dim && opcion!=27){
        a[i].id=i+1;

        printf("\n Legajo..............: ");
        scanf("%d", &a[i].legajo);

        printf(" DNI..................: ");

        do{
            scanf("%d", &dni);
        }
        while(buscaDNI(a, i, dni));
        a[i].dni = dni;

        fflush(stdin);
        printf(" Genero...............: ");
        scanf("%c", &a[i].genero);
        fflush(stdin);
        printf(" Apellido.............: ");
        scanf("%s", a[i].apellido);
        fflush(stdin);
        printf(" Nombre...............: ");
        scanf("%s", a[i].nombre);
        printf(" Calle................: ");
        scanf("%s", a[i].domicilio.calle);

        i++;

        printf("\n ESC para salir - cualquier tecla para continuar");
        opcion=getch();
        system("cls");

    }
    return i;
}

void muestraAlumnos(stAlumno a[], int v){
    for(int i=0;i<v;i++){
        muestraUnAlumno(a[i]);
    }
}

void muestraUnAlumno(stAlumno a){
    printf("\n ID.................: %d", a.id);
    printf("\n Legajo.............: %d", a.legajo);
    printf("\n DNI................: %d", a.dni);
    printf("\n Genero.............: %c", a.genero);
    printf("\n Apellido...........: %s", a.apellido);
    printf("\n Nombre.............: %s", a.nombre);
    printf("\n Calle..............: %s", a.domicilio.calle);
    printf("\n---------------------------------------------");
}

int buscaDNI(stAlumno a[], int v, int dni){
    int flag=0;
    int i=0;

    while(i<v && flag == 0){
        if(a[i].dni == dni){
            flag=1;
        }
        i++;
    }

    return flag;
}

stAlumno buscaApellido(stAlumno a[], int v, char ape[]){
    stAlumno alumno;
    int flag=0;
    int i=0;

    while(i<v && flag == 0){
        if(strcmp(a[i].apellido, ape)==0){
            flag=1;
            alumno = a[i];
        }
        i++;
    }
    return alumno;
}

int buscaCalle(stAlumno a[], int v, int calle){
    int flag=-1;
    int i=0;

    while(i<v && flag == -1){
        if(a[i].domicilio.calle == calle){
            flag=i;
        }
        i++;
    }

    return flag;
}

int buscaApellidoP(stAlumno a[], int v, stAlumno *alu, char ape[]){
    int flag=0;
    int i=0;

    while(i<v && flag == 0){
        if(strcmp(a[i].apellido, ape)==0){
            flag=1;
            /**strcpy(alu->apellido, a[i].apellido);
            strcpy(alu->nombre, a[i].nombre);
            alu->legajo = a[i].legajo;*/
            (*alu)=a[i];
        }
        i++;
    }
    return flag;
}
