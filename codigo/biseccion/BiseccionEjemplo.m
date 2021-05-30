%Implementacion del metodo de biseccion
%Primera version
%Autor:Daniel
%fecha: 04/03/20201

clc
clear
format long

disp('METODO DE BISECCION')
disp('PARA DEFINIR EL INTERVALO [a,b]');
promt = 'Ingrese el valor de a: ';
a = input(promt);
promt = 'Ingres el valor de b: ';
b = input(promt);
i = 1;
TOL = 0.0000001;
IT = 100;
salida = 0; %controla el exito o fracaso del programa
FA = Fx(a);
disp('            i                   a                  b                   p                 f(p)              E')
while i<IT & salida == 0
    p = (a+b)/2;   
    FP = Fx(p);
    iteracion = [i,a,b,p,Fx(p),abs((b-a)/2)];
    disp(iteracion);
    if FP==0 | abs((b-a)/2)<TOL
        disp('Solucion: '); disp(p);
        disp('Iteraciones'); disp(i);
        salida=1;
    end;
    if salida == 0
        i = i +1;
       if ((FA * FP)>0)
           a = p;
           FA = FP;
       else
           b = p;
       end;
    end;
end;
if salida == 0
    disp('El algoritmo fracaso...');
end;




