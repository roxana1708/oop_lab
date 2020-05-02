//
// Created by Roxana on 2020-04-27.
//

#ifndef OOP_TEMA2_NOD_H
#define OOP_TEMA2_NOD_H

class Nod {
protected:
    int m_info;
    Nod *m_st, *m_dr, *m_parinte;

public:
    Nod(int info = 0, Nod *st = nullptr, Nod *dr = nullptr, Nod *parinte = nullptr)
            : m_info{ info }, m_st{ st }, m_dr{ dr }, m_parinte{ parinte }
    {

    }

    Nod(const Nod &nod) = delete;

    virtual ~Nod() = default;
    int getInfo();
    virtual Nod* getParinte();
    virtual Nod* getSt();
    virtual Nod* getDr();

    virtual void setParinte(Nod* p);
    virtual void setSt(Nod* st);
    virtual void setDr(Nod* dr);
    void setInfo(int info);

    Nod& operator=(Nod& nod) = delete;
};

#endif //OOP_TEMA2_NOD_H
