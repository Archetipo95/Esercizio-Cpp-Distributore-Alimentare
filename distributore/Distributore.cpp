#include "Distributore.h"

int Distributore::Nodo::size_N = 0;
string Distributore::idDistributore = "";

Distributore& Distributore::operator=(const Distributore& m) {
    if(this != &m){
        Distruggi(first);
        first = Copia(m.first);
    }
    return *this;
}

Distributore::~Distributore() {
    if(first) delete first;
}

Distributore::Distributore(const Distributore& m) : first(Copia(m.first)) {}

Distributore::Nodo::~Nodo() {
    if(next != nullptr) delete next;
}


std::ostream& operator<<(std::ostream& os, const Distributore& t){
    if(t.first!=nullptr) return t.first->Stampa_Ric(os, 0) << std::endl;
    return os;
}

