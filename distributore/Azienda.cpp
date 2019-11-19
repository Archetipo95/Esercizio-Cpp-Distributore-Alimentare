#include "Azienda.h"


int Azienda::Nodo::sizeNodo = 0;

Azienda::Azienda(const Azienda& m) : first(Copia(m.first,last)) {}

Azienda& Azienda::operator=(const Azienda& m) {
    if(this != &m){
        Distruggi(first);
        first = Copia(m.first, last);
    }
    return *this;
}

Azienda::~Azienda() {
    if(first) delete first;
}

void Azienda::insertFront(const Distributore& t) {
    first = new Nodo(t,nullptr,first);
    if(first->next==nullptr) {
      // lista di invocazione era vuota
      last=first;
    }
    else {
      // lista di invocazione NON era vuota
      (first->next)->prev=first;
    }
  }

void Azienda::insertBack(const Distributore& t) {
    last = new Nodo(t,last,nullptr);
    if(last->prev==nullptr) {
      // lista di invocazione era vuota
      first=last;
    }
    else {
      // lista di invocazione NON era vuota
      (last->prev)->next=last;
    }
  }

Azienda::Nodo::~Nodo() {
    if(next != nullptr) delete next;
}


std::ostream& operator<<(std::ostream& os, const Azienda& t){
    if(t.first!=nullptr) return t.first->Stampa_Ric(os, 0);
    return os;
}

