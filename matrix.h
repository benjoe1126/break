#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <iostream>
#include "vektor.h"
#include "muvelet.h"


class Matrix : public Muvelet{
    size_t height;
    Vektor **mptr = nullptr;
public:
    Matrix(size_t h = 0, size_t w = 0, op o = elsotag);
    Matrix(const Matrix& m);
    Matrix(const Matrix& m, op o);
    Matrix& operator=(const Matrix& m);
    /**
       * Mátrix magassága
       * @return az eredény
       */
    size_t getHeight() const{
        return height;
    }
        /**
       * Mátrix szélessége
       * @return az eredény
       */
    size_t getWidth() const{
        return mptr[0]->getWidth();
    }
    /**
       * Mátrix indexelése
       * @param i index
       * @return referencia a Matrix i-edik sorára
       */
    Vektor& operator[](const size_t i){
        return *mptr[i];
    }
        /**
       * Mátrix indexelése
       * @param i index
       * @return a Matrix i-edik sora
       */
    Vektor operator[](const size_t i) const{
        return *mptr[i];
    }
    Matrix operator+(const Matrix& rhs) const;
    Matrix operator-(const Matrix& rhs) const;
    Matrix operator*(const Matrix& rhs) const;
    Matrix operator*(const double rhs) const;
    Matrix transzponal() const;
    Matrix inverz() const;
    
    Muvelet& szamol(Muvelet& lhs) const;
    void ir(std::ostream&) const;
    Matrix determinans() const;
    
    Matrix rang();
    ~Matrix();
};

Matrix operator*(double lhs, const Matrix& rhs);

std::ostream& operator<<(std::ostream& os, const Matrix m);

Matrix egysegmatrix(size_t size);

Matrix readF(char*);

void writeF(Matrix m, std::string);

#endif // MATRIX_H_INCLUDED
