/**
    UTN
    Tecnicatura Universitaria en Programacion
    Programacion 1 y Laboratorio de computacion 1
    Comision 10
    Prof. Matias Pascual

    IMPORTANTE:
        Este codigo no pretende de ninguna manera reemplazar el contenido
        teorico de los modulos escritos para tal fin. Solo es una
        referencia que complementa la teoria con ejemplos practicos
        utilizados en clase.
*/

/**
    CLASE 1:
        . INTRODUCCION A LA SINTAXIS DE C
        . LIBRERIAS
        . FUNCION MAIN
        . DECLARAR UNA VARIABLE
        . TIPOS DE DATOS
        . ASIGNACION
        . INICIALIZAR UNA VARIABLE
        . CONSTANTES
        . OPERACIONES CON VARIABLES
        . TOMANDO DATOS DESDE EL USUARIO
        . MOSTRANDO DATOS POR PANTALLA
*/

/// ------------------------------------------------------------------------

/// INTRODUCCION A LA SINTAXIS DE C
/**
    . C es un lenguaje de programacion case sensitive, esto significa que para C,
    la misma palabra escrita de una forma diferente, es otra palabra.

    Ejemplo:
        Main, main, maIn, MAIn, maiN.
        Para C, todas estas palabras son distintas.

    . Existen en C palabras que son "reservadas" esto significa que son palabras
    que ya tienen un significado y uso dentro del lenguaje y que no puedo definir
    nuevamente.

    Algunos ejemplos de estas palabras reservadas son:
        if, else, main, int, float, while.

    . El punto y coma en C es muy importante. La mayoria de las veces, luego de
    escribirle a la computadora que haga algo, deberemos escribir punto y coma.
    Presta atencion al ; al final de la oracion.

    Ejemplo:
        int variableA = 10;

    Aca le estamos diciendo a la computadora que reserve espacio en la memoria RAM
    para una variable de tipo entero y luego le ponemos el punto y coma para
    decirle que ahi termino la orden que le dimos.

    A esta "orden" que le damos a la computadora, le decimos sentencia.
*/

/// ------------------------------------------------------------------------

/// LIBRERIAS
/**
    Son archivos que incluyen definiciones y funciones que nos ayudan a
    programar mas facilmente.

    Las incluimos en nuestro programa con el comando #include.

    Ejemplo:
        #include <windows.h>
*/

#include <stdio.h>      /// esta libreria nos permite usar las funciones printf y scanf
#include <stdlib.h>     /// esta libreria nos permite usar la funcion system

/// ------------------------------------------------------------------------

/// FUNCION main
/**
    Es la funcion principal del programa.

    Lo minimo que nuestro codigo tiene que tener para funcionar es una funcion main.

    La funcion main es por donde comienza nuestro programa. Sin esta funcion, la
    computadora no sabria donde iniciar la ejecucion de lo que estamos creando.

    Se compone de:
        int         - que es el valor de retorno de esta funcion
        main        - el nombre de la funcion
        ()          - parentesis
        {           - llave de inicio
        return 0    - le decimos al programa que al finalizar devuelva un cero
        }           - llave de cierre

        Ejemplo:
            int main()
            {
                return 0;
            }

    Nota: el "return 0" puede no estar. Aun asi se recomienda escribirlo.

    IMPORTANTE: Solo debe haber una unica funcion main en cada programa que
                estamos creando.
*/

