#include <string.h> /// incluimos esta libreria para usar string
#include <ctype.h> /// para cambiar mayusculas y minusculas

void ejemplo_string()
{
    /// un string es un arreglo de char

    /// declaramos un arreglo de char para 30 elementos
    char palabra[30];

    /// inicializamos un arreglo de char con una palabra
    char unaPalabra[30] = {'h','o','l','a'};

    /// hacemos lo mismo de una forma mas facil
    char otraPalabra[30] = "hola";

    /// esto tambien es valido, pero innecesario
    char otraPalabra_2[30] = {"hola"};

    /// mostramos los strings
    printf("palabra: %s \n", unaPalabra);
    printf("palabra: %s \n", otraPalabra);
    printf("palabra: %s \n", otraPalabra_2);
}

void ejemplo_operacionesConString()
{
    /// Conocer la longitud de una cadena
    char unaFrase[] = "Bienvenido a Laboratorio de computacion 1";

    printf("longitud: %d \n", strlen(unaFrase));

    /// ----------------------------------------------------------
    printf("\n");

    /// Comparar dos cadenas para saber si son iguales o no
    char frase_0[] = "buenos dias 2";
    char frase_1[] = "buenos dias 2";

    char frase_2[] = "buenos dias 1";

    printf("frases 0 y 1: %d \n", strcmp(frase_0, frase_1));
    printf("frases 1 y 2: %d \n", strcmp(frase_1, frase_2));

    /**
        valores de la comparacion
         0 : son iguales
        -1 : la primera es mas chica
         1 : la segunda es mas chica
    */

    /// ----------------------------------------------------------
    printf("\n");

    /// Comparar dos cadenas para saber si son iguales o no, sin tener
    /// en cuenta las mayusculas ni minusculas
    char palabra_1[] = "hola";
    char palabra_2[] = "HoLA";

    printf("palabra 1 y 2: %d \n", strcmpi(palabra_1, palabra_2));

    /// ----------------------------------------------------------
    printf("\n");

    /// Copia un string en otro
    char original[100] = "buenos dias";
    char copia[] = " ";

    strcpy(copia, original);
    printf("copia: %s \n", copia);

    /// ----------------------------------------------------------
    printf("\n");

    /// Unir dos strings
    char primeraParte[] = "Bienvenidos a ";
    char segundoParte[] = "Laboratorio de computacion ";
    char terceraParte[] = "1";

    char fraseCompleta[200] = " ";

    strcat(fraseCompleta, primeraParte);
    strcat(fraseCompleta, segundoParte);
    strcat(fraseCompleta, terceraParte);

    printf("frase completa: %s \n", fraseCompleta);

    /// ----------------------------------------------------------
    printf("\n");

    /// Saber si un string se encuentra dentro de otro
    /// y tomar su posicion en memoria
    char palabraBuscada[] = "Laboratorio";

    printf("%s, esta en la posicion %X \n", palabraBuscada, strstr(fraseCompleta, palabraBuscada));

    char* posicion = strstr(fraseCompleta, palabraBuscada);

    posicion[0] = 'M';
    printf("%s \n", fraseCompleta);

    /// ----------------------------------------------------------
    printf("\n");

    /// mayusculas y minusculas

    char miFrase[] = "Soy La Ultima Frase Del Ejemplo";

    printf("frase original: %s \n", miFrase);

    /// pasando a minusculas
    for(int i = 0; i < strlen(miFrase); i++)
    {
        miFrase[i] = tolower(miFrase[i]);
    }
    printf("en minusculas: %s \n", miFrase);

    /// pasando a mayusculas
    for(int i = 0; i < strlen(miFrase); i++)
    {
        miFrase[i] = toupper(miFrase[i]);
    }
    printf("en mayusculas: %s \n\n", miFrase);
}
