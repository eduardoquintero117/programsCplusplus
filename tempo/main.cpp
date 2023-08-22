#include <iostream>
#include <stdlib.h>
#include <array>
#include <vector>

using namespace  std;


//-----------Declaracion de la clase
class Producto{
private:          // Atributos
    string  nombre;
    double  peso;
    int disponibilidad;
    int numjaula;
    string fecha;


public:    //Metodos
    Producto(string,double,int,int,string);
    Producto();
    void setNombre(string);
    void setPeso(double);
    void setDisponibilidad(int);
    void setNumjaula(int);
    void setFecha(string);

    string getNombre();
    double getPeso();
    int getDisponibilidad();
    int getNumeroJaula();
    string getFecha();

};
Producto::Producto() {
    nombre = "";
    peso = 0.0;
    disponibilidad = 0;
    numjaula = 0;
    fecha = "";

}

Producto::Producto(string _nombre, double _peso,int _disponibilidad,int _numerojaula,string _fecha){
    nombre = _nombre;
    peso  = _peso;
    disponibilidad = _disponibilidad;
    numjaula = _numerojaula;
    fecha = _fecha;
}

void Producto::setNombre(string _nuevoNombre) {
    nombre = _nuevoNombre;
}

void Producto::setPeso(double _nuevoPeso) {
    peso = _nuevoPeso;
}

void Producto::setDisponibilidad(int _nuevaDisponibilidad) {
    disponibilidad = _nuevaDisponibilidad;
}
void Producto::setNumjaula(int _nuevoNum) {
    numjaula = _nuevoNum;
}
void Producto::setFecha(string _nuevaFecha) {
    fecha = _nuevaFecha;
}
// set

string Producto::getNombre() {
    return nombre;
}
double Producto::getPeso() {
    return peso;
}
int Producto::getDisponibilidad() {
    return disponibilidad;
}
int Producto::getNumeroJaula() {
    return numjaula;
}
string Producto::getFecha() {
    return fecha;
}

//-----------------------------Funciones para el Arreglo de objetos

void  ImprimirTodosLosProductos(Producto miMatriz[], int numero);
void contadorDeProductosEnExistencia(Producto miMatriz[], int numero);
void contadorDeProductosVendidos(Producto miMatriz[], int numero);
void calculadorDePromedioDepreciosDeProductosVendidos(Producto miMatriz[], int numero);
void provarClaseSetGet();
void ImprimirLosProductosDisponibles(Producto miMatriz[], int numero);


//---------------- Main
int main() {
    int numeroProductos = 6;

    Producto ProductosTienda[numeroProductos];


    ProductosTienda[0] = Producto("leon",10.5,1,0,"7/4/2000");
    ProductosTienda[1] = Producto("lobo",20.5,1,0,"8/5/2022");
    ProductosTienda[2] = Producto("coyote",30.5,1,0,"4/3/2044");
    ProductosTienda[3] = Producto("ciervo",40.5,0,0,"5/2/2000");
    ProductosTienda[4] = Producto("vaca",50.5,0,0,"7/4/2000");
    ProductosTienda[5] = Producto("cotorro",50.5,0,0,"7/4/2000");


    int status = 0;
    int other = 0;
    int contadorJaula = 1;
    cout<<"Hola, Bievenido al ZOO "<<endl;
    cout<<"Opcion:"<<endl;
    cout<<"1)Ver Animales disponibles Nombre , peso , depredador 1 o presa 0, numero de jaula , fecha."<<endl;
    cout<<"2)Ver todos los animales"<<endl;
    cout<<"3)Vender producto."<<endl;
    cout<<"4)Ver el numero de los productos en existencia."<<endl;
    cout<<"5)Ver el numero de los productos vendidos."<<endl;
    cout<<"6)Ver el numero del promedio del precio de los productos vendidos."<<endl;
    cout<<"7)Salir."<<endl;


    while(status != 7){
        cout<<endl;
        cout << "Ingresa el numero:";
        cin >> status;
        cout<<endl;


        switch(status){
            case 1:
                ImprimirLosProductosDisponibles(ProductosTienda, numeroProductos);
                break;

            case 2:
                ImprimirTodosLosProductos(ProductosTienda, numeroProductos);
                break;

            case 3:
                cout<<"Elija el animal:"<<endl;
                //ImprimirLosProductosDisponibles(ProductosTienda, numeroProductos);
                cout << "Ingresa los animale que quieras juntar:";
                cin >> status;
                cout<<endl;
                cout << "Ingresa los animale que quieras juntar:";
                cin >> other;
                cout<<endl;



                if(ProductosTienda[status].getDisponibilidad() ==ProductosTienda[other].getDisponibilidad() ){
                    //ProductosTienda[status].setDisponibilidad(0);
                    cout << "Se pueden Juntar"<<endl;
                    ProductosTienda[status].setNumjaula(contadorJaula);
                    ProductosTienda[other].setNumjaula(contadorJaula);
                    contadorJaula = contadorJaula + 1 ;


                }else{
                    cout << "no se pueden juntar te regresamos al primer menu."<<endl;
                }
                status = 0;
                break;

            case 4:
                contadorDeProductosEnExistencia(ProductosTienda, numeroProductos);
                break;
            case 5:
                contadorDeProductosVendidos(ProductosTienda, numeroProductos);
                break;

            case 6:
                calculadorDePromedioDepreciosDeProductosVendidos(ProductosTienda, numeroProductos);
                break;

            case 7:
                cout << "sesion cerrada"<<endl;
                break;

        }

    }


    return 0;


}

