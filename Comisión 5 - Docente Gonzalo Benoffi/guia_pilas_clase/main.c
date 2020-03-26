#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
/*
Suponiendo la existencia de una pila MODELO (vacía o no),
eliminar de la pila DADA todos los elementos que existan en MODELO.
*/
   Pila dada;
   Pila modelo;
   Pila basura;
   Pila temporal;
   Pila modelo_temporal;

   inicpila(&dada);
   inicpila(&modelo);
   inicpila(&basura);
   inicpila(&temporal);
   inicpila(&modelo_temporal);

   apilar(&modelo,4);
   apilar(&modelo,7);
   apilar(&modelo,10);

   apilar(&dada,4);
   apilar(&dada,5);
   apilar(&dada,6);
   apilar(&dada,7);
   apilar(&dada,7);
   apilar(&dada,8);


   while (!pilavacia(&dada))//recorro dada
   {
        apilar(&temporal,desapilar(&dada));//desapilo el primer elemento para romper el while
        //lo guardo en temporal


       while (!pilavacia(&modelo)) //recorro modelo
       {
           //si el topetemporal (viejo tope de modelo) es igual al topeMODELO
           if (tope(&temporal) == tope(&modelo))
           {
                apilar(&basura,desapilar(&temporal));  // a la basura porque no lo necesito
           }

           apilar(&modelo_temporal,desapilar(&modelo));    //quito tope modelo para seguir comparando
       }//se acabo modelo



       while (!pilavacia(&modelo_temporal)) //muevo de MT a M para comparar nuevamente el
        //siguiente de dada con el resto de modelo
       {
           apilar(&modelo,desapilar(&modelo_temporal));
       }

   }

   while (!pilavacia(&temporal))//quedaron los elementos que no estan en MODELO
   {
       apilar(&dada,desapilar(&temporal));
   }

   printf("dada\n");
   mostrar(&dada);










    return 0;
}
