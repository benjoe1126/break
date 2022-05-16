#include <iostream>
#include <fstream>
#include "vektor.h"
#include "matrix.h"
/**
       * Konstruktor
       * @param h a mátrix magassága
       * @param w a mátrix szélessége
       * @param o a mátrixhoz tartozó operátor
       */
Matrix::Matrix(size_t h, size_t w, op o) : Muvelet(o), height(h){
    mptr = new Vektor* [h];
    for (size_t i = 0; i < h; i++){
        mptr[i] = new Vektor(w);
    }
}
/**
       * Másoló konstruktor
       * @param m a másolandó mátrix
       */
Matrix::Matrix(const Matrix& m) : Muvelet(m.getMuv()){
    height = m.height;
    mptr = new Vektor* [height];
    for (size_t i = 0; i < height; i++){
        mptr[i] = new Vektor(m[i]);
    }
}
/**
       * Másoló konstruktor
       * @param m a másolandó mátrix
       * @param o az új mátrixhoz tartozó operátor
       */
Matrix::Matrix(const Matrix& m, op o) : Muvelet(o){
    height = m.height;
    mptr = new Vektor* [height];
    for (size_t i = 0; i < height; i++){
        mptr[i] = new Vektor(m[i]);
    }
}

/**
       * Értékadó operátor
       * @param m a másolandó mátrix
       * @return referencia az eredeti módosult mátrixra
       */
Matrix& Matrix::operator=(const Matrix& m){
    if (mptr == m.mptr)
        return *this;
    
    for (size_t i = 0; i < height; i++)
        delete mptr[i];
    delete[] mptr;
    height = m.height;
    mptr = new Vektor* [height];
    for (size_t i = 0; i < height; i++){
        mptr[i] = new Vektor(m[i]);
    }
    return *this;
}


/**
       * Transzponáló függvény (felcseréli a mátrix oszlopainak és sorainak szerepét)
       * @return egy új mátrix, ami az eredeti transzponáltja
       */
Matrix Matrix::transzponal() const{
    size_t width = getWidth();
    Matrix res(width, height);
    for (size_t i = 0; i < height; i++){
        for (size_t j = 0; j < width; j++){
            res[j][i] = (*mptr[i])[j];
        }
    }
    return res;
}

/**
       * Mátrixok összeadása
       * @param rhs ajobb oldali operandus mátrix
       * @return az eredény
       */
Matrix Matrix::operator+(const Matrix& rhs) const{
    size_t h_nagyobb;
    size_t h_kisebb;
    (height > rhs.height) ? h_nagyobb = height : h_nagyobb = rhs.height;
    (height > rhs.height) ? h_kisebb = rhs.height : h_kisebb = height;
    Matrix res(h_nagyobb, getWidth());
    for (size_t i = 0; i < h_nagyobb; i++){
        if (i < h_kisebb)
            (res)[i] = rhs[i] + (*this)[i];
        else if (height == h_nagyobb)
            (res)[i] = (*this)[i];
        else 
            (res)[i] = rhs[i];
    }
    return (res);
}

/**
       * Mátrixok kivonása egymásból
       * @param rhs ajobb oldali operandus mátrix
       * @return az eredény
       */
Matrix Matrix::operator-(const Matrix& rhs) const{
    return (*this)+(-1)*rhs;
}

/**
       * Mátrixok szorzása
       * @param rhs ajobb oldali operandus mátrix
       * @return az eredény
       */
Matrix Matrix::operator*(const Matrix& rhs) const{
    if ((rhs.getHeight()==1&&rhs.getWidth()==1)){
        return *this * rhs[0][0];
    }
    if ((getHeight()==1)&&(getWidth()==1)){
        return (*this)[0][0] * rhs;
    }
    if (getWidth() != rhs.height) throw "Nem kompatibilis a  mátrixok mérete!";
    
    Matrix res(height, rhs.getWidth());
    Matrix rhs_transp = rhs.transzponal();
    for (size_t i = 0; i < height; i++){
        for (size_t j = 0; j < rhs.getWidth(); j++){
            (res)[i][j] = (*mptr[i])*(rhs_transp)[j];
        }
    }
    return (res);
}

