%Implementacion del metodo de NewtonRaphson
%Primera version
%Autor:Daniel
%fecha: 04/03/20201

clc
clear
format long

disp('METODO DE NEWTON RAPHSON')
promt = 'INGRESE LA APROXIMACION INICIAL(p0): ';
p0 = input(promt);
promt = 'INGRESE LA TOLERANCIA (TOL): ';
TOL = input(promt);
promt = 'INGRESE LA CANTIDAD MAXIMA DE ITERACIONES: ';
IT = input(promt);

i = 1;
salida = 0; %controla el exito o fracaso del programa

disp('          IT                p0                  p                  f(p)               ERROR     ')
while (i<=IT) && salida == 0
    
    p = p0 - (Fx(p0)/Gx(p0));   
    E = abs((p-p0)/p);
    
    iteracion = [i,p0,p,Fx(p),abs((p-p0)/p)];
    disp(iteracion);
    if Fx(p)==0 || E<TOL
        disp('Solucion: '); disp(p);
        disp('Iteraciones'); disp(i);
        salida=1;
    else
        i = i+1;       
        p0 = p;       
    end
end  
if salida == 0
    disp('El algoritmo fracaso.');
end


