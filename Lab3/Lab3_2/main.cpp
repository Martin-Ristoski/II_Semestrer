/*
Да се дефинира класа Potpisuvac во која се чуваат информации за:

име (низа од максимум 20 знаци)
презиме (низа од максимум 20 знаци)
ЕМБГ (низа од максимум 14 знаци)
За класата да се дефинира copy конструктор, default конструктор и конструктор со аргументи.

Да се дефинира класа Dogovor, во која се чуваат информации за:

број на договор (int),
категорија на договор (низа од 50 знаци),
поле од 3 потпишувачи на договорот (објекти од класата Potpisuvac)
Во класата да се додаде метод кој ќе проверува дали постојат два исти потпишувачи (имаат ист ЕМБГ).*/

#include <iostream>
#include <cstring>
char def[20]="Default";
using namespace std;

class Potpisuvac
{
	char ime[20];
	char prezime[20];
	char embg[14];
	public:
	Potpisuvac(){
	    strcpy(ime,def);
	    strcpy(prezime,def);
	    strcpy(embg,def);
	}
	Potpisuvac(char i[20],char pi[20], char maticen[14]){
	    strcpy(ime,i);
	    strcpy(prezime,pi);
	    strcpy(embg,maticen);
	}
	Potpisuvac(const Potpisuvac &p){
	    strcpy(ime,p.ime);
	    strcpy(prezime,p.prezime);
	    strcpy(embg,p.embg);
	}
	friend class Dogovor;
};
class Dogovor
{
    int brdog;
    char kat[50];
    Potpisuvac p[3];
public:
    Dogovor(int br, char kateg[20], Potpisuvac potp[3]){
    brdog=br;
    strcpy(kat,kateg);
    p[0]=potp[0];
    p[1]=potp[1];
    p[2]=potp[2];

    }
    bool proverka(){
        int br=0;
    if(strcmp(p[0].embg,p[1].embg)) //|| strcmp(p[0].embg,p[1].embg) || p[1].embg==p[2].embg)
        br++;
    if(strcmp(p[0].embg,p[2].embg))
                br++;
    if (strcmp(p[2].embg,p[1].embg))
                         br++;
    if(br==3)
        return false; else return true;
    }
};


//ne smee da se menuva main funkcijata
int main()
{
    char embg[14], ime[20], prezime[20], kategorija[20];
    int broj, n;
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p1(ime, prezime, embg);
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p2(ime, prezime, embg);
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p3(ime, prezime, embg);
    	cin >> broj >> kategorija;
    	Potpisuvac p[3];
    	p[0] = p1; p[1] = p2; p[2] = p3;
    	Dogovor d(broj, kategorija, p);
        cout << "Dogovor " << broj << ":" << endl;
    	if(d.proverka() == true)
    	    cout << "Postojat potpishuvaci so ist EMBG" << endl;
    	else
    	    cout << "Ne postojat potpishuvaci so ist EMBG" << endl;
    }
    return 0;
}
