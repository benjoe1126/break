#include <iostream>
#include <sstream>
#include <math.h>
#include "vektor.h"
#include "matrix.h"
#include "EgyOperand.h"
#include "MuveletiSor.h"
#include "test.h"

bool almostEqual(double a, double b){
    double diff = b-a;
    return (fabs(diff)<0.01*std::max(fabs(a),fabs(b)));
}

//1. egyforma mérertű vektorok összeadását teszteli
bool TesztOsszeadEgyformaVektor(){
    Vektor a(5);
    for (int i = 0; i < 5 ; i++){
        a[i] = i;
    }
    Vektor b(5);
    for (int i = 0; i < 5 ; i++){
        b[i] = -i;
    }
    std::stringstream ss;
    ss<<a+b;
    std::string s = "(0,\t0,\t0,\t0,\t0)";
    return s == ss.str();
}

//2. különböző mérertű vektorok összeadását teszteli
bool TesztOsszeadKulVektor(){
    Vektor a(5);
    for (int i = 0; i < 5 ; i++){
        a[i] = i;
    }
    Vektor b(3);
    for (int i = 0; i < 3 ; i++){
        b[i] = -i;
    }
    std::stringstream ss;
    ss<<a+b;
    std::string s = "(0,\t0,\t0,\t3,\t4)";
    return s == ss.str();
}

//3. vektorok szorzását teszteli
bool TesztSzorozVektor(){
    Vektor a(5);
    for (int i = 0; i < 5 ; i++){
        a[i] = i;
    }
    Vektor b(5);
    for (int i = 0; i < 5 ; i++){
        b[i] = -i;
    }
    std::stringstream ss;
    ss<<a*b;
    std::string s = "-30";
    return s == ss.str();
}

//4. különböző méretű vektorok szorzását teszteli
bool TesztSzorozVektorKul(){
    Vektor a(5);
    for (int i = 0; i < 5 ; i++){
        a[i] = i;
    }
    Vektor b(3);
    for (int i = 0; i < 3 ; i++){
        b[i] = -i;
    }
    try{
        std::cout<<a*b;
    }
    catch(const char * err){
        return true;
    }
    return false;
}

//5. vektorok számmal szorzását teszteli
bool TesztSzammalSzorozVektor(){
    Vektor a(5);
    for (int i = 0; i < 5 ; i++){
        a[i] = i;
    }
    std::stringstream ss;
    Vektor b = a*3;
    ss<<b;
    std::stringstream ss2;
    Vektor c = a*3;
    ss2<<b;
    std::string s = "(0,\t3,\t6,\t9,\t12)";
    return (s == ss.str()) && (s == ss2.str());
}

//6. egyforma mérertű mátrixok összeadását teszteli
bool TesztOsszeadEgyforma(){
    Matrix a(3, 3);
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3; j++){
            a[i][j] = i*j;
        }
    }
    Matrix b(3, 3);
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3; j++){
            b[i][j] = (2-i)*(2-j);
        }
    }
    std::stringstream ss;
    ss<<a+b;
    std::string s = "(4,\t2,\t0)\n(2,\t2,\t2)\n(0,\t2,\t4)\n";
    return s == ss.str();
}

//7. különböző mérertű mátrixok összeadását teszteli
bool TesztOsszeadKul(){
    Matrix a(3, 3);
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3; j++){
            a[i][j] = i*j;
        }
    }
    Matrix b(2, 2);
    for (int i = 0; i < 2 ; i++){
        for (int j = 0; j < 2; j++){
            b[i][j] = (2-i)*(2-j);
        }
    }
    std::stringstream ss;
    ss<<a+b;
    std::string s = "(4,\t2,\t0)\n(2,\t2,\t2)\n(0,\t2,\t4)\n";
    return s == ss.str();
}

//8. egyforma mérertű mátrixok kivonását teszteli
bool TesztKivonEgyforma(){
    Matrix a(3, 3);
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3; j++){
            a[i][j] = i*j;
        }
    }
    Matrix b(3, 3);
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3; j++){
            b[i][j] = (2-i)*(2-j);
        }
    }
    std::stringstream ss;
    ss<<(a-b);
    std::string s = "(-4,\t-2,\t0)\n(-2,\t0,\t2)\n(0,\t2,\t4)\n";
    return s == ss.str();
}

