#include <iostream>
#include <cstring>
using namespace std;

class Film{
    char ime[100];
    char reziser[50];
    char zanr[50];
    int godina;
    public:
    Film(){
    }
    Film(char *i,char *r,char *z,int g){
        strcpy(ime,i);
        strcpy(reziser,r);
        strcpy(zanr,z);
        godina=g;
    }

    void pecatiInfo(){
        cout<<"Ime: "<<ime<<endl;
        cout<<"Reziser: "<<reziser<<endl;
        cout<<"Zanr: "<<zanr<<endl;
        cout<<"Godina: "<<godina<<endl;
    };

    int getGodina(){
    return godina;
    }
};
void pecati_po_godina(Film *f, int n, int godina){
    for(int i;i<n;i++){
    if(f[i].getGodina()==godina)
        f[i].pecatiInfo();}
}

int main() {
 	int n;
 	cin >> n;
 	Film f[n];
 	for(int i = 0; i < n; ++i) {
 		char ime[100];
 		char reziser[50];
 		char zanr[50];
 		int godina;
 		cin >> ime;
 		cin >> reziser;
 		cin >> zanr;
        cin >> godina;
        Film film_poedinecno(ime,reziser,zanr,godina);
        f[i]=film_poedinecno;
 		}

 	int godina;
 	cin >> godina;
 	pecati_po_godina(f,n,godina);
 	return 0;
 }
