//
// Created by Eduardo Quintero on 25/06/23.
//

#include "Animal.h"



Animal::Animal() {
    nombreDelAnimal = "";
    especie ="";
    peso = 0;
    edad = 0;
    numeroDeJaula = 0;
    numeroDeJaulaComunitaria = 0;
    fechaDePesaje = "";
    tipo = 0;
}
Animal::Animal(std::string _nombreN, std::string _especieN, float _pesoN, int _edadN, int _numeroDeJaulaN, int _numeroDeJaulaComunitariaN, std::string _fechaDePesajeN, bool _tipoN) {
    nombreDelAnimal = _nombreN;
    especie = _especieN;
    peso = _pesoN;
    edad = _edadN;
    numeroDeJaula = _numeroDeJaulaN;
    numeroDeJaulaComunitaria = _numeroDeJaulaComunitariaN;
    fechaDePesaje = _fechaDePesajeN;
    tipo = _tipoN;



}


string Animal::getNombreDelAnimal() {
    return nombreDelAnimal;
}
string Animal::getEspecie() {
    return especie;
}
float Animal::getPeso() {
    return  peso;
}
int Animal::getEdad() {
    return edad;
}

int Animal::getNumeroDeJaula() {
    return numeroDeJaula;

}
int Animal::getNumeroDeJaulaComunitaria() {
    return numeroDeJaulaComunitaria;

}

string Animal::getFechaDePesaje() {
    return fechaDePesaje;
}
bool Animal::getTipo() {
    return tipo;
}


//-------------------

void Animal::setNombreDelAnimal(string _nuevoNombre){
    nombreDelAnimal = _nuevoNombre;

}
void Animal::setEspecie(string _nuevaEspecie){
    especie = _nuevaEspecie;
}
void Animal::setPeso(float _nuevoPeso){
    peso = _nuevoPeso;
}
void Animal::setEdad(int _nuevaEdad){
    edad = _nuevaEdad;
}
void Animal::setNumeroDeJaula(int _nuevoNumeroDeJaula){
    numeroDeJaula = _nuevoNumeroDeJaula;
}
void Animal::setNumeroDeJaulaComunitaria(int _nuevoNumeroDeJaulaComunitaria){
    numeroDeJaulaComunitaria = _nuevoNumeroDeJaulaComunitaria;
}
void Animal::setFechaDePesaje(string _nuevaFecha){
    fechaDePesaje = _nuevaFecha;
}
void Animal::setTipo(bool _nuevoTipo){
    tipo = _nuevoTipo;
}