//9. különböző mérertű mátrixok kivoását teszteli
bool TesztKivonKul(){
    Matrix a(3, 3);
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3; j++){
            a[i][j] = i*j;
        }
    }
    Matrix b(2, 2);
    for (int i = 0; i < 2 ; i++){
        for (int j = 0; j < 2; j++){
            b[i][j] = (2-i)*(2-j);
        }
    }
    std::stringstream ss;
    ss<<a-b;
    std::string s = "(-4,\t-2,\t0)\n(-2,\t0,\t2)\n(0,\t2,\t4)\n";
    return s == ss.str();
}

//10. mátrixok szorzását teszteli
bool TesztSzoroz(){
    Matrix a(3, 3);
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3; j++){
            a[i][j] = i*j;
        }
    }
    Matrix b(3, 3);
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3; j++){
            b[i][j] = (2-i)*(2-j);
        }
    }
    std::stringstream ss;
    ss<<a*b;
    std::string s = "(0,\t0,\t0)\n(2,\t1,\t0)\n(4,\t2,\t0)\n";
    return s == ss.str();
}

//11. különböző méretű mátrixok szorzását teszteli
bool TesztSzorozKul(){
    Matrix a(3, 3);
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3; j++){
            a[i][j] = i*j;
        }
    }
    Matrix b(2, 2);
    for (int i = 0; i < 2 ; i++){
        for (int j = 0; j < 2; j++){
            b[i][j] = (2-i)*(2-j);
        }
    }
    try{
        Matrix c = a*b;
        std::cout<<c;
    }
    catch (const char * err){
        return true;
    }
    return false;
}

//12. mátrix számmal szorzását teszteli
bool TesztSzammalSzoroz(){
    Matrix a(3, 3);
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3; j++){
            a[i][j] = i*j;
        }
    }
    std::stringstream ss;
    ss<<3*a;
    std::string s = "(0,\t0,\t0)\n(0,\t3,\t6)\n(0,\t6,\t12)\n";
    return (s == ss.str());
}

//13. mátrix transzponálását teszteli
bool TeszTranszp(){
    Matrix a(2, 4);
    for (int i = 0; i < 2 ; i++){
        for (int j = 0; j < 4; j++){
            a[i][j] = i*j;
        }
    }
    std::stringstream ss;
    ss<<a.transzponal();
    std::string s = "(0,\t0)\n(0,\t1)\n(0,\t2)\n(0,\t3)\n";
    return s == ss.str();
}

//14. mátrix transzponálását teszteli
bool TeszTranszp2(){
    Matrix *a = new Matrix(1, 4);
    for (int i = 0; i < 1 ; i++){
        for (int j = 0; j < 4; j++){
            (*a)[i][j] = i*j;
        }
    }
    std::stringstream ss;
    Matrix b = a->transzponal();
    delete a;
    ss<<b;
    std::string s = "(0)\n(0)\n(0)\n(0)\n";
    return s == ss.str();
}

//14. mátrix determinánsát számoló függvényt teszteli
bool TeszDet(){
    Matrix a(3, 3);
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3; j++){
            if (i == j)
                a[i][j] = 5;
            else
                a[i][j] = i+1+j*j;
        }
    }
    return almostEqual(a.determinans()[0][0], (-14));
}

//15. mátrix determinánsát számoló függvényt teszteli túl nagy mátrixra
bool TeszDetNagy(){
    Matrix a(10, 10);
    for (int i = 0; i < 10 ; i++){
        for (int j = 0; j < 10; j++){
            if (i == j)
                a[i][j] = 5;
            else
                a[i][j] = i+1+j*j;
        }
    }
    try{
        double det = (a.determinans())[0][0];
        std::cout<<det;
    }
    catch(const char* err){
        return true;
    }
    return false;
}

