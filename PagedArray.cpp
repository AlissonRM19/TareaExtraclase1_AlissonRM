//
// Created by alisson on 27/08/22.
//

#include "PagedArray.h"

//Algoritmo de reemplazo

#include <bits/stdc++.h>
using namespace std;

// En esta funcion se hace una revision de que la pagina exista
bool search(int key, vector<int>& fr)
{
    for (int i = 0; i < fr.size(); i++)
        if (fr[i] == key)
            return true;
    return false;
}

//Funcion para encontrar la pagina que no se este usando

int predict(int inpS[], vector<int>& fr, int pn, int indice)
{
    // Almacena el indice de las paginas
    // para posteriormente ser usado
    int res = -1, farthest = indice;
    for (int i = 0; i < fr.size(); i++) {
        int j;
        for (j = indice; j < pn; j++) {
            if (fr[i] == inpS[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }

        // Si nunca se hace referencia a una pagina se retorna lo siguiente
        if (j == pn)
            return i;
    }

    // si no estuvieran todos los marcos
    return (res == -1) ? 0 : res;
}

void optimalPage(int inpS[], int pn, int fn)
{
    // Se crea un array para un nuemeo determinado de paginas
    vector<int> fr;

    // Array de referencia
    int hit = 0;
    for (int i = 0; i < pn; i++) {

        // Pagina no encontrada
        if (search(inpS[i], fr)) {
            hit++;
            continue;
        }



        // Si no hay espacio disponible en los marcos
        if (fr.size() < fn)
            fr.push_back(inpS[i]);

            // Encuentra pagina para ser reemplazada.
        else {
            int j = predict(inpS, fr, pn, i + 1);
            fr[j] = inpS[i];
        }
    }
    cout << "No. of hits = " << hit << endl;
    cout << "No. of misses = " << pn - hit << endl;
}



