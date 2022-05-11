#include <stdio.h>
#include <stdlib.h>

#define DIM 100

int cargaNombres(int dim, char n[][20]);

int main()
{
    int temp[3][3];
    char nombres[DIM][20];
    char apellidos[DIM][20];
    int dnis[DIM];
    int notasParcial[DIM];

    int vParalelos=0;

    vParalelos = cargaArreglosParalelos(DIM, nombres, apellidos, dnis, notasParcial);
    muestraArreglosParalelos(vParalelos, nombres, apellidos, dnis, notasParcial);


    int vNombres = 0;

    cargaMatriz(3,3,temp);
    muestraMatriz(3,3,temp);

  //  vNombres = cargaNombres(100, nombres);
  //  muestraStrings(vNombres, nombres);

    char nombre[21];
    nombre[0]='U';
    nombre[1]='T';
    nombre[2]='N';
    nombre[3]=' ';
    nombre[4]='M';
    nombre[5]='d';
    nombre[6]='P';
    nombre[7]='\0';
    char apellido[20];
    char apellido2[20];
    char nombreYapellido[40];
    char nombreYapellido2[40];
    int num = 5000;

    fflush(stdin);
    printf("\n Apellido: ");
    scanf("%s", apellido);
    printf("\n Apellido: ");
    scanf("%s", apellido2);
    printf("\n Nombre y Apellido: ");
    scanf(" %s", nombreYapellido);
    fflush(stdin);
    printf("\n usando gets: ");
    gets(nombreYapellido2);

    printf("\n Nombre: %s\n", nombre);
    printf("\n Apellido: %s\n", apellido);
    printf("\n Nombre y Apellido: %s\n", nombreYapellido);
    printf("\n Nombre y Apellido: %s\n", nombreYapellido2);

    muestraArregloChar(nombre);
    printf("\n");

    printf("Hello world!\n");
    return 0;
}

void muestraArregloChar(char c[]){
    for(int i=0;i<strlen(c);i++){
        printf("%c",c[i]);
    }
}

void cargaMatriz(int lin, int col, int m[lin][col]){
    for(int i=0;i<lin;i++){
        for(int j=0;j<col;j++){
            m[i][j]=rand()%11;
        }
    }
}

void muestraMatriz(int lin, int col, int m[lin][col]){
    for(int i=0;i<lin;i++){
        for(int j=0;j<col;j++){
            printf("%d | ",m[i][j]);
        }
        printf("\n");
    }
}

int cargaArreglosParalelos(int dim, char n[][20], char a[][20], int d[], int notas[]){
    char opcion;
    int i = 0;

    do{
        system("cls");
        printf("\n Ingrese un nombre: ");
        fflush(stdin);
        gets(n[i]);
        printf("Ingrese un apellido: ");
        fflush(stdin);
        gets(a[i]);
        printf("Ingrese un dni: ");
        scanf("%d", &d[i]);
        printf("Ingrese un notas: ");
        scanf("%d", &notas[i]);

        i++;
        printf("\n ESC para salir o cualquier tecla para continuar");
        opcion=getch();

    }while(opcion!=27);

    return i;
}

void muestraArreglosParalelos(int v, char n[][20], char a[][20], int d[], int notas[]){
    for(int i=0;i<v;i++){
        printf("\n Nombre...: %s",n[i]);
        printf("\n Apellido.: %s",a[i]);
        printf("\n DNI......: %d",d[i]);
        printf("\n Nota.....: %d",notas[i]);
        printf("\n===============================================================\n");
    }
}

void muestraStrings(int v, char n[][20]){
    for(int i=0;i<v;i++){
        printf("\n %s", n[i]);
    }
}