//16. mátrix rangját számoló függvényt teszteli
bool TeszRang(){
    Matrix a(3, 5);
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 5; j++){
            if (i == j)
                a[i][j] = 5;
            else
                a[i][j] = i+1+j*j;
        }
    }
    return (a.rang()[0][0] == 3);
}

//17. mátrix rangját számoló függvényt teszteli túl nagy mátrixra
bool TeszRangNagy(){
    Matrix a(10, 10);
    for (int i = 0; i < 10 ; i++){
        for (int j = 0; j < 10; j++){
            if (i == j)
                a[i][j] = 5;
            a[i][j] = i+1+j*j;
        }
    }
    try{
        double rang = (a.rang())[0][0];
        std::cout<<rang;
    }
    catch(const char* err){
        return true;
    }
    return false;
}

//18. mátrix inverzét számoló függvényt teszteli
bool TeszInv(){
    Matrix a(3, 3);
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3; j++){
            if (i == j)
                a[i][j] = 0.5;
            else 
                a[i][j] = 0;
        }
    }
    std::stringstream ss;
    ss<<a.inverz();
    std::string s = "(2,\t0,\t0)\n(0,\t2,\t0)\n(0,\t0,\t2)\n";
    return s == ss.str();
}

//19. mátrix inverzét számoló függvényt teszteli túl nagy mátrixra
bool TeszInvNagy(){
    Matrix a(10, 10);
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3; j++){
            if (i == j)
                a[i][j] = 0.5;
            else 
                a[i][j] = 0;
        }
    }
    try{
        Matrix inv = a.inverz();
        std::cout<<inv;
    }
    catch(const char* err){
        return true;
    }
    return false;
}

//20. mátrix inverzét számoló függvényt teszteli, nem létezik inverz
bool TeszInvNincs(){
    Matrix a(3, 3);
    try{
        Matrix inv = a.inverz();
        std::cout<<inv;
    }
    catch(const char* err){
        return true;
    }
    return false;
}

//21. műveleti sort teszteli
bool TesztMuvSor(){
    MuveletiSor ms;
    Matrix *a = new Matrix(3,3);
    ms.ujOp(a);
    Matrix *b = new Matrix(3,3, osszead);
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3; j++){
            if (i == j)
                (*b)[i][j] = 0.5;
            else (*b)[i][j] = 0;
        }
    }
    ms.ujOp(b);
    EgyOperand* c = new EgyOperand(inv);
    ms.ujOp(c);
    
    try{
        Muvelet *res = &(ms.kiszamol());
        std::stringstream ss;
        res->ir(ss);
        delete res;
        std::string s = "(2,\t0,\t0)\n(0,\t2,\t0)\n(0,\t0,\t2)\n";
        return s == ss.str();
    }
    catch(const char * err){
        std::cout<<err;
    }
    return false;
}

//22. műveleti sort teszteli
bool TesztMuvSor2(){
    MuveletiSor ms;
    Matrix *a = new Matrix(1,4);
    ms.ujOp(a);
    EgyOperand* c = new EgyOperand(transzp);
    ms.ujOp(c);
    Matrix *res = dynamic_cast<Matrix*>(&(ms.kiszamol()));
    std::stringstream ss;
    ss<<*res;
    delete res;
    std::string s = "(0)\n(0)\n(0)\n(0)\n";
    return s == ss.str();
}

//23. műveleti sor hibakezelést teszteli (a)
bool TesztMuvSorA(){
    MuveletiSor ms;
    Matrix* a = new Matrix(3,3);
    ms.ujOp(a);
    Matrix *b = new Matrix(3,3);
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3; j++){
            if (i == j)
                (*b)[i][j] = 0.5;
            else (*b)[i][j] = 0;
        }
    }
    try{
        ms.ujOp(b);
    }
    catch(const char* err){
        delete b;
        return true;
    }
    return false;
}

//23. műveleti sor hibakezelést teszteli (b)
bool TesztMuvSorB(){
    MuveletiSor ms;
    Matrix* a = new Matrix(3,3);
    a->setMuv(osszead);
    try{
        ms.ujOp(a);
    }
    catch(const char* err){
        delete a;
        return true;
    }
    return false;
}

