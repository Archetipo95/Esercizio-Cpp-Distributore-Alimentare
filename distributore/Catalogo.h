#ifndef CATALOGO_H
#define CATALOGO_H

#include <iostream>
#include "Articolo.h"

class Catalogo {
friend class Iteratore;
friend std::ostream& operator<<(std::ostream&, const Catalogo&);
private:
class Nodo {
  public:
    Articolo info;
    Nodo* next;

    Nodo(const Articolo& x=Articolo(), Nodo* p=nullptr):info(x),next(p){
    }
    ~Nodo();
    std::ostream& Stampa_Ric(std::ostream& os, int n){
        os<<n<<" "<<info<<"\n";
        if(next)next->Stampa_Ric(os,++n);
        return os;
    }
};//end class Nodo
    Nodo* first;    //puntatore al primo nodo della lista
    static Nodo* Copia(Nodo*);
    static void Distruggi(Nodo*);
    static int numeroArticoli;
public:

    class Iteratore {
        friend class Catalogo;
    private:
        Catalogo::Nodo* punt;      //nodo puntato dall'iteratore
    public:
        bool operator==(Iteratore) const;
        bool operator!=(Iteratore) const;
        Iteratore& operator++();    //operator++ prefisso
        Iteratore operator++(int);  //operator++ postfisso
    };//end class Iteratore
    Catalogo(): first(nullptr){}
    ~Catalogo(); //distruttore profondo
    Catalogo(const Catalogo&); //copia profonda
    Catalogo& operator=(const Catalogo&); //assegnazione profonda
    bool Vuota() const;
    void Aggiungi_Articolo(Articolo t);
    void Togli_Artiolo(Articolo t);
    Articolo Estrai_Articolo();
    void Svuota();
    //metodi che usano iteratore
    Iteratore begin() const;
    Iteratore end() const;
    Articolo& operator[](int) const;
    int getNumeroArticolo(){
        return numeroArticoli;
    }

};

std::ostream& operator<<(std::ostream&, const Catalogo&);

#endif // CATALOGO_H
