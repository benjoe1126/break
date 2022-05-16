#include <iostream>
#include "vektor.h"
#include "matrix.h"
#include "muvelet.h"
#include "EgyOperand.h"
#include "MuveletiSor.h"
#include "main_functions.h"
#include "test.h"
#include "memtrace.h"
#ifndef MEMTRACE
#define MEMTRACE
#endif


int Menuk(MuveletiSor* ms){
    char in;
    bool egy = false;
    if (ms->getHossz() == 0){
        while (!egy){
            MenuEgyKiir();
            std::cin>>in;
            switch (in){
                case 'F':
                    try{
                        MxFajlbolOlvas(*ms);
                        egy = true;
                        break;
                    }
                    catch(const char* err){
                        std::cout<<err<<std::endl;
                        break;
                    }
                case '1':
                    try{
                        EgysegmxBerak(*ms);
                        egy = true;
                        break;
                    }
                    catch(const char* err){
                        std::cout<<err<<std::endl;
                        break;
                    }
                case '0':
                    try{
                        NullmxBerak(*ms);
                        egy = true;
                        break;
                    }
                    catch(const char* err){
                        std::cout<<err<<std::endl;
                        break;
                    }
                case 'X':
                    return 0; 
                default: 
                    std::cout<<"Hibás bemenet!"<<std::endl<<std::endl;
                    break;
                }
        }
    }
    bool ketto = false;
    while(!ketto){
        MenuKettoKiir();
        std::cin>>in;
        
        switch (in){
        case 'x':
            try{
                SzamOlvas(*ms, in);
                ketto = true;
                break;
            }
            catch(const char *err){
                std::cout<<err<<std::endl;
                break;
            }
        case '*':
            try{
                MenuHaromKiir();
                MenuHarom(*ms, in);
                ketto = true;
                break;
            }
            catch(const char *err){
                std::cout<<err<<std::endl;
                break;
            }
        case '+':
            try{
                MenuHaromKiir();
                MenuHarom(*ms, in);
                ketto = true;
                break;
            }
            catch(const char *err){
                std::cout<<err<<std::endl;
                break;
            }
        case '-':
            try{
                MenuHaromKiir();
                MenuHarom(*ms, in);
                ketto = true;
                break;
            }
            catch(const char *err){
                std::cout<<err<<std::endl;
                break;
            }
        case 'i':
            try{
                EgyOperandusosMuveletetVegez(*ms, in);
                ketto = true;
                break;
            }
            catch(const char *err){
                std::cout<<err<<std::endl;
                break;
            }
        case 'r':
            try{
                EgyOperandusosMuveletetVegez(*ms, in);
                ketto = true;
                break;
            }
            catch(const char *err){
                std::cout<<err<<std::endl;
                break;
            }
        case 'T':
            try{
                EgyOperandusosMuveletetVegez(*ms, in);
                ketto = true;
                break;
            }
            catch(const char *err){
                std::cout<<err<<std::endl;
                break;
            }
        case 'X':
            return 0; 
        default: 
            std::cout<<"Hibás bemenet!"<<std::endl<<std::endl;
        }
    }
    try{
        ms->kiir();
    }
    catch(const char* err){
        std::cout<<err;
    }
    Matrix *res;
    try{
        res = dynamic_cast<Matrix*>(&ms->kiszamol());
        std::cout<<"=\n"<<(*res);
        
        std::cout<<std::endl;
    }
    catch(const char * err){
        std::cout<<err<<std::endl;
        return -1;
    }
    
    bool negy = false;
        while (!negy){
            MenuNegyKiir();
            std::cin>>in;
            
            switch (in){
            case 's':
                try{
                    std::string fajlnev;
                    std::cin>>fajlnev;
                    fajlnev += ".bin";
                    writeF(*res, fajlnev);
                    delete res;
                    break;
                }
                catch(const char *err){
                    std::cout<<err<<std::endl;
                    delete res;
                    break;
                }
            case 'S':
                try{
                    std::string fajlnev;
                    std::cin>>fajlnev;
                    fajlnev += ".txt";
                    ms->fajlbaKiir(fajlnev);
                    delete res;
                    break;
                }
                catch(const char *err){
                    std::cout<<err<<std::endl;
                    delete res;
                    break;
                }
                
            case 'X':
                delete res;
                return 0; 
            default: 
                std::cout<<"Hibás bemenet!"<<std::endl<<std::endl;
            }
        }
    delete res;
    return -1;
}

int main(){
    test();
    MuveletiSor* ms = new MuveletiSor;
    int i = 1;
    while (i!=0 && i != -1){
        i = Menuk(ms);
    }
    delete ms;    
    return 0;
}

