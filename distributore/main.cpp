#include <iostream>
#include <string>
#include <fstream>

#include <Articolo.h>
#include <Molla.h>
#include <Distributore.h>

void clear()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void benvenuto() {
    std::cout << "  -------------------------\n";
    std::cout << " |Il Distributore          |\n";
    std::cout << "  -------------------------\n";
}

void displayMenu() {
    std::cout << "\n";
    std::cout << " ============================ \n";
    std::cout << " | Comandi disponibili:     |\n";
    std::cout << " |                          |\n";
    std::cout << " | 1) Stampa distributore   |\n";
    std::cout << " | 2) NULL OPTION           |\n";
    std::cout << " | 3) NULL OPTION           |\n";
    std::cout << " ============================ \n";
    std::cout << " | 0) Esci dal programma    |\n";
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

int main()
{


    Articolo a = Articolo("Matilde",1000,"never");
    Articolo b = Articolo("BBB",2.5,"2/2/2");
    Articolo c = Articolo("CCC",3.5,"3/3/3");

    //std::cout << a << std::endl;
    //std::cout << b << std::endl;
    //std::cout << c << std::endl;

    Distributore dis(10);
    Distributore::Iteratore it = dis.begin();

    dis[it].Aggiungi_Articolo(a);
    dis[it].Aggiungi_Articolo(a);
    dis[it].Aggiungi_Articolo(a);
    dis[it].Aggiungi_Articolo(a);
    dis[it].Aggiungi_Articolo(a);
    dis[it].Aggiungi_Articolo(a);
    dis[it].Aggiungi_Articolo(a);
    dis[it].Aggiungi_Articolo(a);
    dis[it].Aggiungi_Articolo(a);
    dis[it].Aggiungi_Articolo(a);

    //++it == it=it+1;
    dis[++it].Aggiungi_Articolo(c);
    dis[it].Aggiungi_Articolo(a);
    dis[it].Aggiungi_Articolo(a);
    dis[it].Aggiungi_Articolo(b);
    dis[it].Aggiungi_Articolo(b);

    //++it == it=it+1;
    dis[++it].Aggiungi_Articolo(c);
    dis[it].Aggiungi_Articolo(c);


    //std::cout << dis.getSize();

/* Dice se Molla vuota o no
    for(Distributore::Iteratore it = dis.begin();it!=dis.end();it++){
        if(dis[it].Vuota())
            std::cout << "Molla " << &it << " vuota" << std::endl;
        else
            std::cout << "Molla " << &it << " non vuota" << std::endl;
    }
*/

    try {
        int scelta;
        do {
            clear();
            benvenuto();
            displayMenu();
            std::string s;
            std::cin >> s;
            scelta = std::stoi(s);

            switch (scelta){
            case 1:
                clear();
                stampa_Distributore(dis);
                pausa();
                break;
            }

            if (scelta < 0 || scelta>4) throw 1;
        } while (scelta);
    }
    catch (...) {
        std::cerr << "\nERRORE\n";
        std::cerr << "Selezionare un numero valido\n";

    }

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
