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
float a, b, TOL, p, FA, FP;


void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon,dwPos);
}

float f(float x) {
    float ex = -(pow(x, 2));
    //La funcion matematica es f(x) = x^5 - x+ 3 = 0
    //return ( pow(x,5) - x + 3 );

    //La funcion matematica es f(x) = x^5 + sen(x) -1.2 = 0
    //return (pow(x, 5) + sin(x) - 1.2);
    //la funcion matematica es: 
    return pow(exp(1), ex ) -x + 1.37;
}

int dibujar_pantalla() {
int i, j;

    system("cls");
    gotoxy(1, 1);
    printf("%c",201);
    for ( i = 2; i < 79; i++)
    {
        gotoxy(i,1);
        printf("%c",205);
    }
    gotoxy(79, 1);
    printf("%c",187);
    for ( i = 2; i < 24; i++)
    {
        gotoxy(1,i); printf("%c",186);
        gotoxy(79,i); printf("%c", 186);
    }
    gotoxy(1, 24);
    printf("%c",200);
    for ( i = 2; i < 79; i++)
    {
        gotoxy(i, 24);
        printf("%c", 205);
    }
    printf("%c",188);
    printf("\n \n");
    //gotoxy(8, 4);
    printf("METODOS NUMERICOS");
    //gotoxy(8, 5);
    printf("METODO DE BISECCION");
    printf("\n \n");
    return(0);
}

int datos_iteracion() {
    //gotoxy(8, 13); 
    //printf_s("\n \n \n \n \n \n \n \n \n");
    
    printf(" Iteraciion: %i", i);
    printf(" Intervalo: [%4.8f, %4.8f]", a,b);
    printf(" p = %4.8f", p);
    printf(" f(%4.8f) = %4.8f", p, f(p));
    printf(" Error: %4.8f", abs((b-a)/2));
    printf_s("\n ");
    return(0);
}


int pedir_datos_iniciales() {
    //gotoxy(8,7);
    printf("Ingrese el intervalo [a,b]: ");
    printf_s("\n");
    //gotoxy(8, 8); 
    printf("Ingrese el limite inferior(a): "); scanf_s("%f", &a);
    //gotoxy(8, 9); 
    printf("Ingrese el limite superior(b): "); scanf_s("%f", &b);
    //gotoxy(8, 10); 
    printf("Ingrese la tolerancia(TOL): "); scanf_s("%f", &TOL);
    //gotoxy(8, 11); 
    printf("Ingrese la cantidad maxima de iteraciones "); scanf_s("%i", &IT);
    printf_s("\n ");
    return(0);
}

int salida(int caso) {
    
    if (caso == 0) { //salida con fracaso
        //gotoxy(8,13);
        printf("FRACASO, se supero la cantidad maxima de ITERACIONES permitidas");
        //gotoxy(8,14);
        printf("Si que se alcanzara una aproximacion valida");
    }
    else {
        //gotoxy(8, 13);
        printf(" Aproximaciones alcanzada con exito: Iteraciones: %i ",i);
        printf_s("\n ");
        //gotoxy(8, 14);
        printf(" Intervalo: [%4.8f, %4.8f]", a, b);
        //gotoxy(8, 15);
        printf(" p=%4.8f",p);
        //gotoxy(8, 16);
        printf(" f(%4.8f) = %4.8f", p, f(p));
        //gotoxy(8, 17);
        printf(" Error: %4.8f", abs((b-a)/2));
        printf_s("\n ");
        printf_s("\n ");

    }
    return (0);
}

int ejecutar_metodo() {
    salir = 0; //indica cuando hay que salir del ciclo repetitivo con exito o fracaso
    i = 1;
    FA = f(a);
    
    do {
        p = (a + b) / 2; //calcula el punto p de la iteracion
        FP = f(p); //calcular el valor de la funcion en el punto p
        
        if (FP == 0 || abs((b-a)/2)< TOL) {
            salir = 1;
            salida(1); //salida con exito
        }
        else {
            datos_iteracion(); //mostrar los datos de la iteracion 
            i = i + 1;
            if ((FA * FP) > 0) {
                a = p;
                FA = FP;
            }
            else {
                b = p;
            }
        }
    } while ((i<IT)and (salir==0));
    
    if (salir == 0) {
        salida(0); //salida con fracaso
    }
    return(0);
}


int main()
{
    //dibujar_pantalla();

    pedir_datos_iniciales();

    ejecutar_metodo();

}

// Run