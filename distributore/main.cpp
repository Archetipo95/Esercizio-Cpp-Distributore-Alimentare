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
    std::cout << " |Il Distributore di Martin|\n";
    std::cout << "  -------------------------\n";
}

void displayMenu() {
    std::cout << "\n";
    std::cout << " ============================ \n";
    std::cout << " | Comandi disponibili:     |\n";
    std::cout << " |                          |\n";
    std::cout << " | 1) Fai cosa A            |\n";
    std::cout << " | 2) Fai cosa B            |\n";
    std::cout << " | 3) Fai cosa C            |\n";
    std::cout << " ============================ \n";
    std::cout << " | 0) Esci dal programma    |\n";
    std::cout << " ============================ \n";
    std::cout << "\n";
    std::cout << "Scegli: ";


}

void loopMenu() {
    int scelta;
    do {
        benvenuto();
        displayMenu();
        std::string s;
        std::cin >> s;
        scelta = std::stoi(s);

        clear();

        if (scelta < 0 || scelta>4) throw 1;
    } while (scelta);
}

int main()
{

    /*try {
        loopMenu();
    }
    catch (...) {
        std::cerr << "ERRORE\n";
        std::cerr << "Selezionare un numero valido\n";
    }
*/

    //dic distributore con 10x5 molle




    Articolo a = Articolo("Matilde",1000,"never");
    Articolo b = Articolo("BBB",2.5,"2/2/2");
    Articolo c = Articolo("CCC",3.5,"3/3/3");

    //std::cout << a << std::endl;
    //std::cout << b << std::endl;
    //std::cout << c << std::endl;

    Distributore dis(10);
   // Molla mol;

    //mol.Aggiungi_Articolo(a);
   // mol.Aggiungi_Articolo(b);
    //mol.Aggiungi_Articolo(c);

    dis.insert(a,0);
    dis.insert(a,0);

    dis.insert(c,1);
    dis.insert(a,1);
    dis.insert(b,1);
    dis.insert(b,1);

    //std::cout << dis << std::endl;


    dis.insert(c,2);
    dis.insert(c,2);
    std::cout << dis << std::endl;

    //Distributore::Iteratore it = dis.begin();
    //std::cout << dis[++it];

    std::cout << dis.getSize();
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
