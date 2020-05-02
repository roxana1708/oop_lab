//
// Created by Roxana on 2020-04-27.
//

#ifndef OOP_TEMA2_ARBOREBICOLOR_H
#define OOP_TEMA2_ARBOREBICOLOR_H

#include "NodRosuNegru.h"
#include "ABC.h"

class Arbore_bicolor : public ABC{

private:
    void rotateLeft(Nod_rosu_negru *&x);
    void rotateRight(Nod_rosu_negru *&x);
    void fix(Nod_rosu_negru *&x);
    void colorareCazUnchiRosu(Nod_rosu_negru *b, Nod_rosu_negru *p, Nod_rosu_negru *u);
    void rotatieCazPStUNegru(Nod_rosu_negru *&b, Nod_rosu_negru *&p, Nod_rosu_negru *&x);
    void colorareCazParinteFiuSt(Nod_rosu_negru *&b, Nod_rosu_negru *&p, Nod_rosu_negru *&x);
    void rotatieCazPDrUNegru(Nod_rosu_negru *&b, Nod_rosu_negru *&p, Nod_rosu_negru *&x);
    void colorareCazParinteFiuDr(Nod_rosu_negru *&b, Nod_rosu_negru *&p, Nod_rosu_negru *&x);

    void fixDelete(Nod_rosu_negru *&node);
    void stergereCazNoduriRosii(Nod_rosu_negru *&nod);
    void stergereCazNodNegru(Nod_rosu_negru *&nod);
    int stergereCazNNFiuSt(Nod_rosu_negru *&ptr, Nod_rosu_negru *&frate, Nod_rosu_negru *&parinte);
    int stergereCazNNFiuDr(Nod_rosu_negru *&ptr, Nod_rosu_negru *&frate, Nod_rosu_negru *&parinte);
    void stergereColorareCazFrateFiuDrN(Nod_rosu_negru *&frate, Nod_rosu_negru *&parinte);
    void stergereColorareCazFrateFiuStN(Nod_rosu_negru *&frate, Nod_rosu_negru *&parinte);

    void insertRBT(int info);
    void deleteRBT(int info);

public:
    Arbore_bicolor(int nr_noduri = 0, Nod_rosu_negru *rad = nullptr)
            : ABC{ nr_noduri, rad }
    {

    }

    Arbore_bicolor(Arbore_bicolor &arboreBicolor);
    void copieArbore_bicolor(Nod_rosu_negru *&copie, Nod_rosu_negru *&sursa);

    virtual Nod_rosu_negru* getRadacina();
    virtual void setRadacina(Nod_rosu_negru *rad);

    void insert(int vector[]);
    void sterge(int vector[]);

    Arbore_bicolor& operator=(Arbore_bicolor& arboreBicolor);
    Arbore_bicolor& operator>>(int info);
    friend std::ostream& operator<<(std::ostream& msj, Arbore_bicolor& arboreBicolor);

    virtual int adancimeArbore(Nod_rosu_negru *root);
};

#endif //OOP_TEMA2_ARBOREBICOLOR_H
