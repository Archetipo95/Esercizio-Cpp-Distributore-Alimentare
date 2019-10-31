#include "Articolo.h"

int Articolo::conta = 0;

Articolo::Articolo(string n, double p, string dS): idArticolo(conta+1), nome(n), prezzo(p), dataScadenza(dS)
{
    conta++;
}

Articolo::~Articolo(){
    //conta--;
}
