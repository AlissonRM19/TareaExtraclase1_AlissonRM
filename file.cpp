//
// Created by lmint on 08/09/22.
//
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

// crea o lee el archivo txt y crea el contenido aleatorio
// sizefile es el tamano del que queremos el archivo(cantidad de enteros)
int createfile(int sizefile) {
    std::ofstream newtxt ("New.txt");
    for (int i=0;i<sizefile;i++)
        newtxt<<rand()<<","<<std::endl;
    newtxt.close();
}

//lee el archivo txt por linea y lo escribe en consola
int leer(){
    std::string line;
    std::ifstream myfile("New.txt");
    if(myfile.is_open()){
        while(getline(myfile,line)){
            std::cout<<"el numero es "<<line<<"\n";
        }
        myfile.close();
    }
    else std::cout<<"no se pudo abrir el archivo";
}
/*
//convierte un .txt a .bin ERROR
int converttobin(){
    char buffer;
    //std::string line;
    std::ifstream myfile("New.txt");
    std::ofstream binfile("binfile.bin",std::ios::out|std::ios::binary);
    int nums[3];
        while(!myfile.eof()){
            myfile>> nums[0]>> nums[1]>> nums[2];
            binfile.write(reinterpret_cast<const char*>(nums), 3*sizeof (int ));
        }
        myfile.close();
}
*/

int main() {
    createfile(10);
    leer();
    //converttobin();
    return 0;
}