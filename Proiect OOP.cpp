#include <iostream>
#include <string.h>
#include <ctype.h>
#include <vector>
#include <list>
#include <fstream>

using namespace std;

class Supermarket
{
private:
    const char nume_supermarket[15] = "Sultani";
    bool deschis;
    float lei_sapt;
    float* lei_zi;
    string nume_patron;
    char prenume_patron[15];

public:
    const char* getNumeSupermarket(){return this->nume_supermarket;}

    void setDeschis(bool deschis)
    {this->deschis = deschis;}
    bool getDeschis()
    {return this->deschis;}

    void setLeisapt(float lei_sapt)
    {this->lei_sapt = lei_sapt;}
    float getLeisapt()
    {return this->lei_sapt;}

    void setLeizi(float* a)
    {
        if(this->lei_zi!=nullptr)
            delete[] this->lei_zi;
        this->lei_zi = new float[7];
        for(int i=0; i<7; i++)
            this->lei_zi[i]=a[i];
    }
    float* getLeizi()
    {return this->lei_zi;}

    void setNumePatron(string nume_patron)
    {this->nume_patron = nume_patron;}
    string getNumePatron()
    {return this->nume_patron;}

    void setPrenumePatron(char prenume_patron[15])
    {strcpy(this->prenume_patron,prenume_patron);}
    char* getPrenumePatron()
    {return this->prenume_patron;}

    //functia de afisare
    void afisare()
    {
        if(deschis==0)
            cout<<"Bine ati venit la "<<this->nume_supermarket<<", momentan este inchis, va asteptam maine.";
            else
            cout<<"Bine ati venit la "<<this->nume_supermarket;
    }


    //constructor cu parametri
    Supermarket(bool deschis, float lei_sapt, string nume_patron, char prenume_patron[]):nume_supermarket("Sultani")
    {
        this->deschis=deschis;
        this->lei_sapt=lei_sapt;
        this->nume_patron=nume_patron;
        strcpy(this->prenume_patron,prenume_patron);
    }

    //constructorul 2
    Supermarket(bool deschis, float lei_sapt):nume_supermarket("Sultani")
    {
        this->deschis=deschis;
        this->lei_sapt=lei_sapt;
        this->nume_patron='-';
        strcpy(this->prenume_patron,"");
    }

    //copy constructor
    Supermarket(const Supermarket &ob):nume_supermarket("Sultani")
    {
        this->deschis=ob.deschis;
        this->lei_sapt=ob.lei_sapt;
        this->nume_patron=ob.nume_patron;
        strcpy(this->prenume_patron,ob.prenume_patron);
    }

       //constructor fara parametri
    Supermarket():nume_supermarket("Sultani")
    {
        this->deschis=0;
        this->lei_sapt=0;
        this->nume_patron='-';
        strcpy(this->prenume_patron,"-");
    }

    //operatorul =
    Supermarket &operator=(const Supermarket &ob)
    {
    if(this!=&ob)
    {
        this->deschis=ob.deschis;
        this->lei_sapt=ob.lei_sapt;
        this->nume_patron=ob.nume_patron;
        strcpy(this->prenume_patron,ob.prenume_patron);
    }
    return *this;
    }

    //operatorul de citire
    friend istream &operator>>(istream &in, Supermarket &ob)
    {
        cout<<"Introduceti daca este deschis(0=inchis, 1=deschis):";
        in>>ob.deschis;
        if(ob.deschis==0)
        {
            cout<<"Supermarketul este inchis";
            exit(0);
        }
        cout<<"Introduceti numele patronului:";
        in>>ob.nume_patron;
        cout<<"Introduceti prenumele patronului:";
        in>>ob.prenume_patron;
        cout<<"Introduceti cati lei s-au incasat aceasta saptamana:";
        in>>ob.lei_sapt;
        return in;
    }

