#include <iostream>
#include <fstream>
#include "MuveletiSor.h"
#include "muvelet.h"
#include "matrix.h"




void MuveletiSor::kiir(){
    for (size_t i = 0; i < hossz; i++){
        operandusok[i]->ir(std::cout);
    }
}

void MuveletiSor::fajlbaKiir(std::string fajlnev){
    std::ofstream file;
    file.open (fajlnev);
    if(!file) throw "nem sikerült megnyitni a fájlt!";
    for (size_t i = 0; i < hossz; i++){
        operandusok[i]->ir(file);
    }
    file.close();
}

void MuveletiSor::ujOp(Muvelet* m){
    if (m->getMuv() == elsotag && hossz != 0)
        throw "Hiba: már van első tag!";
    if (m->getMuv() != elsotag && hossz == 0)
        throw "Hiba: első tagnak nem lehet művelete!";
    Muvelet** temp = new Muvelet* [hossz+1];
    for (size_t i = 0; i < hossz; i++){
        temp[i] = operandusok[i];
    }
    temp[hossz] = m;
    if (hossz!=0){
        delete[] operandusok;
    }
    hossz+=1;
    operandusok = temp;
}

MuveletiSor::~MuveletiSor(){
    for (size_t i = 0; i < hossz; i++)
        delete operandusok[i];
    delete [] operandusok;
    hossz = 0;
}

Muvelet& MuveletiSor::kiszamol(){
    Matrix *elsotag = dynamic_cast<Matrix*>(operandusok[0]);
    Matrix res(*elsotag);
    for (size_t i = 1; i < hossz; i++){
        Muvelet *reszeredm = &(operandusok[i]->szamol(res));
        res = *(dynamic_cast<Matrix*>(reszeredm));
        delete reszeredm;
    }
    Matrix *result = new Matrix(res);
    return *result;
}
