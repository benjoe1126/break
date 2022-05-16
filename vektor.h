#ifndef VEKTOR_H_INCLUDED
#define VEKTOR_H_INCLUDED

#include <iostream>

//!  Vektor 
/*!
  Ezekből épülnek fel a mátrixok, a rajtuk megvalósított műveletek segítségével vannak megvalósítva a mátrix műveletek.
*/


class Vektor{
    size_t width;
    double* vptr;
public:
    Vektor(const size_t meret = 0);
    Vektor(const Vektor& v);
    size_t getWidth() const{
        return width;
    }
    /**
       * Vektor indexelése
       * @param i index
       * @return referencia a Vektor i-edik elemére
       */
    double& operator[](const size_t i){
        return vptr[i];
    }
    /**
       * Vektor indexelése
       * @param i index
       * @return a Vektor i-edik sora
       */
    double operator[](const size_t i) const{
        return vptr[i];
    }
    Vektor& operator=(const Vektor& v);
    Vektor operator+(const Vektor& rhs) const;
    Vektor operator*(const double& rhs) const;
    Vektor operator-(const Vektor& rhs) const;
    double operator*(const Vektor& rhs) const;
    bool operator==(const Vektor& rhs) const;
    bool operator!=(const Vektor& rhs) const;
    void ir(std::ostream&) const;
    ~Vektor();
};

Vektor operator*(const double& lhs, const Vektor& rhs);

Vektor operator*(const int& lhs, const Vektor& rhs);

std::ostream& operator<<(std::ostream& os, Vektor v);
#endif // VEKTOR_H_INCLUDED
