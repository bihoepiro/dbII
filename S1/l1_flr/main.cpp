#include <iostream>
#include "fstream"
using namespace std;

// Fixed-Length Records - Binary

struct Alumno{
    char nombre [20]; // string no porq usa punteros y no es fijo
    char carrera [10];
};

ofstream & operator <<(ofstream&file, Alumno al){
    file.write(al.nombre, 20);
    file.write(al.carrera, 10);
    file<<flush;
    return file;
}

istream & operator >> (istream &file, Alumno & al){
    file.read(al.nombre, sizeof(al.nombre));
    file.read(al.carrera, sizeof(al.carrera));
    file.get();
    return file;
}

void testWrite(){
    Alumno al1{"Pedro", "CS"};
    Alumno al2{"Marta", "IND"};
    Alumno al3{"Santos", "MEC"};
    ofstream ofile("datos.txt", ios::app | ios::binary);
    ofile<<al1<<endl;
    ofile<<al2<<endl;
    ofile<<al3<<endl;
    ofile.close();
}


void testRead(){
    ifstream ifile("datos.txt",ios::in | ios::binary);
    while(true){
        Alumno al;
        ifile >> al;
        if(ifile.eof()) break;
        cout<< al.nombre << '-' << al.carrera  << endl;
    }
    ifile.close();
}


void testRead(int i){
    ifstream ifile("datos.txt", ios::in | ios::binary);
    Alumno al;
    ifile.seekg(i* (sizeof(Alumno)+1), ios::beg);
    ifile >> al;
    std::cout << al.nombre << "-" << al.carrera << std::endl;
    ifile.close();
}

int main() {
    testWrite();
    testRead();
    testRead(2);
    return 0;
}