/**
       * Mátrixok kivonása egymásból
       * @param rhs ajobb oldali operandus valós
       * @return az eredény
       */
Matrix Matrix::operator*(const double rhs) const{
    Matrix res(*this);
    for (size_t i = 0; i < height; i++)
        (res)[i] = (res)[i]*rhs;
    return (res);
}

/**
       * Mátrix determinánsának számolása
       * @return az eredény
       */
Matrix Matrix::determinans() const{
    if (height > 3 || getWidth() > 3) throw "túl nagy mátrix!";
    if (getWidth() != height) throw "nem kvadratikus";
    Matrix m(height, height);
    m = *this;
    double det = 1;
    for (size_t i = 0; i < height; i++){
        if (m[i][i] != 0){
            double d = 1/m[i][i];
            m[i] = m[i]*d;
            det *= (1/d);
            for (size_t j = i+1; j < height; j++){
                if (m[j][i] != 0){
                    m[j] = m[j] + -1*m[j][i]*m[i];
                }
            } 
        }
        else {
            for (size_t j = i+1; j < height && m[i][i] == 0; j++){
                if (m[j][i] != 0){
                    Vektor tmp(getWidth());
                    tmp = m[i];
                    m[i] = m[j];
                    m[j] = tmp;
                    det*=-1;
                    if (m[i][j] != 0)
                        i--;
                }
            }
        }
    }
    Vektor test(getWidth());
    for (size_t i = 0; i < height; i++){
        if (m[i] == test)
            det = 0;
    }
    Matrix res(1, 1);
    (res)[0][0] = det;
    return res;
}

/**
       * Mátrix rangjának számolása
       * @return az eredény
       */
Matrix Matrix::rang(){
    if (height > 5 || getWidth() > 5) throw "túl nagy mátrix!";
    
    Matrix m(height, getWidth());
    m = *this;
    if (getWidth() < height)
        m = m.transzponal();
    double rang = 0;
    for (size_t i = 0; i < height; i++){
        if (m[i][i] != 0){
            double d = 1/m[i][i];
            m[i] = m[i]*d;
            for (size_t j = i+1; j < height; j++){
                if (m[j][i] != 0){
                    m[j] = m[j] + -1*m[j][i]*m[i];
                }
            } 
        }
        else {
            for (size_t j = i+1; j < height && m[i][i] == 0; j++){
                if (m[j][i] != 0){
                    Vektor tmp(getWidth());
                    tmp = m[i];
                    m[i] = m[j];
                    m[j] = tmp;
                    if (m[i][j] != 0)
                        i--;
                }
            }
        }
    }
    Vektor test(getWidth());
    for (size_t i = 0; i < height; i++){
        if (m[i] != test)
        rang+=1;
    }
    Matrix res(1, 1);
    (res)[0][0] = rang;
    return res;
}

/**
       * Mátrix inverzének számolása
       * @return az eredény
       */
Matrix Matrix::inverz() const{
    if (height > 3 || getWidth() > 3) throw "túl nagy mátrix!";
    Matrix deter = (this->determinans());
    if ((deter)[0][0] == 0){
        throw "nincs neki";
    }
    Matrix m(height, height);
    m = *this;
    Matrix inv = egysegmatrix(height);
    for (size_t i = 0; i < height; i++){
        if (m[i][i] != 0){
            double d = 1/m[i][i];
            m[i] = m[i]*d;
            inv[i] = inv[i]*d;
            for (size_t j = i+1; j < height; j++){
                if (m[j][i] != 0){
                    m[j] = m[j] - m[j][i]*m[i];
                    inv[i] = inv[j] - inv[j][i]*inv[i];
                }
            } 
        }
        else {
            for (size_t j = i+1; j < height && m[i][i] == 0; j++){
                if (m[j][i] != 0){
                    Vektor tmp(getWidth());
                    tmp = m[i];
                    m[i] = m[j];
                    m[j] = tmp;
                    tmp = inv[i];
                    inv[i] = inv[j];
                    inv[j] = tmp;
                    if (m[i][j] != 0)
                        i--;
                }
            }
        }
    }
    return inv;
}