/// este es el comienzo de la funcion main de nuestro programa
int main()
{

    /// DECLARAR UNA VARIABLE
    /**
        Para declarar una variable necesitamos dos cosas:
            . tipo de dato que almacenara la variable
            . nombre de la variable

        Ejemplo:
            int miPrimerVariable;
    */

    /// ------------------------------------------------------------------------

    /// TIPOS DE DATOS
    int numerosEnteros;             /// almacena numeros enteros
    float numerosReales;            /// almacena numeros reales
    double numerosRealesGrandes;    /// almacena numeros reales grandes
    char caracteres;                /// almacena caracteres. Por ejemplo letras.

    /// ------------------------------------------------------------------------

    /// ASIGNACION
    /** Es cuando le damos un valor a una variable */

    numerosEnteros = 10;
    numerosReales = 10.5F; /// ponemos una F al final para indicarle a la computadora que
                           /// 10.5 es del tipo float.

    numerosRealesGrandes = 10.5;    /// al no poner una F al final, la computadora interpreta
                                    /// que 10.5 es un double.

    caracteres = 'a';   /// usamos comillas simples para los caracteres. Tambien podriamos usar
                        /// comillas dobles, aunque no es lo mas recomendable, ya que las
                        /// comillas dobles son para las cadenas de caracteres.

    /// ------------------------------------------------------------------------

    /// INICIALIZAR UNA VARIABLE
    /** Es darle un valor a una variable al momento de su declaracion */

    int miVariableA = 10;
    float otraVariable = 0.5F;
    double algunNumeroDouble = 0.00007;
    char unaSimpleVariableChar = 'm';

    /// ------------------------------------------------------------------------

    /// CONSTANTES
    /**
        Es un tipo especial de variable al que se le deba dar un valor inicial y no
        puede cambiarse este valor en ninguna parte de nuestro programa.

        Se acostumbra a escribirlas en MAYUSCULAS
    */

    const float FUERZA_DE_GRAVEDAD = 9.8F;
    const int NUMERO_ALUMNOS = 20;
    const char SALIR = 's';
    const double VELOCIDAD = 0.00025;

    /// ------------------------------------------------------------------------

    /// OPERACIONES CON VARIABLES
    /**
        Podemos hacer operaciones matematicas con las variables.

        Por ejemplo, para sumarle un valor a una variable, escribimos:

            miVariableA = miVariableA + 10;

        Tambien podemos escribir lo mismo poniendo el + antes del =

            miVariableA += 10;

            (esto es lo mismo y mas rapido de escribir)
    */

    /// Ejemplos de operaciones simples:

    int variableA = 0;
    variableA += 10;   /// sumar
    variableA -= 10;   /// restar

    float variableB = 0.0F;
    variableB *= 0.5F;  /// multiplicacion
    variableB /= 0.5F;  /// division

    /// Ejemplos de operaciones entre variables:

    variableA += variableB;
    variableB /= variableA + variableA;
    variableA -= variableA + variableB / 10.4F + 2;
    variableB *= (variableA + 2) * 2;

    /// ------------------------------------------------------------------------

    /// MOSTRANDO DATOS POR PANTALLA
    /**
        Utilizamos la funcion printf()

        Esta funcion tiene dos parametros:
            Entre comillas, el texto que vamos a mostrar y, si vamos a mostrar
            una variable, un simbolo que representa el tipo de dato de la
            variable.

            Las variables que queremos mostrar. Pueden ser una, muchas o ninguna.
    */

    /// Ejemplos

    /// mostrando solo texto
    printf("Hola Mundo!");

    /// Mostrando una variable de tipo int
    int mostrandoUnEntero = 30;
    printf("%d", mostrandoUnEntero);  /// %d es la manera en que le decimos a printf
                                        /// que nuestra variable es de tipo int

    /// Ejemplos con otros tipos de datos
    char mostrandoUnCaracter = 'C';
    printf("%c", mostrandoUnCaracter);

    float mostrandoUnFloat = 0.5F;
    printf("%f", mostrandoUnFloat);

    double mostrandoUnDouble = 0.25;
    printf("%lf", mostrandoUnDouble);

    /// Tambien podemos mostrar valores literales.
    /// Es importante respetar el tipo de dato, igual que como hacemos con las variables.

    printf("%d", 50);       /// int
    printf("%c", 'A');      /// char
    printf("%f", 10.05F);   /// float
    printf("%lf", 0.0001);   /// double

    /// Mostrando un texto y un valor
    printf("Estoy estudiando programacion y mi numero preferido es el %d", 33);

    /// Mostrando un texto y una variable
    float altura = 1.71F;
    printf("Si me paro bien derecho, mido: %f", altura);

    /// Mostrando texto, valores y variables
    int variableC = 10;
    float variableD = 1.5F;
    char variableE = 'A';
    double variableF = 70.98;

    /// Asi se pueden combinar variables, valores literales y texto.
    printf("Variables: %d, %f, %c, %lf. Valores %d, %c", variableC, variableD, variableE, variableF, 10, 'C');

    /// ------------------------------------------------------------------------

    /// TOMANDO DATOS INGRESADOS POR EL USUARIO
    /**
        Para tomar datos del usuario, utilizamos la funcion scanf()

        Esta funcion tiene dos parametros:
            . Entre comillas, el tipo de dato de la variable que vamos a utilizar
            para guardar el dato.

            . La direccion de memoria de la variable donde guardaremos el dato. Esto
            se lo indicamos poniendo el simbolo & antes del nombre de la variable.

        El simbolo &, se escribe y pronuncia ampersand. Y en el lenguaje C, podriamos
        decir que se traduce como "la direccion de memoria de... "

        Asi, cuando escribimos &variableA, le estamos diciendo a C:

            "la direccion de memoria de variableA".
    */

    /// Ejemplos
    int guardoUnEntero;
    scanf("%d", &guardoUnEntero);

    char guardoUnCaracter;
    scanf("%c", &guardoUnCaracter);

    float guardoUnFloat;
    scanf("%f", &guardoUnFloat);

    double guardoUnDouble;
    scanf("%lf", &guardoUnDouble);      /// para diferenciar un float de un double,
                                        /// se usa lf (LF) en lugar de f

    /// ------------------------------------------------------------------------

    return 0;   /// devolvemos un cero al finalizar nuestro programa

} /// aca finaliza la funcion main de nuestro programa
