#include <DList.h>
#include <fstream>
#include <Distributore.h>

void loadCatalogo(dList<Articolo>& catalogo){
    std::ifstream dBArticoli("dataBaseArticoli.txt");
    if (dBArticoli.is_open()){
        string nome, data;
        double prezzo;
        while(dBArticoli >> nome >> prezzo >> data){
            catalogo.insertBack(Articolo(nome,prezzo,data));

        }
    }else std::cout << "non riesco ad aprire il file catalogo\n";
    dBArticoli.close();
}

void loadDistributori(dList<Distributore>& distributore){
    std::ifstream dBDistributori("dataBaseDistributori.txt");
    if (dBDistributori.is_open()){
        unsigned int molle;
        string localita,riga;
        while(std::getline(dBDistributori,riga)){
            molle = stoi(riga.substr(0,riga.find(",")));
            localita = riga.substr(riga.find(",")+1,riga.find("$")-riga.find(",")-1);
            distributore.insertBack(Distributore(molle,localita));
        }
    }else std::cout << "non riesco ad aprire il file distributori\n";
    dBDistributori.close();
}

void loadMolle(dList<Distributore>& distributore, dList<Articolo>& catalogo){
    std::ifstream dMolle("dataBaseMolle.txt");
    if (dMolle.is_open()){
        int a,b,c;
        while(dMolle >> a >> b >> c){
            if(a<distributore.getSize() && c<catalogo.getSize() && b<distributore[a].getMolle())
            distributore[a].addOnMolla(b,catalogo[c]);
        }
    }else std::cout << "non riesco ad aprire il file catalogo\n";
    dMolle.close();
}


void saveMolle(dList<Distributore>& distributore){
    std::ofstream dBMolle("dataBaseMolle.txt");

    for(int a=0; a<distributore.getSize(); a++){
        for(int b=0;b<distributore[a].getMolle();b++){
            for(int c=0; c<distributore[a][b].getSize();c++)
           dBMolle << a << " " << b << " " <<distributore[a][b][c].getId() << std::endl;
        }
    }
    dBMolle.close();
}

void saveDistributori(dList<Distributore>& azienda){
    std::ofstream dBDistributori("dataBaseDistributori.txt");

    for(dList<Distributore>::constIterator itz=azienda.begin(); itz != azienda.end(); ++itz){
        dBDistributori << (*itz).Distributore::getMolle() << "," << (*itz).Distributore::getLocalita() << "$\n";
    }
    dBDistributori.close();

    saveMolle(azienda);
}
