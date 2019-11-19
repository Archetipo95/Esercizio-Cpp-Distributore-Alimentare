#include <iostream>
#include <string>
#include <fstream>


//#include <Azienda.h>
#include <Catalogo.h>
#include <Distributore.h>

#include <DList.h>

void clear() {
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void Menu_Azienda() {
    std::cout << "      -------------------------\n";
    std::cout << "     |       Azienda Mia       |\n";
    std::cout << "      -------------------------\n";
    std::cout << "     |       Sei un tecnico    |\n";
    std::cout << "      -------------------------\n";
    std::cout << "\n";
    std::cout << " ================================== \n";
    std::cout << " | Comandi disponibili:           |\n";
    std::cout << " |                                |\n";
    std::cout << " | 1) Stampa tutti i distributori |\n";
    std::cout << " | 2) Aggiungi distributore       |\n";
    std::cout << " | 3) Rimuovi distributore        |\n";
    std::cout << " | 4) Gestisci distributore       |\n";
    std::cout << " ================================== \n";
    std::cout << " | 0) Esci dal programma          |\n";
    std::cout << " ================================== \n";
    std::cout << "\n";
    std::cout << "Scegli: ";
}

void Menu_Distributore(Distributore& dis) {
    std::cout << "      -------------------------\n";
    std::cout << "     | Distributore: NoName    |\n";
    std::cout << "     | Localita: "<< dis.getLocalita() << "           |\n";
    std::cout << "      -------------------------\n";
    std::cout << "     |       Sei un tecnico    |\n";
    std::cout << "      -------------------------\n";
    std::cout << "\n";
    std::cout << " ================================== \n";
    std::cout << " | Comandi disponibili:           |\n";
    std::cout << " |                                |\n";
    std::cout << " | 1) Stampa distributore         |\n";
    std::cout << " | 2) Aggiungi articolo           |\n";
    std::cout << " | 3) Rimuovi articolo            |\n";
    std::cout << " | 4) Svuota distributore         |\n";
    std::cout << " ================================== \n";
    std::cout << " | 0) Torna al menu precedente    |\n";
    std::cout << " ================================== \n";
    std::cout << "\n";
    std::cout << "Scegli: ";


}

void pausa(){
    std::cout << "\n" << "Premi un pulsante per continuare";
    std::cin.ignore();
    std::cin.get();
}

void stampa_Distributore(Distributore& d){
    std::cout << "Molle distributore: \n";
    std::cout << d << "\n";
}
/*
void Svuota_Distributore (Distributore& dis){
    for(Distributore::Iteratore it = dis.begin(); it!=dis.end(); ++it){
        dis[it].Svuota();
    }
}*/

/*void stampa_Azienda(Azienda& a){
    std::cout << a << "\n";
}*/

/*void AggiungiDis(Azienda& srl){
    std::cout << "Aggiunta nuovo distributore"<< "\n";
    std::cout << "\n";
    std::cout << "Quante molle ha?"<< "\n";
    std::string s;
    std::cin >> s;
    int scelta = std::stoi(s);
    std::cout << "Dove si trova?" << "\n";
    string input;
    std::cin.ignore();
    getline(std::cin,input);
    srl.Aggiungi_Distributore(scelta,input);
}*/

/*void RimuoviDis(Azienda& srl){
    stampa_Azienda(srl);
    std::cout << "\n";
    std::cout << "Quale distributore vuoi eliminare?"<< "\n";
    std::string s;
    std::cin >> s;
    int scelta = std::stoi(s);
    srl.Rimuovi_Distributore(scelta);//parte da 0
}*/

void stampa_Articoli(Catalogo& cat){
    std::cout<<cat;
}

/*void aggiungiArticolo(Catalogo& catalogo, Azienda& azienda, Azienda::Iteratore& itAz){
    stampa_Distributore(azienda[itAz]);
    std::cout << "\nIn quale molla vuoi inserire? ";
    std::string molSel;
    std::cin >> molSel;
    int moll = stoi(molSel);
    stampa_Articoli(catalogo);
    std::cout << "\nQuale articolo vuoi inserire? ";
    std::string artSel;
    std::cin >> artSel;
    int art = stoi(artSel);

    Catalogo::Iteratore itcat=catalogo.begin();
    while(art){ ++itcat; art--;}

    Distributore::Iteratore itdis=azienda[itAz].begin();
    while(moll){ ++itdis; moll--;}
    azienda[itAz][itdis].Aggiungi_Articolo(catalogo[itcat]);
}*/

/*void rimuoviArticolo(Catalogo& catalogo, Azienda& azienda, Azienda::Iteratore& itAz){
    stampa_Distributore(azienda[itAz]);
    std::cout << "\nDa quale molla vuoi rimuovere? ";
    std::string molSel;
    std::cin >> molSel;
    int moll = stoi(molSel);
    stampa_Articoli(catalogo);
    std::cout << "\nQuale articolo vuoi rimuovere? ";
    std::string artSel;
    std::cin >> artSel;
    int art = stoi(artSel);

    Catalogo::Iteratore itcat=catalogo.begin();
    while(art){ ++itcat; art--;}

    Distributore::Iteratore itdis=azienda[itAz].begin();
    while(moll){ ++itdis; moll--;}
    azienda[itAz][itdis].Togli_Artiolo(catalogo[itcat]);
}*/

void loadCatalogo(Catalogo& catalogo){
    std::ifstream dBArticoli("dataBaseArticoli.txt");
    if (dBArticoli.is_open()){
        string nome, data;
        double prezzo;
        while(dBArticoli >> nome >> prezzo >> data){
            catalogo.Aggiungi_Articolo(Articolo(nome,prezzo,data));

        }
    }else std::cout << "non riesco ad aprire il file catalogo\n";
    dBArticoli.close();
}

void loadDistributori(dList<Distributore>& azienda){
    std::ifstream dBDistributori("dataBaseDistributori.txt");
    if (dBDistributori.is_open()){
        int molle;
        string localita,riga;
        while(std::getline(dBDistributori,riga)){
            molle = stoi(riga.substr(0,riga.find(",")));
            localita = riga.substr(riga.find(",")+1,riga.find("$")-riga.find(",")-1);
            Distributore dis(molle, localita);
            azienda.insertBack(dis);
        }
    }else std::cout << "non riesco ad aprire il file distributori\n";
    dBDistributori.close();
}

void saveMolle(dList<Distributore>& azienda){
    std::ofstream dBMolle("dataBaseMolle.txt");

    for(int a=0; a<azienda.getSize(); a++){
        for(int b=0;b<azienda[a].getMolle();b++){
            for(int c=0; c<azienda[a][b].getSize();c++)
           dBMolle << a << " " << b << " " <<azienda[a][b][c].getId() << std::endl;
        }

    }
    dBMolle.close();
}

void saveDistributori(dList<Distributore>& azienda){
    std::ofstream dBDistributori("dataBaseDistributori.txt");

    for(dList<Distributore>::constiterator itz=azienda.begin(); itz != azienda.end(); ++itz){
        dBDistributori << (*itz).Distributore::getMolle() << "," << (*itz).Distributore::getLocalita() << "$\n";
    }
    dBDistributori.close();

    saveMolle(azienda);
}

void loadMolle(dList<Distributore>& azienda, Catalogo& catalogo){
    std::ifstream dMolle("dataBaseMolle.txt");
    if (dMolle.is_open()){
        int a,b,c;
        while(dMolle >> a >> b >> c){
            if(a<azienda.getSize() && c<catalogo.getNumeroArticolo() && b<azienda[a].getMolle())
            azienda[a][b].Aggiungi_Articolo(catalogo[c]);
        }
    }else std::cout << "non riesco ad aprire il file catalogo\n";
    dMolle.close();
}

//MAIN
int main(){
    dList<Distributore> azienda;
    Catalogo catalogo;

    //riempi catalogo da file Load
    loadCatalogo(catalogo);

    //riempi azienda da file
    loadDistributori(azienda);

    //riempi distributori
    loadMolle(azienda, catalogo);

    std::cout << azienda;

    /*
        int scelta, scelta2;
        do {
            clear();
            Menu_Azienda();
            std::string s;
            std::cin >> s;
            scelta = std::stoi(s);

            switch (scelta){
            case 1:{
                clear();
                //stampa_Azienda(azienda);
                pausa();
                break;}
            case 2:{
                clear();
                //AggiungiDis(azienda);
                break;}
            case 3:{
                clear();
                //RimuoviDis(azienda);
                break;}
            case 4:{
                clear();
                stampa_Azienda(azienda);
                std::cout << "\nQuale distributore vuoi selezionare? ";
                std::string s;
                std::cin >> s;
                int dis = std::stoi(s);
                Azienda::Iteratore itAz=azienda.begin();
                std::cout << azienda[itAz].getId();
                while(dis){
                    ++itAz;
                    dis--;
                }
                do{
                    clear();
                    Menu_Distributore(azienda[itAz]);
                    std::cin >> s;
                    scelta2 = std::stoi(s);

                    switch (scelta2){
                    case 1:{
                        clear();
                        stampa_Distributore(azienda[itAz]);
                        pausa();
                        break;}
                    case 2:{
                        clear();
                        //aggiungi articolo
                        aggiungiArticolo(catalogo, azienda, itAz);
                        //BONUS: chiedi quanti articoli vuoi aggiongere
                        pausa();
                        break;}
                    case 3:{
                        clear();
                        rimuoviArticolo(catalogo, azienda, itAz);
                        //rimuove la prima occorrenza
                        //BONUS: quantità da togliere
                        break;}
                    case 4:{
                        clear();
                        //svuota distributore
                        Svuota_Distributore(azienda[itAz]);
                        break;}
                    }
                }while(scelta2);
                break;}
            }
            //if (scelta < 0 || scelta>4) throw 1;
        } while (scelta);
    */




    //salva stato azienda
    saveDistributori(azienda);

    /*
    std::cout << " \nPress any key to continue\n";
    std::cin.ignore();
    std::cin.get();
    */
}
