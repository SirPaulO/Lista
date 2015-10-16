#include "lista.h"
#include "testing.h"
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void pruebas_memoria_dinamica();
void pruebas_memoria_estatica();
void pruebas_iterador_externo();
void pruebas_iterador_externo_enteros();
void pruebas_iterador_interno_enteros();
void pruebas_iterador_externo_varios();
void pruebas_molestass();

void pruebas_lista_alumno() {
    pruebas_memoria_estatica();
    pruebas_memoria_dinamica();

    pruebas_iterador_externo_varios();

    pruebas_iterador_externo_enteros();
    pruebas_iterador_interno_enteros();
    pruebas_molestass();
}


void pruebas_molestass()
{
    char char_a = 'a';
    char char_b = 'b';
    char char_c = 'c';

    lista_t* lista = lista_crear();
    if(lista == NULL)
        return;

    printf("INICIO DE PRUEBAS MOLESTAS \n");

    print_test("Prueba crear lista", lista);

    print_test("Prueba insertar primero valor1", lista_insertar_primero(lista, &char_a));
    print_test("Prueba insertar primero valor2", lista_insertar_primero(lista, &char_b));
    print_test("Prueba insertar primero valor3", lista_insertar_primero(lista, &char_c));

    lista_iter_t *iter = lista_iter_crear(lista);

    print_test("Prueba crear iterador", iter );

    print_test("Prueba iter no esta al final.", lista_iter_al_final(iter)==false );
    print_test("Prueba iter borrar es valor3", lista_borrar(lista, iter)==&char_c );
    print_test("Prueba iter ver_actual es valor2", lista_iter_ver_actual(iter)==&char_b);
    print_test("Prueba lista ver_primero es valor2", lista_ver_primero(lista)==&char_b);
    print_test("Prueba iter borrar es valor2", lista_borrar(lista, iter)==&char_b );
    print_test("Prueba iter ver_actual es valor1", lista_iter_ver_actual(iter)==&char_a );
    print_test("Prueba lista ver_primero es valor1", lista_ver_primero(lista)==&char_a );
    print_test("Prueba iter borrar es valor1", lista_borrar(lista, iter)==&char_a );
    print_test("Prueba iter avanzar es false", lista_iter_avanzar(iter)==false );

    print_test("Prueba lista esta vacia", lista_esta_vacia(lista) );
    print_test("Prueba lista largo es 0", lista_largo(lista) == 0);
    print_test("Prueba lista ver_primero es NULL", lista_ver_primero(lista)==NULL );

    print_test("Insertar valor1 al final luego de borrar el ultimo", lista_insertar_ultimo(lista, &char_a));

    lista_iter_destruir(iter);

    printf("Iter destruido\n");

    iter = lista_iter_crear(lista);

    print_test("Prueba crear iterador", iter );

    print_test("Prueba iter borrar es valor1", lista_borrar(lista, iter)==&char_a );
    print_test("Prueba iter avanzar es false", lista_iter_avanzar(iter)==false );

    print_test("Prueba lista esta vacia", lista_esta_vacia(lista) );
    print_test("Prueba lista largo es 0", lista_largo(lista) == 0);
    print_test("Prueba lista ver_primero es NULL", lista_ver_primero(lista)==NULL );
    lista_iter_destruir(iter);

    printf("Iter destruido\n");

    //=======================

    printf("PRUEBAS MOLESTAS PARTE II\n");

    iter = lista_iter_crear(lista);

    print_test("Iter creado", iter );
    print_test("Inserta con el iterador al principio", lista_insertar(lista, iter, &char_a));
    print_test("Se cambió el primer elemento de la lista", lista_ver_primero(lista) == &char_a);
    print_test("Ver actual con el iterador luego de insertar", lista_iter_ver_actual(iter)==&char_a);
    print_test("El largo es 1 luego de insertar un elemento", lista_largo(lista) == 1 );
    print_test("No está al final", !lista_iter_al_final(iter));
    print_test("Avanza después de insertar", lista_iter_avanzar(iter));
    print_test("Está al final", lista_iter_al_final(iter));
    print_test("Inserción con el iterador al final", lista_insertar(lista, iter, &char_b));
    print_test("Verifico actual luego de insertar al final", lista_iter_ver_actual(iter) == &char_b);
    print_test("Se actualizó el largo", lista_largo(lista)==2);
    print_test("Inserta uno mas luego del insertado", lista_insertar_ultimo(lista,&char_c));
    print_test("Se actualizó el largo", lista_largo(lista)==3);

    lista_iter_destruir(iter);

    printf("Iter destruido\n");

    printf("========================== IMPRIMIR LISTA \n");

    iter = lista_iter_crear(lista);

    print_test("Prueba crear iterador", iter );

    int pos = 0;
    while(!lista_iter_al_final(iter)){
        printf("Iter pos: %d es: %c\n", pos, *(char*)lista_iter_ver_actual(iter));
        pos++;
        lista_iter_avanzar(iter);
    }

    lista_iter_destruir(iter);

    printf("Iter destruido\n");

    printf("========================== FIN \n");

    lista_iter_t *iter2 = lista_iter_crear(lista);

    print_test("Creacion de un nuevo iterador", iter2);

    print_test("Avanzo en el segundo iterador", lista_iter_avanzar(iter2));
    print_test("Ver actual con el iterador", lista_iter_ver_actual(iter2)==&char_b);
    print_test("Avanzo en el segundo iterador", lista_iter_avanzar(iter2));
    print_test("Ver actual con el iterador", lista_iter_ver_actual(iter2)==&char_c);
    print_test("Avanzo en el segundo iterador", lista_iter_avanzar(iter2));
    print_test("El segundo iterador está al final", lista_iter_al_final(iter2));

    lista_iter_destruir(iter2);
    printf("Iter2 destruido\n");

    iter2 = lista_iter_crear(lista);

    print_test("Iter2 Reborn", iter2);

    while(!lista_iter_al_final(iter2)){
        lista_borrar(lista, iter2);
        printf("Iter2 Eliminando de la lista\n");
    }

    lista_iter_destruir(iter2);
    printf("Iter2 destruido\n");

    print_test("Prueba lista esta vacia", lista_esta_vacia(lista) );
    print_test("Prueba lista largo es 0", lista_largo(lista) == 0);

    printf("PRUEBAS MOLESTAS RELOADED\n");

    int numero2 = 2;
    int numero3 = 3;
    int numero5 = 5;
    int numero10 = 10;
    int sumaTotal = numero2 + numero3 + numero5 + numero10;
    int sumaParcial = 0;

    print_test("Lista creada no es null", lista != NULL);
    print_test("Lista esta vacia", lista_esta_vacia(lista));
    print_test("Lista Largo es 0", lista_largo(lista) == 0);
    print_test("Lista Insertar 2", lista_insertar_ultimo(lista, &numero2) );
    print_test("Lista Ver primero es 2", *(int*)lista_ver_primero(lista) == numero2);
    print_test("Lista Largo es 1", lista_largo(lista) == 1);
    print_test("Lista Insertar 3", lista_insertar_ultimo(lista, &numero3) );
    print_test("Lista Largo es 2", lista_largo(lista) == 2);
    print_test("Lista Insertar 5", lista_insertar_ultimo(lista, &numero5) );
    print_test("Lista Insertar 10",lista_insertar_ultimo(lista, &numero10) );

    iter = lista_iter_crear(lista);
    print_test("Iterador Creado", iter);

    // Fixed Largo
    print_test("Iterador al principio", *(int*)lista_iter_ver_actual(iter) == numero2);
    print_test("Iterador Insertar 5", lista_insertar(lista, iter, &numero5) );
    print_test("Iterador actual es 5", *(int*)lista_iter_ver_actual(iter) == numero5);
    print_test("Lista Largo es 5", lista_largo(lista) == 5);

    lista_iter_destruir(iter);

    iter2 = lista_iter_crear(lista);
    print_test("Iterador 2 Creado", iter2);
    print_test("Avanzo en el segundo iterador", lista_iter_avanzar(iter2));
    print_test("Ver actual con el iterador 2", *(int*)lista_iter_ver_actual(iter2) == numero2 );

    while(!lista_iter_al_final(iter2)){
        sumaParcial += *(int*)lista_iter_ver_actual(iter2);
        print_test("Sumando Parcial", lista_iter_avanzar(iter2));
    }

    print_test("Suma total Correcta", sumaParcial == sumaTotal);

    print_test("Inserción con el iterador al final", lista_insertar(lista, iter2, &numero3) );
    print_test("Verifico actual luego de insertar al final", *(int*)lista_iter_ver_actual(iter2) == numero3);
    print_test("Lista Largo es 6", lista_largo(lista) == 6);
    print_test("Inserta uno mas luego del insertado", lista_insertar(lista, iter2, &numero3) );
    print_test("Lista Largo es 7", lista_largo(lista) == 7);

    print_test("Lista borrar actual", *(int*)lista_borrar(lista, iter2) == numero3);
    print_test("Lista Largo es 6", lista_largo(lista) == 6);
    print_test("Verifico actual luego de borrar", *(int*)lista_iter_ver_actual(iter2) == numero3);

    print_test("Destruir Lista e Iterador 2", true);

    lista_iter_destruir(iter2);


    lista_destruir(lista, NULL);
}

