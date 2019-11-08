#include "Articolo.h"

int Articolo::conta = 0;

Articolo::Articolo(string n, double p, string dS): idArticolo(conta+1), nome(n), prezzo(p), dataScadenza(dS)
{
    conta++;
}

Articolo::~Articolo(){
    //conta--;
}

bool Articolo::operator==(const Articolo t) const{
    return idArticolo == t.idArticolo;
}

std::ostream& operator<<(std::ostream& os, const Articolo& t){
    os << "[" <<t.nome /*<< " " << t.prezzo << " " << t.dataScadenza */<< "]";
    return os;
}
