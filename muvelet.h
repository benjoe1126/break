#ifndef MUVELET_H_INCLUDED
#define MUVELET_H_INCLUDED

#include <string.h>
#include <iostream>

enum op{
    elsotag, osszead, kivon, szor, transzp, inv, rank
};

class Muvelet{
protected: 
    op muv; 
    
public:
    /**
       * Konstruktor
       * @param o operátor
       */
    Muvelet(op o = elsotag);
    /**
       * Másoló konstruktor
       * @param m művelet, amiről másol
       */
    Muvelet(Muvelet& m) : Muvelet(m.muv){}
    /**
       * Visszadja a műveletben tárolt operátort
       * @return az operátor
       */
    op getMuv() const{
        return muv;
    }
    /**
       * Beállítja a műveletben tárolt operátort
       * @param o az operátor
       */
    void setMuv(op o){
        muv = o;
    }
    virtual void ir(std::ostream&) const = 0;
    virtual Muvelet& szamol(Muvelet& lhs) const = 0;
    virtual ~Muvelet();
};


/**
       * Operátor alapján visszaadja a kiírandó c-stringet
       * @param o az operátor
       * @return c-string
       */
char* getOperand(op o);
/**
       * karakter alapján visszaadja az operátort
       * @param c a karakter
       * @return az operátor
       */
op setOperand(const char c);

#endif // MUVELET_H_INCLUDED
// 