    //operatorul de afisare
    friend ostream &operator<<(ostream &out, const Supermarket &ob)
    {
        out<<"Numele supermarketului este:"<<ob.nume_supermarket<<", acesta este deschis, saptamana aceasta s-au incasat:"<<ob.lei_sapt<<" lei. Numele patronului este:"<<ob.nume_patron<<". Prenumele patronului este:"<<ob.prenume_patron<<".";
        return out;
    }
    //functionalitate
    void functionalitate()
    {
        cout<<"Target-ul zilnic este: ";
        float target;
        int target_atins=0;
        cin>>target;
       // if(lei_zi!=nullptr)
            //delete[] lei_zi;
    lei_zi=new float[7];
        for(int i=0;i<7;i++)
            {
                cout<<"Introduceti cati lei s-au incasat astazi: ";
                cin>>lei_zi[i];
            }
        for(int i=0;i<7;i++)
        {
            if(lei_zi[i]>=target)
                target_atins++;
        }
        cout<<"S-a atins target-ul de "<<target_atins<<" ori.";
    }

    //operator de indexare
    char operator [](int i)
    {
        if ((i<strlen(prenume_patron))&& i>0)
            return this->prenume_patron[i];
        else
        {
            cout<<"Nu am gasit index.";
            return -1;
        }
    }

    //operator ++ pre
    const Supermarket operator++()
    {
        this->lei_sapt++;
        return *this;
    }

    //operator ++ post
    const Supermarket operator++(int)
    {
        this->lei_sapt++;
        return *this;
    }

    //operator +
    Supermarket operator+(int a)
    {
        this->lei_sapt+=a;
        return *this;
    }

    //operator *
    Supermarket operator*(int a)
    {
        this->lei_sapt*=a;
        return *this;
    }

    //operator cast explicit
    explicit operator int()
    {
        return (int)this->lei_sapt;
    }

    // operator conditional <
    bool operator<(Supermarket &ob)
    {
        return this->lei_sapt<ob.lei_sapt;
    }

    // operator conditional ==
    bool operator==(Supermarket &ob)
    {
        return this->lei_sapt==ob.lei_sapt;
    }

    //destructor
    ~Supermarket()
    {
        if(this->lei_zi!=nullptr)
            delete[] this->lei_zi;
    }

};


class Angajati
{
private:
    char* nume_angajat;
    char prenume_angajat[15];
    char gen;
    int varsta;
    bool lucreaza_acum;
    int numar_angajati;
    const int cod_angajat;
    float salariu;

public:
    void setNumeAngajat(char* nume_angajat)
    {
        if(this->nume_angajat!=nullptr)
            delete[] this->nume_angajat;
        this->nume_angajat=new char[strlen(nume_angajat)+1];
        strcpy(this->nume_angajat, nume_angajat);

    }
    char* getNumeAngajat()
    {return this->nume_angajat;}

    void setPrenumeAngajat(char prenume_angajat[15])
    {strcpy(this->prenume_angajat,prenume_angajat);}
    char* getPrenumeAngajat()
    {return this->prenume_angajat;}


    void setGen(char gen)
    {this->gen=gen;}
    char getGen()
    {return this->gen;}

    void setVarsta(int varsta)
    {this->varsta=varsta;}
    int getVarsta()
    {return this->varsta;}

    void setLucreazaAcum(bool lucreaza_acum)
    {this->lucreaza_acum=lucreaza_acum;}
    bool getLucreazaAcum()
    {return this->lucreaza_acum;}

    const int getCodAngajat()
    {return this->cod_angajat;}

    void setSalariu(float salariu)
    {this->salariu=salariu;}
    float getSalariu()
    {return this->salariu;}

    //functia de afisare
    void afisare()
    {
        if(lucreaza_acum==0)
            cout<<"Angajatul "<<nume_angajat<<" "<<prenume_angajat<<" nu lucreaza acum.";
            else
            cout<<"Angajatul "<<nume_angajat<<" "<<prenume_angajat<<" lucreaza acum.";
    }



    //constructor cu parametri
    Angajati(char* nume_angajat, char prenume_angajat[15], char gen, int varsta, bool lucreaza_acum, float salariu):cod_angajat(1234)
    {
        strcpy(this->nume_angajat,nume_angajat);
        strcpy(this->prenume_angajat,prenume_angajat);
        this->gen=gen;
        this->varsta=varsta;
        this->lucreaza_acum=lucreaza_acum;
        this->salariu=salariu;
    }

    //constructorul 2
    Angajati(char gen, char varsta, bool lucreaza_acum, float salariu):cod_angajat(1234)
    {
        this->gen=gen;
        this->varsta=varsta;
        this->lucreaza_acum=lucreaza_acum;
        this->salariu=salariu;
    }