void pruebas_iterador_externo_enteros()
{
    lista_t* lista_enteros = lista_crear();
    if(lista_enteros == NULL)
        return;

    int numero2 = 2;
    int numero3 = 3;
    int numero5 = 5;
    int numero10 = 10;
    int sumaTotal = numero2 + numero3 + numero5 + numero10;
    int sumaParcial = 0;

    print_test("Lista creada no es null", lista_enteros != NULL);
    print_test("Lista esta vacia", lista_esta_vacia(lista_enteros));
    print_test("Lista Insertar 2", lista_insertar_ultimo(lista_enteros, &numero2) );
    print_test("Lista Insertar 3", lista_insertar_ultimo(lista_enteros, &numero3) );
    print_test("Lista Insertar 5", lista_insertar_ultimo(lista_enteros, &numero5) );
    print_test("Lista Insertar 10",lista_insertar_ultimo(lista_enteros, &numero10) );

    lista_iter_t *iter = lista_iter_crear(lista_enteros);
    print_test("Iterador Creado", iter);

    while(!lista_iter_al_final(iter)){
        sumaParcial += *(int*)lista_iter_ver_actual(iter);
        print_test("Sumando Parcial", lista_iter_avanzar(iter));
    }

    print_test("Suma total Correcta", sumaParcial == sumaTotal);
    print_test("Destruir Lista e Iterador", true);
    lista_iter_destruir(iter);
    lista_destruir(lista_enteros, NULL);
}

