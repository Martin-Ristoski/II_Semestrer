/*
Во оваа задача е потребно да уредите даден дом со маси. Креирајте класа Masa со следниве атрибути:

должина (целобројна вредност)
ширина (целобројна вредност)
конструктор со и без параметри и метода pecati().

Креирајте класа Soba која содржи:

маса (објект од класата Маса)
должина на собата (целобројна вредност)
ширина на собата (целобројна вредност)
конструктор со и без параметри и метода pecati() во која се повикува и pecati() за објектот Masa.

Креирајте класа Kukja со атрибути:

соба (објект од класата Soba)
адреса (низа од 50 знаци), и соодветни методи.
конструктор со и без параметри, деструктор и метода pecati() во која се повикува и pecati() за објектот Soba.
*/

#include <iostream>
#include <cstring>
using namespace std;

class Masa{
    int dolzina;
    int sirina;
public:
    Masa(){
    }
    Masa(int _dolzina, int _sirina){
        dolzina=_dolzina;
        sirina=_sirina;
    }
    void pecati(){
        cout<<"Masa: "<<dolzina<<" "<<sirina<<endl;
    }
};

class Soba{
    Masa masa;
    int dolzSoba;
    int sirSoba;
public:
    Soba(){
    }
    Soba(int _dolzSoba, int _sirSoba,Masa _masa){
        masa=_masa;
        dolzSoba=_dolzSoba;
        sirSoba=_sirSoba;
    }
    void pecati(){
        cout<<"Soba: "<<dolzSoba<<" "<<sirSoba<<" ";
        masa.pecati();
    }
};

class Kukja{
    Soba soba;
    char adresa[50];
public:
    Kukja(){
    }
    Kukja(Soba _soba, char _adresa[50]){
        soba=_soba;
        strcpy(adresa,_adresa);
    }
    void pecati(){
    cout<<"Adresa: "<<adresa<<" ";
    soba.pecati();
    }
};


//ne smee da se menuva main funkcijata!
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
    	int masaSirina,masaDolzina;
        cin>>masaSirina;
        cin>>masaDolzina;
    	Masa m(masaSirina,masaDolzina);
    	int sobaSirina,sobaDolzina;
        cin>>sobaSirina;
        cin>>sobaDolzina;
    	Soba s(sobaSirina,sobaDolzina,m);
    	char adresa[30];
        cin>>adresa;
    	Kukja k(s,adresa);
    	k.pecati();
	}

    return 0;
}
