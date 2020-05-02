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
    virtual ~ABC();

    virtual Nod* getRadacina();
    virtual void setRadacina(Nod* rad);

    Nod* search(Nod *root, int key);

    virtual ABC& operator=(ABC& abc);
    virtual ABC& operator>>(Nod *nod);
    friend std::ostream& operator<<(std::ostream& msj, ABC& abc);

    virtual int adancimeArbore(Nod* root);

    Nod* inserareABC(Nod *&root, Nod *&x);
    Nod* deleteBST(Nod *&root, int data);

    void insert(int vector[]);
    void sterge(int vector[]);

private:
    void copieABC(Nod *&copie, Nod *&sursa);
    void sterge_ABC(Nod *nod);

    void inserareVal(int val);

    void dltBST(Nod *&nod);
    void stergeNod(int data);

};

#endif //OOP_TEMA2_ABC_H

