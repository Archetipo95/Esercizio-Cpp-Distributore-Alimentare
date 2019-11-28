#ifndef DISTRIBUTORE_H
#define DISTRIBUTORE_H

#include "DList.h"
#include "Molla.h"

class Distributore
{
    friend std::ostream& operator<<(std::ostream&, const Distributore&);
    dList<Molla> molle;    //lista di molle max n
    int numeroMolle;
    string localita;

public:

    //non ci può essere un distributore senza molle
    Distributore(unsigned int n, string s):molle(dList<Molla>(n,Molla())), numeroMolle(molle.getSize()), localita(s){}
    ~Distributore(){}
    //Distributore(const Distributore&); //copia profonda
    //Distributore& operator=(const Distributore&); //assegnazione profonda
    //bool Vuota() const { return first == nullptr; }

    int getMolle() const{
        return numeroMolle;
    }

    string getLocalita() const{
        return localita;
    }

    void addOnMolla(int n, Articolo a){
        molle[n].addArticolo(a);
    }

    void removeFromMolla(int n, int articolo){
        molle[n].removeArticolo(articolo);
    }

    void emptyMolle(){
        for(int n=0; n<static_cast<int>(molle.getSize()); n++){
            molle[n].Svuota();
        }
    }


    Molla& operator[](int n) const {
        return molle[n];
    }


};

std::ostream& operator<<(std::ostream& os, const Distributore& t){
    /*if(!t.molle.isEmpty())*/ return os << "# DISTRIBUTORE: "<< t.getLocalita() <<std::endl<< t.molle << "\n";
   // return os;
}
#endif // DISTRIBUTORE_H
