#include <saveLoad.cpp>

#include "mainwindow.h"

#include <QApplication>

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
    std::cout << "     |       Azienda SRL       |\n";
    std::cout << "      -------------------------\n";
    std::cout << "     |           |\n";
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
    std::cout << "     | Distributore: iD    \n";
    std::cout << "     | molle: "<<dis.getMolle()<<"\n";
    std::cout << "     | Localita: "<< dis.getLocalita() <<"\n";
    std::cout << "      -------------------------\n";
    std::cout << "     |           |\n";
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
        dis.emptyMolle();
    }
}

void stampaAzienda(dList<Distributore>& distributore){
    std::cout << distributore << "\n";
}

void aggiungiDis(dList<Distributore>& distributore){
    std::cout << "Aggiunta nuovo distributore"<< "\n";
    std::cout << "\n";
    std::cout << "Quante molle ha?"<< "\n";
    unsigned int molle;
    std::cin >> molle;
    std::cout << "Dove si trova?" << "\n";
    std::string localita;
    std::cin.ignore();
    getline(std::cin,localita);
    distributore.insertBack(Distributore(molle,localita));
}

void rimuoviDis(dList<Distributore>& distributore){
    stampaAzienda(distributore);
    std::cout << "\n";
    std::cout << "Quale distributore vuoi eliminare?"<< "\n";
    int scelta;
    std::cin >> scelta;
    distributore.removeNth(scelta);//parte da 0
}

void stampa_Articoli(dList<Articolo>& catalogo){
    std::cout<<catalogo;
}

void aggiungiArticolo(dList<Articolo>& catalogo, dList<Distributore>& azienda, int itaz){
    stampaDistributore(azienda[itaz]);
    std::cout << "\nIn quale molla vuoi inserire? ";
    int itm;
    std::cin >> itm;
    stampa_Articoli(catalogo);
    std::cout << "\nQuale articolo vuoi inserire? ";
    int itar;
    std::cin >> itar;
    azienda[itaz].addOnMolla(itm,catalogo[itar]);
}

void rimuoviArticolo(dList<Articolo>& catalogo, dList<Distributore>& distributore, int itaz){
    stampaDistributore(distributore[itaz]);
    std::cout << "\nDa quale molla vuoi rimuovere? ";
    int itm;
    std::cin >> itm;
    stampa_Articoli(catalogo);
    std::cout << "\nQuale articolo vuoi rimuovere? ";
    int itar;
    std::cin >> itar;
    distributore[itaz].removeFromMolla(itm,itar);
}




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();


    /* dList<Distributore> distributore;
    dList<Articolo> catalogo;

    //riempi catalogo da file Load
    loadCatalogo(catalogo);

    //riempi azienda da file
    loadDistributori(distributore);

    //riempi distributori
    loadMolle(distributore, catalogo);

    int scelta, scelta2;
    do {
        clear();
        Menu_Azienda();
        std::cin >> scelta;

        switch (scelta){
        case 1:{
            clear();
            stampaAzienda(distributore);
            pausa();
            break;}
        case 2:{
            clear();
            aggiungiDis(distributore);
            break;}
        case 3:{
            clear();
            rimuoviDis(distributore);
            break;}
        case 4:{
            clear();
            stampaAzienda(distributore);
            std::cout << "\nQuale distributore vuoi selezionare? ";
            int itd;
            std::cin >> itd;

            do{
                clear();
                Menu_Distributore(distributore[1]);
                std::cin >> scelta2;

                switch (scelta2){
                case 1:{
                    clear();
                    stampaDistributore(distributore[itd]);
                    pausa();
                    break;}
                case 2:{
                    clear();
                    //aggiungi articolo
                    aggiungiArticolo(catalogo, distributore, itd);
                    //BONUS: chiedi quanti articoli vuoi aggiongere
                    pausa();
                    break;}
                case 3:{
                    clear();
                    rimuoviArticolo(catalogo, distributore, itd);
                    break;}
                case 4:{
                    clear();
                    svuotaDistributore(distributore[itd]);
                    break;}
                }
            }while(scelta2);
            break;}
        }
        //if (scelta < 0 || scelta>4) throw 1;
    } while (scelta);


    saveDistributori(distributore);*/

}


