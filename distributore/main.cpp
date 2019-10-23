#include <iostream>
#include <string>
#include <fstream>

#include <articolo.h>

using namespace std;

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
/*
    try {
        loopMenu();
    }
    catch (...) {
        std::cerr << "ERRORE\n";
        std::cerr << "Selezionare un numero valido\n";
    }
*/
    string n;
    double p;
    string d;



    ifstream dBArticoli("dataBaseArticoli.txt");

    if (dBArticoli.is_open()){
    while(dBArticoli >> n >> p >> d){
        cout << n << ", " << p << ", " << d << endl;
    }
}else cout << "non riesco ad aprire il file"<<endl;
    /*
    std::cout << " \nPress any key to continue\n";
    std::cin.ignore();
    std::cin.get();
    */

}
