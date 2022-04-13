/*
Во оваа задача треба да се внесат и испечатат податоци за автомобили.
За еден автомобил (објект од класата Car) се чуваат следниве податоци:
сопственик (објект од класата Person)
датум на купување (објект од класата Date)
цена (float price), предодредена вредност 0
За класата Car потребно е да се напише метод за печатење print() и метод за добивање на цената getPrice().
Класата Date содржи три цели броеви (int year, month, day) кои претставуваат датум. За неа треба да се напише метод за печатење print(), предодреден (default) конструктор, конструктор со параметри и конструктор за копирање.
Класата Person содржи име и презиме (низи од максимум 20 знаци, со предодредени вредности not specified), предодреден конструктор, конструктор со параметри и метод за печатење print().
Методот за печатење кај класата Person изгледа вака: [name] [lastName].
Методот за печатење кај класата Date изгледа вака: [year].[month].[day].
Методот за печатење кај класата Car изгледа вака:
owner.print()
date.print()
Price: [price]
Покрај тоа, потребно е да се напише метод cheaperThan(Car* cars, int numCars, float price) кој ќе ги испечати сите објекти Car од низата cars со големина numCars чија цена е помала од price.
*/
char ns[20]="not specified";
#include<iostream>
#include<cstring>
using namespace std;

class Date{
    int year;
    int month;
    int day;
    public:
    Date(){
        year=2000;
        month=1;
        day=1;
    }
    Date(int y, int m, int d){
        year=y;
        month=m;
        day=d;
    }
    Date(const Date &d){
        year=d.year;
        month=d.month;
        day=d.day;
    }
    void print(){
        cout<<year<<"."<<month<<"."<<day<<endl;
    }
};

class Person{
    char ime[20];
    char prezime[20];
    public:
    Person(){
        strcpy(ime,ns);
        strcpy(prezime,ns);
    }
    Person(char i[20],char pi[20]){
        strcpy(ime,i);
        strcpy(prezime,pi);
    }
    void print(){
        cout<<ime<<" "<<prezime<<endl;
    }
};

class Car{
    Person sopstvenik;
    Date datum;
    float price;
    public:
    Car(){
        price=0;
    }
    float getPrice(){
        return price;
    }
    Car(Person s, Date d, float p=0){
        sopstvenik=s;
        datum=d;
        price=p;
    }
    Car(const Car &c){
        sopstvenik=c.sopstvenik;
        datum=c.datum;
        price=c.price;
    }
    void print(){
    sopstvenik.print();
    datum.print();
    cout<<"Price: "<<price<<endl;
    }
};

void cheaperThan(Car *cars,int numCars,float priceLimit){
    for(int i=0;i<numCars;i++){
        if(cars[i].getPrice()<priceLimit)
            cars[i].print();
    }
}
int main() {
	char name[20];
	char lastName[20];
	int year;
	int month;
	int day;
	float price;

	int testCase;
	cin >> testCase;

	if (testCase == 1) {
		cin >> name;
		cin >> lastName;
		Person lik(name, lastName);

		cin >> year;
		cin >> month;
		cin >> day;
		Date date(year, month, day);

		cin >> price;
		Car car(lik, date,  price);

		car.print();
	}
	else if (testCase == 2) {
		cin >> name;
		cin >> lastName;
		Person lik(name, lastName);

		cin >> year;
		cin >> month;
		cin >> day;
		Date date(Date(year, month, day));

		cin >> price;
		Car car(lik, date,  price);
		car.print();
	}
	else {
		int numCars;
		cin >> numCars;

		Car cars[10];
		for (int i = 0; i < numCars; i++) {
			cin >> name;
			cin >> lastName;
			Person lik(name, lastName);

			cin >> year;
			cin >> month;
			cin >> day;
			Date date(year, month, day);

			cin >> price;
			cars[i] = Car(lik, date,  price);
		}
        float priceLimit;
        cin >> priceLimit;
		cheaperThan(cars, numCars, priceLimit);
	}


	return 0;
}
