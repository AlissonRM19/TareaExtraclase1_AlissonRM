#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include "page.h"

//Funcion que crea archivo txt y crea el contenido aleatorio
int createfile(int sizefile) {
    std::string sum = std::to_string(sizefile);
    std::ofstream newtxt ("New"+sum+"KB.txt");
    int numint = sizefile*256;
    for (int i=0;i<numint;i++)
        newtxt<<rand()<<","<<std::endl;
    newtxt.close();
}

//Funcion que convierte decimal a binario
std::basic_string<char> tobinary(int n){
    std::string r;
    while(n!=0){
        r=(n%2==0 ?"0":"1")+r;
        n/=2;
    }
    return r;
}

//FUncion que convierte un string a integer
int toint(std::basic_string<char> str){
    long long int num;
    num= std::stoi(str);
    return num;
}

//Funcion que determina que archivo leer y extrae el numero leido
int leer(std::string filename){
    int Tam;

    //Comprobaciones para averiguar el tamano del archivo a leer
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

    //Creacion del array de bits vacio
    int ArrVa[Tam*256];

    std::string line;
    std::ifstream myfile(filename);
    int count  = 0;
    if(myfile.is_open()){

        //Ciclo que lee el archivo, obtiene el numero y lo convierte a binario
        while(getline(myfile,line)){

            std::stringstream ss;
            int num;

            std::cout<<"The line is "<<line<<"\n";
            ss<<line;
            ss>>num;
            std::cout<<"The number is "<<num<<"\n";

            std::stringstream ssbin;
            int t;
            std::basic_string<char> s;

            s= tobinary(num);
            ssbin<<s;
            ssbin>>t;
            //ArrVa[count]=num;
            count++;
            std::cout<<"The binary is "<<s<<"\n";
        }
        myfile.close();
    }
    else std::cout<<"no se pudo abrir el archivo";
}

//Array para la eleccion de tamaño de pagina
int inpS[6]={1,4,8,12,24,36};

//Funcion que crea los 6 archivos de distinto tamano
int multipfiles(int sizearray[]) {
    for (int i = 0; i < 6; i++) {
        int size = sizearray[i];
        createfile(size);
    }
}

//Funcion principal
int main() {
    multipfiles(inpS);
    leer("New1KB.txt");
    return 0;
}