#ifndef DISTRIBUTORE_H
#define DISTRIBUTORE_H

#include "Molla.h"


class Distributore
{
    friend class Iteratore;
private:
    class Nodo {
      public:
        Molla info;
        Nodo* next;
        Nodo();
        Nodo(const Molla& x, Nodo* p):info(x),next(p){}
        ~Nodo();
    };//end class Nodo
    Nodo* first;    //puntatore al primo nodo della lista
    static Nodo* copia(Nodo*);
    static void distruggi(Nodo*);
public:
    class Iteratore {
        friend class Distributore;
    private:
        Distributore::Nodo* punt;      //nodo puntato dall'iteratore
    public:
        bool operator==(Iteratore) const;
        bool operator!=(Iteratore) const;
        Iteratore& operator++();    //operator++ prefisso
        Iteratore operator++(int);  //operator++ postfisso
    };//end class Iteratore
    Distributore(): first(nullptr){}
    ~Distributore();
    Distributore(const Distributore&); //copia profonda
    Distributore& operator=(const Distributore&); //assegnazione profonda
    bool Vuota() const;
    void Aggiungi_Molla(Molla t);
    void Togli_Molla(Molla t);
    Molla Estrai_Molla();

    //metodi che usano iteratore
    Iteratore begin() const;
    Iteratore end() const;
    Molla& operator[](Iteratore) const;

    //add container con iteratore per molle (maybe modulare)
    //matrice di molle

};

#endif // DISTRIBUTORE_H
