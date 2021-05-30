// laSecante.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <cstdlib>
#include <windows.h>
#include <cmath>
#include <iomanip>

// Daniel Ramirez

using namespace std;

int  IT, salir, i;
double a, b, TOL, p, fp, E, q0, q1, p0, p1;

double f(double x) {            
    // La funcion matematica es f(x) =
    return  pow(x,3)+x+16;
}

string validar(float E,float tol) {
    if (E<TOL) {
        return "TRUE";
    }
    else {
        return "FALSE";
    }
}

int datos_iteracion() {
    //printf_s("\n \n \n \n \n \n \n \n \n");
    cout << "|  "<< i <<" ";
    cout << fixed << setprecision(15);
    cout << "|  " << p0 <<" ";
    cout << "|  " << p1 <<" ";
    cout << "|  " << q0 <<" ";
    cout << "|  " << q1 <<" ";
    cout << "|  " << p << " ";
    cout << "|  " << f(p) << " ";
    cout << "|  "<< E<<"\n \n";
    return(0);
}

int pedir_datos_iniciales() {
    cout << " METODO DE LA SECANTE"<<endl;
    cout << " Ingrese la aproximacion inicial (p0) :";
    cin >> p0;
    cout <<" Ingrese la aproximacion secundaria(p1) : ";
    cin >> p1;
    cout << endl;
    cout <<"|  IT        p0              p1             q0             q1               p               f(p)              ERROR         " <<endl<<endl;  
    return(0);
}

int salida(int caso) {

    if (caso == 0) { //salida con fracaso
        cout <<"FRACASO, se supero la cantidad maxima de ITERACIONES permitidas"<<endl<<"Si que se alcanzara una aproximacion valida"<<endl ;        
    }
    else {
        cout << endl << endl;
        cout << "  Aproximacion alcanzada con exito en iteraciones : "<<i<<endl;
        cout << "  TOL = "<<TOL<< "    IT = "<<IT;
        cout << "  En el punto  p = " << p;
        cout << "  f(" << p << ")" << " = " << f(p);
        cout << "  Error = "<< abs((p - p0) / p)<<endl<<endl;
       
    }
    return (0);
}

int ejecutar_metodo() {
        
    salir = 0; //indica cuando hay que salir del ciclo repetitivo con exito o fracaso
    i = 2;
    IT = 100;
    TOL = 0.00000001;
    //    0.0000000001
    do {

        q0 = f(p0);
        q1 = f(p1);
        p = p1 - q1 * (p1-p0)/(q1-q0);
        fp = f(p);

        E = abs((p - p1) / p);
     
        cout << setprecision(15);
            datos_iteracion(); //mostrar los datos de la iteracion             
            p0 = p1;
            p1 = p;
            q0 = q1;             
            q1 = f(p);
            i = i + 1;
    } while ((i<IT) && E>TOL);

    if (E<TOL) {
        salida(1); //salida con fracaso
    }
    else {
        salida(0);
    }
    return(0);
}


int main()
{
    int yn;
    do {
        system("cls");
        pedir_datos_iniciales();

        ejecutar_metodo();
        cout << "¿Desea volver a repetir el algoritmo? 1/0";
        cin >> yn;
    } while (yn == 1);
    
}
