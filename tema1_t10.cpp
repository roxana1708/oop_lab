#include <iostream>

class Nod
{
    int info;
    Nod *pre, *urm;

public:
    Nod(int info = 0, Nod *pre = nullptr, Nod *urm = nullptr);
    ~Nod();

    int getInfo(){return info;}
    Nod* getPre(){return pre;}
    Nod* getUrm(){return urm;}
    void setInfo(int n_info){info = n_info;}
    void setPre(Nod *n_pre){pre = n_pre;}
    void setUrm(Nod *n_urm){urm = n_urm;}

    friend class Lista_dublu_inlantuita;
};

Nod::Nod(int info, Nod *pre, Nod *urm) {
    this->info = info;
    this->pre = pre;
    this->urm = urm;
}

Nod::~Nod() = default;

class Info
{
    int val;
    int poz;

public:
    Info();
    Info(int val = 0, int poz = 0);

    int getVal(){return val;}
    int getPoz(){ return poz;}
    void setVal(int val){this->val = val;}
    void setPoz(int poz){this->poz = poz;}
};

Info::Info() {
    val = 0;
    poz = 0;
}

Info::Info(int val, int poz) {
    this->val = val;
    this->poz = poz;
}

class Lista_dublu_inlantuita
{
    Nod *prim, *ultim;

public:
    Lista_dublu_inlantuita();
    Lista_dublu_inlantuita(const Lista_dublu_inlantuita &l);
    ~Lista_dublu_inlantuita();
    void adauga_element(Info info);
    void sterge_element(int poz);
    friend void operator>>(Lista_dublu_inlantuita& list, Info info_nod);
    friend std::ostream& operator<<(std::ostream& out, Lista_dublu_inlantuita& list);
    friend Lista_dublu_inlantuita& operator+(Lista_dublu_inlantuita &list1, Lista_dublu_inlantuita &list2);
};

Lista_dublu_inlantuita::Lista_dublu_inlantuita() {
    prim = ultim = nullptr;
}

Lista_dublu_inlantuita::Lista_dublu_inlantuita(const Lista_dublu_inlantuita &l) {
    prim = l.prim;
    ultim = l.ultim;
}

Lista_dublu_inlantuita::~Lista_dublu_inlantuita() {
    Nod *curent = prim;
    Nod *temp;

    while(curent != nullptr){
        temp = curent;
        curent = curent->urm;
        delete temp;
    }

    prim = ultim = nullptr;
}

void Lista_dublu_inlantuita::adauga_element(Info info) {
    Nod *prev, *curent;
    Nod *p;
    int i;
    p = new Nod(info.getVal());
    if(prim == nullptr){
        prim = ultim = p;
    }else if (info.getPoz() == 1){
        prim->pre = p;
        p->urm = prim;
        prim = p;
    }else{
            curent = prim;
            for(i = 1; i < info.getPoz() && curent != nullptr; i++){
                prev = curent;
                curent = curent->urm;
            }
            if(curent != nullptr){
                prev->urm = p;
                p->pre = prev;
                p->urm = curent;
                curent->pre = p;
            }else{
                ultim->urm = p;
                p->pre = ultim;
                p->urm = nullptr;
                ultim = p;
            }

        }
}

void Lista_dublu_inlantuita::sterge_element(int poz) {
    Nod *curent, *temp;
    curent = this->prim;
    if(poz == 1){
        this->prim = this->prim->urm;
        this->prim->pre = nullptr;
    }else {
        //curent = this->prim;
        for (int i = 1; i < poz; i++) {
            temp = curent;
            curent = curent->urm;
        }
        if (curent->urm != nullptr) {
            temp->urm = curent->urm;
            curent->urm->pre = temp;
        }else{
            temp->urm = nullptr;
            this->ultim = temp;
        }
    }
    delete curent;
}

void operator>>(Lista_dublu_inlantuita& list, Info info_nod) {
    list.adauga_element(info_nod);
}

std::ostream& operator<<(std::ostream& out, Lista_dublu_inlantuita& list) {
    Nod *curent = list.prim;
    std::cout << "> ";
    while(curent){
        std::cout << curent->getInfo() << " ";
        curent = curent->getUrm();
    }
    std::cout<<std::endl;
    curent = list.ultim;
    std::cout << "< ";
    while(curent){
        std::cout << curent->getInfo() << " ";
        curent = curent->getPre();
    }
    return out;
}

Lista_dublu_inlantuita& operator+(Lista_dublu_inlantuita &list1, Lista_dublu_inlantuita &list2) {
    static Lista_dublu_inlantuita list3 = list1;
    Nod *curent;
    int i = 1;

    curent = list3.prim;
    while(curent){i++; curent = curent->getUrm();}

    curent = list2.prim;
    while(curent){
        list3>>Info {curent->getInfo(), i};
        curent = curent->getUrm();
        i++;
    }

    return list3;
}

int main() {

    Lista_dublu_inlantuita l1;
    Info i{7, 7}, j{8, 8};
    l1.adauga_element(Info {1, 1});
    l1.adauga_element(Info {2, 2});
    l1.adauga_element(Info {3, 3});
    l1.adauga_element(Info {4, 4});
    l1.adauga_element(Info {5, 5});
    l1.adauga_element(Info {6, 6});
    l1.sterge_element(5);
    l1 >> i;
    l1 >> j;
    std::cout << l1 << std::endl;
    Lista_dublu_inlantuita l2;
    l2.adauga_element({4, 1});
    l2.adauga_element({5, 1});
    l2.adauga_element({6, 1});
    std::cout << l2;
    std::cout << std::endl;
    Lista_dublu_inlantuita l3 = l1+l2;
    std::cout << l3;
    return 0;
}
