#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>

using namespace std;

struct Znajomy {
    Znajomy() {
        id=0;
        imie="nowy";
        nazwisko="nowy";
        adres="nowy";
        telefon="nowy";
        mail="nowy";
    }
    int id;
    string imie, nazwisko, adres, telefon, mail;
};


vector <Znajomy> daneZPliku(vector <Znajomy> znajomi) {
    int nrLinii=1;
    string linia;
    Znajomy nowy;

    fstream plik;
    plik.open("KsiazkaAdresowa.txt", ios::in);

    while(getline(plik,linia)) {
        switch(nrLinii) {
        case 1:
            nowy.id = atoi(linia.c_str());
            break;
        case 2:
            nowy.imie = linia;
            break;
        case 3:
            nowy.nazwisko = linia;
            break;
        case 4:
            nowy.adres = linia;
            break;
        case 5:
            nowy.telefon = linia;
            break;
        case 6:
            nowy.mail = linia;
            break;
        }
        nrLinii++;
        if (nrLinii==7) {
            nrLinii=1;
            znajomi.push_back(nowy);
        }

    }
    plik.close();
    return znajomi;
}

void dodanieDoPlikuWszystkichZnajomych(vector <Znajomy> znajomi) {
    fstream plik;
    plik.open("KsiazkaAdresowa.txt", ios::out | ios::trunc);
    for (int i=0; i<znajomi.size(); i++) {

        plik<<znajomi[i].id<<"|"<<znajomi[i].imie<<"|"<<znajomi[i].nazwisko<<"|"<<znajomi[i].adres<<"|"<<znajomi[i].telefon<<"|"<<znajomi[i].mail<<"|"<<endl;
    }
    plik.close();
}

int main()
{
    vector <Znajomy> znajomi;

    cout<<"Wklej do folderu z programem plik txt z danymi do konwersji."<<endl;
    cout<<"Zmien jego nazwe na 'KsiazkaAdresowa.txt' a nastepnie wcisnij ENTER."<<endl;

    system("pause");
        system("cls");

    znajomi=daneZPliku(znajomi);
    dodanieDoPlikuWszystkichZnajomych(znajomi);



    cout<<"Konwersja danych przebiegla pomyslnie"<<endl;



    return 0;
}
