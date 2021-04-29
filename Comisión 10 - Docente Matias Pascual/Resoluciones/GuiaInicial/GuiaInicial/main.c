#include <stdio.h>
#include <stdlib.h>

int main()
{
    char control = 's';
    int opcion;
    while (control == 's'){
        printf("BIENVENIDO A LA RESOLUCION GUIA INICIAL PROGRAMACION/LABORATORIO I\n");
        printf("------------------------------------------------------------------\n\n");
        printf("Ingrese opcion numerica\n");
        printf("A- PROBLEMAS SECUENCIALES\n");
        printf("1 - Ejercicio 1\n");
        printf("2 - Ejercicio 2\n");
        printf("3 - Ejercicio 3\n\n");
        printf("B- USO DE ESTRUCTURAS SELECTIVAS\n");
        printf("4 - Ejercicio 1\n\n");
        printf("C- PROBLEMAS SELECTIVOS SIMPLES\n");
        printf("5 - Ejercicio 1\n");
        printf("6 - Ejercicio 2\n");
        printf("7 - Ejercicio 3\n");
        printf("8 - Ejercicio 4\n");
        printf("9 - Ejercicio 5\n\n");
        printf("D- PROBLEMAS SELECTIVOS COMPUESTOS\n");
        printf("10- Ejercicio 1\n");
        printf("11- Ejercicio 2\n\n");
        printf("E- USO DE ESTRUCTURAS REPETITIVAS\n");
        printf("12- Ejercicio 1\n\n");
        printf("F- COMBINACION DE ESTRUCTURAS SELECTIVAS Y REPETITIVAS\n");
        printf("13- Ejercicio 1\n\n");
        printf("G- EJEMPLO PARA - HACER\n");
        printf("14- Ejercicio 1\n");
        printf("15- Ejercicio 2\n");
        printf("16- Ejercicio 3\n");
        printf("17- Ejercicio 4\n");
        printf("18- Ejercicio 5\n");
        printf("19- Ejercicio 6\n\n");

        fflush(stdin);
        scanf("%d", &opcion);
        system("cls");

        switch(opcion){
            case 1:
                printf("PROBLEMAS SECUENCIALES\n----------------------\n");
                printf(".:EJERCICIO 1:.\n\n");

                printf("Suponga que un individuo desea invertir su capital en un banco y desea\nsaber cuanto dinero ganara despues de un mes si el banco paga a razon\nde 2%% mensual.\n\n");

                float capital, ganancia = 0;

                printf("Ingrese capital a invertir\n");
                fflush(stdin);
                scanf("%f",&capital);

                ganancia = capital * 0.02;

                printf("Va a tener una ganancia de: %.2f\n", ganancia);

                system("Pause");
                system("cls");
                break;

            case 2:
                printf("PROBLEMAS SECUENCIALES\n----------------------\n");
                printf(".:EJERCICIO 2:.\n\n");

                printf("Una tienda ofrece un descuento del 15%% sobre el total de la compra\ny un cliente desea saber cuanto debera pagar finalmente por su compra.\n\n");

                float compra, descuento, totalDescuento = 0;

                printf("Ingrese monto total de la compra\n");
                fflush(stdin);
                scanf("%f",&compra);

                descuento = compra * 0.15;
                totalDescuento = compra - descuento;

                printf("Usted debera pagar: $%.2f\n", totalDescuento);

                system("Pause");
                system("cls");
                break;

            case 3:
                printf("PROBLEMAS SECUENCIALES\n----------------------\n");
                printf(".:EJERCICIO 3:.\n\n");

                printf("Un maestro desea saber que porcentaje de hombres y que porcentaje de mujeres\nhay en un grupo de estudiantes.\n\n");

                int mujeres, hombres, totalAlumnos = 0;
                float por_muj, por_hom = 0;

                printf("Ingrese cantidad de hombres en el curso\n");
                fflush(stdin);
                scanf("%d",&hombres);

                printf("Ingrese cantidad de mujeres en el curso\n");
                fflush(stdin);
                scanf("%d",&mujeres);

                totalAlumnos = hombres + mujeres;
                por_hom = (float)hombres*100/(float)totalAlumnos;
                por_muj = 100 - por_hom;

                printf("\nEl porcentaje de hombres es: %.2f\n", por_hom);
                printf("El porcentaje de mujeres es: %.2f\n", por_muj);
                printf("Total de alumnos en el curso: %d\n", totalAlumnos);

                system("Pause");
                system("cls");
                break;

            case 4:
                printf("USO DE ESTRUCTURAS SELECTIVAS\n-----------------------------\n");
                printf(".:EJERCICIO 1:.\n\n");

                printf("Realizar un algoritmo que permita ingresar un numero e informe Numero mayor a cero\no Numero menor o igual a cero segun corresponda.\n\n");

                int numero = 0;

                printf("Ingrese un numero entero\n");
                fflush(stdin);
                scanf("%d",&numero);

                if(numero>0)
                    printf("El numero %d es mayor a cero\n", numero);
                else
                    printf("El numero %d es menor o igual a cero\n", numero);

                system("Pause");
                system("cls");
                break;

            case 5:
                printf("PROBLEMAS SELECTIVOS SIMPLES\n----------------------------\n");
                printf(".:EJERCICIO 1:.\n\n");

                printf("Determinar si un alumno aprueba a reprueba un curso, sabiendo que aprobara si\nsu promedio de tres calificaciones es mayor o igual a 7; reprueba en caso contrario.\n\n");

                int contador=0, nota=0 , suma = 0;
                float promedioCalificacion = 0;

                while(contador < 3){
                    contador++; /// lo pongo primero porque lo uso para mostrar por pantalla

                    printf("Ingrese nota nro %d\n", contador);
                    fflush(stdin);
                    scanf("%d",&nota);

                    suma += nota; //suma = suma + nota;
                }
                promedioCalificacion = (float)suma/(float)contador;

                printf("El promedio del alumno es %.2f, por lo tanto el alumno ", promedioCalificacion);
                if(promedioCalificacion >= 7){
                    printf("APROBO la materia\n");
                }
                else{
                    printf("DESAPROBO la materia\n");
                }

                system("Pause");
                system("cls");
                break;

            case 6:
                printf("PROBLEMAS SELECTIVOS SIMPLES\n----------------------------\n");
                printf(".:EJERCICIO 2:.\n\n");

                printf("En un almacen se hace un 20%% de descuento a los clientes cuya compra supere los $1000\n¿Cual sera la cantidad que pagara una persona por su compra?\n\n");

                float compraAlmacen, totalCompraDescuento = 0;

                printf("Ingrese total de compra\n");
                fflush(stdin);
                scanf("%f", &compraAlmacen);

                if(compraAlmacen >= 1000){
                    totalCompraDescuento = compraAlmacen - (compraAlmacen * 0.2);
                    printf("El cliente supero los $1000, el monto con descuento es: $");
                }
                else{
                    totalCompraDescuento = compraAlmacen;
                    printf("El cliente NO supero los $1000, el monto a pagar es el mismo: $");
                }
                printf("%.2f\n", totalCompraDescuento);

                system("Pause");
                system("cls");
                break;

            case 7:
                printf("PROBLEMAS SELECTIVOS SIMPLES\n----------------------------\n");
                printf(".:EJERCICIO 3:.\n\n");

                printf("Un obrero necesita calcular su salario semanal, el cual se obtiene de la sig. manera:\nSi trabaja 40 horas o menos se le paga $16 por hora\nSi trabaja mas de 40 horas se le paga $16 por cada una de las primeras 40 horas y $20 por cada hora extra.\n\n");

                int cantHoras, totalSueldo, extrasHoras, extraSueldo = 0;


                printf("Ingrese cantidad de horas trabajadas\n");
                fflush(stdin);
                scanf("%d", &cantHoras);

                if(cantHoras >= 40){
                    extrasHoras = cantHoras - 40;
                    extraSueldo = extrasHoras * 20;
                    totalSueldo = 40 * 16 + extraSueldo;
                    printf("El empleado hizo mas de 40 horas, su salario total es: $%d de los cuales $%d pertenecen a horas extras\n",totalSueldo, extraSueldo);
                }
                else{
                    totalSueldo = cantHoras * 16;
                    printf("El empleado no registra horas extras, su salario es de: $%d\n", totalSueldo);
                }

                system("Pause");
                system("cls");
                break;

            case 8:
                printf("PROBLEMAS SELECTIVOS SIMPLES\n----------------------------\n");
                printf(".:EJERCICIO 4:.\n\n");

                printf("Que lea dos numeros y los imprima en forma ascendente\n\n");

                int nro1, nro2 = 0;

                printf("Ingrese Numero 1\n");
                fflush(stdin);
                scanf("%d", &nro1);

                printf("Ingrese Numero 2\n");
                fflush(stdin);
                scanf("%d", &nro2);

                printf("Numeros ordenados: ");
                if(nro1 < nro2){
                    printf("- %d - %d -\n", nro1, nro2);
                }
                else{
                    printf("- %d - %d -\n", nro2, nro1);
                }

                system("Pause");
                system("cls");
                break;

            case 9:
                printf("PROBLEMAS SELECTIVOS SIMPLES\n----------------------------\n");
                printf(".:EJERCICIO 5:.\n\n");

                printf("Hacer un algoritmo que calcule el total a pagar por la compra de camisas. Si se compran\ntres camisas o mas se aplica un descuento del 20%% sobre el total de la compra y si son\nmenos de tres camisas un descuento del 10%%\n\n");

                int cantCamisas = 0;
                float precioCamisas, totalCamisas = 0;

                printf("Ingrese cantidad de camisas\n");
                fflush(stdin);
                scanf("%d", &cantCamisas);

                printf("Ingrese precio por camisa\n");
                fflush(stdin);
                scanf("%f", &precioCamisas);

                totalCamisas = precioCamisas * cantCamisas;

                if(cantCamisas >= 3){
                    totalCamisas -= totalCamisas*0.2;
                    printf("El cliente tiene un descuento del 20%% por lo tanto ");
                }
                else{
                   totalCamisas -= totalCamisas*0.1;
                   printf("El cuente tiene un descuento del 10%% por lo tanto");
                }

                printf("tiene que pagar: $%.2f\n", totalCamisas);

                system("Pause");
                system("cls");
                break;

            case 10:
                printf("PROBLEMAS SELECTIVOS COMPUESTOS\n-------------------------------\n");
                printf(".:EJERCICIO 1:.\n\n");

                printf("Leer 2 numeros; si son iguales que los multiplique, si el primero es mayor que\nel segundo que los reste y si no que los sume.\n\n");

                int nro11, nro22, resultadoOperacion = 0;

                printf("Ingrese primer numero\n");
                fflush(stdin);
                scanf("%d", &nro11);

                printf("Ingrese segundo numero\n");
                fflush(stdin);
                scanf("%d", &nro22);

                if(nro11 == nro22){
                    resultadoOperacion = nro11 * nro22;
                }
                else{
                    if(nro11 > nro22){
                        resultadoOperacion = nro11 - nro22;
                    }
                    else{
                        resultadoOperacion = nro11 + nro22;
                    }
                }

                printf("El resultado de la operacion es: %d\n", resultadoOperacion);

                system("Pause");
                system("cls");
                break;

            case 11:
                printf("PROBLEMAS SELECTIVOS COMPUESTOS\n-------------------------------\n");
                printf(".:EJERCICIO 2:.\n\n");

                printf("Leer tres números diferentes e imprimir el numero mayor de los tres.\n\n");

                int nro111, nro222, nro333, mayor = 0;

                printf("Ingrese nro 1\n");
                fflush(stdin);
                scanf("%d",&nro111);

                printf("Ingrese nro 2\n");
                fflush(stdin);
                scanf("%d",&nro222);

                printf("Ingrese nro 3\n");
                fflush(stdin);
                scanf("%d",&nro333);

                if(nro111< nro222 && nro222 < nro333){
                    mayor = nro333;
                }
                else{
                    if(nro111 < nro222 && nro222 > nro333){
                        mayor = nro222;
                    }
                    else{
                        mayor = nro111;
                    }
                }

                printf("El mayor de los tres es: %d\n", mayor);

                system("Pause");
                system("cls");
                break;

            case 12:
                printf("USO DE ESTRUCTURAS REPETITIVAS\n------------------------------\n");
                printf(".:EJERCICIO 1:.\n\n");

                printf("Realizar un algoritmo que permita realizar 3 veces lo siguiente:\ningresar 2 numeros calcular su suma e informar el resultado.\n\n");

                int i = 0, valorIngresado, sumaTotal = 0;

                while(i<3){
                    int j = 0;
                    for(j=0; j<2; j++){
                        printf("Ingrese nro %d\n", j+1);
                        fflush(stdin);
                        scanf("%d", &valorIngresado);
                        sumaTotal += valorIngresado;
                    }
                    printf("El resultado de la suma de los dos nros es: %d\n\n", sumaTotal);
                    sumaTotal = 0;
                    i++;
                }

                system("Pause");
                system("cls");
                break;

            case 13:
                 printf("COMBINACION DE ESTRUCTURAS SELECTIVAS Y REPETITIVAS\n---------------------------------------------------\n");
                printf(".:EJERCICIO 1:.\n\n");

                printf("Realizar un algoritmo que permita ingresar 5 numeros e informe cuantos numeros ingresados son\nmayores a cero y cuantos menores a cero.\n\n");

                int datos, contadorfor = 0;
                int mayores = 0, menores = 0;

                for(contadorfor = 0; contadorfor < 5; contadorfor++){
                    printf("Ingrese valor %d\n", contadorfor+1);
                    fflush(stdin);
                    scanf("%d", &datos);
                    if(datos >= 0){
                        mayores++;
                    }
                    else{
                        menores++;
                    }
                }

                printf("En total se ingresaron %d numeros mayores a 0 y %d numeros menores a 0\n", mayores, menores);

                system("Pause");
                system("cls");
                break;

            case 14:
                printf("EJEMPLOS PARA - HACER\n---------------------\n");
                printf(".:EJERCICIO 1:.\n\n");

                printf("Calcular el promedio de un alumno que tiene 7 calificaciones en la\nmateria de Disenio Estructurado de Algoritmos\n\n");

                int contPromedio, notas, sumaCalificaciones = 0;
                float promedioNotas = 0;

                for(contPromedio = 0; contPromedio < 7; contPromedio++){
                    printf("Ingrese nota %d\n", contPromedio+1);
                    fflush(stdin);
                    scanf("%d", &notas);

                    sumaCalificaciones+= notas;
                }

                promedioNotas = (float)sumaCalificaciones/(float)contPromedio;

                printf("El promedio de la materia Disenio Estructurado de Algoritmos es: %.2f\n", promedioNotas);

                system("Pause");
                system("cls");
                break;

            case 15:
                printf("EJEMPLOS PARA - HACER\n---------------------\n");
                printf(".:EJERCICIO 2:.\n\n");

                printf("Leer 10 numeros y obtener su cubo y su cuarta.\n\n");

                int valor = 0;
                int contadorCubo = 0;
                int valorCubo, valorCuarta;

                for(contadorCubo = 0 ; contadorCubo < 10; contadorCubo++){
                    printf("\nIngrese valor %d\n", contadorCubo+1);
                    fflush(stdin);
                    scanf("%d", &valor);

                    valorCubo = valor * valor * valor;
                    printf("El cubo de %d es: %d\n", valor, valorCubo);
                    valorCuarta = valorCubo * valor;
                    printf("La cuarta de %d es: %d\n", valor, valorCuarta);
                }

                system("Pause");
                system("cls");
                break;

            case 16:
                printf("EJEMPLOS PARA - HACER\n---------------------\n");
                printf(".:EJERCICIO 3:.\n\n");

                printf("Leer 10 numeros e imprimir solamente los numeros positivos\n\n");

                int numeros;
                int cont = 0;

                for(cont = 0; cont<10; cont++){
                    printf("Ingrese valor\n");
                    fflush(stdin);
                    scanf("%d",&numeros);

                    if(numeros>=0){
                        printf("El numero es positivo: %d\n",numeros);
                    }
                    else{
                        printf("El numero es negativo, no se muestra\n");
                    }
                }

                system("Pause");
                system("cls");
                break;

            case 17:
                printf("EJEMPLOS PARA - HACER\n---------------------\n");
                printf(".:EJERCICIO 4:.\n\n");

                printf("Leer 15 numeros negativos y convertirlos a positivos e imprimir dichos numeros.\n\n");

                int contador4 = 0;
                int numero4;
                int positivo;

                for(contador4=0; contador4 <15; contador4++){
                    printf("Ingrese numero %d\n", contador4+1);
                    fflush(stdin);
                    scanf("%d", &numero4);
                    while(numero4 >= 0){
                        printf("Ingrese un numero NEGATIVO!\n");
                        fflush(stdin);
                        scanf("%d",&numero4);
                    }

                    positivo = (-1) * numero4;

                    printf("El numero en positivo es: %d\n", positivo);
                }

                system("Pause");
                system("cls");
                break;

            case 18:
                printf("EJEMPLOS PARA - HACER\n---------------------\n");
                printf(".:EJERCICIO 5:.\n\n");

                printf("Suponga que se tiene un conjunto de calificaciones de un grupo de 40 alumnos. Realizar un algoritmo para calcular\nla calificacion media y la calificacion mas baja de todo el grupo.\n\n");

                int calificacion = 0;
                float media = 0;
                int sumaMedia = 0;
                int cantidad = 0;
                int notaMenor = 500;

                for(cantidad = 0; cantidad<3; cantidad++){
                    printf("Ingrese nota del alumno %d\n", cantidad+1);
                    fflush(stdin);
                    scanf("%d", &calificacion);

                    if(notaMenor>calificacion){
                        notaMenor = calificacion;
                    }
                    sumaMedia += calificacion;
                }

                media = (float)sumaMedia/cantidad;
                printf("La nota mas baja es : %d\n", notaMenor);
                printf("La media de las notas es: %.2f\n", media);

                system("Pause");
                system("cls");
                break;

            case 19:
                printf("EJEMPLOS PARA - HACER\n---------------------\n");
                printf(".:EJERCICIO 6:.\n\n");

                printf("Calcular e imprimir la tabla de multiplicar de un numero cualquiera. \nImprimir el multiplicando, el multiplicador y el producto\n\n");

                int numerito = 0;
                int multiplicador = 0;
                int resultado = 0;

                printf("Ingrese numero para mostrar tabla de multiplicacion\n");
                fflush(stdin);
                scanf("%d", &numerito);

                for(multiplicador = 0; multiplicador<=10; multiplicador++){
                        resultado = numerito * multiplicador;
                        printf("%d x %d = %d\n", numerito, multiplicador, resultado);
                }

                system("Pause");
                system("cls");
                break;

            default:
                printf("Opcion incorrecta\n");
        }
        printf("Desea probar otro ejercicio? s - SI, cualquier letra NO\n");
        fflush(stdin);
        scanf("%c", &control);

        system("cls");

    }///primer WHILE

    printf("Gracias por usar esta guia interactiva\n\n");
    return 0;
}

