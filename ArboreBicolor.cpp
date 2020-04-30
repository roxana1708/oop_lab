//
// Created by Roxana on 2020-04-27.
//

#include "ArboreBicolor.h"

std::ostream& afisare(std::ostream& msj, Nod_rosu_negru* nod) {
    if(nod == nullptr)
        return msj;
    else
    {
        afisare(msj, nod->getSt());
        msj << nod->getInfo() << getCuloare(nod) << std::endl;
        afisare(msj, nod->getDr());
    }
    return msj;
}

std::ostream& operator<<(std::ostream& msj, Arbore_bicolor &abc) {

    msj << "Afisare: ";
    Nod_rosu_negru *rad = abc.getRadacina();
    return afisare(msj, rad) << std::endl;
}

Arbore_bicolor& Arbore_bicolor::operator=(Arbore_bicolor &arboreBicolor) {

    Nod_rosu_negru *rad = this->getRadacina();
    Nod_rosu_negru *rad_aB = arboreBicolor.getRadacina();
    copieArbore_bicolor(rad, rad_aB);
    return *this;
}

Arbore_bicolor& Arbore_bicolor::operator>>(int info) {

    insertRBT(info);
    return *this;
}

void Arbore_bicolor::copieArbore_bicolor(Nod_rosu_negru *&copie, Nod_rosu_negru *&sursa) {

    if(sursa == nullptr)
        copie = nullptr;
    else
    {
        copie = new Nod_rosu_negru;
        copie->setInfo(sursa->getInfo());
        setCuloare(copie, getCuloare(sursa));

        Nod_rosu_negru *cst = copie->getSt();
        Nod_rosu_negru *cdr = copie->getDr();
        Nod_rosu_negru *sst = sursa->getSt();
        Nod_rosu_negru *sdr = sursa->getDr();

        copieArbore_bicolor(cst, sst);
        copieArbore_bicolor(cdr, sdr);
    }
}

Arbore_bicolor::Arbore_bicolor(Arbore_bicolor &arboreBicolor) {

    if(arboreBicolor.getRadacina() == nullptr)
        setRadacina(nullptr);
    else
    {
        Nod_rosu_negru *copie_rad = this->getRadacina();
        Nod_rosu_negru *sursa_rad = arboreBicolor.getRadacina();
        copieArbore_bicolor(copie_rad, sursa_rad);
        this->setRadacina(copie_rad);
    }
}

Nod_rosu_negru* Arbore_bicolor::getRadacina() {
    return static_cast<Nod_rosu_negru*>(this->m_rad);
}

void Arbore_bicolor::setRadacina(Nod_rosu_negru *rad) {
    this->m_rad = rad;
}

void Arbore_bicolor::insertRBT(int info) {

    Nod_rosu_negru *x = new Nod_rosu_negru(info);

    Nod *nod_rad = static_cast<Nod*>(getRadacina());
    Nod *nod = static_cast<Nod*>(x);
    nod_rad = inserareABC(nod_rad, nod);

    setRadacina(static_cast<Nod_rosu_negru*>(nod_rad));
    fix(x);
    m_nr_noduri++;
}

void Arbore_bicolor::rotateLeft(Nod_rosu_negru *&x) {

    Nod_rosu_negru *right_child = x->getDr();
    x->setDr(right_child->getSt());

    if (x->getDr() != nullptr)
        x->getDr()->setParinte(x);

    right_child->setParinte(x->getParinte());

    if (x->getParinte() == nullptr)
        setRadacina(right_child);
    else if (x == x->getParinte()->getSt())
        x->getParinte()->setSt(right_child);
    else
        x->getParinte()->setDr(right_child);

    right_child->setSt(x);
    x->setParinte(right_child);
}

void Arbore_bicolor::rotateRight(Nod_rosu_negru *&x) {

    Nod_rosu_negru *left_child = x->getSt();
    x->setSt(left_child->getDr());

    if (x->getSt() != nullptr)
        x->getSt()->setParinte(x);

    left_child->setParinte(x->getParinte());

    if (x->getParinte() == nullptr)
        setRadacina(left_child);
    else if (x == x->getParinte()->getSt())
        x->getParinte()->setSt(left_child);
    else
        x->getParinte()->setDr(left_child);

    left_child->setDr(x);
    x->setParinte(left_child);
}

void swapColor(Nod_rosu_negru *a, Nod_rosu_negru *b) {

    Culoare aux = getCuloare(a);
    setCuloare(a, getCuloare(b));
    setCuloare(b, aux);
}

void Arbore_bicolor::fix(Nod_rosu_negru *&x) {

    Nod_rosu_negru *parinte = nullptr;
    Nod_rosu_negru *bunic = nullptr;

    while (x != getRadacina() && getCuloare(x) == Rosu && getCuloare(x->getParinte()) == Rosu)
    {
        parinte = x->getParinte();
        bunic = parinte->getParinte();

        if (parinte == bunic->getSt())
        {
            Nod_rosu_negru *uncle = bunic->getDr();

            if(uncle != nullptr && getCuloare(uncle) == Rosu)
            {
                setCuloare(uncle, Negru);
                setCuloare(parinte, Negru);
                setCuloare(bunic, Rosu);
                x = bunic;
            }
            else
            {
                if (x == parinte->getDr())
                {
                    rotateLeft(parinte);
                    x = parinte;
                    parinte = x->getParinte();
                }

                rotateRight(bunic);
                swapColor(parinte, bunic);
                x = parinte;
            }
        }
        else
        {
            Nod_rosu_negru *uncle = bunic->getSt();

            if(uncle != nullptr && getCuloare(uncle) == Rosu)
            {
                setCuloare(uncle, Negru);
                setCuloare(parinte, Negru);
                setCuloare(bunic, Rosu);
                x = bunic;
            }
            else
            {
                if (x == parinte->getSt())
                {
                    rotateRight(parinte);
                    x = parinte;
                    parinte = x->getParinte();
                }

                rotateLeft(bunic);
                swapColor(parinte, bunic);
                x = parinte;
            }
        }
    }

    setCuloare(getRadacina(), Negru);
}