bool sumar_elementos(void *dato, void *extra)
{
    int* sumaParcial = extra;
    *sumaParcial = *sumaParcial + *(int *)dato;
    return true;
}

void pruebas_iterador_interno_enteros()
{
   lista_t* lista_enteros = lista_crear();
    if(lista_enteros == NULL)
        return;

    int numero2 = 2;
    int numero3 = 3;
    int numero5 = 5;
    int numero10 = 10;
    int sumaTotal = numero2 + numero3 + numero5 + numero10;
    int sumaParcial = 0;

    print_test("Lista creada no es null", lista_enteros != NULL);
    print_test("Lista esta vacia", lista_esta_vacia(lista_enteros));
    print_test("Lista Insertar 2", lista_insertar_ultimo(lista_enteros, &numero2) );
    print_test("Lista Insertar 3", lista_insertar_ultimo(lista_enteros, &numero3) );
    print_test("Lista Insertar 5", lista_insertar_ultimo(lista_enteros, &numero5) );
    print_test("Lista Insertar 10",lista_insertar_ultimo(lista_enteros, &numero10) );

    lista_iterar(lista_enteros, sumar_elementos, &sumaParcial);
    print_test("Suma total Correcta", sumaParcial == sumaTotal);
    lista_destruir(lista_enteros, NULL);
}

