//
// Created by Roxana on 2020-04-27.
//

#ifndef OOP_TEMA2_ARBORE_H
#define OOP_TEMA2_ARBORE_H

class Arbore {
public:
    int m_nr_noduri;

    Arbore(int nr_noduri = 0)
            : m_nr_noduri{ nr_noduri }
    {

    }

    virtual ~Arbore() = default;

    virtual void insert(int vector[]) = 0;
    virtual void sterge(int vector[]) = 0;
};

#endif //OOP_TEMA2_ARBORE_H
