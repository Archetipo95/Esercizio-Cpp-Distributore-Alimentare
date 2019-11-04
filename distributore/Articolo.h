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
    Articolo();
    Articolo(string nome, double prezzo, string dataScadenza);
    static int conta;
    ~Articolo();

    bool operator==(const Articolo t) const;
};

#endif // ARTICOLO_H