    //copy constructor
    Angajati(const Angajati &ob):cod_angajat(1234)
    {
        strcpy(this->nume_angajat,ob.nume_angajat);
        strcpy(this->prenume_angajat,ob.prenume_angajat);
        this->gen=ob.gen;
        this->varsta=ob.varsta;
        this->lucreaza_acum=ob.lucreaza_acum;
        this->salariu=ob.salariu;
    }

    //constructor fara parametri
    Angajati():cod_angajat(1234)
    {
        this->lucreaza_acum=0;
        this->nume_angajat=new char [20];
        strcpy(this->nume_angajat, "-");
        strcpy(this->prenume_angajat,"-");
        this->numar_angajati=100;
    }


    //operator =
    Angajati &operator=(const Angajati &ob)
    {
        if(this!=&ob)
        {
            this->lucreaza_acum=ob.lucreaza_acum;
            this->nume_angajat=new char [20];
            strcpy(this->nume_angajat, ob.nume_angajat);
            strcpy(this->prenume_angajat, ob.prenume_angajat);
            this->numar_angajati=ob.numar_angajati;
        }
        return *this;
    }

    //operatorul de citire
    friend istream &operator>>(istream &in, Angajati &ob)
    {
        cout<<"Introduceti daca angajatul lucreaza acum(0=nu lucreaza, 1=lucreaza):";
        in>>ob.lucreaza_acum;
        if(ob.lucreaza_acum==0)
        {
            cout<<"Angajatul nu lucreaza acum.";
            exit(0);
        }
        cout<<"Introduceti numele angajatului:";
        in>>ob.nume_angajat;
        cout<<"Introduceti prenumele angajatului:";
        in>>ob.prenume_angajat;
        cout<<"Introduceti salariul angajatului:";
        in>>ob.salariu;
    return in;
    }

        //citire din fisier
    friend ifstream &operator>>(ifstream &in, Angajati &ob)
    {
        in>>ob.lucreaza_acum;
        if(ob.lucreaza_acum==0)
        {
            exit(0);
        }
        in>>ob.nume_angajat;
        in>>ob.prenume_angajat;
        in>>ob.salariu;
        return in;
    }


    //operatorul de afisare
    friend ostream &operator<<(ostream &out, const Angajati &ob)
    {
        out<<"Numele angajatului este:"<<ob.nume_angajat<<" "<<ob.prenume_angajat<<" si acesta are un salariu de "<<ob.salariu<<" lei pe luna.";
        return out;
    }


  //afisare din fisier
    friend ofstream &operator<<(ofstream &out, const Angajati &ob)
    {
        out<<"Numele angajatului este:"<<ob.nume_angajat<<" "<<ob.prenume_angajat<<" si acesta are un salariu de "<<ob.salariu<<" lei pe luna.";
        return out;
    }


    //functionalitate
    void functionalitate()
    {
        cout<<"Se citeste numarul de angajati: ";
        cin>>numar_angajati;
        float salariu_mare;
        cout<<"Introduceti salariul la care ne raportam: ";
        cin>>salariu_mare;
        int salariu_atins=0;
        float* salarii_angajati;
        salarii_angajati=new float[numar_angajati];
        for(int i=0;i<numar_angajati;i++)
            {
                cout<<"Introduceti salariul angajatului "<<i+1<<": ";
                cin>>salarii_angajati[i];
                if(salarii_angajati[i]>salariu_mare)
                    salariu_atins++;
            }

            cout<<"Avem un numar de "<<salariu_atins<<" angajati care au un salariu de peste "<<salariu_mare<<".";


    }

    void citire()
    {
        char copie[20];
        cout<<"Citim numele angajatului:";
        cin>>copie;
        if(nume_angajat!=nullptr)
            delete[]nume_angajat;
        nume_angajat=new char[strlen(copie)+1];
        strcpy(nume_angajat, copie);
        cout<<"Prenumele angajatului este:";
        cin>>prenume_angajat;
        cout<<"Varsta angajatului este:";
        cin>>varsta;
        cout<<"Salariul angajatului este:";
        cin>>salariu;
    }



