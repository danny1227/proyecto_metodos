// Biseccion1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <cstdlib>
#include <windows.h>
#include <cmath>


using namespace std;

int i, IT, salir;
float a, b, TOL, p, p0, FA, FD, E;

float f(float x) {
    //La funcion matematica es f(x) =  x^5 + sen(x) – 1.2 = 0

    //return  (pow(x,5) + sin(x) - 1.2);
    return pow(x, 3) -2* pow(x, 2) -5;
}

float g(float x) {
    //-****La transformacion matematica es g(x) = 5x^4+ cos(x)
    //return  (5 * po   w(x,4) + cos(x));
    return  3*pow(x, 2) -4*x;
}


int datos_iteracion() {
    //printf_s("\n \n \n \n \n \n \n \n \n");

    printf(" |  %i ", i);
    printf(" |  %4.15f", p0);
    printf(" |  %4.15f", p);
    printf(" |  %4.15f", f(p));
    printf(" |  %4.15f", abs(((p - p0) / p)));
    printf_s("\n");
    return(0);
}


int pedir_datos_iniciales() {
    printf("METODO DE NEWTON TAPHSON");
    printf("\n");
    printf("Ingrese la aproximacion inicial (p0): "); scanf_s("%f", &p0);
    printf("Ingrese la tolerancia(TOL): "); scanf_s("%f", &TOL);
    printf("Ingrese la cantidad maxima de iteraciones "); scanf_s("%i", &IT);
    printf(" \n \n ");
    printf(" |  IT              p0                   p                 f(p)                ERROR      ");
    printf(" \n");
    return(0);
}

int salida(int caso) {

    if (caso == 0) { //salida con fracaso
        printf("FRACASO, se supero la cantidad maxima de ITERACIONES permitidas");
        printf("Si que se alcanzara una aproximacion valida");
    }
    else {
        printf_s("\n \n");
        printf(" Aproximaciones alcanzada con exito: \n Iteraciones: %i", i);
        printf(" En el punto = %4.15f", p0);
        printf("\n");
        printf(" p = %4.15f ", p);
        printf(" f(%4.15f) = %4.15f  ", p, f(p));
        printf(" Error= %4.15f", abs(((p - p0) / p)));
        printf_s("\n \n");
    }
    return (0);
}

int ejecutar_metodo() {
    salir = 0; //indica cuando hay que salir del ciclo repetitivo con exito o fracaso
    i = 1;    
   //se asigna por primera ocacion el valor de p      
    
    
    do {
        
        p = p0 - (f(p0) / g(p0));
        
        E = abs((p - p0) / p);

        if (f(p) == 0 || E < TOL) {
            salir = 1;
            salida(1); //salida con exito
        }
        else {
            datos_iteracion(); //mostrar los datos de la iteracion 
            i = i++;
            p0=p;
        }
    } while ((i<=IT) and salir == 0);

    if (salir == 0) {
        salida(0); //salida con fracaso
    }
    return(0);
}


int main()
{

    pedir_datos_iniciales();

    ejecutar_metodo();

}

// Run
