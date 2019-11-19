#include "Catalogo.h"

int Catalogo::numeroArticoli=0;

bool Catalogo::Vuota() const { return first == nullptr; }

//aggiunge articolo in coda
void Catalogo::Aggiungi_Articolo(Articolo t) {
    if(!first) first = new Nodo(t,first);
    else{
       Catalogo::Nodo* aux = first;
        while(first->next){
            first=first->next;
        }
        first->next = new Nodo(t,nullptr);
        first=aux;
    }

    numeroArticoli++;
}

//toglie prima occorrenza di t
void Catalogo::Togli_Artiolo(Articolo t) {
    Nodo* p= first, *prec=nullptr;
    while(p && !(p->info==t)){
        prec=p; p=p->next;
    }
    if(p){
        if(!prec)
            first=p->next;
        else
            prec->next=p->next;
        //isolo il nodo
        p->next=nullptr;
        delete p;
    }
}

//toglie e ritorna prima occorrenza di t
//precondizione la Catalogo non è vuota
Articolo Catalogo::Estrai_Articolo(){
    Nodo* p= first;
    first = first->next;
    Articolo aux = p->info; //costruttore di copia
    p->next=nullptr;
    delete p;
    return aux;
}

void Catalogo::Svuota(){
    delete first;
    first=nullptr;
}

std::ostream& operator<<(std::ostream& os, const Catalogo& t){
    os << "Catalogo articoli:\n";
    if(t.first!=nullptr) return t.first->Stampa_Ric(os, 0);
    return os;
}

Catalogo::Nodo* Catalogo::Copia(Nodo* p){
if(!p) return nullptr;
return new Nodo(p->info, Copia(p->next));
}

void Catalogo::Distruggi(Nodo* p) {
    if(p){
        Distruggi(p->next);
        delete p;
    }
}

Catalogo& Catalogo::operator=(const Catalogo& m) {
    if(this != &m){
        Distruggi(first);
        first = Copia(m.first);
    }
    return *this;
}

Catalogo::~Catalogo() {
    if(first) {delete first;}
}

Catalogo::Catalogo(const Catalogo& m) : first(Copia(m.first)) {}

Catalogo::Nodo::~Nodo() {
    if(next != nullptr) {
        delete next;
    }
}

bool Catalogo::Iteratore::operator==(Iteratore i) const {
    return punt==i.punt;
}

bool Catalogo::Iteratore::operator!=(Iteratore i) const {
    return punt!=i.punt;
}

//incremento prefisso
Catalogo::Iteratore& Catalogo::Iteratore::operator++() {
    if(punt) punt=punt->next; //side-effect
    return *this;
}//NB se punt==0 non fa nulla

//incremento postfisso
Catalogo::Iteratore Catalogo::Iteratore::operator++(int) {
    Iteratore aux = *this;
    if(punt) punt=punt->next;
    return aux;
}

Catalogo::Iteratore Catalogo::begin() const{
    Iteratore aux;
    aux.punt = first; //per amicizia
    return aux;
}

Catalogo::Iteratore Catalogo::end() const{
    Iteratore aux;
    aux.punt = nullptr; //per amicizia
    return aux;
}

Articolo& Catalogo::operator[](int n) const {
    Nodo* aux = first;

    while(aux && n){
        aux=aux->next;
        n--;
    }

    return aux->info; //per amicizia
    //NB nessun controllo se i.punt != 0
}