    //operator de indexare
    char operator [](int i)
    {
        if ((i<strlen(prenume_angajat))&& i>0)
            return this->prenume_angajat[i];
        else
        {
            cout<<"Nu am gasit index.";
            return -1;
        }
    }

    //operator ++ pre
    const Angajati operator++()
    {
        this->varsta++;
        return *this;
    }

    //operator ++ post
    const Angajati operator++(int)
    {
        this->varsta++;
        return *this;
    }

    //operator +
    Angajati operator+(int a)
    {
        this->varsta +=a;
        return *this;
    }

    //operator *
    Angajati operator*(int a)
    {
        this->varsta*=a;
        return *this;
    }

    //operator cast explicit
    explicit operator int()
    {
        return (int)this->varsta;
    }

    // operator conditional <
    bool operator<(Angajati &ob)
    {
        return this->varsta<ob.varsta;
    }

    // operator conditional ==
    bool operator==(Angajati &ob)
    {
        return this->varsta==ob.varsta;
    }

    //destructor
    ~Angajati()
    {
        if(this->nume_angajat!=nullptr)
            delete[] this->nume_angajat;
    }
};

class Casa
{
private:
    const int cod_bare;
    char* nume_produs;
    int pret_produs;
    float lei_incasati;
    int produse_vandute;
    char numar_casa;
    bool functionala;

public:
    int getCodBare()
    {return this->cod_bare;}

    void setNumeProdus(char* nume_produs)
    {
        if(this->nume_produs!=nullptr)
            delete[] this->nume_produs;
        this->nume_produs=new char[strlen(nume_produs)+1];
        strcpy(this->nume_produs, nume_produs);
    }

    void setPretProdus(int pret_produs)
    {this->pret_produs=pret_produs;}
    int getPretProdus()
    {return this->pret_produs;}

    void setLeiIncasati(float lei_incasati)
    {this->lei_incasati=lei_incasati;}
    float getLeiIncasati()
    {return this->lei_incasati;}

    void setProduseVandute(int produse_vandute)
    {this->produse_vandute=produse_vandute;}
    int getProduseVandute()
    {return this->produse_vandute;}

    void setNumarCasa(char numar_casa)
    {this->numar_casa=numar_casa;}
    char getNumarCasa()
    {return this->numar_casa;}

    void setFunctionala(bool functionala)
    {this->functionala=functionala;}
    bool getFunctionala()
    {return this->functionala;}

    //functia de afisare
    void afisare()
    {
        if(functionala==0)
            cout<<"Casa nu este functionala.";
            else
            cout<<"Casa este functionala.";
    }

    //constructor cu parametri
    Casa(char* nume_produs, int pret_produs, float lei_incasati, int produse_vandute, char numar_casa, bool functionala):cod_bare(1234)
    {
        strcpy(this->nume_produs, nume_produs);
        //this->pret_produs= new int;
        this->pret_produs=pret_produs;
        this->lei_incasati=lei_incasati;
        this->produse_vandute=produse_vandute;
        this->numar_casa=numar_casa;
        this->functionala=functionala;
    }

    //constructorul 2
    Casa(char* nume_produs, int pret_produs, float lei_incasati, bool functionala):cod_bare(1234)
    {
        strcpy(this->nume_produs, nume_produs);
        this->pret_produs=pret_produs;
        this->lei_incasati=lei_incasati;
        this->functionala=functionala;
    }

    //copy constructor
    Casa(const Casa &ob):cod_bare(1234)
    {
        this->nume_produs=new char [20];
        strcpy(this->nume_produs, ob.nume_produs);
        this->pret_produs=ob.pret_produs;
        this->lei_incasati=ob.lei_incasati;
        this->produse_vandute=ob.produse_vandute;
        this->numar_casa=ob.numar_casa;
        this->functionala=ob.functionala;
    }

    //constructor fara parametri
    Casa():cod_bare(1234)
    {
        this->functionala=0;
        this->nume_produs=new char [20];
        strcpy(this->nume_produs, "-");
        this->produse_vandute=100;
    }

    //operator =
    Casa &operator=(const Casa &ob)
    {
        if(this!=&ob)
        {
            strcpy(this->nume_produs, ob.nume_produs);
            this->pret_produs=ob.pret_produs;
            this->lei_incasati=ob.lei_incasati;
            this->produse_vandute=ob.produse_vandute;
            this->numar_casa=ob.numar_casa;
            this->functionala=ob.functionala;
        }
        return *this;
    }

