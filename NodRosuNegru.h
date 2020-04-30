//
// Created by Roxana on 2020-04-27.
//

#ifndef OOP_TEMA2_NODROSUNEGRU_H
#define OOP_TEMA2_NODROSUNEGRU_H

#include "Nod.h"

enum Culoare {Rosu, Negru, Dublu};

class Nod_rosu_negru : public Nod {

protected:
    Culoare m_culoare;

public:
    Nod_rosu_negru(int info = 0, Nod_rosu_negru *st = nullptr, Nod_rosu_negru *dr = nullptr, Nod_rosu_negru *parinte = nullptr, Culoare culoare = Rosu)
            : Nod(info, st, dr, parinte), m_culoare{ culoare }
    {

    }

    Nod_rosu_negru(const Nod_rosu_negru &nod);

    virtual Nod_rosu_negru* getParinte();
    virtual Nod_rosu_negru* getSt();
    virtual Nod_rosu_negru* getDr();

    void setParinte(Nod_rosu_negru* p);
    void setSt(Nod_rosu_negru* st);
    void setDr(Nod_rosu_negru* dr);

    friend Culoare getCuloare(Nod_rosu_negru *x);
    friend void setCuloare(Nod_rosu_negru *x, Culoare color);

};

#endif //OOP_TEMA2_NODROSUNEGRU_H
