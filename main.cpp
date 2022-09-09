#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "page.h"





// crea o lee el archivo txt y crea el contenido aleatorio
int createfile(int sizefile) {
    std::string suma = std::to_string(sizefile);
    std::ofstream newtxt ("New"+suma+"Kb.txt");
    for (int i=0;i<sizefile;i++)
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

static int multipfiles(int inpS){
    for(int i = 0; i< sizeof(inpS);i++ ){
        createfile(i*256);

    }



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







//Funcion principal
int main() {
    int multipfiles();
    //  leer();


    return 0;
}
