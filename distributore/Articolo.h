#ifndef ARTICOLO_H
#define ARTICOLO_H

#include <string>

using std::string;

class Articolo {
public:
    string IDarticolo;
    string nome;
    double prezzo;
    string dataScadenza;
    Articolo(string id, string nome, double prezzo, string dataScadenza);
};

#endif // ARTICOLO_H
