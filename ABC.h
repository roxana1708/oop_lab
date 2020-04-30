//
// Created by Roxana on 2020-04-27.
//

#ifndef OOP_TEMA2_ABC_H
#define OOP_TEMA2_ABC_H

#include "Nod.h"
#include "Arbore.h"
#include <iostream>

class ABC : public Arbore {
public:
    Nod *m_rad;

    ABC(int nr_noduri = 0, Nod *rad = nullptr)
            : Arbore{ nr_noduri }, m_rad{ rad }
    {

    }

    ABC(ABC &abc);
    void copieABC(Nod *&copie, Nod *&sursa);

    virtual ~ABC();
    void sterge_ABC(Nod *nod);

    virtual Nod* getRadacina();
    virtual void setRadacina(Nod* rad);

    Nod* inserareABC(Nod *&root, Nod *&x);
    void inserareVal(int val);
    Nod* deleteBST(Nod *&root, int data);
    void dltBST(Nod *&nod);
    void stergeNod(int data);
    Nod* search(Nod *root, int key);

    virtual ABC& operator=(ABC& abc);
    virtual ABC& operator>>(Nod *nod);
    friend std::ostream& operator<<(std::ostream& msj, ABC& abc);

    virtual int adancimeArbore(Nod* root);
};

#endif //OOP_TEMA2_ABC_H
