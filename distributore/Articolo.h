#ifndef ARTICOLO_H
#define ARTICOLO_H

#include <iostream>
#include <string>

using std::string;

class Articolo {
    friend std::ostream& operator<<(std::ostream&, const Articolo&);
public:
    int idArticolo;
    string nome;
    double prezzo;
    string dataScadenza;
    //Articolo(){}
    Articolo(string nome, double prezzo, string dataScadenza);
    static int conta;
    ~Articolo();

    bool operator==(const Articolo t) const;
    int getId(){
        return idArticolo;
    }
};

std::ostream& operator<<(std::ostream&, const Articolo&);

#endif // ARTICOLO_H
