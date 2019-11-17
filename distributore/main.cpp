#include <iostream>
#include <string>
#include <fstream>


#include <Azienda.h>
#include <Catalogo.h>

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
    std::cout << "     | Localita: "<< dis.getId() << "           |\n";
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

void Svuota_Distributore (Distributore& dis){
    for(Distributore::Iteratore it = dis.begin(); it!=dis.end(); ++it){
        dis[it].Svuota();
    }
}

void stampa_Azienda(Azienda& a){
    std::cout << a << "\n";
}

void AggiungiDis(Azienda& srl){
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
}

void RimuoviDis(Azienda& srl){
    stampa_Azienda(srl);
    std::cout << "\n";
    std::cout << "Quale distributore vuoi eliminare?"<< "\n";
    std::string s;
    std::cin >> s;
    int scelta = std::stoi(s);
    srl.Rimuovi_Distributore(scelta);//parte da 0
}

void stampa_Articoli(Catalogo& cat){
    std::cout<<cat;
}

void aggiungiArticolo(Catalogo& catalogo, Azienda& azienda, Azienda::Iteratore& itAz){
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
}

void rimuoviArticolo(Catalogo& catalogo, Azienda& azienda, Azienda::Iteratore& itAz){
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
}

//MAIN

int main()
{
    Azienda azienda;
    Catalogo catalogo;

    //riempi catalogo da file Load
    std::ifstream dBArticoli("dataBaseArticoli.txt");
    if (dBArticoli.is_open()){
        string nome, data;
        double prezzo;
        while(dBArticoli >> nome >> prezzo >> data){
            catalogo.Aggiungi_Articolo(Articolo(nome,prezzo,data));

        }
    }else std::cout << "non riesco ad aprire il file\n";

    azienda.Aggiungi_Distributore(1,"111");
    azienda.Aggiungi_Distributore(2,"222");
    azienda.Aggiungi_Distributore(3,"333");
    azienda.Aggiungi_Distributore(4,"444");
    azienda.Aggiungi_Distributore(5,"555");

    Azienda::Iteratore itAzz=azienda.begin();
    Distributore::Iteratore itDiss=azienda[itAzz].begin();
    Catalogo::Iteratore itCat = catalogo.begin();
    azienda[itAzz][itDiss].Aggiungi_Articolo(catalogo[itCat]);
    azienda[itAzz][itDiss].Aggiungi_Articolo(catalogo[++itCat]);
    azienda[itAzz][itDiss].Aggiungi_Articolo(catalogo[++itCat]);
    azienda[itAzz][itDiss].Aggiungi_Articolo(catalogo[++itCat]);
    azienda[itAzz][itDiss].Aggiungi_Articolo(catalogo[++itCat]);
    azienda[itAzz][itDiss].Aggiungi_Articolo(catalogo[itCat]);

    //try {
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
                stampa_Azienda(azienda);
                pausa();
                break;}
            case 2:{
                clear();
                AggiungiDis(azienda);
                break;}
            case 3:{
                clear();
                RimuoviDis(azienda);
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
   /* }
    catch (...) {
        std::cerr << "\nERRORE\n";
        std::cerr << "Selezionare un numero valido\n";

    }*/





    std::cout << "\n";


    /*
    std::cout << " \nPress any key to continue\n";
    std::cin.ignore();
    std::cin.get();
    */

}
