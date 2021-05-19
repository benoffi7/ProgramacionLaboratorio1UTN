#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define DIM 100

typedef struct {
    int legajo;
    int dni;
    char apellido[30];
    char nombre[30];
}stAlumno;

int cargaAlumnos(stAlumno a[], int dim);
void muestraAlumnos(stAlumno a[], int v);
void muestraUnAlumno(stAlumno a);
stAlumno buscaAlumno(stAlumno a[], int v, int legajo);


int main()
{
    stAlumno alumnos[DIM];
    int vAlumnos=0;
    stAlumno a;

    printf("\n________________ %d", sizeof(stAlumno));
    system("pause");
    exit(0);

    vAlumnos = cargaAlumnos(alumnos, DIM);

    printf("\nMuestra Alumnos\n");
    muestraAlumnos(alumnos,vAlumnos);

    a = buscaAlumno(alumnos, vAlumnos, 125);
    if(a.legajo != -1){
        muestraUnAlumno(a);
    }else{
        printf("\n El legajo nro %d no existe!!!", 125);
    }

    return 0;
}




int cargaAlumnos(stAlumno a[], int dim){
    char opcion=0;
    int i=0;

    while(i<dim && opcion!=27){
        printf("\n Legajo.........: ");
        scanf("%d", &a[i].legajo);
        printf("DNI............: ");
        scanf("%d", &a[i].dni);
        printf("Apellido.......: ");
        fflush(stdin);
        scanf("%s", a[i].apellido);
        printf("Nombre.........: ");
        fflush(stdin);
        scanf("%s", a[i].nombre);
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
    printf("\nLegajo............: %d", a.legajo);
    printf("\nDNI...............: %d", a.dni);
    printf("\nApellido..........: %s", a.apellido);
    printf("\nNombres...........: %s", a.nombre);
    printf("\n-----------------------------------------------");
}

stAlumno buscaAlumno(stAlumno a[], int v, int legajo){
    stAlumno alumno;
    alumno.legajo=-1;
    int i = 0;

    while(i<v && alumno.legajo == -1){
        if(a[i].legajo == legajo){
            alumno = a[i];
        }
        i++;
    }
    return alumno;
}

int buscaAlumnoPuntero(stAlumno a[], int v, stAlumno *al, int legajo){
    int flag=0;
    int i = 0;

    while(i<v && flag == 0){
        if(a[i].legajo == legajo){
            (*al) = a[i];
            flag=1;
        }
        i++;
    }
    return flag;
}

void muestraAlumnosConTeminacion(stAlumno a[], int v, char c){
    int pos;
    for(int i=0;i<v;i++){
        pos = strlen(a[i].apellido);
        if(a[i].apellido[pos-1]==c){
            muestraUnAlumno(a[i]);
        }
    }
}

int cuentaAlumnosConTerminacionDNI(stAlumno a[], int v, int t){
    int cont=0;
    for(int i=0;i<v;i++){
        if(a[i].dni % 10 == t){
            cont++;
        }
    }
    return cont;
}
