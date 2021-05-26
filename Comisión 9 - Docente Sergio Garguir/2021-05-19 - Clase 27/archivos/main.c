#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define DIM 100

typedef struct {
    int id;
    int legajo;
    int dni;
    char apellido[30];
    char nombre[30];
}stAlumno;

typedef struct {
    int id;
    int legajo;
    int dni;
    char apellido[30];
    char nombre[30];
}stAlumnoNew;


void cargaArchivoAlumnos(char archivo[]);
void muestraArchivoAlumnos(char archivo[]);
void muestraUnAlumno(stAlumno a);
void muestraArregloAlumnos(stAlumno a[], int v);
int cargaArregloConFiltro(char nombreArchivo[], stAlumno a[], int dim, char letra);

int main()
{
    stAlumno arregloAlumnos[100];
    int vAlumnos = 0;

    cargaArchivoAlumnos("alumnos.dat");

    printf("\n\t\tListado de Alumnos! El ultimo id es: %d\n", retornaUltimoId("alumnos.dat"));
    muestraArchivoAlumnos("alumnos.dat");
/*
    vAlumnos = cargaArregloConFiltro("alumnos.dat", arregloAlumnos, 100, 'A');
    printf("\n Arreglo de Alumnos\n");
    muestraArregloAlumnos(arregloAlumnos, vAlumnos);
*/
    return 0;
}

void cargaArchivoAlumnos(char archivo[]){
    char opcion = 0;
    int id = cuentaRegistros(archivo, sizeof(stAlumno));
    stAlumno a;

    FILE *pArchiAlumnos = fopen(archivo,"ab");
    if(pArchiAlumnos != NULL){
        do{
            printf("\n Legajo...........: ");
            scanf("%d", &a.legajo);
            printf(" DNI..............: ");
            scanf("%d", &a.dni);
            fflush(stdin);
            printf(" Apellido.........: ");
            scanf("%s", a.apellido);
            fflush(stdin);
            printf(" Nombre...........: ");
            scanf("%s", a.nombre);
            id++;
            a.id = id;
            fwrite(&a, sizeof(stAlumno), 1, pArchiAlumnos);

            printf("\n ESC para salir - cualquier tecla para continuar");
            opcion=getch();
            system("cls");
        }
        while(opcion!=27);

        fclose(pArchiAlumnos);
    }else{
        printf("\n ERROR DE APERTURA DE ARCHIVO ");
    }
}

void muestraArchivoAlumnos(char archivo[]){
    stAlumno a;
    FILE *pArchiAlumnos = fopen(archivo, "rb");

    if(pArchiAlumnos != NULL){
        while(fread(&a, sizeof(stAlumno), 1, pArchiAlumnos) > 0){
            muestraUnAlumno(a);
        }
        fclose(pArchiAlumnos);
    }else{
        printf("\n ERROR DE APERTURA DE ARCHIVO ");
    }
}

void muestraUnAlumno(stAlumno a){
    printf("\n Id..............: %d", a.id);
    printf("\n Legajo..........: %d", a.legajo);
    printf("\n DNI.............: %d", a.dni);
    printf("\n Apellido........: %s", a.apellido);
    printf("\n Nombre..........: %s", a.nombre);
    printf("\n--------------------------------------");
}

void muestraArregloAlumnos(stAlumno a[], int v){
    for(int i=0;i<v;i++){
        muestraUnAlumno(a[i]);
    }
}

int cargaArregloConFiltro(char nombreArchivo[], stAlumno a[], int dim, char letra){
    stAlumno alumno;
    int i=0;

    FILE *pArchi = fopen(nombreArchivo, "rb");

    if(pArchi != NULL){
        while(i<dim && fread(&alumno, sizeof(stAlumno), 1, pArchi) > 0){
            if(alumno.apellido[0]==letra){
                a[i] = alumno;
                i++;
            }
        }
        fclose(pArchi);
    }
    return i;
}

void archivoOld2New(char old[], char new[]){
    int id=1;
    stAlumno alumnoOld;
    stAlumnoNew alumnoNew;
    FILE *pOld = fopen(old, "rb");
    FILE *pNew = fopen(new, "ab");

    if(pOld){
        if(pNew!=NULL){
            while(fread(&alumnoOld, sizeof(stAlumno), 1, pOld) > 0){
                alumnoNew.id = id;
                alumnoNew.dni = alumnoOld.dni;
                alumnoNew.legajo = alumnoOld.legajo;
                strcpy(alumnoNew.apellido, alumnoOld.apellido);
                strcpy(alumnoNew.nombre, alumnoOld.nombre);

                fwrite(&alumnoNew, sizeof(alumnoNew), 1, pNew);
                id++;
            }

            fclose(pNew);
        }
        fclose(pOld);
    }
}

int cuentaRegistros(char archivo[], int tamanioSt){
    int cantidadRegistros = 0;
    FILE *p = fopen(archivo, "rb");
    if(p!=NULL){
        fseek(p, 0, SEEK_END);
        cantidadRegistros=ftell(p)/tamanioSt;
        fclose(p);
    }

    return cantidadRegistros;
}

int retornaUltimoId(char archivo[]){
    int ultimoId = 0;
    stAlumno a;
    FILE *p = fopen(archivo, "rb");
    if(p!=NULL){
        fseek(p, -1 * sizeof(stAlumno), SEEK_END);
        if(fread(&a, sizeof(stAlumno), 1, p)>0) {
            ultimoId = a.id;
        }
        fclose(p);
    }

    return ultimoId;
}