//24. mátrix fájlba írását teszteli
bool TesztMatrixFajlba(){
    Matrix a(3, 3);
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3; j++){
            if (i == j)
                a[i][j] = 0.5;
            else 
                a[i][j] = 0;
        }
    }
    char fajlnev[20] = "proba.bin";
    writeF(a, fajlnev);
    Matrix b = readF(fajlnev);
    std::stringstream ss;
    ss<<a;
    std::stringstream ss2;
    ss2<<b;
    return (ss.str() == ss2.str());
}

//25. mátrix fájlba írását teszteli, hibás fájlnév
bool TesztMatrixFajlbaHibas(){
    Matrix a(3, 3);
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3; j++){
            if (i == j)
                a[i][j] = 0.5;
            else 
                a[i][j] = 0;
        }
    }

    char fajlnev[20] = "hiba";
    try{
        Matrix b = readF(fajlnev);
        std::stringstream ss;
        ss<<b;
    }
    catch(const char * err){
        return true;
    }
    return false;
}

void test() {
    std::cout<<"1. egyforma mérertű vektorok összeadás"<<std::endl;
    if (TesztOsszeadEgyformaVektor())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"2. különböző mérertű vektorok összeadása"<<std::endl;
    if (TesztOsszeadKulVektor())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"3. vektorok sz       * @param rhs ajobb oldali operandus mátrixorzása"<<std::endl;
    if (TesztSzorozVektor())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"4. különböző méretű vektorok szorzása"<<std::endl;
    if (TesztSzorozVektor())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"5. vektorok számmal szorzása"<<std::endl;
    if (TesztSzammalSzorozVektor())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"6. egyforma mérertű mátrixok összeadása"<<std::endl;
    if (TesztOsszeadEgyforma())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"7. különböző mérertű mátrixok összeadása"<<std::endl;
    if (TesztOsszeadKul())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"8. egyforma mérertű mátrixok kivonása"<<std::endl;
    if (TesztKivonEgyforma())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"9. különböző mérertű mátrixok kivonása"<<std::endl;
    if (TesztKivonKul())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"10. mátrixok szorzása"<<std::endl;
    if (TesztSzoroz())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"11. különböző mérertű mátrixok szorzása"<<std::endl;
    if (TesztSzorozKul())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"12. mátrix számmal szorzása"<<std::endl;
    if (TesztSzammalSzoroz())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"13. mátrix transzponálása"<<std::endl;
    if (TeszTranszp())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"13. mátrix transzponálása 2"<<std::endl;
    if (TeszTranszp2())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"14. mátrix determinánsa"<<std::endl;
    if (TeszDet())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"15. mátrix determinánsa túl nagy mátrixra"<<std::endl;
    if (TeszDetNagy())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"16. mátrix rangja"<<std::endl;
    if (TeszRang())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"17. mátrix rangja túl nagy mátrixra"<<std::endl;
    if (TeszRangNagy())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"18. mátrix inverze"<<std::endl;
    if (TeszInv())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"19. mátrix inverze túl nagy mátrixra"<<std::endl;
    if (TeszInv())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"20. mátrix inverze, nem létezik"<<std::endl;
    if (TeszInvNincs())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"21. műveleti sor"<<std::endl;
    if (TesztMuvSor())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"22. műveleti sor 2"<<std::endl;
    if (TesztMuvSor2())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"22. műveleti sor, hibakezelés (a)"<<std::endl;
    if (TesztMuvSorA())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"23. műveleti sor, hibakezelés (b)"<<std::endl;
    if (TesztMuvSorB())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"24. mátrixok fájlba kiírása"<<std::endl;
    if (TesztMatrixFajlba())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
    
    std::cout<<"25. mátrixok fájlba kiírása, hibás fájlnév"<<std::endl;
    if (TesztMatrixFajlbaHibas())
        std::cout<<"\tSIKERES\n\n";
    else std::cout<<"\tHIBA\n\n";
}