void pruebas_iterador_externo_varios()
{
    lista_t* ejemplo = lista_crear();

    char cadena[] = "Hola Mundo!";
    int entero = 3;
    char ch = 'x';
    float flt = 3.1415f;
    int * puntero = &entero;
    double doble = 1.4142;

    print_test("Lista creada no es null", ejemplo != NULL);
    print_test("Lista esta vacia", lista_esta_vacia(ejemplo));

    lista_iter_t *iter = lista_iter_crear(ejemplo);
    print_test("Iterador Creado", iter);

    print_test("Lista Insertar Cadena", lista_insertar(ejemplo, iter, cadena) );
    print_test("Lista Insertar Entero", lista_insertar(ejemplo, iter, &entero) );
    print_test("Lista Insertar Char",   lista_insertar(ejemplo, iter, &ch) );
    print_test("Lista Insertar Float",  lista_insertar(ejemplo, iter, &flt) );
    print_test("Lista Insertar Punter", lista_insertar(ejemplo, iter, puntero) );
    print_test("Lista Insertar Double", lista_insertar(ejemplo, iter, &doble) );

    print_test("Ver dato actual del Iterador", *(double*)lista_iter_ver_actual(iter) == doble );
    print_test("Avanzar Iterador", lista_iter_avanzar(iter));

    print_test("Ver dato actual del Iterador", (int*)lista_iter_ver_actual(iter) == puntero );
    print_test("Avanzar Iterador", lista_iter_avanzar(iter));

    print_test("Ver dato actual del Iterador", *(float*)lista_iter_ver_actual(iter) == flt );
    print_test("Avanzar Iterador", lista_iter_avanzar(iter));

    print_test("Ver dato actual del Iterador", *(char*)lista_iter_ver_actual(iter) == ch );
    print_test("Avanzar Iterador", lista_iter_avanzar(iter));

    print_test("Ver dato actual del Iterador", *(int*)lista_iter_ver_actual(iter) == entero );
    print_test("Avanzar Iterador", lista_iter_avanzar(iter));

    print_test("Ver dato actual del Iterador", *(char*)lista_iter_ver_actual(iter) == cadena[0] );
    print_test("Avanzar Iterador", lista_iter_avanzar(iter));

    print_test("Iterador al final", lista_iter_al_final(iter));
    lista_iter_destruir(iter);
    print_test("Destruir Iterador", true);

    iter = lista_iter_crear(ejemplo);
    print_test("Iterador Creado", iter);
    print_test("Avanzar Iterador", lista_iter_avanzar(iter));

    print_test("Lista borrar Puntero", (int*)lista_borrar(ejemplo, iter) == puntero );
    print_test("Ver dato actual del Iterador es Float", *(float*)lista_iter_ver_actual(iter) == flt );
    print_test("Avanzar Iterador", lista_iter_avanzar(iter));

    print_test("Lista borrar Char", *(char*)lista_borrar(ejemplo,iter) == ch );
    print_test("Ver dato actual del Iterador", *(int*)lista_iter_ver_actual(iter) == entero );
    print_test("Avanzar Iterador", lista_iter_avanzar(iter));

    lista_iter_destruir(iter);
    print_test("Destruir Iterador", true);
    lista_destruir(ejemplo, NULL);
}

void pruebas_memoria_estatica()
{
    lista_t* ejemplo = lista_crear();

    char cadena[] = "Hola Mundo!";
    int entero = 3;
    char ch = 'x';
    float flt = 3.1415f;
    int * puntero = &entero;
    double doble = 1.4142;
    lista_t* listaPrueba = lista_crear();

    print_test("Lista creada no es null", ejemplo != NULL);
    print_test("Lista esta vacia", lista_esta_vacia(ejemplo));

    print_test("Lista Insertar Ultimo \"Hola Mundo!\" es true", lista_insertar_ultimo(ejemplo, cadena) );
    print_test("Lista Insertar Ultimo entero '3' es true", lista_insertar_ultimo(ejemplo, &entero) );
    print_test("Lista Insertar Ultimo char 'x' es true", lista_insertar_ultimo(ejemplo, &ch) );
    print_test("Lista Insertar Ultimo float '3.1415' es true", lista_insertar_ultimo(ejemplo, &flt) );
    print_test("Lista Insertar Ultimo puntero a entero es true", lista_insertar_ultimo(ejemplo, puntero) );
    print_test("Lista Insertar Ultimo double '1.4142' es true", lista_insertar_ultimo(ejemplo, &doble) );
    print_test("Lista Insertar Primero double '1.4142' es true", lista_insertar_primero(ejemplo, &doble) );

    if(listaPrueba != NULL)
        print_test("Lista Insertar Ultimo listaPrueba es true", lista_insertar_ultimo(ejemplo, &listaPrueba) );

    print_test("Lista no vacia", lista_esta_vacia(ejemplo) == false);

    print_test("Lista Borrar Primero es double '1.4142'", *( (double*) lista_borrar_primero(ejemplo) ) == doble);
    print_test("Lista Borrar Primero es cadena \"Hola Mundo!\"", strcmp( (char*) lista_borrar_primero(ejemplo), cadena) == 0);
    print_test("Lista Borrar Primero es entero '3'", *( (int*) lista_borrar_primero(ejemplo) ) == entero);
    print_test("Lista ver primero es char'x'", *( (char*) lista_ver_primero(ejemplo) ) == ch);
    print_test("Lista Borrar Primero es char 'x'", *( (char*) lista_borrar_primero(ejemplo) ) == ch);
    print_test("Lista Borrar Primero es float '3.1415'", *( (float*) lista_borrar_primero(ejemplo) ) == flt);
    print_test("Lista Borrar Primero es puntero a entero", *( (int*) lista_borrar_primero(ejemplo) ) == *puntero);
    print_test("Lista Borrar Primero es double '1.4142'", *( (double*) lista_borrar_primero(ejemplo) ) == doble);

    if(listaPrueba != NULL)
        print_test("Lista Borrar Primero es listaPrueba", *( (lista_t**) lista_borrar_primero(ejemplo) ) == listaPrueba);

    lista_destruir(listaPrueba, NULL);

    print_test("Lista esta vacia", lista_esta_vacia(ejemplo));

    print_test("Lista Borrar Primero es NULL", lista_borrar_primero(ejemplo) == NULL);

    lista_destruir(ejemplo, NULL);
}

