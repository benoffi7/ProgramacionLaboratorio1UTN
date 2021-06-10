#include "articulo.h"

void muestraUnArticulo(stArticulo a){
    char rubro[15];
    getRubro(a.rubro, rubro);

    printf("\n Id...................: %d", a.id);
    printf("\n Codigo...............: %d", a.codigo);
    printf("\n Rubro................: %d (%s)", a.rubro, rubro);
    printf("\n Marca................: %s", a.marca);
    printf("\n Modelo...............: %s", a.modelo);
    printf("\n Precio...............: %.2f", a.precio);
    printf("\n------------------------------------------------");
}

void getRubro(int nro, char rubro[]){
    switch(nro){
        case 1: strcpy(rubro, "Televisores");
                break;
        case 2: strcpy(rubro, "Lavarropas");
                break;
        case 3: strcpy(rubro, "Cocinas");
                break;
        case 4: strcpy(rubro, "Calefactores");
    }
}
