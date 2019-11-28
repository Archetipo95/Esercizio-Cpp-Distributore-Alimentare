#ifndef MOLLA_H
#define MOLLA_H

#include "Articolo.h"
#include "DList.h"

class Molla {
friend std::ostream& operator<<(std::ostream&, const Molla&);

    dList<Articolo> molla; //lista articoli max 10
    const unsigned int capacitaMolla= 10;
public:

    Molla(){}
    Molla(Articolo& a){
        molla.insertBack(a);
    }
    ~Molla(){} //distruttore profondo
    //Molla(const Molla&);//copia profonda
    //Molla& operator=(const Molla&); //assegnazione profonda
    //bool Vuota() const;
    bool isFull() const{
        return molla.getSize()==capacitaMolla;
    }
    void addArticolo(Articolo a){
        if(!isFull()){
            molla.insertBack(a);
        }else{
            std::cout << "Capacita molla raggiunta articolo: " << a << " non aggiunto\n";
        }
    }

    void removeArticolo(int n){
        molla.removeNth(n);
    }
    //void Togli_Artiolo(Articolo t);
    //Articolo Estrai_Articolo();
    void Svuota(){
        molla.Empty();
    }

    int getSize(){
        return molla.getSize();
    }

    Articolo& operator[](int n) const {
        return molla[n];
    }
};

std::ostream& operator<<(std::ostream& os, const Molla& t){
    return os << "{" << t.molla<< "}\n";
}

#endif // MOLLA_H
