#include "muvelet.h"

Muvelet::Muvelet(op o) : muv(o){}

char* getOperand(op o){
    char* op = new char[4];
    switch (o){
        case rank:
            strcpy(op, "R");
            return op;
        case osszead:
            strcpy(op, "+");
            return op;
        case kivon:
            strcpy(op, "-");
            return op;
        case szor:
            strcpy(op, "*");
            return op;
        case transzp:
            strcpy(op, "^T");
            return op;
        case inv:
            strcpy(op, "^-1");
            return op;
        default:
            strcpy(op, "");
            return op;
    }
}

op setOperand(const char c){
    op muvelet;
    switch (c){
        case 'x':
            muvelet = szor;
            break;
        case '*':
            muvelet = szor;
            break;
        case '+':
            muvelet = osszead;
            break;
        case '-':
            muvelet = kivon;
            break;
        case 'i':
            muvelet = inv;
            break;
        case 'r':
            muvelet = rank;
            break;
        case 'T':
            muvelet = transzp;
            break;
        case '0':
            muvelet = elsotag;
            break;
        default:
            throw "Hibás bemenet!";
    }
    return muvelet;
}

Muvelet::~Muvelet(){}
