#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char apellido[30];
    char dni[15];
}stPersona;


int main()
{
    /// Implementen el funcionamiento

    printf("Hello world!\n");
    return 0;
}

void cargaArchivoPeronas(char nombreArchivo[]){
    stPersona p;
    char opcion;
    int id = ultimoID(nombreArchivo)+1;
    FILE *pArchi = fopen(nombreArchivo, "ab");

    if(pArchi){
        do{
            p.id = id;
            printf("\n Apellido...........: ");
            fflush(stdin);
            scanf("%s", p.apellido);

            printf("\n DNI................: ");
            do{
                fflush(stdin);
                scanf("%s", p.dni);
            }while(existeDNI(pArchi, p.dni));

            fwrite(&p, sizeof(stPersona), 1, pArchi);
            id++;

            printf("\n ESC para salir - cualquier tecla para continuar ");
            opcion=getch();
            system("cls");

        }while(opcion != 27);

        fclose(pArchi);
    }
}

int existeDNI(FILE *pA, char dni[]){
    int flag = 0;
    stPersona p;

    rewind(pA);
    //fseek(pA, 0, SEEK_SET);
    if(pA){
        while(flag == 0 && fread(&p, sizeof(stPersona), 1, pA) > 0){
            if(strcmp(p.dni, dni) == 0){
                flag = 1;
            }
        }
    }
    return flag;
}

int cuentaRegistros(char nombreArchivo[], tamanioSt){
    int cantidad=0;
    FILE *pArchi = fopen(nombreArchivo, "rb");

    if(pArchi){
        fseek(pArchi, 0, SEEK_END);
        cantidad = ftell(pArchi) / tamanioSt;

        fclose(pArchi);
    }

    return cantidad;
}

int ultimoID(char nombreArchivo[]){
    int ultimoId=0;
    stPersona p;
    FILE *pArchi = fopen(nombreArchivo, "rb");

    if(pArchi){
        fseek(pArchi, -1 * sizeof(stPersona), SEEK_END);
        if(fread(&p, sizeof(stPersona), 1, pArchi) > 0){
            ultimoId = p.id;
        }
    }

    return ultimoId;
}
