    //operatorul de citire
    friend istream &operator>>(istream &in, Casa &ob)
    {
        cout<<"Introduceti daca casa este functionala acum(0=nu este functionala, 1=este functionala):";
        in>>ob.functionala;
        if(ob.functionala==0)
        {
            cout<<"Casa nu este functionala.";
            exit(0);
        }
    cout<<"Introduceti numele produsului:";
    in>>ob.nume_produs;
    cout<<"Introduceti pretul produsului:";
    in>>ob.pret_produs;

    }

    //operatorul de afisare
    friend ostream &operator<<(ostream &out, const Casa &ob)
    {
        out<<"Numele produsului este:"<<ob.nume_produs<<" si pretul acestuia este "<<ob.pret_produs<<" lei.";
        return out;
    }

    //functionalitate
    void functionalitate()
    {
        cout<<"Se citeste numele produsului cautat: ";
        cin>>nume_produs;
        int contor=0, produse_totale;
        cout<<"Cate produse s-au vandut in total: ";
        cin>>produse_totale;
        string produs;
        for(int i=0; i<produse_totale; i++)
        {
            cout<<"Se citeste numele produsului: ";
            cin>>produs;
            if(nume_produs==produs)
                contor++;
        }
        cout<<"Produsul pe care il cautam s-a vandut de "<<contor<<" ori.";
    }


    //operator de indexare
    char operator [](int i)
    {
        if((i<strlen(nume_produs))&& i>0)
            return this->nume_produs[i];
        else
        {
            cout<<"Nu am gasit produsul.";
            return -1;
        }
    }

    //operator ++ pre
    const Casa operator++()
    {
        this->pret_produs++;
        return *this;
    }

    //operator ++ post
    const Casa operator++(int)
    {
        this->pret_produs++;
        return *this;
    }

    //operator +
    Casa operator+(int a)
    {
        this->pret_produs +=a;
        return *this;
    }

    //operator *
    Casa operator*(int a)
    {
        this->pret_produs*=a;
        return *this;
    }

    //operator cast explicit
    explicit operator int()
    {
        return (int)this->pret_produs;
    }

    // operator conditional <
    bool operator<(Casa &ob)
    {
        return this->pret_produs<ob.pret_produs;
    }

    // operator conditional ==
    bool operator==(Casa &ob)
    {
        return this->pret_produs==ob.pret_produs;
    }

    //destructor
    ~Casa()
    {
        if(this->nume_produs!=nullptr)
            delete[] this->nume_produs;
    }

};




class Produse
{
private:
    const int cod_bare;
    char* nume_produs;
    float pret_produs;
    bool stoc;
    string descriere;
    int bucati_produs;
public:
    virtual float pret_marfa_vanduta()=0;


    void setBucatiProdus(int bucati_produs)
    {this->bucati_produs=bucati_produs;}
    int getBucatiProdus()
    {return this->bucati_produs;}

    void setPretProdus(float pret_produs)
    {this->pret_produs=pret_produs;}
    float getPretProdus()
    {return this->pret_produs;}



    //functia de afisare
    void afisare()
    {
        if(stoc==0)
            cout<<"Produsul nu este in stoc.";
        else
            cout<<"Produsul este in stoc.";
    }

    //constructor cu parametri
    Produse(char* nume_produs, float pret_produs, bool stoc, string descriere, int bucati_produs):cod_bare(1234)
{
    this->nume_produs=new char[strlen(nume_produs)+1];
    strcpy(this->nume_produs, nume_produs);
    this->pret_produs=pret_produs;
    this->stoc=stoc;
    this->descriere=descriere;
    this->bucati_produs=bucati_produs;
}

    //constructorul 2
    Produse(float pret_produs, bool stoc, int bucati_produs):cod_bare(1234)
    {
    this->pret_produs=pret_produs;
    this->stoc=stoc;
    this->bucati_produs=bucati_produs;
    }

    //copy constructor
    Produse(const Produse &ob):cod_bare(1234)
    {
    this->nume_produs=new char[strlen(ob.nume_produs)+1];
    strcpy(this->nume_produs, ob.nume_produs);
    this->pret_produs=ob.pret_produs;
    this->stoc=ob.stoc;
    this->descriere=ob.descriere;
    this->bucati_produs=ob.bucati_produs;
    }

