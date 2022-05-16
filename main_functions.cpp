#include "main_functions.h"
#include <iostream>
#include "MuveletiSor.h"
#include "EgyOperand.h"
#include "muvelet.h"
#include "matrix.h"
#include "vektor.h"

void MxFajlbolOlvas(MuveletiSor& ms, const char muvelet){
    char fajlnev[50];
    std::cout<<"Fájlév:\n";
    std::cin>>fajlnev;
    if (!std::cin){
        std::cin.clear();
        throw "Hibás méret!";
    }
    Matrix* a = new Matrix(readF(fajlnev));
    if (a->getWidth() > 5 || a->getWidth() < 1 || a->getHeight() > 5 || a->getHeight() < 1) throw "Hibs méret!";
    a->setMuv(setOperand(muvelet));
    ms.ujOp(a);
    std::cout<<(*a);
}

void EgysegmxBerak(MuveletiSor& ms, const char muvelet){
    int e; 
    std::cout<<"Mérete:"<<std::endl;
    std::cin.clear();
    std::cin>>e;
    if (!std::cin){
        std::cin.clear();
        throw "Hibás méret!";
    }
    std::cout<<e;
    if (e > 9 || e < 1) throw "Hibs méret!";
    Matrix* emx = new Matrix(egysegmatrix(e));
    emx->setMuv(setOperand(muvelet));
    ms.ujOp(emx);
    std::cout<<(*emx);
}

void NullmxBerak(MuveletiSor& ms, const char muvelet){
    int w, h;
    std::cout<<"Szélessége:"<<std::endl;
    std::cin>>w;
    if (!std::cin){
        std::cin.clear();
        throw "Hibás méret!";
    }
    if (w > 5 || w < 1) throw "Hibs méret!";
    std::cout<<"Magassága:"<<std::endl;
    std::cin>>h;
    if (!std::cin){
        std::cin.clear();
        throw "Hibás méret!";
    }
    if (h > 5 || h < 1) throw "Hibs méret!";
    Matrix* uj;
    uj = new Matrix(h, w);
    std::cout<<(*uj);
    uj->setMuv(setOperand(muvelet));
    ms.ujOp(uj);
    std::cin.clear();
}

void SzamOlvas(MuveletiSor& ms, const char muvelet){
    double num; 
    std::cout<<"Szám:"<<std::endl;
    std::cin>>num;
    if (!std::cin){
        std::cin.clear();
        throw "Hibs méret!";
    }
    Matrix* uj = new Matrix(1, 1);
    (*uj)[0][0] = num;
    std::cout<<(*uj);
    uj->setMuv(setOperand(muvelet));
    ms.ujOp(uj);
    std::cin.clear();
}

void EgyOperandusosMuveletetVegez(MuveletiSor& ms, const char muvelet){
    EgyOperand* i = new EgyOperand(setOperand(muvelet));
    ms.ujOp(i);
}

void MenuEgyKiir(){
    std::cout<<"F_mátrix olvasása fájlból"<<std::endl;
    std::cout<<"1_egységmátrix létrehozása"<<std::endl;
    std::cout<<"0_nullmátrix létrehozása"<<std::endl;
    std::cout<<"X_kilépés"<<std::endl;
}

void MenuKettoKiir(){
    std::cout<<"x_szorzás számmal"<<std::endl;
    std::cout<<"*_szorzás mátrixxal"<<std::endl;
    std::cout<<"+_hozzáadás mátrixhoz"<<std::endl;
    std::cout<<"-_másik mátrix kivonása belőle"<<std::endl;
    std::cout<<"i_inverz mátrix előállítása"<<std::endl;
    std::cout<<"r_rang számítása"<<std::endl;
    std::cout<<"T_transzponált előállítása"<<std::endl;
    std::cout<<"X_kilépés"<<std::endl;
}
void MenuHaromKiir(){
    std::cout<<"F_mátrix olvasása fájlból"<<std::endl;
    std::cout<<"1_egységmátrix létrehozása"<<std::endl;
    std::cout<<"0_nullmátrix létrehozása"<<std::endl;
    std::cout<<"X_vissza"<<std::endl;
}
void MenuNegyKiir(){
    std::cout<<"s_eredmény mentése"<<std::endl;
    std::cout<<"S_műveletek mentése"<<std::endl;
    std::cout<<"X_kilépés"<<std::endl;
}

void MenuHarom(MuveletiSor& ms, const char muvelet){
    char in;
    bool harom = false;
    while (!harom){
        MenuEgyKiir();
        std::cin>>in;
        switch (in){
            case 'F':
                try{
                    MxFajlbolOlvas(ms, muvelet);
                    harom = true;
                    break;
                }
                catch(const char* err){
                    std::cout<<err<<std::endl;
                    break;
                }
            case '1':
                try{
                    EgysegmxBerak(ms, muvelet);
                    harom = true;
                    break;
                }
                catch(const char* err){
                    std::cout<<err<<std::endl;
                    break;
                }
            case '0':
                try{
                    NullmxBerak(ms, muvelet);
                    harom = true;
                    break;
                }
                catch(const char* err){
                    std::cout<<err<<std::endl;
                    break;
                }
            case 'X':
                return; 
            default: 
                std::cout<<"Hibás bemenet!"<<std::endl<<std::endl;
                break;
            }
    }
}
