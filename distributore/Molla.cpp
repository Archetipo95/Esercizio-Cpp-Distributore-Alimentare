#include "Molla.h"

Molla::Nodo* Molla::copia(Nodo* p){
if(!p) return nullptr;
return new Nodo(p->info, copia(p->next));
}

void Molla::distruggi(Nodo* p) {
    if(p){
        distruggi(p->next);
        delete p;
    }
}

Molla& Molla::operator=(const Molla& m) {
    if(this != &m){
        distruggi(first);
        first = copia(m.first);
    }
    return *this;
}

Molla::~Molla() {
    if(first) delete first;
}

Molla::Molla(const Molla& m) : first(copia(m.first)) {}

Molla::Nodo::~Nodo() {
    if(next != nullptr) delete next;
}

bool Molla::Iteratore::operator==(Iteratore i) const {
    return punt==i.punt;
}

bool Molla::Iteratore::operator!=(Iteratore i) const {
    return punt!=i.punt;
}

//incremento prefisso
Molla::Iteratore& Molla::Iteratore::operator++() {
    if(punt) punt=punt->next; //side-effect
    return *this;
}//NB se punt==0 non fa nulla

//incremento postfisso
Molla::Iteratore Molla::Iteratore::operator++(int) {
    Iteratore aux = *this;
    if(punt) punt=punt->next;
    return aux;
}

Molla::Iteratore Molla::begin() const{
    Iteratore aux;
    aux.punt = first; //per amicizia
    return aux;
}

Molla::Iteratore Molla::end() const{
    Iteratore aux;
    aux.punt = nullptr; //per amicizia
    return aux;
}

Articolo& Molla::operator[](Molla::Iteratore it) const {
    return (it.punt)->info; //per amicizia
    //NB nessun controllo se i.punt != 0
}



