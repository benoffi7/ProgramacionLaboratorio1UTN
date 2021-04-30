#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int cargaAbecedario(char c[], int dim);
void muestraArregloChar(char c[], int v);
int esPalindromo(char c[], int v);
void invierteArregloChar(char c[], int v);
void intercambio(char *a, char *b);
int main()
{
    char palabra1[30]={"neuquen"};
    char palabra[30];
    char opcion;

    char c[50];
    int vC=0;

    opcion=getch();
    printf("%i", opcion);

    if(esPalindromo(palabra1, strlen(palabra1))){
        printf("\n La palabra %s es un palindromo", palabra1);
    }else{
        printf("\n La palabra %s NO es un palindromo", palabra1);
    }

    printf("\n Ingrese su nombre: ");
    scanf("%s", palabra);
    //strcpy(palabra1,palabra);

    printf("\n Su nombre es: %s", palabra1);
    printf("\n Su nombre es: ");
    muestraArregloChar(palabra, strlen(palabra));

    vC=cargaAbecedario(c, 50);
    printf("\n Abecedario\n");
    muestraArregloChar(c, vC);

    invierteArregloChar(c, vC);
    printf("\n Abecedario\n");
    muestraArregloChar(c, vC);
    system("pause");

    if(esPalindromo(c, vC)){
        printf("\n El arreglo de char es capicua");
    }else{
        printf("\n El arreglo de char %s NO es capicua"); /// El error es el %s, lo quitan y funciona
    }

    printf("\nHello world!\n");
    return 0;
}

int cargaAbecedario(char c[], int dim){
    int i=0;
    while(i<26 && i<dim){
        c[i]=65+i;
        i++;
    }
    return i;
}

void muestraArregloChar(char c[], int v){
    for(int i=0;i<v;i++){
        printf("[%c]", c[i]);
    }
}

int esPalindromo(char c[], int v){
    int i=0;
    int f=v-1;
    int flag=1;

    while(i<v/2 && flag==1){
        if(c[i]==c[f]){
            i++;
            f--;
        }else{
            flag=0;
        }
    }
    return flag;
}

void invierteArregloChar(char c[], int v){
    int i=0;
    int f=v-1;

    while(i<f){
        intercambio(&c[i],&c[f]);
        i++;
        f--;
    }
}

void intercambio(char *a, char *b){
    char aux = *a;
    *a = *b;
    *b = aux;
}
