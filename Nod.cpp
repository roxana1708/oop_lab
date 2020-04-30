//
// Created by Roxana on 2020-04-27.
//

#include "Nod.h"

Nod&  Nod::operator=(Nod& nod) {
    this->setInfo(nod.getInfo());

    this->setSt(nod.getSt());

    this->setDr(nod.getDr());

    this->setParinte(nod.getParinte());
    return *this;
}

Nod::Nod(const Nod &nod) {
    m_info = nod.m_info;
    m_st = nod.m_st;
    m_dr = nod.m_dr;
    m_parinte = nod.m_parinte;
}


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