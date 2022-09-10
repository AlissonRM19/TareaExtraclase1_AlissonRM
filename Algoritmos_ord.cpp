//
// Created by alisson on 09/09/22.
//

#include "Algoritmos_ord.h"
#include "PagedArray.cpp"
#include "main.cpp"

//Algoritmos de ordenamiento

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;



//funcion para dividir el array y hacer los intercambios
int dividir(int *array , int inicio, int fin)
{
    int izq;
    int der;
    int pibote;
    int temp;

    pibote = array[inicio];
    izq = inicio;
    der = fin;

    //Mientras no se cruzen los índices
    while (izq < der){
        while (array[der] > pibote){
            der--;
        }

        while ((izq < der) && (array[izq] <= pibote)){
            izq++;
        }

        // Si todavia no se cruzan los indices seguimos intercambiando
        if(izq < der){
            temp= array[izq];
            array[izq] = array[der];
            array[der] = temp;
        }
    }

    //Los indices ya se han cruzado, ponemos el pivote en el lugar que le corresponde
    temp = array[der];
    array[der] = array[inicio];
    array[inicio] = temp;

    //La nueva posición del pivote
    return der;
}

//	Funcion Quicksort

//funcion recursiva para hacer el ordenamiento
void quicksort(int *array, int inicio, int fin)
{
    int pivote;
    if(inicio < fin)
    {
        pivote = dividir(array, inicio, fin );
        quicksort( array, inicio, pivote - 1 );//ordeno la lista de los menores
        quicksort( array, pivote + 1, fin );//ordeno la lista de los mayores
    }
}

//======================================================================
//inseton sort

using std::cout; using std::endl;
using std::string; using std::vector;

template<typename T>
void printVector(const vector<T> &vec) {
    for (auto &i : vec) {
        cout << i << "; ";
    }
    cout << endl;
}

template<typename T>
void insertionSort(vector<T> &vec) {
    for (auto it = vec.begin() + 1; it != vec.end(); ++it) {
        auto key = it;
        for (auto i = it - 1; i >= vec.begin(); --i) {
            if (*i > *key) {
                std::swap(*i, *key);
                key--;
            } else {
                break;
            }
        }
    }
}


//Selection sort

using std::cout; using std::endl;
using std::vector;

template<typename T>
void selectionSort(vector<T> &vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::swap(*it, *std::min_element(it, vec.end()));
    }
}
using std::cout; using std::endl;
using std::vector;

