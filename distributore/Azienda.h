#ifndef AZIENDA_H
#define AZIENDA_H


#include <iostream>
#include "Distributore.h"


class Azienda
{
    friend class Iteratore;
    friend std::ostream& operator<<(std::ostream&, const Azienda&);
private:
    class Nodo {
      public:
        Distributore info;
        Nodo* next;
        static int size_N;
        Nodo(const Distributore& x, Nodo* p=nullptr):info(x),next(p){}
        /*Nodo(int n, const Distributore& x=Distributore(), Nodo* p=nullptr):info(x),next(p){
            if(n!=0)
                next= new Nodo(n-1);
        }*/
        ~Nodo();
        std::ostream& Stampa_Ric(std::ostream& os){
            os << info;
            if(next){ os << std::endl; next->Stampa_Ric(os); }
            return os;
        }
    };//end class Nodo
    Nodo* first;    //puntatore al primo nodo della lista

    static Nodo* Copia(Nodo* p){
        if(!p) return nullptr;
        return new Nodo(p->info, Copia(p->next));
        }
    static void Distruggi(Nodo* p) {
        if(p){
            Distruggi(p->next);
            delete p;
        }
    }

public:

    class Iteratore {
        friend class Azienda;
    private:
        Azienda::Nodo* punt;      //nodo puntato dall'iteratore
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
    Azienda():first(nullptr){}
    ~Azienda();
    Azienda(const Azienda&); //copia profonda
    Azienda& operator=(const Azienda&); //assegnazione profonda
    bool Vuota() const { return first == nullptr; }

    int getSize(){
        return first->size_N;
    }

    void Aggiungi_Distributore(int n, string s){
        Distributore dis(n,s);
        if(first==nullptr) {first= new Nodo(dis);}
        else{ first= new Nodo(dis,first);}
    }

    void Rimuovi_Distributore(int n){
        if(first && !first->next){
            delete first;
            first=nullptr;
        }else if(first){
            Nodo* aux=first;
            Nodo* prec=nullptr;
            for(int i=0;i<n || !aux;i++){
                prec=aux;
                aux=aux->next;
            }
            //deve eliminare aux
            std::cout << aux->info;
            prec->next=aux->next;
            aux->next=nullptr;
            delete aux;
        }
    }

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

    Distributore& operator[](Azienda::Iteratore it) const {
        return (it.punt)->info; //per amicizia
        //NB nessun controllo se i.punt != 0
    }
};

std::ostream& operator<<(std::ostream&, const Azienda&);


#endif // AZIENDA_H
