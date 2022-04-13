/*
Креирајте класа Rabotnik која во себе содржи:

ime (низа од максимум 30 знаци)
prezime (низа од максимум 30 знаци)
plata (целобројна вредност)
За оваа класа да се креираат default конструктор и конструктор со аргументи. Да се имплементираат и следните методи:

getPlata() која ја враќа платата на работникот
pecati() која ги печати името, презимето и платата.
Креирајте класа Fabrika во која има:

rabotnik [100] (низа од вработени)
brojVraboteni (целобројна вредност)
Во класата имплементирајте ги следните методи:

pecatiVraboteni() ги печати сите вработени
pecatiSoPlata(int plata) ги печати сите вработени со плата поголема или еднаква на дадената во аргументот(int plata).
Во главната функција се внесуваат податоци за n вработени. Притоа прво се внесува n, па податоците за сите n вработени. Во последниот ред се чита минималната плата.

На излез да се прикажат прво сите вработени, а потоа само оние со поголема плата од минималната. Треба да се корисатат методите pecatiVraboteni и pecatiSoPlata!
*/

#include <iostream>
#include <cstring>
using namespace std;

class Rabotnik{
    char ime[30];
    char prezime[30];
    int plata;
public:
    Rabotnik(){
    }
    Rabotnik(char _ime[30], char _prezime[30], int _plata){
        strcpy(ime,_ime);
        strcpy(prezime,_prezime);
        plata=_plata;
    }
    int getPlata(){
        return plata;
    }
    void pecati(){
        cout<<ime<<" "<<prezime<<" "<<plata;
    }
};

class Fabrika{
    Rabotnik rabotnik[100];
    int brojVraboteni;
public:
    Fabrika(){
    }
    Fabrika(Rabotnik rab[],int _brojVraboteni){
    brojVraboteni=_brojVraboteni;
    for(int i=0;i<brojVraboteni;i++){
        rabotnik[i]=rab[i];
    }
    }
    void pecatiVraboteni(){
        cout<<"Site vraboteni:"<<endl;
        for(int i=0;i<brojVraboteni;i++){
            rabotnik[i].pecati(); cout<<endl;
        }
    }
    void pecatiSoPlata(int minimalnaPlata){
        cout<<"Vraboteni so plata povisoka od "<<minimalnaPlata<<" :"<<endl;
        for(int i=0;i<brojVraboteni;i++){
            if(rabotnik[i].getPlata()>minimalnaPlata){
                    rabotnik[i].pecati();
                    cout<<endl;}
        }
    }
};

int main()
{
    int n,i,minimalnaPlata;
    char ime[30];
    char prezime[30];
    int plata;
    Rabotnik rab[100];
    cin>>n;
    for(i=0;i<n;i++){
        cin>>ime;
        cin>>prezime;
        cin>>plata;
    Rabotnik poedinecenRab(ime, prezime, plata);
    rab[i]=poedinecenRab;
    }
    cin>>minimalnaPlata;
    Fabrika f(rab, n);
    f.pecatiVraboteni();
    f.pecatiSoPlata(minimalnaPlata);
    return 0;
}
