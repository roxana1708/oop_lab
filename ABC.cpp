//
// Created by Roxana on 2020-04-27.
//

#include "ABC.h"

std::ostream& afisare(std::ostream& msj, Nod* nod) {

    if(nod == nullptr)
        return msj;
    else {
        afisare(msj, nod->getSt());
        msj << nod->getInfo() << " ";
        afisare(msj, nod->getDr());
    }

    return msj;
}

std::ostream& operator<<(std::ostream& msj, ABC &abc) {

    msj << "Afisare: ";
    return afisare(msj, abc.getRadacina()) << std::endl;
}

ABC& ABC::operator>>(Nod *nod) {

    inserareABC(m_rad, nod);
    return *this;
}

void ABC::copieABC(Nod *&copie, Nod *&sursa) {

    if(sursa == nullptr)
        copie = nullptr;
    else {
        copie = new Nod;
        copie->setInfo(sursa->getInfo());

        Nod *cst = copie->getSt();
        Nod *cdr = copie->getDr();
        Nod *sst = sursa->getSt();
        Nod *sdr = sursa->getDr();

        copieABC(cst, sst);
        copieABC(cdr, sdr);
    }
}

ABC& ABC::operator=(ABC &abc) {

    copieABC(this->m_rad, abc.m_rad);
    return *this;
}

ABC::ABC(ABC &abc) {

    if(abc.getRadacina() == nullptr)
        this->setRadacina(nullptr);
    else
        copieABC(this->m_rad, abc.m_rad);
}

void ABC::sterge_ABC(Nod *nod) {

    if(nod != nullptr)
    {
        sterge_ABC(nod->getSt());
        sterge_ABC(nod->getDr());
        delete nod;
    }
}

ABC::~ABC() {
    sterge_ABC(m_rad);
}

Nod* ABC::getRadacina() {
    return this->m_rad;
}

void ABC::setRadacina(Nod* rad) {
    this->m_rad = rad;
}

Nod* ABC::search(Nod *root, int key) {

    if (root == nullptr || root->getInfo() == key)
        return root;

    if (root->getInfo() < key)
        return search(root->getDr(), key);

    return search(root->getSt(), key);
}

Nod* ABC::inserareABC(Nod *&root, Nod *&x) {

    try
    {
        if(this->search(m_rad, x->getInfo()) != nullptr)
            throw "Nu poti insera o valoare deja existenta in arbore";
    }
    catch (const char* exception)
    {
        std::cout << std::endl << exception;
        return root;
    }

    if (root == nullptr)
        return x;

    Nod *st = root->getSt();
    Nod *dr = root->getDr();

    if (x->getInfo() < root->getInfo())
    {
        root->setSt(inserareABC(st, x));
        root->getSt()->setParinte(root);
    }
    else if (x->getInfo() > root->getInfo())
    {
        root->setDr(inserareABC(dr, x));
        root->getDr()->setParinte(root);
    }

    return root;
}

void ABC::inserareVal(int val) {

    if (m_rad == nullptr)
        m_rad = new Nod(val);
    else
    {
        Nod *nou = new Nod(val);
        inserareABC(this->m_rad, nou);
    }

    m_nr_noduri++;
}

void ABC::insert(int vector[]) {
    int info = vector[0];
    int i = 1;
    while (info) {
        inserareVal(info);
        info = vector[i];
        i++;
    }
}

Nod* minValueNode(Nod *&node) {

    Nod *ptr = node;

    while (ptr->getSt() != nullptr)
        ptr = ptr->getSt();

    return ptr;
}

Nod* maxValueNode(Nod *&nod) {

    Nod *ptr = nod;

    while (ptr->getDr() != nullptr)
        ptr = ptr->getDr();

    return ptr;
}

Nod* ABC::deleteBST(Nod *&root, int data)
{
    if (root == nullptr)
        return root;

    Nod *dr = root->getDr();
    Nod *st = root->getSt();


    if(data < root->getInfo())
        return deleteBST(st, data);


    if (data > root->getInfo())
        return deleteBST(dr, data);

    if (st == nullptr || dr == nullptr)
        return root;

    Nod *aux = minValueNode(dr);
    root->setInfo(aux->getInfo());

    return deleteBST(dr, aux->getInfo());
}


void ABC::dltBST(Nod *&root) {

    if(root->getSt() == nullptr && root->getDr() == nullptr) {
        if (root == root->getParinte()->getSt())
            root->getParinte()->setSt(nullptr);
        else
            root->getParinte()->setDr(nullptr);
    }
    else if(root->getSt() == nullptr) {
        if(root == root->getParinte()->getDr()) {
            root->getParinte()->setDr(root->getDr());
            root->getDr()->setParinte(root->getParinte());
        }
        else {
            root->getParinte()->setSt(root->getDr());
            root->getDr()->setParinte(root->getParinte());
        }
    }
    else if(root->getDr() == nullptr) {
        if(root == root->getParinte()->getSt()) {
            root->getParinte()->setSt(root->getSt());
            root->getSt()->setParinte(root->getParinte());
        }
        else {
            root->getParinte()->setDr(root->getSt());
            root->getSt()->setParinte(root->getParinte());
        }
    }
    else {
        Nod *dr = root->getDr();
        Nod *temp = maxValueNode(dr);
        root->setInfo(temp->getInfo());

        dltBST(temp);
    }
}

void ABC::stergeNod(int data) {
    try {
        if (this->search(m_rad, data) == nullptr)
            throw "Nu exista aceasta valoare in arbore";
    }
    catch (const char* exceptie)
    {
        std::cout << exceptie;
        return;
    }

    Nod *nod = deleteBST(this->m_rad, data);
    dltBST(nod);
    m_nr_noduri--;
}

void ABC::sterge(int vector[]) {
    int info = vector[0];
    int i = 1;
    while (info) {
        stergeNod(info);
        info = vector[i];
        i++;
    }
}

int ABC::adancimeArbore(Nod *root)
{

    if (root == nullptr)
        return 0;

    if (root->getSt() == nullptr && root->getDr() == nullptr)
        return 1;

    if (!root->getSt())
        return adancimeArbore(root->getDr()) + 1;

    if (!root->getDr())
        return adancimeArbore(root->getSt()) + 1;

    return 1 + (adancimeArbore(root->getSt()) > adancimeArbore(root->getDr()) ? adancimeArbore(root->getSt()):adancimeArbore(root->getDr()));

}
