#include "Distributore.h"

int Distributore::Nodo::size_N = 0;

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
    os << "***STAMPA DISTRIBUTORE***" << std::endl;
    if(t.first!=nullptr) return t.first->Stampa_Ric(os) << std::endl << "***FINE STAMPA DISTRIBUTORE***";
    return os;
}

