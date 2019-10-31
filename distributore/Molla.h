#ifndef MOLLA_H
#define MOLLA_H

#include "Articolo.h"

class Molla {
friend class Iteratore;
private:
class Nodo {
  public:
    Articolo info;
    Nodo* next;
    Nodo();
    Nodo(const Articolo& x, Nodo* p):info(x),next(p){}
    ~Nodo();
};//end class Nodo
    Nodo* first;    //puntatore al primo nodo della lista
    static Nodo* copia(Nodo*);
    static void distruggi(Nodo*);
public:
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
    Articolo Estrai_Una();
    //metodi che usano iteratore
    Iteratore begin() const;
    Iteratore end() const;
    Articolo& operator[](Iteratore) const;
};

#endif // MOLLA_H
