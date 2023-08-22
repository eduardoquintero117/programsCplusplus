#include <iostream>
#include <stdlib.h>
#include <array>

#include <vector>

using namespace  std;


//-----------Declaracion de la clase
class Producto{
private:          // Atributos
    string  nombre;
    double  precio;
    int disponibilidad;
    string ciudad;

public:    //Metodos
    Producto(string,double,int,string);
    Producto();
    void setNombre(string);
    void setPrecio(double);
    void setDisponibilidad(int);
    void setCiudad(string);

    string getNombre();
    double getPrecio();
    int getDisponibilidad();
    string getCiudad();

};

Producto::Producto() {
    nombre = "";
    precio = 0.0;
    disponibilidad = 0;
    ciudad = "";
}


Producto::Producto(string _nombre, double _precio, int _disponibilidad, string _ciudad) {
    nombre = _nombre;
    precio = _precio;
    disponibilidad = _disponibilidad;
    ciudad = _ciudad;
}

void Producto::setNombre(string _nuevoNombre) {
    nombre = _nuevoNombre;
}

void Producto::setPrecio(double _nuevoPrecio) {
    precio = _nuevoPrecio;
}

void Producto::setDisponibilidad(int _nuevaDisponibilidad) {
    disponibilidad = _nuevaDisponibilidad;
}
void Producto::setCiudad(string _nuevaCiudad) {
    ciudad = _nuevaCiudad;
}
// set

string Producto::getNombre() {
    return nombre;
}
double Producto::getPrecio() {
    return precio;
}
int Producto::getDisponibilidad() {
    return disponibilidad;
}

string Producto::getCiudad() {
    return ciudad;
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
    int numeroProductos = 5;

    Producto ProductosTienda[numeroProductos];

    ProductosTienda[0] = Producto("Manzana",10.5,1,"CDMX");
    ProductosTienda[1] = Producto("lap",20.5,0,"CDMX");
    ProductosTienda[2] = Producto("compu",30.5,1,"CDMX");
    ProductosTienda[3] = Producto("agua",40.5,0,"CDMX");
    ProductosTienda[4] = Producto("pan",50.5,1,"CDMX");


    int status = 0;

    cout<<"Hola, Bievenido a la tienda"<<endl;
    cout<<"Opcion:"<<endl;
    cout<<"1)Ver productos disponibles."<<endl;
    cout<<"2)Ver todos los productos."<<endl;
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
                cout<<"Elija el producto:"<<endl;
                ImprimirLosProductosDisponibles(ProductosTienda, numeroProductos);
                cout << "Ingresa la opcion del producto que quiera vender:";
                cin >> status;
                cout<<endl;

                if(status<numeroProductos){
                    ProductosTienda[status].setDisponibilidad(0);
                }else{
                    cout << "X Esa opcion no es valida te regresamos al primer menu."<<endl;
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
        cout <<",Precio: "<< miMatriz[i].getPrecio()<< " ";
        cout <<",Disponibilidad: "<< miMatriz[i].getDisponibilidad()<< " ";
        cout <<",Ciudad: "<< miMatriz[i].getCiudad()<< " ";
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
            cout <<"Producto: "<< miMatriz[i].getNombre()<< " ";
            cout <<",Precio: "<< miMatriz[i].getPrecio()<< " ";
            cout <<",Disponibilidad: "<< miMatriz[i].getDisponibilidad()<< " ";
            cout <<",Ciudad: "<< miMatriz[i].getCiudad()<< " ";
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

    cout <<"Numero de productos en existencia: "<< contador<< " ";
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

    cout <<"Numero de productos vendidos: "<< contador<< " ";
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
                promedio = miMatriz[i].getPrecio() + promedio;
                contador = contador + 1;
            }
        }

    }
    promedio = promedio/contador;


    cout <<"Promedio de precio de productos vendidos: "<< promedio<< " ";
    cout << "\n";

}

void provarClaseSetGet(){

    Producto mercancia1 = Producto("Manzana",10.5,1,"CDMX");

    mercancia1.setNombre("Platanos");
    mercancia1.setPrecio(20.8);
    mercancia1.setDisponibilidad(0);
    mercancia1.setCiudad("monterrey");


    std::cout << mercancia1.getNombre() << std::endl;
    std::cout << mercancia1.getPrecio() << std::endl;
    std::cout << mercancia1.getDisponibilidad() << std::endl;
    std::cout << mercancia1.getCiudad() << std::endl;


}








