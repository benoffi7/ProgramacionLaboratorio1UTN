#include <stdio.h>
#include <stdlib.h>
#define nomArch "numerito.bin"


void lecturaArchivo()
{
    FILE* fp = fopen(nomArch,"rb"); ///si no existe, error = devuelve null
    int numerito;
    if (fp != NULL) ///si se abrio correctamente
    {
      fread(&numerito,sizeof(int),1,fp);
      fclose(fp);
    }

    printf("numerito: %i", numerito);

}


int main()
{
    FILE* fp;
    int numerito;
    numerito = 5;
    ///wb escritura con sobreescritura por cada ejecucion ///crea el archivo si no existe
    ///ab escritura al final de archivo ///crea el archivo si no existe
    ///rb lectura (si no existe devolvera NULL)
    ///w+b escritura y lectura ///si no existe se crea, sobreescribe la info
    ///a+b escritura al final de archivo y lectura /// si no existe se crea
    ///r+b lectura y escritura ///*** si no existe no lo crea***

    ///funciones sin formato
    ///fwrite -> escribir
    ///fread -> leer


//    fp = fopen(nomArch,"wb"); ///si no existe lo crea, si existia, sobreescribe la info
//    if (fp != NULL) ///si no hubo error
//    {
//        fwrite(&numerito,sizeof(int),1,fp);
//        ///enviarle la dir de numerito que tiene el valor que quiero escribir
//        /// el tamano de mi variable (cuantos bytes voy a escribir)
//        /// cantidad de variables que estaria escribiendo
//        ///fp que contiene la info de mi archivo
//
//        ///DEBO CERRAR EL ARCHIVO
//        fclose(fp);
//    }

   lecturaArchivo();


    return 0;
}
