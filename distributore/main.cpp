#include <iostream>
#include <string>
#include <fstream>


#include <Azienda.h>

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
    std::cout << "  -------------------------\n";
    std::cout << " |       Azienda sr        |\n";
    std::cout << "  -------------------------\n";
    std::cout << "\n";
    std::cout << " ============================ \n";
    std::cout << " | Comandi disponibili:     |\n";
    std::cout << " |                          |\n";
    std::cout << " | 1) Stampa tutti i distri |\n";
    std::cout << " | 2) Aggiungi distributore |\n";
    std::cout << " | 3) Rimuovi distributore  |\n";
    std::cout << " | 4) Gestisci distributore |\n";
    std::cout << " ============================ \n";
    std::cout << " | 0) Esci dal programma    |\n";
    std::cout << " ============================ \n";
    std::cout << "\n";
    std::cout << "Scegli: ";
}

void Menu_Distributore() {
    std::cout << "  -------------------------\n";
    std::cout << " | Distributore #000000    |\n";
    std::cout << " | Localita: Via XXX       |\n";
    std::cout << "  -------------------------\n";
    std::cout << "\n";
    std::cout << " ============================ \n";
    std::cout << " | Comandi disponibili:     |\n";
    std::cout << " |                          |\n";
    std::cout << " | 1) Stampa distributore   |\n";
    std::cout << " | 2) Aggiungi articolo     |\n";
    std::cout << " | 3) Togli articolo        |\n";
    std::cout << " | 4) Svuota distributore   |\n";
    std::cout << " ============================ \n";
    std::cout << " | 0) Torna al menu precedente |\n";
    std::cout << " ============================ \n";
    std::cout << "\n";
    std::cout << "Scegli: ";


}

void pausa(){
    std::cout << std::endl << "Premi un pulsante per continuare";
    std::cin.ignore();
    std::cin.get();
}

void stampa_Distributore(Distributore& d){
    std::cout << d << std::endl;
}

void stampa_Azienda(Azienda& a){
    std::cout << a << std::endl;
}

void AggiungiDis(Azienda& srl){
    std::cout << "Aggiunta nuovo distributore"<< std::endl;
    std::cout << std::endl;
    std::cout << "Quante molle ha?"<< std::endl;
    std::string s;
    std::cin >> s;
    int scelta = std::stoi(s);
    std::cout << "Dove si trova?"<< std::endl;
    std::cin >> s;
    srl.Aggiungi_Distributore(scelta,s);
}

void RimuoviDis(Azienda& srl){
    stampa_Azienda(srl);
    std::cout << std::endl;
    std::cout << "Quale distributore vuoi eliminare?"<< std::endl;
    std::string s;
    std::cin >> s;
    int scelta = std::stoi(s);
    srl.Rimuovi_Distributore(scelta);//parte da 0
}

int main()
{

    Articolo a = Articolo("Matilde",1000,"never");
    Articolo b = Articolo("BBB",2.5,"2/2/2");
    Articolo c = Articolo("CCC",3.5,"3/3/3");

    Azienda srl;
    srl.Aggiungi_Distributore(1,"5");
    srl.Aggiungi_Distributore(2,"5");
    srl.Aggiungi_Distributore(3,"5");
    srl.Aggiungi_Distributore(4,"5");
    srl.Aggiungi_Distributore(5,"5");
 /*   Azienda::Iteratore itAzz=srl.begin();

    Distributore::Iteratore itDis = srl[itAzz].begin();

    srl[itAzz][itDis].Aggiungi_Articolo(a);
    srl[itAzz][itDis].Aggiungi_Articolo(a);
    srl[itAzz][itDis].Aggiungi_Articolo(a);
    srl[itAzz][itDis].Aggiungi_Articolo(a);
    srl[itAzz][itDis].Aggiungi_Articolo(a);
    srl[itAzz][itDis].Aggiungi_Articolo(a);
    srl[itAzz][itDis].Aggiungi_Articolo(a);
    srl[itAzz][itDis].Aggiungi_Articolo(a);
    srl[itAzz][itDis].Aggiungi_Articolo(a);
    srl[itAzz][itDis].Aggiungi_Articolo(a);

    srl[itAzz][++itDis].Aggiungi_Articolo(c);
    srl[itAzz][itDis].Aggiungi_Articolo(c);
    srl[itAzz][itDis].Aggiungi_Articolo(b);
    srl[itAzz][itDis].Aggiungi_Articolo(b);
    srl[itAzz][itDis].Aggiungi_Articolo(a);
    srl[itAzz][itDis].Aggiungi_Articolo(a);

    //++it == it=it+1;
    srl[itAzz][++itDis].Aggiungi_Articolo(c);
    srl[itAzz][itDis].Aggiungi_Articolo(c);
    srl[itAzz][itDis].Aggiungi_Articolo(c);

    srl[itAzz][++itDis].Aggiungi_Articolo(c);
*/
    //try {
        int scelta;
        do {
            clear();
            Menu_Azienda();
            std::string s;
            std::cin >> s;
            scelta = std::stoi(s);

            switch (scelta){
            case 1:
                clear();
                stampa_Azienda(srl);
                pausa();
                break;

            case 2:
                clear();
                AggiungiDis(srl);
                break;
            case 3:
                clear();
                RimuoviDis(srl);
                break;
            case 4:
                clear();
                Menu_Distributore();
                pausa();
                break;
            }
            //if (scelta < 0 || scelta>4) throw 1;
        } while (scelta);
    /*}
    catch (...) {
        std::cerr << "\nERRORE\n";
        std::cerr << "Selezionare un numero valido\n";

    }*/

/*
Distributore::Iteratore it = dis.begin();

std::cout << dis[it].capacitaMolla << std::endl;

dis[it].Svuota();

dis.Inserisci(a,0);
dis.Inserisci(a,0);
dis.Inserisci(a,0);
dis.Inserisci(a,0);
dis.Inserisci(a,0);


std::cout << dis << std::endl;
//std::cout << dis << std::endl;

*/









    std::cout << std::endl;
    /*ifstream dBArticoli("dataBaseArticoli.txt");

    if (dBArticoli.is_open()){
        while(dBArticoli >> n >> p >> d){
            Articolo a = Articolo(n,p,d);
            cout << a.idArticolo << ", " << n << ", " << p << ", " << d << endl;
        }
    }else cout << "non riesco ad aprire il file"<<endl;
    */

    /*
    std::cout << " \nPress any key to continue\n";
    std::cin.ignore();
    std::cin.get();
    */

}
