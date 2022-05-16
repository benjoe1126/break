#ifndef MAIN_FUNCTIONS_H_INCLUDED
#define MAIN_FUNCTIONS_H_INCLUDED

#include "MuveletiSor.h"
#include <iostream>
        /**
       * Beolvas egy fájlból egy mátrixot és hozzáadja a műveleti sorhoz
       * @param ms referencia a műveleti sorra
       * @param muvelet a művelet amivel hozzáadja
       */
void MxFajlbolOlvas(MuveletiSor& ms, const char muvelet = '0');
        /**
       * Kiír fájlba egy mátrixot
       * @param m referencia a műveleti sorra
       */
void MxFajlbaKiir(MuveletiSor& m);
        /**
       * Beolvas egy számot és hozzáadja a műveleti sorhoz
       * @param ms referencia a műveleti sorra
       * @param muvelet a művelet amivel hozzáadja
       */
void SzamOlvas(MuveletiSor& ms, const char muvelet = '0');
        /**
       * Beolvassa egy egységmátrix méretét és hozzáadja a műveleti sorhoz
       * @param ms referencia a műveleti sorra
       * @param muvelet a művelet amivel hozzáadja
       */
void EgysegmxBerak(MuveletiSor& ms, const char muvelet = '0');
        /**
       * Beolvassa egy nullmátrix méretét és hozzáadja a műveleti sorhoz
       * @param ms referencia a műveleti sorra
       * @param muvelet a művelet amivel hozzáadja
       */
void NullmxBerak(MuveletiSor& ms, const char muvelet = '0');
        /**
       * Hozzáad egy egsoperandusos műveletet a sorhoz
       * @param ms referencia a műveleti sorra
       * @param muvelet a művelet amivel hozzáadja
       */
void EgyOperandusosMuveletetVegez(MuveletiSor& ms, const char muvelet);
        /**
       * Kiírja az első menüt
       */
void MenuEgyKiir();
       /**
       * Kiírja a második menüt
       */
void MenuKettoKiir();
       /**
       * Kiírja a harmadik menüt
       */
void MenuHaromKiir();
       /**
       * Végrehajtja a harmadik menüt, létrehoz egy új műveletet
       * @param ms referencia a műveleti sorra
       * @param muvelet a művelet amivel hozzáadja
       */
void MenuHarom(MuveletiSor& ms, const char muvelet);
       /**
       * Kiírja a negyedik menüt
       */
void MenuNegyKiir();
#endif // MAIN_FUNCTIONS_H_INCLUDED
