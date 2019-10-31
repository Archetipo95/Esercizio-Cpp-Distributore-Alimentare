#ifndef ARTICOLO_H
#define ARTICOLO_H

#include <string>

using std::string;

class Articolo {
public:
    int idArticolo;
    string nome;
    double prezzo;
    string dataScadenza;
    Articolo(string nome, double prezzo, string dataScadenza);
    static int conta;
    ~Articolo();
};

#endif // ARTICOLO_H
