#include <iostream>
#include "vektor.h"
/**
       * Konstruktor
       * @param meret a vektor szélessége
       */
Vektor::Vektor(const size_t meret) : width(meret) {
        vptr = new double[width];
        for (size_t i = 0; i < width; i++)
            vptr[i] = 0;
    }
/**
       * Másoló konstruktor
       * @param v a másolandó vektor
       */
Vektor::Vektor(const Vektor& v){
    width = v.width;
    vptr = new double[width];
    for (size_t i = 0; i < width; i++){
        vptr[i] = v[i];
    }
}
/**
       * Értékadó operátor
       * @param v a másolandó vektor
       * @return az eredeti vektor megváltozott értékkel
       */
Vektor& Vektor::operator=(const Vektor& v){
    if (vptr == v.vptr)
        return *this;
    width = v.width;
    delete[] vptr;
    vptr = new double [width];
    for (size_t i = 0; i < width; i++){
        vptr[i] = v[i];
    }
    return *this;
}
/**
       * Vektorok összeadása
       * @param rhs a jobb oldali operandus vektor
       * @return az eredény
       */
Vektor Vektor::operator+(const Vektor& rhs) const{
    size_t nagyobb;
    size_t kisebb;
    (width > rhs.width) ? nagyobb = width : nagyobb = rhs.getWidth();
    (width > rhs.width) ? kisebb = rhs.getWidth() : kisebb = width;
    Vektor res(nagyobb);
    for (size_t i = 0; i < nagyobb; i++){
        if (i < kisebb)
            res[i] = rhs[i] + vptr[i];
        else if (width == nagyobb)
            res[i] = vptr[i];
        else 
            res[i] = rhs[i];
    }
    return res;
}
/**
       * Vektorok kivonása
       * @param rhs a jobb oldali operandus vektor
       * @return az eredény
       */
Vektor Vektor::operator-(const Vektor& rhs) const{
        return *this+((-1.0)*(rhs));
    }
/**
       * Vektor szorzása számmal
       * @param rhs a jobb oldali operandus vektor
       * @return az eredény
       */
Vektor Vektor::operator*(const double& rhs) const{
    Vektor res(width);
    for (size_t i = 0; i < width; i++){
        (res)[i] = rhs*vptr[i];
    }
    return (res);
}
/**
       * Vektor szorzása vektorral
       * @param rhs a jobb oldali operandus vektor
       * @return az eredény
       */
double Vektor::operator*(const Vektor& rhs) const{
    double sum = 0;
    if (width != rhs.width) throw "nem kompatibilis a vektorok mérete!";
    for (size_t i = 0; i < width; i++){
        sum += rhs[i]*vptr[i];
    }
    return sum;
}
/**
       * Vektor szorzása vektorral
       * @param lhs a bal oldali operandus valós
       * @param rhs a jobb oldali operandus vektor
       * @return az eredény
       */
Vektor operator*(const double& lhs, const Vektor& rhs){
    return rhs*lhs;
}
/**
       * Vektor szorzása vektorral
       * @param lhs a bal oldali operandus egész
       * @param rhs a jobb oldali operandus vektor
       * @return az eredény
       */
Vektor operator*(const int& lhs, const Vektor& rhs){
    return rhs*lhs;
}
/**
       * Egyenlőség vizsgálat
       * @param rhs a jobb oldali operandus vektor
       * @return az eredény
       */
bool Vektor::operator==(const Vektor& rhs) const{
    if (width != rhs.getWidth())
        return false;
    for (size_t i = 0; i < width; i++)
        if (vptr[i] != rhs[i])
            return false;
    return true;
}
/**
       * Egyenlőtlenség vizsgálat
       * @param rhs a jobb oldali operandus vektor
       * @return az eredény
       */
bool Vektor::operator!=(const Vektor& rhs) const{
    return !(operator==(rhs));
}
/**
       * Destruktor
       */
Vektor::~Vektor() {
    delete[] vptr;
}
/**
       * Bitshiftelő operátor (kiír az ostreamre)
       * @param os ostream, amire kiír
       * @param v a vektor, amit kiír
       * @return az ostream, amire írt
       */
std::ostream& operator<<(std::ostream& os, Vektor v){
    os<<"(";
        size_t width = v.getWidth();
        for (size_t i = 0; i < width-1; i++)
            os<<v[i]<<",\t";
        os<<v[width-1]<<")";
        return os;
    return os;
}

void Vektor::ir(std::ostream& os) const{
    os<<*this;
}
