//
// Created by Roxana on 2020-04-27.
//

#ifndef OOP_TEMA2_ARBOREBICOLOR_H
#define OOP_TEMA2_ARBOREBICOLOR_H

#include "NodRosuNegru.h"
#include "ABC.h"

class Arbore_bicolor : public ABC{

public:
    Arbore_bicolor(int nr_noduri = 0, Nod_rosu_negru *rad = nullptr)
            : ABC{ nr_noduri, rad }
    {

    }

    Arbore_bicolor(Arbore_bicolor &arboreBicolor);
    void copieArbore_bicolor(Nod_rosu_negru *&copie, Nod_rosu_negru *&sursa);

    virtual Nod_rosu_negru* getRadacina();
    virtual void setRadacina(Nod_rosu_negru *rad);

    void insertRBT(int info);
    void rotateLeft(Nod_rosu_negru *&x);
    void rotateRight(Nod_rosu_negru *&x);
    void fix(Nod_rosu_negru *&x);
    void deleteRBT(int info);
    void fixDelete(Nod_rosu_negru *&node);

    Arbore_bicolor& operator=(Arbore_bicolor& arboreBicolor);
    Arbore_bicolor& operator>>(int info);
    friend std::ostream& operator<<(std::ostream& msj, Arbore_bicolor& arboreBicolor);

    virtual int adancimeArbore(Nod_rosu_negru *root);
};

#endif //OOP_TEMA2_ARBOREBICOLOR_H
