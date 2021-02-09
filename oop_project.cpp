#include <iostream>
#include <vector>

class Masca {
protected:
    std::string tip_protectie;
public:
    Masca(std::string protec = "ffp1")
        : tip_protectie{protec}
    {

    }
};

class MascaChirurgicala: public Masca {
protected:
    std::string culoare;
    int nr_pliuri;

public:
    MascaChirurgicala(std::string protec = "ffp1", std::string cul = "", int nr_p = 0)
        : Masca(protec), culoare{cul}, nr_pliuri{nr_p}
    {

    }

    MascaChirurgicala(const MascaChirurgicala &mascaChirurgicala);

    std::string getTipProtec() { return tip_protectie;}
    std::string getCuloare() { return culoare;}
    int getNrPliuri() { return nr_pliuri;}

    MascaChirurgicala& operator=(MascaChirurgicala& mc);

    friend std::istream& operator>>(std::istream& in, MascaChirurgicala& mc);
    friend std::ostream& operator<<(std::ostream& out, MascaChirurgicala& mc);


};

MascaChirurgicala::MascaChirurgicala(const MascaChirurgicala &mascaChirurgicala)
{
    this->tip_protectie = mascaChirurgicala.tip_protectie;
    this->culoare = mascaChirurgicala.culoare;
    this->nr_pliuri = mascaChirurgicala.nr_pliuri;
}

MascaChirurgicala& MascaChirurgicala::operator=(MascaChirurgicala& mc) {
    this->tip_protectie = mc.tip_protectie;
    this->culoare = mc.culoare;
    this->nr_pliuri = mc.nr_pliuri;

    return *this;
}

std::istream& operator>>(std::istream& in, MascaChirurgicala& mc){

    in >> mc.tip_protectie >> mc.culoare >> mc.nr_pliuri;
    return in;
}

std::ostream& operator<<(std::ostream& out, MascaChirurgicala& mc) {
    std::cout << "Tip protectie: " << mc.tip_protectie << "; Culoare: " << mc.culoare << "; Nr. pliuri: " << mc.nr_pliuri << "\n";
    return out;
}


class MascaPolicarbonat: public Masca{
protected:
    std::string tip_prindere;

public:
    MascaPolicarbonat(std::string prindere = "nespecificat")
        : Masca("ffp0"), tip_prindere{prindere}
    {

    }
    friend std::istream& operator>>(std::istream& in, MascaPolicarbonat* mp);
    friend std::ostream& operator<<(std::ostream& out, MascaPolicarbonat* mp);
};

std::istream& operator>>(std::istream& in, MascaPolicarbonat* mp){

    in >> mp->tip_prindere;
    return in;
}

std::ostream& operator<<(std::ostream& out, MascaPolicarbonat* mp) {
    std::cout << "Tip protectie: " << mp->tip_protectie << "; Tip prindere: " << mp->tip_prindere<< "\n";
    return out;
}


class Dezinfectant {
protected:
    int nrSpOrg;
    std::vector<std::string> ingrediente;
    std::vector<std::string> suprafete;

public:
    Dezinfectant(int nrOrg = 0, std::vector<std::string> ingr = {""}, std::vector<std::string> supr = {""})
        : nrSpOrg{nrOrg}, ingrediente{ingr}, suprafete{supr}
    {

    }

    virtual float eficienta() = 0;
};

class DezinfectantBacterii: virtual public Dezinfectant {
public:
    DezinfectantBacterii(int nrOrg = 0, std::vector<std::string> ingr = {""}, std::vector<std::string> supr = {""})
        : Dezinfectant(nrOrg, ingr, supr)
    {

    }

    virtual float eficienta();
};

float DezinfectantBacterii::eficienta() {
    int TotalBacterii = 1000000000;
    return (float)nrSpOrg/TotalBacterii;
}

class DezinfectantVirusuri: virtual public Dezinfectant {
public:
    DezinfectantVirusuri(int nrOrg = 0, std::vector<std::string> ingr = {""}, std::vector<std::string> supr = {""})
            : Dezinfectant(nrOrg, ingr, supr)
    {

    }

    virtual float eficienta();
};

float DezinfectantVirusuri::eficienta() {
    int TotalVirusi = 100000000;
    return (float)nrSpOrg/TotalVirusi;
}

class DezinfectantFungi: virtual public Dezinfectant {
public:
    DezinfectantFungi(int nrOrg = 0, std::vector<std::string> ingr = {""}, std::vector<std::string> supr = {""})
            : Dezinfectant(nrOrg, ingr, supr)
    {

    }

    virtual float eficienta();
};

float DezinfectantFungi::eficienta() {
    int TotalFungi = 1.5*1000000;
    return (float)nrSpOrg/TotalFungi;
}

class DezinfectantToate: public DezinfectantFungi, public DezinfectantBacterii, public DezinfectantVirusuri {

    virtual float eficienta();
};

float DezinfectantToate::eficienta() {
    //return ()/(100000000 + 1000000000 + 1.5*1000000);
}

