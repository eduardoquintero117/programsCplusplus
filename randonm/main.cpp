#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

// Añadir std para fácil llamado de funciones
using namespace std;

//// Declaración de funciones
//Definimos un template (un tipo de dato) para nuestra matriz
template <typename matriz>
void inicializarMatrices(matriz & miMatriz);

template <typename matriz>
void ImprimirMatriz(matriz & miMatriz);

template <typename matriz>
void GaussJordan(matriz & miMatriz);

template <typename matriz>
void ImprimirSolucion(matriz & miMatriz);

template <typename matriz>
void SumaSolucion(matriz & miMatriz);



int main()
{
    srand((int)time(0));
    // Definimos el número de variables de nuestro sistema
    const int variables = 4;
    // El número de columnas será el número de variables más su solición para cada ecuación
    const int columnas = variables + 1;
    // Inicializamos la matriz que vamos a ocupar
    array <array<float, columnas>, variables> miMatriz = { 0 };
    // Pedimos al usuario que llene la matriz
    inicializarMatrices(miMatriz);
    ImprimirMatriz(miMatriz);

    // Aplicamos el método de Gauss-Jordan sobre nuestra matriz
    GaussJordan(miMatriz);
    // Imprimimos la solución de la matriz
    ImprimirSolucion(miMatriz);
    SumaSolucion(miMatriz);
    return 0; // Indicamos que salimos del programa con éxito
}
/*
Llena 'miMatriz' con valores ingresados por el usuario para cada elemento.
No regresa ningún valor.
*/
template <typename matriz>
void inicializarMatrices(matriz & miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) {
        for (int j = 0; j <= variables; j++) {
            cout << "Valor elemento [" << i << "][" << j << "]: ";
            miMatriz[i][j] = (rand() % 20) + 1;
            cout <<  miMatriz[i][j] << endl;
        }
    }
}
/*
Imprime cada elemento de 'miMatriz' emulando una matriz con corchetes cuadrados.
No regresa ningún valor.
*/
template <typename matriz>
void ImprimirMatriz(matriz & miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) {
        cout << "[ ";
        for (int j = 0; j < variables + 1; j++)
            cout << miMatriz[i][j] << '\t';
        cout << "]\n";
    }
}
/*
Imprime en pantalla la solución para cada variable del sistema de ecuaciones correspondiente a los valores en 'miMatriz'.
No regresa ningún valor.
*/
template <typename matriz>
void ImprimirSolucion(matriz & miMatriz)
{
    cout << "Solución:"<<endl ;
    int variables = miMatriz.size();
    for (int k = 0; k < variables; k++){
        cout << "X" << k << "= " ;
        miMatriz[k][variables] = miMatriz[k][variables] / miMatriz[k][k] ;
        cout << miMatriz[k][variables] << "\n" ;
        miMatriz[k][k] = 1;
    }
}
/*
Implementa el algoritmo de Gauss-Jordan sobre 'miMatriz', finalizando en ella la solución del algoritmo.
No regresa ningún valor.
*/
template <typename matriz>
void GaussJordan(matriz & miMatriz)
{
    int variables = miMatriz.size();
    float z = 0;
    cout << "\n";
    for (int k = 0; k < variables-1; k++) {
        for (int i = k+1; i < variables; i++) {
            z = miMatriz[i][k] /miMatriz[k][k];
            miMatriz[i][k] = 0 ;
            for (int j = k+1; j < variables + 1; j++){
                miMatriz[i][j] = miMatriz[i][j] - (z*miMatriz[k][j])  ;
            }
        }
    }
    z = 0;
    for (int k = 0; k < variables-1; k++) {

        for (int i = k-1 ; i > -1; i--) {
            z = miMatriz[i][k] /miMatriz[k][k];
            miMatriz[i][k] = 0 ;
            for (int j = k+1; j < variables + 1; j++){
                miMatriz[i][j] = miMatriz[i][j] - (z*miMatriz[k][j])  ;

                for (int k = 0; k < variables; k++){
                    if(miMatriz[k][k] == 0 && miMatriz[k][variables] == 0)
                        cout << "solucion infinita "<<endl;
                    if(miMatriz[k][k] != 0 && miMatriz[k][variables]==0)
                        cout << "no existe solucion  "<<endl;
                }
            }
        }
    }
}

/*
Imprime en pantalla la solución de la suma de todas las variable del sistema de ecuaciones correspondiente a los valores en 'miMatriz'.
No regresa ningún valor.
*/
template <typename matriz>
void SumaSolucion(matriz & miMatriz)
{
    cout << "suma:"<<endl ;
    int variables = miMatriz.size();
    float numerofinal = 0;
    for (int k = 0; k < variables; k++){

        numerofinal = numerofinal + miMatriz[k][variables]  ;


    }

    cout << numerofinal << "\n" ;
}





