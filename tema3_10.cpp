#include <iostream>
#include <string>
#include <vector>

class Locuinta {
protected:
    //id?
    std::string m_client;
    int m_suprafataUtila;
    int m_discount;

public:
    Locuinta(std::string client = "", int suprafataUtila = 0, int discount = 0)
        : m_client{ client }, m_suprafataUtila{ suprafataUtila }, m_discount{ discount }
    {

    }

    std::string getNumeClient() {
        return this->m_client;
    }

    int getSuprafataUtila() {
        return this->m_suprafataUtila;
    }

    int getDiscount() {
        return this->m_discount;
    }
};


class Apartament: public Locuinta {
protected:
    int m_etaj;

public:
    Apartament(std::string client = "", int suprafataUtila = 0, int discount = 0, int etaj = 0)
        : Locuinta(client, suprafataUtila, discount), m_etaj{ etaj }
    {

    }

    int getEtaj() {return m_etaj;}

    float chirie();
    void afisare();
};

float Apartament::chirie() {
    float pretFinal{(float)this->getSuprafataUtila() * 30};

    if (this->getDiscount() > 0)
        return pretFinal - pretFinal * ((float)this->getDiscount()/100);

    return pretFinal;
}

void Apartament::afisare() {
    std::cout << "Apartament, " << "Nume client: " << this->getNumeClient()
        << ", "<< "Suprafata utila: " << this->getSuprafataUtila()
        << "metri patrati, Discount: " << this->getDiscount() << "%, Etaj: "
        << this->m_etaj << std::endl;
}


class Casa: public Locuinta {
protected:
    int m_suprafataCurte;
    int m_nrEtaje;
    std::vector<int> m_suprafeteEtaje;

public:

    Casa(std::string client = "", int suprafataUtila = 0, int discount = 0, int suprafataCurte = 0, int nrEtaje = 0, std::vector<int> suprafeteEtaje = std::vector<int>())
        : Locuinta(client, suprafataUtila, discount), m_suprafataCurte{suprafataCurte}, m_nrEtaje{nrEtaje}
    {
        for(int index = 0; index < suprafeteEtaje.size(); index++)
            m_suprafeteEtaje.push_back(suprafeteEtaje[index]);
    }

    int getSuprCurte() {return m_suprafataCurte;}
    int getNrEtaje() {return m_nrEtaje;}

    float chirie();
    void afisare();
};

float Casa::chirie() {
    float pretFinal{(float)this->getSuprafataUtila() * 30};

    if (this->getDiscount() > 0)
        pretFinal -= pretFinal * (float)this->getDiscount()/100;

    pretFinal += m_suprafataCurte * 50;

    return pretFinal;
}

void Casa::afisare() {
    std::cout << "Casa, " << "Nume client: " << this->getNumeClient()
        << ", "<< "Suprafata utila: " << this->getSuprafataUtila()
        << "metri patrati, Discount: " << this->getDiscount() << "%";

    for (int index = 0; index < m_suprafeteEtaje.size(); index++)
        std::cout << "Etaj: " << index << " Suprafata utila: "
            << m_suprafeteEtaje[index] << " metri patrati";

    std::cout << "Suprafata curte: " << this->m_suprafataCurte;
}


template <class T>
class Gestiune {
private:
    std::vector<T*> m_locuinte;

public:
    Gestiune() {

    }

    ~Gestiune() {

    }

    Gestiune& operator+=(T t) {
        T* ptr = &t;
        m_locuinte.push_back(ptr);
        return *this;
    };

    T* operator[](int index) {
        try {
            if (index >= m_locuinte.size())
                throw "Index gresit";
        }
        catch (const char* exceptie)
        {
            std::cout << exceptie;
            return nullptr;
        }
        return m_locuinte[index];
    }

    friend Gestiune& operator>>(Gestiune& gestiune, T* locuinta) {
        gestiune.m_locuinte.push_back(locuinta);
    };

    friend std::ostream& operator<<(std::ostream& out, Gestiune& gestiune) {
        for (int index = 0; index < gestiune.m_locuinte.size(); index++)
            std::cout << "Id locuinta: " << gestiune.m_locuinte[index] <<"\n";
        return out;
    };
    
    void print() {
        for(int index = 0; index < m_locuinte.size(); index++) {
            m_locuinte[index]->afisare();
            std::cout << "Chirie lunara: " << m_locuinte[index]->chirie() << std::endl;
        }
    }
};


template <>
void Gestiune<Casa>::print() {
    float total = 0;

    for (int index = 0; index < m_locuinte.size(); index++)
        total += m_locuinte[index]->chirie();

    std::cout << "Castiguri lunare din inchirieri case: " << total << std::endl;
}

int main() {
    /// Am considerat pretul pe metru patrat universal valabil: pretMP = 30; pretMPCurte = 50;


    ///Exemplu Case
    std::vector<int> etajeCasa1{ 60, 60 };
    std::vector<int> etajeCasa2{ 36, 36, 36 };
    std::vector<int> etajeCasa3{ 50, 50, 40, 20};

    Casa casa1("Client1", 120, 0, 10, 2, etajeCasa1);
    Casa casa2("Client2", 108, 0, 50, 3, etajeCasa2);
    Casa casa3("Client3", 160, 0, 60, 4, etajeCasa2);

    Gestiune<Casa> gestiune2;
    gestiune2 += casa1;
    gestiune2 += casa2;
    gestiune2.print();


    ///Exemplu Apartamente
    Apartament apartament1("Client4", 75, 10, 4);
    Apartament apartament2("Client5", 50, 5, 9);
    Apartament apartament3("Client6", 42, 3, 1);
    Apartament apartament4("Client7", 55, 10, 5);

    Gestiune<Apartament> gestiune;
    gestiune += apartament1;
    gestiune += apartament2;
    gestiune += apartament3;
    gestiune += apartament4;
    gestiune.print();

    return 0;
}
