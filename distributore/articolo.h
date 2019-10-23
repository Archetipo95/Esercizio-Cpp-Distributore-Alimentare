#ifndef ARTICOLO_H
#define ARTICOLO_H

#include <string>

using std::string;

class articolo
{
public:
    string nome;
    double prezzo;
    string dataScadenza;
    articolo(string nome, double prezzo, string dataScadenza);
};

#endif // ARTICOLO_H
