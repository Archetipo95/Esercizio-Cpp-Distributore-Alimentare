
#include "Azienda.h"



#include "Azienda.h"

int Azienda::Nodo::size_N = 0;

Azienda& Azienda::operator=(const Azienda& m) {
    if(this != &m){
        Distruggi(first);
        first = Copia(m.first);
    }
    return *this;
}

Azienda::~Azienda() {
    if(first) delete first;
}

Azienda::Azienda(const Azienda& m) : first(Copia(m.first)) {}

Azienda::Nodo::~Nodo() {
    if(next != nullptr) delete next;
}


std::ostream& operator<<(std::ostream& os, const Azienda& t){
    if(t.first!=nullptr) return t.first->Stampa_Ric(os, 0);
    return os;
}