void Arbore_bicolor::deleteRBT(int info) {
    try {
        if (this->search(m_rad, info) == nullptr)
            throw "Nu exista aceasta valoare in arbore";
    }
    catch (const char* exceptie)
    {
        std::cout << exceptie;
        return;
    }

    Nod *nod_rad = static_cast<Nod*>(getRadacina());

    Nod *x = deleteBST(nod_rad, info);
    Nod_rosu_negru *y = static_cast<Nod_rosu_negru*>(x);

    fixDelete(y);
    m_nr_noduri--;
}

void Arbore_bicolor::fixDelete(Nod_rosu_negru *&nod) {
    if (nod == nullptr)
        return;

    if (nod == getRadacina())
    {
        setRadacina(nullptr);
        return;
    }

    if (getCuloare(nod) == Rosu || getCuloare(nod->getSt()) == Rosu || getCuloare(nod->getDr()) == Rosu)
    {
        Nod_rosu_negru *copil = nod->getSt() != nullptr ? nod->getSt() : nod->getDr();

        if (nod == nod->getParinte()->getSt())
        {
            nod->getParinte()->setSt(copil);

            if (copil != nullptr)
                copil->setParinte(nod->getParinte());


            setCuloare(copil, Negru);
            delete (nod);
        }
        else
        {
            nod->getParinte()->setDr(copil);

            if (copil != nullptr)
                copil->setParinte(nod->getParinte());


            setCuloare(copil, Negru);
            delete (nod);
        }
    }
    else
    {
        Nod_rosu_negru *frate = nullptr;
        Nod_rosu_negru *parinte = nullptr;
        Nod_rosu_negru *ptr = nod;

        setCuloare(ptr, Dublu);

        while (ptr != getRadacina() && getCuloare(ptr) == Dublu)
        {
            parinte = ptr->getParinte();

            if (ptr == parinte->getSt())
            {
                frate = parinte->getDr();

                if (getCuloare(frate) == Rosu)
                {
                    setCuloare(frate, Negru);
                    setCuloare(parinte, Rosu);
                    rotateLeft(parinte);
                }
                else
                {
                    if (getCuloare(frate->getSt()) == Negru && getCuloare(frate->getDr()) == Negru)
                    {
                        setCuloare(frate, Rosu);

                        if(getCuloare(parinte) == Rosu)
                            setCuloare(parinte, Negru);
                        else
                            setCuloare(parinte, Dublu);

                        ptr = parinte;
                    }
                    else
                    {
                        if (getCuloare(frate->getDr()) == Negru)
                        {
                            setCuloare(frate->getSt(), Negru);
                            setCuloare(frate, Rosu);
                            rotateRight(frate);
                            frate = parinte->getDr();
                        }

                        setCuloare(frate, getCuloare(parinte));
                        setCuloare(parinte, Negru);
                        setCuloare(frate->getDr(), Negru);
                        rotateLeft(parinte);

                        break;
                    }
                }
            }
            else
            {
                frate = parinte->getSt();

                if (getCuloare(frate) == Rosu)
                {
                    setCuloare(frate, Negru);
                    setCuloare(parinte, Rosu);
                    rotateRight(parinte);
                }
                else
                {
                    if (getCuloare(frate->getSt()) == Negru && getCuloare(frate->getDr()) == Negru)
                    {
                        setCuloare(frate, Rosu);

                        if (getCuloare(parinte) == Rosu)
                            setCuloare(parinte, Negru);
                        else
                            setCuloare(parinte, Dublu);

                        ptr = parinte;
                    }
                    else
                    {
                        if (getCuloare(frate->getSt()) == Negru)
                        {
                            setCuloare(frate->getDr(), Negru);
                            setCuloare(frate, Rosu);
                            rotateLeft(frate);
                            frate = parinte->getSt();
                        }

                        setCuloare(frate, getCuloare(parinte));
                        setCuloare(parinte, Negru);
                        setCuloare(frate->getSt(), Negru);
                        rotateRight(parinte);

                        break;
                    }
                }
            }
        }

        if (nod == nod->getParinte()->getSt())
            nod->getParinte()->setSt(nullptr);
        else
            nod->getParinte()->setDr(nullptr);

        delete(nod);
        setCuloare(getRadacina(), Negru);
    }


}

int Arbore_bicolor::adancimeArbore(Nod_rosu_negru *root) {

    if (root == nullptr or getCuloare(root) != Negru)
        return 0;

    if (root->getSt() == nullptr && root->getDr() == nullptr)
        return 1;


    if (!root->getSt())
        return adancimeArbore(root->getDr()) + 1;


    if (!root->getDr())
        return adancimeArbore(root->getSt()) + 1;

    return 1 + (adancimeArbore(root->getSt()) > adancimeArbore(root->getDr()) ? adancimeArbore(root->getSt()):adancimeArbore(root->getDr()));

}