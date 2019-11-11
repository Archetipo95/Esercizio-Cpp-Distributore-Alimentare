#ifndef MOLLA_H
#define MOLLA_H

#include <iostream>
#include "Articolo.h"

class Molla {
friend class Iteratore;
friend class Distributore;
friend std::ostream& operator<<(std::ostream&, const Molla&);
private:
class Nodo {
  public:
    Articolo info;
    Nodo* next;


    Nodo(const Articolo& x=Articolo(), Nodo* p=nullptr):info(x),next(p){
    }
    ~Nodo();
    std::ostream& Stampa_Ric(std::ostream& os){
        os<<info<<"-";
        if(next)next->Stampa_Ric(os);
        return os;
    }
};//end class Nodo
    Nodo* first;    //puntatore al primo nodo della lista
    static Nodo* Copia(Nodo*);
    static void Distruggi(Nodo*);


public:
 int capacitaMolla=10;
    class Iteratore {
        friend class Molla;
    private:
        Molla::Nodo* punt;      //nodo puntato dall'iteratore
    public:
        bool operator==(Iteratore) const;
        bool operator!=(Iteratore) const;
        Iteratore& operator++();    //operator++ prefisso
        Iteratore operator++(int);  //operator++ postfisso
    };//end class Iteratore
    Molla(): first(nullptr){}
    ~Molla(); //distruttore profondo
    Molla(const Molla&); //copia profonda
    Molla& operator=(const Molla&); //assegnazione profonda
    bool Vuota() const;
    void Aggiungi_Articolo(Articolo t);
    void Togli_Artiolo(Articolo t);
    Articolo Estrai_Articolo();
    void Svuota();
    //metodi che usano iteratore
    Iteratore begin() const;
    Iteratore end() const;
    Articolo& operator[](Iteratore) const;

};

std::ostream& operator<<(std::ostream&, const Molla&);

#endif // MOLLA_H
