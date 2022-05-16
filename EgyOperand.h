#ifndef EGYOPERAND_H_INCLUDED
#define EGYOPERAND_H_INCLUDED

#include "muvelet.h"
#include "matrix.h"
class EgyOperand: public Muvelet{
public:
    /**
       * Konstruktor
       * @param o az operandus
       */
    EgyOperand(op o) : Muvelet(o){}
        /**
       * Másoló konstruktor
       * @param e amiről másol
       */
    EgyOperand(EgyOperand& e) : Muvelet(e.muv){}
    Muvelet& szamol(Muvelet& lhs) const{
        Matrix& lhs_m = dynamic_cast<Matrix&>(lhs);
        switch (this->getMuv()){
                case rank:{
                    Matrix* res = new Matrix(lhs_m.rang());
                    return *res;
                }
                case transzp:{
                    Matrix* res = new Matrix(lhs_m.transzponal());
                    return *res;
                }
                case inv:{
                    Matrix* res = new Matrix(lhs_m.inverz());
                    return *res;
                }
                case elsotag:{
                    Matrix *res = new Matrix(lhs_m);
                    return *res;
                }
                default:
                    throw "Nem kétoperandusos művelet!";
            }
    }
    virtual void ir(std::ostream& os) const{
        char* tmp;
        tmp = getOperand(getMuv());
        os << tmp;
        delete [] tmp;
    }
        /**
       * 
       * @param o az operandus
       */
    ~EgyOperand(){}
};
#endif // EGYOPERAND_H_INCLUDED
