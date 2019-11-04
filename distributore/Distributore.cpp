#include "Distributore.h"

Distributore::Nodo::Nodo():next(nullptr){}

Distributore::Nodo::Nodo(const Articolo& t, Nodo* s): info(t),next(s){}

bool Distributore::Vuota() const { return first == nullptr; }

void Distributore::Aggiungi_Molla(Molla t) {
    first = new Nodo(t,first); //aggiunge articolo in testa
}

void Distributore::Togli_Molla(Molla t) {
    Nodo* p= first, *prec=nullptr;
    while(p /*&& !(p->info==t)*/){  //todo opt== su articolo
        prec=p; p=p->next;
    }
    if(p){
        if(!prec)
            first=p->next;
        else
            prec->next=p->next;
        delete p;
    }
}

Molla Distributore::Estrai_Molla(){
//precondizione il distributoe non è vuoto
    Nodo* p= first;
    first = first->next;
    Molla aux = p->info; //costruttore di copia
    delete p;
    return aux;
}

Distributore::Nodo* Distributore::copia(Nodo* p){
if(!p) return nullptr;
return new Nodo(p->info, copia(p->next));
}

void Distributore::distruggi(Nodo* p) {
    if(p){
        distruggi(p->next);
        delete p;
    }
}

Distributore& Distributore::operator=(const Distributore& m) {
    if(this != &m){
        distruggi(first);
        first = copia(m.first);
    }
    return *this;
}

Distributore::~Distributore() {
    if(first) delete first;
}

Distributore::Distributore(const Distributore& m) : first(copia(m.first)) {}

Distributore::Nodo::~Nodo() {
    if(next != nullptr) delete next;
}

bool Distributore::Iteratore::operator==(Iteratore i) const {
    return punt==i.punt;
}

bool Distributore::Iteratore::operator!=(Iteratore i) const {
    return punt!=i.punt;
}

//incremento prefisso
Distributore::Iteratore& Distributore::Iteratore::operator++() {
    if(punt) punt=punt->next; //side-effect
    return *this;
}//NB se punt==0 non fa nulla

//incremento postfisso
Distributore::Iteratore Distributore::Iteratore::operator++(int) {
    Iteratore aux = *this;
    if(punt) punt=punt->next;
    return aux;
}

Distributore::Iteratore Distributore::begin() const{
    Iteratore aux;
    aux.punt = first; //per amicizia
    return aux;
}

Distributore::Iteratore Distributore::end() const{
    Iteratore aux;
    aux.punt = nullptr; //per amicizia
    return aux;
}

Molla& Distributore::operator[](Distributore::Iteratore it) const {
    return (it.punt)->info; //per amicizia
    //NB nessun controllo se i.punt != 0
}



