#include <iostream>
#include <string>
#include <fstream>

#include <DList.h>
#include <Distributore.h>


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
    std::cout << "     | Distributore: iD    |\n";
    std::cout << "     | molle: "<<dis.getMolle()<<"    |\n";
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

void stampaDistributore(Distributore& d){
    std::cout << "Molle distributore: \n";
    std::cout << d << "\n";
}

void svuotaDistributore (Distributore& dis){
    for(int n = 0; n<dis.getMolle(); n++){
        dis[n].Svuota();
    }
}

void stampaAzienda(dList<Distributore>& azienda){
    std::cout << azienda << "\n";
}

void aggiungiDis(dList<Distributore>& azienda){
    std::cout << "Aggiunta nuovo distributore"<< "\n";
    std::cout << "\n";
    std::cout << "Quante molle ha?"<< "\n";
    std::string s;
    std::cin >> s;
    int molle = std::stoi(s);
    std::cout << "Dove si trova?" << "\n";
    string localita;
    std::cin.ignore();
    getline(std::cin,localita);
    Distributore dis(molle,localita);
    azienda.insertBack(dis);
}

void rimuoviDis(dList<Distributore>& azienda){
    stampaAzienda(azienda);
    std::cout << "\n";
    std::cout << "Quale distributore vuoi eliminare?"<< "\n";
    std::string s;
    std::cin >> s;
    int scelta = std::stoi(s);
    azienda.removeNth(scelta);//parte da 0
}

void stampa_Articoli(dList<Articolo>& catalogo){
    std::cout<<catalogo;
}

void aggiungiArticolo(dList<Articolo>& catalogo, dList<Distributore>& azienda, int itaz){
    stampaDistributore(azienda[itaz]);
    std::cout << "\nIn quale molla vuoi inserire? ";
    std::string molSel;
    std::cin >> molSel;
    int itm = stoi(molSel);
    stampa_Articoli(catalogo);
    std::cout << "\nQuale articolo vuoi inserire? ";
    std::string artSel;
    std::cin >> artSel;
    int itar = stoi(artSel);

    azienda[itaz][itm].Aggiungi_Articolo(catalogo[itar]);
}

void rimuoviArticolo(dList<Articolo>& catalogo, dList<Distributore>& azienda, int itaz){
    stampaDistributore(azienda[itaz]);
    std::cout << "\nDa quale molla vuoi rimuovere? ";
    std::string molSel;
    std::cin >> molSel;
    int itm = stoi(molSel);
    stampa_Articoli(catalogo);
    std::cout << "\nQuale articolo vuoi rimuovere? ";
    std::string artSel;
    std::cin >> artSel;
    int itar = stoi(artSel);

    azienda[itaz][itm].Togli_Artiolo(catalogo[itar]);
}

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

void loadMolle(dList<Distributore>& azienda, dList<Articolo>& catalogo){
    std::ifstream dMolle("dataBaseMolle.txt");
    if (dMolle.is_open()){
        int a,b,c;
        while(dMolle >> a >> b >> c){
            if(a<azienda.getSize() && c<catalogo.getSize() && b<azienda[a].getMolle())
            azienda[a][b].Aggiungi_Articolo(catalogo[c]);
        }
    }else std::cout << "non riesco ad aprire il file catalogo\n";
    dMolle.close();
}

//MAIN
int main(){
    dList<Distributore> azienda;
    dList<Articolo> catalogo;

    //riempi catalogo da file Load
    loadCatalogo(catalogo);

    //riempi azienda da file
    loadDistributori(azienda);

    //riempi distributori
    loadMolle(azienda, catalogo);

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
                stampaAzienda(azienda);
                pausa();
                break;}
            case 2:{
                clear();
                aggiungiDis(azienda);
                break;}
            case 3:{
                clear();
                rimuoviDis(azienda);
                break;}
            case 4:{
                clear();
                stampaAzienda(azienda);
                std::cout << "\nQuale distributore vuoi selezionare? ";
                std::string s;
                std::cin >> s;
                int itd = std::stoi(s);

                do{
                    clear();
                    Menu_Distributore(azienda[itd]);
                    std::cin >> s;
                    scelta2 = std::stoi(s);

                    switch (scelta2){
                    case 1:{
                        clear();
                        stampaDistributore(azienda[itd]);
                        pausa();
                        break;}
                    case 2:{
                        clear();
                        //aggiungi articolo
                        aggiungiArticolo(catalogo, azienda, itd);
                        //BONUS: chiedi quanti articoli vuoi aggiongere
                        pausa();
                        break;}
                    case 3:{
                        clear();
                        rimuoviArticolo(catalogo, azienda, itd);
                        //rimuove la prima occorrenza
                        //BONUS: quantità da togliere
                        break;}
                    case 4:{
                        clear();
                        //svuota distributore
                        svuotaDistributore(azienda[itd]);
                        break;}
                    }
                }while(scelta2);
                break;}
            }
            //if (scelta < 0 || scelta>4) throw 1;
        } while (scelta);





    //salva stato azienda
    saveDistributori(azienda);

    /*
    std::cout << " \nPress any key to continue\n";
    std::cin.ignore();
    std::cin.get();
    */
}