    //constructor fara parametri
    Produse():cod_bare(1234)
    {
        this->pret_produs=10;
        this->stoc=0;
        this->bucati_produs=100;
        this->nume_produs=new char [20];
        strcpy(this->nume_produs, "-");
    }

    //operator =
    Produse &operator=(const Produse &ob)
    {
        if(this!=&ob)
        {
            this->pret_produs=ob.pret_produs;
            this->stoc=ob.stoc;
            this->bucati_produs=ob.bucati_produs;
            strcpy(this->nume_produs, ob.nume_produs);
        }
    }

    //operatorul de citire
    friend istream &operator>>(istream &in, Produse &ob)
    {
        cout<<"Introduceti daca produsul este in stoc(0=nu este in stoc, 1=este in stoc):";
        in>>ob.stoc;
        if(ob.stoc==0)
        {
            cout<<"Produsul nu este in stoc.";
            exit(0);
        }
        cout<<"Introduceti numele produsului:";
        in>>ob.nume_produs;
        cout<<"Introduceti pretul produsului:";
        in>>ob.pret_produs;
        cout<<"Introduceti cate bucati din produsul ales sunt:";
        in>>ob.bucati_produs;
    }

    //operatorul de afisare
       friend ostream &operator<<(ostream &out, const Produse &ob)
       {
        out<<"Numele produsului este: "<<ob.nume_produs<<", pretul acestuia este:"<<ob.pret_produs<<" lei, si avem "<<ob.bucati_produs<<" de bucati disponibile.";
        return out;
       }

       //functionalitate
       void functionalitate()
       {
        cout<<"Se citeste numele produsului cautat:";
        cin>>nume_produs;
        int contor=0, produse_stoc;
        cout<<"Cate produse s-au vandut in total:";
        cin>>produse_stoc;
        string produs;
        for(int i=0; i<produse_stoc; i++)
        {
            cout<<"Se citeste numele produsului:";
            cin>>produs;
            if(nume_produs==produs)
                contor++;
        }
        cout<<"Produsul pe care il cautam este disponibil de "<<contor<<" ori in stoc.";

       }




    //destructor
    ~Produse()
    {
        if(this->nume_produs!=nullptr)
            delete[] this->nume_produs;
    }




};


















    //etapa 2


class Taxe
{
public:
    virtual float impozit() = 0;
};


// HAS A
class Manager:public Angajati, public Taxe
{
private:
    int angajati_subordonati;
   vector<Angajati> vector;
public:
    void setAngajatiSubordonati(int angajati_subordonati)
    {this->angajati_subordonati=angajati_subordonati;}

    void setAngajati()
    {
        for(int i=0; i<angajati_subordonati; i++)
        {
            Angajati x;
            x.citire();
            vector.push_back(x);
        }
    }

    void afisareNumeAngajati(int i)
    {
        cout<<vector.at(i).getNumeAngajat()<<" "<<vector.at(i).getPrenumeAngajat();
    }

    void afisareManager()
    {
        cout<<"Managerul '"<<getNumeAngajat()<<" "<<getPrenumeAngajat()<<" are acesti subordonati:"<<endl;
    }

    float impozit()
    {
        return (getSalariu()-(19*getSalariu())/100);
    }
};
class Depozit:public Produse
{
private:
    int marfa_totala;
public:
    void citesteMarfaTotala()
    {
        cout<<"Marfa totala:";
        cin>>marfa_totala;
    }

    void citesteMarfaVanduta()
    {
        int a;
        cout<<"Cata marfa a ramas:";
        cin>>a;
        setBucatiProdus(a);
    }

    void citestePret()
    {
        float a;
        cout<<"Pret produs:";
        cin>>a;
        setPretProdus(a);
    }

    float pret_marfa_vanduta()
    {
        return (getPretProdus()*(marfa_totala-getBucatiProdus()));
    }
};

