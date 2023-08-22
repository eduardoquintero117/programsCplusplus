#include <iostream>

float X1;
float X2;
float X3;

float Y1;
float Y2;
float Y3;

int X;
int Y;

float base;
float altura;
float resultado;

using namespace std;



int main() {

    cout << "Ingrese la el punto X(1) triangulo: ";
    cin >> X1;
    cout << "Ingrese la el punto Y(1) triangulo: ";
    cin >> Y1;

    cout << "Ingrese la el punto X(2) triangulo: ";
    cin >> X2;
    cout << "Ingrese la el punto Y(2) triangulo: ";
    cin >> Y2;

    cout << "Ingrese la el punto X(3) triangulo: ";
    cin >> X3;
    cout << "Ingrese la el punto Y(3) triangulo: ";
    cin >> Y3;

    X =X2-X1;
    Y =Y3-Y2;

     base = X;
     altura = Y;

    resultado = (base * altura) / 2; // Formula matematica para calcular el area del triangulo.
    cout << "El area de su triangulo es: " << X << Y << base << altura << resultado << endl;
}
