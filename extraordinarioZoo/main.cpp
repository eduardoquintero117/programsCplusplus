#include <iostream>

#include "Animal.h"
#define EXTRAORDINARIOZOO_ANIMAL_H

void imprimeArregloAnimales (Animal arregloDeAnimales[],int numero);
void acomodaAnimales (Animal arregloDeAnimales[],int numero);

int main() {
    int numeroDeAnimales = 6;
    Animal zoologicoJaulasIndividuales[numeroDeAnimales];
    zoologicoJaulasIndividuales[0] = Animal("marmaduck","elefante",500,20,0,0,"12/03/2023",1);
    zoologicoJaulasIndividuales[1] = Animal("jose","tigre",200,15,1,0,"24/03/2023",0);
    zoologicoJaulasIndividuales[2]= Animal("panpan","panda",300,5,2,0,"02/04/2023",1);
    zoologicoJaulasIndividuales[3]= Animal("aqua","delfin",250,12,3,0,"10/01/2023",0);
    zoologicoJaulasIndividuales[4]= Animal("juan","zorro",18.5,6,4,0,"20/08/2023",0);
    zoologicoJaulasIndividuales[5]= Animal("armando","jirafa",240,18,5,0,"12/06/2023",1);
    imprimeArregloAnimales(zoologicoJaulasIndividuales,numeroDeAnimales);
    std::cout << " " << std::endl;

    acomodaAnimales(zoologicoJaulasIndividuales,numeroDeAnimales);


    /*
    std::cout << "Hello, World!" << std::endl;
    //nombre de animal, especie,peso, edad , numero de jaulas , numero de jaulas comunitarias , fecha de pesaje , tipo
    Animal residente = Animal("flipy","marmota",30.5,2,3,4,"04/06/2023",0);
    residente.setNombreDelAnimal("TOMMY");
    residente.setEspecie("delfin");
    std::cout << residente.getNombreDelAnimal() << std::endl;
    std::cout << residente.getEspecie() << std::endl;
    std::cout << residente.getPeso() << std::endl;
    std::cout << residente.getEdad() << std::endl;
     */

    return 0;
}


void acomodaAnimales (Animal arregloDeAnimales[],int numero){
    int variables = numero;
    int contador = 0;
    Animal jaulasComunitarias[numero];
    for (int i = 0; i < variables - 1; i++){
        for (int x = i+1; x < variables; x++){

            if(arregloDeAnimales[i].getTipo() == arregloDeAnimales[x].getTipo()){
                if(arregloDeAnimales[i].getNombreDelAnimal() != "" && arregloDeAnimales[x].getNombreDelAnimal() != ""){
                    std::cout << arregloDeAnimales[i].getEspecie() << std::endl;
                    std::cout << arregloDeAnimales[x].getEspecie() << std::endl;
                    std::cout << "------jaula Comunitaria: " << contador << std::endl;
                    arregloDeAnimales[i] = Animal();
                    arregloDeAnimales[x] = Animal();
                    contador = contador + 1;

                }

            }

        }

    }

    //--
    for (int i = 0; i < variables ; i++){
        if(arregloDeAnimales[i].getNombreDelAnimal() != "" ){
            std::cout << arregloDeAnimales[i].getEspecie() << std::endl;


            std::cout << "------jaula Comunitaria: " << contador << std::endl;
            arregloDeAnimales[i] = Animal();
            contador = contador + 1;


        }


    }

//----



}





void imprimeArregloAnimales (Animal arregloDeAnimales[],int numero){
    int variables = numero;
    for (int i = 0; i < variables; i++){


            std::cout << "nombre: " << arregloDeAnimales[i].getNombreDelAnimal() << std::endl;
            std::cout << "especie: "<< arregloDeAnimales[i].getEspecie() << std::endl;
            std::cout << "peso: "<< arregloDeAnimales[i].getPeso() << std::endl;
            std::cout << "edad: "<< arregloDeAnimales[i].getEdad() << std::endl;
            std::cout << "numero Jaula: "<< arregloDeAnimales[i].getNumeroDeJaula() << std::endl;


            std::cout << "Fecha: "<< arregloDeAnimales[i].getFechaDePesaje() << std::endl;
            std::cout << "Tipo: "<< arregloDeAnimales[i].getTipo() << " " ;
            if(arregloDeAnimales[i].getTipo() == 0){
                std::cout << "depredador" << std::endl;
            }else{
                std::cout << "presa" << std::endl;
            }

            std::cout << "------" << std::endl;



     }

}
