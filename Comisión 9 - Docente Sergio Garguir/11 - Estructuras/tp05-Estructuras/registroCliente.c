#include "registroCliente.h"


/*********************************************************//**
*
* \brief Funcion que retorna un Nro de Cliente al azar
* \return int
*
*************************************************************/
int getNroCliente(){
    return randomRango(1,10000);
}

/*************************************************************//**
*
* \brief Funcion que asigna al string recibido un nombre al azar
* \return void
*
*****************************************************************/
void getNombre(char n[]){
    char nombres[][30] = {"Amalio","Juan","Roberto","Antonio","Fernando","Anibal","Mariano","Jose",
                           "Anastasio","Arturo","Mario","Tamaro","Adolfo","Pedro","Alfredo","Arnaldo",
                           "Mauro","Benicio","Ildefonso","Cuchuflito","Remilgo","Miguel","Reinaldo"};

    strcpy(n,nombres[randomRango(0,sizeof(nombres)/(sizeof(char)*30))]);
}

/*************************************************************//**
*
* \brief Funcion que asigna al string recibido un apellido al azar
* \return void
*
*****************************************************************/
void getApellido(char a[]){
    char apellidos[][30] = {"Gomez","Perez","Rodriguez","Latorre","Fernandez","Torquemada", "Marijuan", "Roca", "Mitre", "Rivadavia",
                            "San Martin", "Alvarez", "Comizo", "Borges", "Zama", "Recato", "Olvido", "Gil", "Trapero", "Restinga",
                            "De Antonio", "Ramirez", "Spinetta", "Cortez", "Gonzalez", "Andujar", "San Juan", "Bautista", "Anchorena", "Paso",
                            "Gaboto","Vega","Vargas","Lloret","Linares","Suarez","Sierra","Amenabar","Blanco","White","Black"};

    strcpy(a,apellidos[randomRango(0,sizeof(apellidos)/(sizeof(char)*30))]);
}

/*********************************************************//**
*
* \brief Funcion que retorna un DNI de Cliente al azar
* \return int
*
*************************************************************/
int getDNI(){
    return randomRango(549,1982)* randomRango(549,19801);
}

/*************************************************************//**
*
* \brief Funcion que asigna al string recibido una calle al azar
* \return void
*
*****************************************************************/
void getCalle(char c[]){
    char calles[][30] = {"San Juan","Funes","Gaboto","San Martin","Colon","Rivadavia", "Alsina", "Roca", "Mitre", "Belgrano",
                            "Paso", "11 de Septiembre", "3 de Febrero", "Balcarce", "Libertad", "Magallanes", "Irala", "Ayolas", "Moreno", "Brown",
                            "Bolivar", "Alberti", "Gascon", "La Rioja", "Catamarca", "Salta", "Jujuy", "XX de Septiembre", "14 de Julio", "Dorrego",
                            "Hernandarias","Don Orione","Juramento","Lanzilota","Estrada","Tierra del Fuego","Mendoza","Chubut","Rio Negro","Misiones","Edison"};

    strcpy(c,calles[randomRango(0,sizeof(calles)/(sizeof(char)*30))]);
}

/*********************************************************//**
*
* \brief Funcion que retorna un Nro de calle de Cliente al azar
* \return int
*
*************************************************************/
int getCalleNro(){
    return randomRango(50,10000);
}

stCliente cargoRegistroClienteRandom(){
    stCliente c;
    c.nroCliente=getNroCliente();
    getNombre(c.nombre);
    getApellido(c.apellido);
    c.dni=getDNI();
    strcpy(c.email,c.nombre);
    strcat(c.email,"_");
    strcat(c.email,c.apellido);
    strcat(c.email,"@gmail.com");

    getCalle(c.domicilio);
    char nro[5];
    strcat(c.domicilio," ");
    strcat(c.domicilio, itoa(getCalleNro(),nro,10));

    c.baja=0;
    return c;
}
