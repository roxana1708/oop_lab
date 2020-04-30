//
// Created by Roxana on 2020-04-27.
//

#include "NodRosuNegru.h"

Nod_rosu_negru::Nod_rosu_negru(const Nod_rosu_negru &nod) {
    m_info = nod.m_info;
    m_st = nod.m_st;
    m_dr = nod.m_dr;
    m_parinte = nod.m_parinte;
    m_culoare = nod.m_culoare;
}

Nod_rosu_negru* Nod_rosu_negru::getParinte() {
    return static_cast<Nod_rosu_negru*>(this->m_parinte);
}

Nod_rosu_negru* Nod_rosu_negru::getSt() {
    return static_cast<Nod_rosu_negru*>(this->m_st);
}

Nod_rosu_negru* Nod_rosu_negru::getDr() {
    return static_cast<Nod_rosu_negru*>(this->m_dr);
}

void Nod_rosu_negru::setParinte(Nod_rosu_negru* p) {
    this->m_parinte = p;
}

void Nod_rosu_negru::setSt(Nod_rosu_negru* st) {
    this->m_st = st;
}

void Nod_rosu_negru::setDr(Nod_rosu_negru* dr) {
    this->m_dr = dr;
}

Culoare getCuloare(Nod_rosu_negru *x) {
    if (x == nullptr)
        return Negru;
    return x->m_culoare;
}

void setCuloare(Nod_rosu_negru *x, Culoare color) {
    if (x == nullptr)
        return;

    x->m_culoare = color;
}