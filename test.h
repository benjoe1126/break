#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <iostream>
#include <sstream>
#include "vektor.h"
#include "matrix.h"
#include "EgyOperand.h"
#include "MuveletiSor.h"
/**
       * Valósak összehasonlításáa, hogy majdnem egyenlőek-e
       * @param a az egyik szam
       * @param b a másik szám
       * @return egyenlőek-e
       */
bool almostEqual(double a, double b);

/**
       * egyforma mérertű vektorok összeadását teszteli
       * @return rendeltetészerűen működik-e
       */
bool TesztOsszeadEgyformaVektor();
/**
       * különböző mérertű vektorok összeadását teszteli
       * @return rendeltetészerűen működik-e
       */
bool TesztOsszeadKulVektor();

/**
       * vektorok szorzását teszteli
       * @return rendeltetészerűen működik-e
       */
bool TesztSzorozVektor();

/**
       * különböző méretű vektorok szorzását teszteli
       * @return rendeltetészerűen működik-e
       */
bool TesztSzorozVektorKul();

/**
       * vektorok számmal szorzását teszteli
       * @return rendeltetészerűen működik-e
       */
bool TesztSzammalSzorozVektor();

/**
       * egyforma mérertű mátrixok összeadását teszteli
       * @return rendeltetészerűen működik-e
       */
bool TesztOsszeadEgyforma();

/**
       * különböző mérertű mátrixok összeadását teszteli
       * @return rendeltetészerűen működik-e
       */
bool TesztOsszeadKul();

/**
       * egyforma mérertű mátrixok kivonását teszteli
       * @return rendeltetészerűen működik-e
       */
bool TesztKivonEgyforma();

/**
       * különböző mérertű mátrixok kivoását teszteli
       * @return rendeltetészerűen működik-e
       */
bool TesztKivonKul();

/**
       * mátrixok szorzását teszteli
       * @return rendeltetészerűen működik-e
       */
bool TesztSzoroz();

/**
       * különböző méretű mátrixok szorzását teszteli
       * @return rendeltetészerűen működik-e
       */
bool TesztSzorozKul();

/**
       * mátrix számmal szorzását teszteli
       * @return rendeltetészerűen működik-e
       */
bool TesztSzammalSzoroz();

/**
       * mátrix transzponálását teszteli
       * @return rendeltetészerűen működik-e
       */
bool TeszTranszp();

/**
       * mátrix determinánsát számoló függvényt teszteli
       * @return rendeltetészerűen működik-e
       */
bool TeszDet();

/**
       * mátrix determinánsát számoló függvényt teszteli túl nagy mátrixra
       * @return rendeltetészerűen működik-e
       */
bool TeszDetNagy();

/**
       * mátrix rangját számoló függvényt teszteli
       * @return rendeltetészerűen működik-e
       */
bool TeszRang();

/**
       * mátrix rangját számoló függvényt teszteli túl nagy mátrixra
       * @return rendeltetészerűen működik-e
       */
bool TeszRangNagy();

/**
       * mátrix inverzét számoló függvényt teszteli
       * @return rendeltetészerűen működik-e
       */
bool TeszInv();

/**
       * mátrix inverzét számoló függvényt teszteli túl nagy mátrixra
       * @return rendeltetészerűen működik-e
       */
bool TeszInvNagy();

/**
       * mátrix inverzét számoló függvényt teszteli, nem létezik inverz
       * @return rendeltetészerűen működik-e
       */
bool TeszInvNincs();

/**
       * műveleti sort teszteli
       * @return rendeltetészerűen működik-e
       */
bool TesztMuvSor();

/**
       * műveleti sor hibakezelést teszteli (a)
       * @return rendeltetészerűen működik-e
       */
bool TesztMuvSorA();

/**
       * műveleti sor hibakezelést teszteli (b)
       * @return rendeltetészerűen működik-e
       */
bool TesztMuvSorB();

/**
       * mátrix fájlba írását teszteli
       * @return rendeltetészerűen működik-e
       */
bool TesztMatrixFajlba();

/**
       * mátrix fájlba írását teszteli, hibás fájlnév
       * @return rendeltetészerűen működik-e
       */
bool TesztMatrixFajlbaHibas();

/**
       * teszteseteket futtatja
       */
void test();

#endif





















































