class Achizitie {
    int zi;
    int luna;
    int an;
    std::string numeClient;
    std::vector<Dezinfectant*> dezinf;
    std::vector<Masca*> masti;
    int total;

public:
    Achizitie(int z = 0, int l = 0, int a = 0, std::string nume = "", std::vector<Dezinfectant*> dezin = {nullptr}, std::vector<Masca*> msc = {
            nullptr}, int t = 0)
            : zi{z}, luna{l}, an{a}, numeClient{nume}, dezinf{dezin}, masti{msc}, total{t}
    {

    }


    Achizitie(const Achizitie* a);

    Achizitie* operator+=(Masca* masca);
    Achizitie* operator+=(Dezinfectant* d);

    std::string getNumeClient() {return numeClient;}

    int calcTotal();
};

Achizitie::Achizitie(const Achizitie* a) {
    this->zi = a->zi;
    this->luna = a->luna;
    this->an = a->an;
    this->numeClient = a->numeClient;
    this->dezinf = a->dezinf;
    this->masti = a->masti;
    this->total = a->total;
}

Achizitie* Achizitie::operator+=(Masca* masca) {
    masti.push_back(masca);
}

Achizitie* Achizitie::operator+=(Dezinfectant* d) {
    dezinf.push_back(d);
}

int Achizitie::calcTotal() {
    //total =
    return total;
}

void op1(std::vector<Achizitie*> a) {
    Dezinfectant* d;
    int index = 0;
    //citim date dezinfectant
    //citim index achizitie
    //a[index] += d;
}

void op2(std::vector<Achizitie*> a) {

}

void op3(std::vector<Achizitie*> a) {

}

void op4(std::vector<Achizitie*> a) {

}

void op5(std::vector<Achizitie*> a) {

}

void op6(std::vector<Achizitie*> a) {

}

void op7(std::vector<Achizitie*> a) {

}

void op8(std::vector<Achizitie*> a) {

}

void op9(std::vector<Achizitie*> a) {

}

void op10(std::vector<Achizitie*> a) {

}


int main() {
    MascaChirurgicala mc1, mc2("ffp2", "verde brotacel", 55), mc3(mc1), mc4, mc5;
    mc4 = mc2;
    ///std::cin >> mc5;
    std::cout << mc2;

    MascaPolicarbonat* mp1 = new MascaPolicarbonat(), *mp2 = new MascaPolicarbonat();
    MascaPolicarbonat* mp3 = new MascaPolicarbonat("elastic");

    ///std::cin >> mp1 >> mp2;
    std::cout << mp3;

    //Suprafetele le-am retinut intr-un vector de stringuri ca in cazul ingredientelor
    Dezinfectant* d1 = new DezinfectantBacterii(100000000, std::vector<std::string>({"sulfati non-ionici", "sulfati cationici", "parfumuri", "Linalool", "Metilpropanol butilpentil"}), std::vector<std::string>({"lemn", "sticla", "metal", "ceramica", "marmura"}));
    Dezinfectant* d2 = new DezinfectantVirusuri(50000000, std::vector<std::string>({"Alkil Dimetilm Benzil Crlorura de amoniu", "parfumuri", "Butilpentil metilpropinal"}), std::vector<std::string>({"lemn", "sticla", "ceramica", "marmura"}));
    Dezinfectant* d3 = new DezinfectantFungi(1400000, std::vector<std::string>({"Alkil Etil Benzil Crlorura de amoniu", "parfumuri", "Butilpentil metilpropinal"}), std::vector<std::string>({"sticla", "plastic"}));
    std::cout << d1->eficienta() << " " << d2->eficienta() << " " << d3->eficienta();

    Achizitie* a1 = new Achizitie(26, 5, 2020, "PlushBio SRL");
    *a1 += mp1;
    *a1 += (&mc1);
    *a1 += d3;
    Achizitie* a2 = new Achizitie(25, 5, 2020, "Gucci");
    *a2 += d1;
    *a2 += d2;
    *a2 += d2;
    Achizitie a3, a4(*a1);
    a3 = *a2;


    std::vector<Achizitie*> achizitii;
    int operatie;
    //Meniu interactiv
    //Citeste si executa operatii, pentru a opri apasa 0 si enter
    while (std::cin >> operatie && operatie != 0)
    {
        switch (operatie) {
            case 1:
                op1(achizitii);
                break;

            case 2:
                op2(achizitii);
                break;

            case 3:
                op3(achizitii);
                break;

            case 4:
                op4(achizitii);
                break;

            case 5:
                op5(achizitii);
                break;

            case 6:
                op6(achizitii);
                break;

            case 7:
                op7(achizitii);
                break;

            case 8:
                op8(achizitii);
                break;

            case 9:
                op9(achizitii);
                break;

            case 10:
                op10(achizitii);
                break;

            default:
                std::cout << "Numarul nu conrespunde niciunei operatii";
        }
    }

    return 0;
}