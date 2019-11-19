#include "Molla.h"

bool Molla::Vuota() const { return first == nullptr; }

//aggiunge articolo in testa
void Molla::Aggiungi_Articolo(Articolo t) {
    if(capacitaMolla>0){
        if(!first) first = new Nodo(t,first);
        else{
           Molla::Nodo* aux = first;
            while(first->next){
                first=first->next;
            }
            first->next = new Nodo(t,nullptr);
            first=aux;
        }
        --capacitaMolla;
        ++Molla::size;
    }else
        //std::cout << "OUT OF BOUND MOLLA!!!"<< std::endl;
        return;
}

//toglie prima occorrenza di t
void Molla::Togli_Artiolo(Articolo t) {
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
        capacitaMolla++;
    }
}

//toglie e ritorna prima occorrenza di t
//precondizione la molla non è vuota
Articolo Molla::Estrai_Articolo(){
    Nodo* p= first;
    first = first->next;
    Articolo aux = p->info; //costruttore di copia
    p->next=nullptr;
    delete p;
    capacitaMolla++;
    return aux;
}

void Molla::Svuota(){
    delete first;
    first=nullptr;
    capacitaMolla=10;
}

std::ostream& operator<<(std::ostream& os, const Molla& t){
    if(t.first!=nullptr) return t.first->Stampa_Ric(os);
    return os;
}

Molla::Nodo* Molla::Copia(Nodo* p){
if(!p) return nullptr;
return new Nodo(p->info, Copia(p->next));
}

void Molla::Distruggi(Nodo* p) {
    if(p){
        Distruggi(p->next);
        delete p;
    }
}

Molla& Molla::operator=(const Molla& m) {
    if(this != &m){
        Distruggi(first);
        first = Copia(m.first);
    }
    return *this;
}

Molla::~Molla() {
    if(first) {delete first;}
}

Molla::Molla(const Molla& m) : first(Copia(m.first)) {}

Molla::Nodo::~Nodo() {
    if(next != nullptr) {
        delete next;
    }
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

Articolo& Molla::operator[](int n) const {
    Nodo* aux = first;

    while(aux && n){
        aux=aux->next;
        n--;
    }

    return aux->info; //per amicizia
    //NB nessun controllo se i.punt != 0
}