void pruebas_memoria_dinamica()
{
    lista_t* ejemplo = lista_crear();

    char* cadena = malloc(sizeof(char)*12);
    strcpy(cadena, "Hola Mundo!");

    int* entero = malloc(sizeof(int));
    *entero = 3;

    char* ch = malloc(sizeof(char));
    *ch = 'x';

    float* flt = malloc(sizeof(float));
    *flt = 3.1415f;

    double* doble = malloc(sizeof(double));
    *doble = 1.4142;

    int* puntero = entero;

    lista_t* listaPrueba = lista_crear();

    print_test("Lista creada no es null", ejemplo != NULL);
    print_test("Lista esta vacia", lista_esta_vacia(ejemplo));

    print_test("Lista Insertar Ultimo \"Hola Mundo!\" es true", lista_insertar_ultimo(ejemplo, cadena) );
    print_test("Lista Insertar Ultimo entero '3' es true", lista_insertar_ultimo(ejemplo, entero) );
    print_test("Lista Insertar Ultimo char 'x' es true", lista_insertar_ultimo(ejemplo, ch) );
    print_test("Lista Insertar Ultimo float '3.1415' es true", lista_insertar_ultimo(ejemplo, flt) );
    print_test("Lista Insertar Ultimo puntero a entero es true", lista_insertar_ultimo(ejemplo, puntero) );
    print_test("Lista Insertar Ultimo double '1.4142' es true", lista_insertar_ultimo(ejemplo, doble) );
    print_test("Lista Insertar Primero double '1.4142' es true", lista_insertar_primero(ejemplo, doble) );

    if(listaPrueba != NULL)
        print_test("Lista Insertar Ultimo listaPrueba es true", lista_insertar_ultimo(ejemplo, &listaPrueba) );

    print_test("Lista no vacia", lista_esta_vacia(ejemplo) == false);

    print_test("Lista Borrar Primero es double '1.4142'", *( (double*) lista_borrar_primero(ejemplo) ) == *doble);
    print_test("Lista Borrar Primero es cadena \"Hola Mundo!\"", strcmp( (char*) lista_borrar_primero(ejemplo), cadena) == 0);
    print_test("Lista Borrar Primero es entero '3'", *( (int*) lista_borrar_primero(ejemplo) ) == *entero);
    print_test("Lista ver primero es char'x'", *( (char*) lista_ver_primero(ejemplo) ) == *ch);
    print_test("Lista Borrar Primero es char 'x'", *( (char*) lista_borrar_primero(ejemplo) ) == *ch);
    print_test("Lista Borrar Primero es float '3.1415'", *( (float*) lista_borrar_primero(ejemplo) ) == *flt);
    print_test("Lista Borrar Primero es puntero a entero", *( (int*) lista_borrar_primero(ejemplo) ) == *puntero);
    print_test("Lista Borrar Primero es double '1.4142'", *( (double*) lista_borrar_primero(ejemplo) ) == *doble);

    if(listaPrueba != NULL)
        print_test("Lista Borrar Primero es listaPrueba", *( (lista_t**) lista_borrar_primero(ejemplo) ) == listaPrueba);

    lista_destruir(listaPrueba, NULL);

    print_test("Lista esta vacia", lista_esta_vacia(ejemplo));

    print_test("Lista Borrar Primero es NULL", lista_borrar_primero(ejemplo) == NULL);

    // Lista Insertar Ultimo de nuevo para que el destructor libere la memoria.
    print_test("Lista Insertar Ultimo cadena \"Hola Mundo!\" es true", lista_insertar_ultimo(ejemplo, cadena) );
    print_test("Lista Insertar Ultimo entero '3' es true", lista_insertar_ultimo(ejemplo, entero) );
    print_test("Lista Insertar Ultimo char 'x' es true", lista_insertar_ultimo(ejemplo, ch) );
    print_test("Lista Insertar Ultimo float '3.1415' es true", lista_insertar_ultimo(ejemplo, flt) );
    print_test("Lista Insertar Ultimo double '1.4142' es true", lista_insertar_ultimo(ejemplo, doble) );

    lista_destruir(ejemplo, free);
}
