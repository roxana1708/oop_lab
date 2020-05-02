//
// Created by Roxana on 2020-04-27.
//

#include "Nod.h"


int Nod::getInfo() {
    return this->m_info;
}

Nod* Nod::getParinte() {
    return this->m_parinte;
}

Nod* Nod::getSt() {
    return this->m_st;
}

Nod* Nod::getDr() {
    return this->m_dr;
}

void Nod::setParinte(Nod* p) {
    this->m_parinte = p;
}

void Nod::setSt(Nod* st) {
    this->m_st = st;
}

void Nod::setDr(Nod* dr) {
    this->m_dr = dr;
}

void Nod::setInfo(int info) {
    this->m_info = info;
}
