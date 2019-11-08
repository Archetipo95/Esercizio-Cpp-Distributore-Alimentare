#ifndef DISTRIBUTORE_H
#define DISTRIBUTORE_H

#include <iostream>
#include "Molla.h"


class Distributore
{
    friend class Iteratore;
    friend class Molla;
    friend std::ostream& operator<<(std::ostream&, const Distributore&);
private:
    class Nodo {
      public:
        Molla info;
        Nodo* next;
        //static int size_N;
        Nodo(const Molla& x=Molla(), Nodo* p=nullptr):info(x),next(p){}
        Nodo(int n, const Molla& x=Molla(), Nodo* p=nullptr):info(x),next(p){
            if(n!=0)
                next= new Nodo(n-1);
        }
        ~Nodo();
        static void insert_ric(const Articolo& t, int pos, Nodo& nod){
            if(nod.next==nullptr){
                nod.info.Aggiungi_Articolo(t);
            return;
            }
            if(pos==0) nod.info.Aggiungi_Articolo(t);
            else{
                insert_ric(t, pos-1,*(nod.next));
            }
        }
        std::ostream& print(std::ostream& os){
            os<<"START "<<info << "END";
            if(next){os<<std::endl; next->print(os); }
            return os;
        }
    };//end class Nodo
    Nodo* first;    //puntatore al primo nodo della lista
    static Nodo* copia(Nodo* p){
        if(!p) return nullptr;
        return new Nodo(p->info, copia(p->next));
        }
    static void distruggi(Nodo* p) {
        if(p){
            distruggi(p->next);
            delete p;
        }
    }

public:

    class Iteratore {
        friend class Distributore;
    private:
        Distributore::Nodo* punt;      //nodo puntato dall'iteratore
    public:
        bool operator==(Iteratore i) const {
            return punt==i.punt;
        }
        bool operator!=(Iteratore i) const {
            return punt!=i.punt;
        }
        //incremento prefisso
        Iteratore& operator++() {
            if(punt) punt=punt->next; //side-effect
            return *this;
        }//NB se punt==0 non fa nulla

        //incremento postfisso
        Iteratore operator++(int) {
            Iteratore aux = *this;
            if(punt) punt=punt->next;
            return aux;
        }
    };//end class Iteratore
    Distributore(int n){
        if(n>0)
            first = new Nodo(n-1);
        else
            return;
    }
    ~Distributore();
    Distributore(const Distributore&); //copia profonda
    Distributore& operator=(const Distributore&); //assegnazione profonda
    bool Vuota() const { return first == nullptr; }

    //metodi che usano iteratore
    Iteratore begin() const{
        Iteratore aux;
        aux.punt = first; //per amicizia
        return aux;
    }

    Iteratore end() const{
        Iteratore aux;
        aux.punt = nullptr; //per amicizia
        return aux;
    }

    Molla& operator[](Distributore::Iteratore it) const {
        return (it.punt)->info; //per amicizia
        //NB nessun controllo se i.punt != 0
    }

    //add container con iteratore per molle (maybe modulare)
    //matrice di molle
    void insert(Articolo& t, int pos){
        first->insert_ric(t,pos,*first);
    }
};

std::ostream& operator<<(std::ostream&, const Distributore&);

#endif // DISTRIBUTORE_H
