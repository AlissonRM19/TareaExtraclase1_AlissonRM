#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "page.h"


// crea o lee el archivo txt y crea el contenido aleatorio
int createfile(int sizefile) {
    std::string suma = std::to_string(sizefile);
    std::ofstream newtxt ("New"+suma+"KB.txt");
    int numint = sizefile*256;
    for (int i=0;i<numint;i++)
        newtxt<<rand()<<","<<std::endl;
    newtxt.close();
}

//lee el archivo txt por linea y lo escribe en consola

int leer(std::string filename){
    std::string line;
    std::ifstream myfile(filename);
    if(myfile.is_open()){
        while(getline(myfile,line)){
            std::cout<<"el numero es "<<line<<"\n";
        }
        myfile.close();
    }
    else std::cout<<"no se pudo abrir el archivo";
}

//Array para la eleccion de tamaño de pagina
int inpS[6]={1,4,8,12,24,36};

int multipfiles(int sizearray[]) {
    for (int i = 0; i < 6; i++) {
        int size = sizearray[i];
        createfile(size);

    }
}

//Funcion principal
int main() {
    std::cout << sizeof(inpS);
    multipfiles(inpS);
    //  leer();


    return 0;
}