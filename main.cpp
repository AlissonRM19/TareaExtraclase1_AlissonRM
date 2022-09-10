#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

#include "page.h"
#include "PagedArray.cpp"

// crea o lee el archivo txt y crea el contenido aleatorio
int createfile(int sizefile) {
    std::string suma = std::to_string(sizefile);
    std::ofstream newtxt ("New"+suma+"KB.txt");
    int numint = sizefile*256;
    for (int i=0;i<numint;i++)
        newtxt<<rand()<<","<<std::endl;
    newtxt.close();
}

//decimal a binario
std::string tobinary(int n){
    std::string r;
    while(n!=0){
        r=(n%2==0 ?"0":"1")+r;
        n/=2;
    }
    return r;
}
//string a integer
int toint(std::string str){
    int num;
    num= stoi(str);
    return num;
}

//lee el archivo txt por linea y lo escribe en consola

int leer(std::string filename){
    int Tam;

    if (filename=="New1KB.txt"){
        Tam=1;
    }
    else if (filename =="New4KB.txt"){
        Tam=4;
    }
    else if (filename =="New8KB.txt"){
        Tam=8;
    }
    else if (filename =="New12KB.txt"){
        Tam=12;
    }
    else if (filename =="New24KB.txt"){
        Tam=24;
    }
    else if (filename =="New36KB.txt"){
        Tam=36;
    }
    else std::cout << "El archivo no existe";


    int ArrVa[Tam*256];

    std::stringstream ss;
    int num;
    std::string line;
    std::ifstream myfile(filename);
    int count  = 0;
    if(myfile.is_open()){
        while(getline(myfile,line)){

            std::cout<<"el numero es "<<line<<"\n";

            ss<<line;
            ss>>num;
            std::cout<<"el numero es "<<num<<"\n";

            int t;
            t= toint(tobinary(num));
            ArrVa[count]= t;

            count++;
            std::cout<<ArrVa<<"\n";

            break;
        }
        myfile.close();
    }
    else std::cout<<"no se pudo abrir el archivo";

}


int defTam(std::string filename){
    std::stringstream ss;
}




//Array para la eleccion de tamaño de pagina
int inpS[6]={1,4,8,12,24,36};

// Crea los 6 archivos de distinto tamano
int multipfiles(int sizearray[]) {
    for (int i = 0; i < 6; i++) {
        int size = sizearray[i];
        createfile(size);

    }
}




//Funcion principal
int main() {
    //std::cout << sizeof(inpS);
    multipfiles(inpS);

    //std::cout << tobinary(num);
    leer("New1KB.txt");
    defTam("New1KB.txt");

    //Prueba de reemplazo de paginas
    int inpS[6] ;
    int pn = sizeof(inpS) / sizeof(inpS[0]);
    int fn = 4;
    optimalPage(inpS, pn, fn);


    return 0;
}