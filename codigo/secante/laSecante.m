%Implementacion de "La secante"
%Autor:Daniel Ramirez
%fecha: 04/20201

clc
clear
format long

disp('METODO DE LA SECANTE')
promt = 'INGRESE LA APROXIMACION INICIAL(p0): ';
p0 = input(promt);
promt = 'INGRESE LA APROXIMACION INICIAL(p1): ';
p1 = input(promt);

i = 2;
TOL = 0.0000000001;
IT = 100;
salida = 0; %controla el exito o fracaso del programa
q0 = Fx(p0);
q1 = Fx(p1);

disp('       i                   p0                   p1                   q0                      q1               p                    f(p)               ERROR     ')

while (i<=IT) && salida == 0

    p = p1 - q1 * (p1-p0)/(q1-q0);
    fp = Fx(p);    
    E = abs((p-p1)/p);
    
    iteracion = [i,p0,p1,q0,q1,p,fp,E];        
    disp(iteracion);
    if fp==0 || E<TOL
        disp('Aproximacion alcanzada con exito en : '); disp(i);     
        disp('TOL: '); disp(TOL); 
        disp('En el punto p ='); disp(p);
        disp('Error = '); disp(p);
        salida = 1;    
    else
        i = i+1;
        p0 = p1;
        q0 = q1;
        p1 = p;
        q1 = Fx(p);
    end     
end

if salida == 0
   disp('El algoritmo fracaso...'); 
end

