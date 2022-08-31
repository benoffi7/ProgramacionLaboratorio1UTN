#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nombre[20];
    int edad;
    char sexo; /// m o f
}stPersona;

stPersona cargaUnaPersona();
void muestraUnaPersona(stPersona p);
int cargaArregloDePersonas(stPersona a[], int dim);
void muestraArregloDePersonas(stPersona a[], int v);
int cuentaPersonasPorSexo(stPersona a[], int v, char sexo);
int pasaPersonasPorSexo(stPersona o[], int vO, char sexo, stPersona d[], int vD);
stPersona * pasaPersonasPorSexo2(stPersona o[], int v, char sexo, int *validos);
int pasaPersonasPorSexo3(stPersona o[], int v, char sexo, stPersona **d);

int main()
{
    stPersona *p = NULL;
    int vP=0;
    stPersona arreglo[100];
    int v=0;
    int cuentaSexo;
    v=cargaArregloDePersonas(arreglo, 100);
    printf("\n Personas \n");
    muestraArregloDePersonas(arreglo, v);
    cuentaSexo=cuentaPersonasPorSexo(arreglo, v, 'f');
    printf("\n La cantidad de personas de sexo femenino son: %d", cuentaSexo);

    stPersona * personasFemeninas=(stPersona *)malloc(sizeof(stPersona)*cuentaSexo);
    int vPersonasFemeninas=0;

    vPersonasFemeninas = pasaPersonasPorSexo(arreglo, v, 'f', personasFemeninas, vPersonasFemeninas);
    printf("\n Personas Femeninas\n");
    muestraArregloDePersonas(personasFemeninas, vPersonasFemeninas);

    vP=pasaPersonasPorSexo3(arreglo, v, 'f', &p);

    return 0;
}


stPersona cargaUnaPersona(){
    static int i = 0;
    i++;
    stPersona p;
    strcpy(p.nombre, "Pep@");
    p.edad = 45;
    p.sexo = (i%2==0)?'m':'f';
    return p;
}

void muestraUnaPersona(stPersona p){
    printf("\n Nombre.........: %s",p.nombre);
    printf("\n Edad...........: %d",p.edad);
    printf("\n Sexo...........: %c",p.sexo);
    printf("\n _________________________________________________");
}

int cargaArregloDePersonas(stPersona a[], int dim){
    int i;
    for(i=0;i<dim;i++){
        a[i] = cargaUnaPersona();
    }
    return i;
}

void muestraArregloDePersonas(stPersona a[], int v){
    for(int i=0;i<v;i++){
        muestraUnaPersona(a[i]);
    }
}

int cuentaPersonasPorSexo(stPersona a[], int v, char sexo){
    int cont=0;
    for(int i=0;i<v;i++){
        if(a[i].sexo == sexo){
            cont++;
        }
    }
    return cont;
}

int pasaPersonasPorSexo(stPersona o[], int vO, char sexo, stPersona d[], int vD){
    for(int i=0;i<vO;i++){
        if(o[i].sexo == sexo){
            d[vD]=o[i];
            vD++;
        }
    }
    return vD;
}

stPersona * pasaPersonasPorSexo2(stPersona o[], int v, char sexo, int *validos){
    stPersona * p = (stPersona*)malloc(sizeof(stPersona)*cuentaPersonasPorSexo(o, v, sexo));
    *validos = pasaPersonasPorSexo(o, v, sexo, p, *validos);
    return p;
}

int pasaPersonasPorSexo3(stPersona o[], int v, char sexo, stPersona **d){
    (*d)=(stPersona*)malloc(sizeof(stPersona)*cuentaPersonasPorSexo(o, v, sexo));
    int validos=pasaPersonasPorSexo(o, v, sexo, *d, validos);
    return validos;
}
