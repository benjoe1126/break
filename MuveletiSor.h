#ifndef MUVELETISOR_H_INCLUDED
#define MUVELETISOR_H_INCLUDED

#include "muvelet.h"
#include "matrix.h"
#include <iostream>

class MuveletiSor{
    Muvelet** operandusok;
    size_t hossz;
public:
        /**
       * Konstruktor
       */
    MuveletiSor() : hossz(0){ operandusok = nullptr; }
        /**
       * Visszaadja a műveleti sor hosszát
       * @return a hossz
       */
    int getHossz(){
        return hossz;
    }
        /**
       * Hozzáad egy új műveletet a sorhoz
       * @param m az új művelet, pointerrel adva
       */
    void ujOp(Muvelet* m);
        /**
       * Végigmegy a soron és kiszámolja az eredményt
       * @return az eredmény
       */
    Muvelet& kiszamol();
    /**
       * Végigmegy a soron és kiírja
       */
    void kiir();
        /**
       * Végigmegy a soron és kiírja fájlba
       */
    void fajlbaKiir(std::string fajlnev);
        /**
       * Destruktor
       */
    ~MuveletiSor();
};



#endif // MUVELETISOR_HPP_INCLUDED
