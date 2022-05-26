#include <iostream>
#include <cstring>
using namespace std;
/*Да се дефинира класа Ekipa за коjа се чуваат следниве информации:

името на екипата (низа од наjмногу 15 знаци)
броj на порази
броj на победи
За оваа класа да се дефинира метод pecati() коjа ги печати податоците за екипаta. Од оваа класа да се изведe новa класa, FudbalskaEkipa.

За фудбалската екипа дополнително се чуваат информации за:

вкупниот броj на црвени картони
вкупниот броj жолти картони
броjот на нерешени натпревари
За фудбалската екипа да се преоптовари методот pecati(), така што покрај останатите информации, ќе се испечатат и бројот на нерешени резултати и
вкупен број на поени во формат: Име на екипа, броj на победи, броj на порази, броj на нерешени натпревари и вкупен броj на поени
(за победа фудбалската екипа добива 3 поени, додека за нерешен резултата, 1 поен);*/

class Ekipa{
    char ime[15];
    int porazi;
    int pobedi;
public:
    Ekipa(char ime[15]="/", int pobedi=0, int porazi=0){
        strcpy(this->ime,ime);
        this->porazi=porazi;
        this->pobedi=pobedi;
    }
    void pecati(){
        cout<<"Ime: "<<ime<<" Pobedi: "<<pobedi<<" Porazi: "<<porazi;
    }
    int poeni(){
        return pobedi*3;
    }
};

class FudbalskaEkipa: public Ekipa{
    int crk;
    int zlk;
    int nereseni;
public:
    FudbalskaEkipa(char ime[15]="/", int pobedi=0, int porazi=0, int crk=0, int zlk=0, int nereseni=0): Ekipa(ime,pobedi,porazi){
        this->crk=crk;
        this->zlk=zlk;
        this->nereseni=nereseni;
    }
    void pecati(){
        Ekipa::pecati();
        cout<<" Nereseni: "<<nereseni<<" Poeni: "<<Ekipa::poeni()+nereseni<<endl;
    }
};

int main(){
	char ime[15];
	int pob,por,ck,zk,ner;
	cin>>ime>>pob>>por>>ck>>zk>>ner;
	FudbalskaEkipa f1(ime,pob,por,ck,zk,ner);
	f1.pecati();
	return 0;
}