/**
       * Elvégzi a muv tagjában tárolt műveletet a paramétereként kapott mátrixon
       * @param lhs a bal oldali operandus mátrix
       * @return referencia az eredényre (dinamikusan foglalt)
       */
Muvelet& Matrix::szamol(Muvelet& lhs) const{
    Matrix& lhs_m = dynamic_cast <Matrix&>(lhs);
    Matrix tmp(lhs_m);
    switch (this->getMuv()){
            case osszead:
                tmp = tmp + *this;
                break;
            case kivon:
                tmp = tmp - *this;
                break;
            case szor:
                tmp = tmp*(*this);
                break;
            default:
                throw "Nem egyopernadusos művelet!!";
        }
    Matrix *res = new Matrix(tmp);
    return *res;
}

/**
       * Destruktor
       */
Matrix::~Matrix(){
    for (size_t i = 0; i < height; i++)
        delete mptr[i];
    delete[] mptr;
}

/**
       * Kiír egy mátrixot egy bináris fájlba
       * @param m a mátrix
       * @param fajlnev a fájl neve
       */
void writeF(Matrix m, std::string fajlnev){
    std::ofstream file(fajlnev, std::ios::binary);
    if(!file) throw "nem sikerült megnyitni a fájlt!";
    size_t w = m.getWidth();
    size_t h = m.getHeight();
    file.write( reinterpret_cast<char*>(&w), sizeof(int));
    file.write( reinterpret_cast<char*>(&h), sizeof(int));
    for (size_t i = 0; i < w*h; i++){
        file.write( reinterpret_cast<char*>(&(m[i/w][i%h])), sizeof(double));
    }
    file.close();
}


/**
       * Beolvas egy mátrixot egy bináris fájlból
       * @param fajlnev a fájl neve
       * @return a mátrix
       */
Matrix readF(char* fajlnev){
    std::ifstream file(fajlnev, std::ios::binary);
    if(!file) throw "nem sikerült megnyitni a fájlt!";
    size_t w;
    size_t h;
    file.read( reinterpret_cast<char*>(&w), sizeof(int));
    file.read( reinterpret_cast<char*>(&h), sizeof(int));
    Matrix m(h, w);
    for (size_t i = 0; i < w*h; i++){
        file.read( reinterpret_cast<char*>(&(m[i/w][i%h])), sizeof(double));
    }
    file.close();
    return m;
}

/**
       * Bitshiftelő operátor (kiír az ostreamre)
       * @param os ostream, amire kiír
       * @param m a mátrix, amit kiír
       * @return az ostream, amire írt
       */
std::ostream& operator<<(std::ostream& os, const Matrix m){
    if (m.getMuv() == elsotag){
        for (size_t i = 0; i < m.getHeight(); i++){
            os<<m[i]<<std::endl;
        }
        return os;
    }
    char* tmp = getOperand((m.getMuv()));
    for (size_t i = 0; i < m.getHeight(); i++){
        if (i == (size_t)m.getHeight()/2)
                    os<<tmp<<" "<<m[i]<<std::endl;
        else os<<"  "<<m[i]<<std::endl;
    }
    delete[] tmp;
    return os;
}

/**
       * Mátrixok szorzása
       * @param lhs a bal oldali operandus mátrix
       * @param rhs ajobb oldali operandus mátrix
       * @return az eredény
       */
Matrix operator*(double lhs, const Matrix& rhs){
    Matrix res = rhs*lhs;
    return res;
}

/**
       * Létrehoz egy egységmátrixot
       * @param size a mátrix mérete (szélessége és magassága))
       * @return a mátrix
       */
Matrix egysegmatrix(size_t size){
    Matrix E(size, size);
    for (size_t i = 0; i < size; i++){
        for (size_t j = 0; j < size; j++){
            if (i==j)
                (E)[i][j] = 1;
        }
    }
    return E;
}

void Matrix::ir(std::ostream& os) const{
    os <<*this;
}