//-----------------------------Funciones

void ImprimirTodosLosProductos(Producto miMatriz[], int numero)
{
    int variables = numero;

    for (int i = 0; i < variables; i++) {
        cout << "[ ";
        cout <<"Producto: "<< miMatriz[i].getNombre()<< " ";
        //cout <<",Precio: "<< miMatriz[i].getPrecio()<< " ";
        cout <<",Disponibilidad: "<< miMatriz[i].getDisponibilidad()<< " ";
        cout <<",juaula: "<< miMatriz[i].getNumeroJaula()<< " ";
        //cout <<",Ciudad: "<< miMatriz[i].getCiudad()<< " ";
        cout << "]\n";
    }

}

void ImprimirLosProductosDisponibles(Producto miMatriz[], int numero)
{
    int variables = numero;

    for (int i = 0; i < variables; i++) {
        if(miMatriz[i].getDisponibilidad() == 1){
            cout << "Opcion "<<i<<") ";
            cout << "[ ";
            cout <<"Animal: "<< miMatriz[i].getNombre()<< " ";
            cout <<",Peso: "<< miMatriz[i].getPeso()<< " ";
            cout <<",Depredador(1) o presa(0): "<< miMatriz[i].getDisponibilidad()<< " ";
            cout <<",numero de jaula: "<< miMatriz[i].getNumeroJaula()<< " ";
            cout <<",Fecha: "<< miMatriz[i].getFecha()<< " ";
            cout << "]\n";
        }

    }

}


void contadorDeProductosEnExistencia(Producto miMatriz[], int numero)
{
    int variables = numero;
    int contador = 0;

    for (int i = 0; i < variables; i++) {

        if(miMatriz[i].getDisponibilidad() > 0){
            contador++;
        }
    }

    cout <<"Numero de depredadores: "<< contador<< " ";
    cout << "\n";
}


void contadorDeProductosVendidos(Producto miMatriz[], int numero)
{
    int variables = numero;
    int contador = 0;

    for (int i = 0; i < variables; i++) {

        if(miMatriz[i].getDisponibilidad() == 0){
            if(miMatriz[i].getNombre() != ""){
                contador++;
            }
        }
    }

    cout <<"Numero de presas: "<< contador<< " ";
    cout << "\n";
}


void calculadorDePromedioDepreciosDeProductosVendidos(Producto miMatriz[], int numero)
{
    int variables = numero;
    double promedio = 0;
    double contador = 0;

    for (int i = 0; i < variables; i++) {

        if(miMatriz[i].getDisponibilidad() == 0){
            if(miMatriz[i].getNombre() != ""){
                //promedio = miMatriz[i].getPrecio() + promedio;
                contador = contador + 1;
            }
        }

    }
    promedio = promedio/contador;


    cout <<"Promedio de precio de productos vendidos: "<< promedio<< " ";
    cout << "\n";

}

void provarClaseSetGet(){

    Producto mercancia1 = Producto ("Perro",4.5,1,1,"6/1/2023");

    mercancia1.setNombre("leon");
    mercancia1.setPeso(20.8);
    mercancia1.setDisponibilidad(0);
    mercancia1.setNumjaula(0);
    mercancia1.setFecha("5/4/2022");


    std::cout << mercancia1.getNombre() << std::endl;
    std::cout << mercancia1.getPeso() << std::endl;
    std::cout << mercancia1.getDisponibilidad() << std::endl;
    std::cout << mercancia1.getNumeroJaula() << std::endl;
    std::cout << mercancia1.getFecha() << std::endl;
}





