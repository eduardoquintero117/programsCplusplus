//
// Created by Eduardo Quintero on 25/06/23.
//
#include <iostream>
#include <stdlib.h>
#ifndef EXTRAORDINARIOZOO_ANIMAL_H
#define EXTRAORDINARIOZOO_ANIMAL_H

using namespace  std;

class Animal {
private:     //----Atributos privados
    string nombreDelAnimal;
    string especie;
    float peso;
    int edad;
    int numeroDeJaula;
    int numeroDeJaulaComunitaria;
    string fechaDePesaje;
    bool tipo;

public:     //----Metodos publicos

    Animal();
    Animal(std::string _nombreN, std::string _especieN, float _pesoN, int _edadN, int _numeroDeJaulaN, int _numeroDeJaulaComunitariaN, std::string _fechaDePesajeN, bool _tipoN);

    //----get leer traer el dato
    string getNombreDelAnimal();
    string getEspecie();
    float getPeso();
    int getEdad();
    int getNumeroDeJaula();
    int getNumeroDeJaulaComunitaria();
    string getFechaDePesaje();
    bool getTipo();


    //----Set reescribir el dato
    void setNombreDelAnimal(string);
    void setEspecie(string);
    void setPeso(float);
    void setEdad(int);
    void setNumeroDeJaula(int);
    void setNumeroDeJaulaComunitaria(int);
    void setFechaDePesaje(string);
    void setTipo(bool);




};



#endif //EXTRAORDINARIOZOO_ANIMAL_H