class ProdusComestibil:public Produse
{
private:
    int valabilitate;
public:
    float pret_marfa_vanduta(){}
    friend istream &operator>>(istream &in, ProdusComestibil &ob)
    {
        in>>(Produse&)ob;
        cout<<"Introduceti valabilitatea(zile):";
        in>>ob.valabilitate;
        return in;
    }
    friend ostream &operator<<(ostream &out, const ProdusComestibil &ob)
    {
        out<<(Produse&)ob;
        cout<<"De asemenea are o valabilitate de "<<ob.valabilitate<<" zile.";
        return out;
    }
};






  /* ifstream fin("angajati.in"); din fisier
        ofstream fout("angajati.out");
        Angajati a;
        fin>>a;
        fout<<a; */









int main()
{

//meniu

int optiune1, optiune2, optiune3, optiune4, optiune5;

list <ProdusComestibil> lista;
cout<<"Bine ati venit la Supermarketul Sultani"<<endl;
do
    {
    cout<<"Meniu principal"<<endl;
    cout<<"1-Supermarket"<<endl;
    cout<<"2-Angajati"<<endl;
    cout<<"3-Casa"<<endl;
    cout<<"4-Produse"<<endl;
    cout<<"5-Iesire"<<endl;
    cout<<"Alege o optiune:";
    cin>>optiune1;
    switch(optiune1)
    {
        case 1:
        {
            do
            {
                cout<<"Supermarket"<<endl;
                cout<<"1-Functionalitate Supermarket"<<endl;
                cout<<"2-Inapoi"<<endl;
                cout<<"Alege o optiune:";
                cin>>optiune2;
                switch(optiune2)
                {
                    case 1:
                    {
                        char inapoi;
                        Supermarket functionalitate;
                        functionalitate.functionalitate();
                        cout<<endl<<"Apasati orice tasta pentru a reveni la meniul anterior.";
                        cin>>inapoi;
                        break;

                    }
                }


            } while(optiune2!=2);
            break;
        }
        case 2:
        {
            do
            {
                cout<<"Angajati"<<endl;
                cout<<"1-Functionalitate Angajati"<<endl;
                cout<<"2-Inapoi"<<endl;
                cout<<"Alege o optiune:";
                cin>>optiune3;
                switch(optiune3)
                {
                    case 1:
                    {
                        char inapoi;
                        Angajati functionalitate;
                        functionalitate.functionalitate();
                        cout<<endl<<"Apasati orice tasta pentru a reveni la meniul anterior.";
                        cin>>inapoi;
                        break;

                    }
                }


            } while(optiune3!=2);
            break;
        }
        case 3:
        {
            do
            {
                cout<<"Casa"<<endl;
                cout<<"1-Functionalitate Casa"<<endl;
                cout<<"2-Inapoi"<<endl;
                cout<<"Alege o optiune:";
                cin>>optiune4;
                switch(optiune4)
                {
                    case 1:
                    {
                        char inapoi;
                        Casa functionalitate;
                        functionalitate.functionalitate();
                        cout<<endl<<"Apasati orice tasta pentru a reveni la meniul anterior.";
                        cin>>inapoi;
                        break;

                    }
                }


            } while(optiune4!=2);
            break;
        }
        case 4:
        {
            do
            {
                cout<<"Produse"<<endl;
                cout<<"1-Functionalitate Produse"<<endl;
                cout<<"2-Adauga produs"<<endl;
                cout<<"3-Afiseaza produs"<<endl;
                cout<<"4-Inapoi"<<endl;
                cout<<"Alege o optiune:";
                cin>>optiune5;
                switch(optiune5)
                {
                    case 1:
                    {
                        char inapoi;
                        ProdusComestibil functionalitate;
                        functionalitate.functionalitate();
                        cout<<endl<<"Apasati orice tasta pentru a reveni la meniul anterior.";
                        cin>>inapoi;
                        break;

                    }

                    case 2:
                    {
                        char inapoi;
                        ProdusComestibil x;
                        cin>>x;
                        lista.push_back(x);
                        cout<<"Am adaugat produsul.";
                        cout<<endl<<"Apasati orice tasta pentru a reveni la meniul anterior.";
                        cin>>inapoi;
                        break;
                    }
                    case 3:
                    {
                        for(auto i=lista.begin(); i!=lista.end(); i++)
                        {
                            cout<<(*i);

                        }
                        break;
                    }
                }


            } while(optiune5!=4);
            break;
        }

    }


    }
    while(optiune1!=5);


        return 0;

}




