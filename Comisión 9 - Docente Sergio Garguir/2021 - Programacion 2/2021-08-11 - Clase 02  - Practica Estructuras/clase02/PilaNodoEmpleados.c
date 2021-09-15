#include "PilaNodoEmpleados.h"

void inicPilaEmpleados(Pila* pila){
    (*pila)=inicLista();
}

void apilarEmpleados(nodo** pila, stEmpleado e){
    (*pila)=agregarAlPrincipio((*pila),crearNodo(e));
}

stEmpleado topePilaEmpleados(Pila* pila){
    return verPrimeroT(*pila);
}

stEmpleado desapilarEmpleado(Pila* pila){
    stEmpleado e = verPrimeroT(*pila);
    (*pila)=borrarPrimerNodo(*pila);
    return e;
}
