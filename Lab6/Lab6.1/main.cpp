#include <iostream>
#include <cstring>
using namespace std;
/*
NBAPlayer
Да се дефинира класа NBAPlayer за која ќе се чуваат:

динамички алоцирана низа од карактери за името на играчот
низа од максимум 40 карактери за тимот во кој играчот моментално настапува
просечен број на поени на играчот оваа сезона (double)
просечен број на асистенции на играчот оваа сезона (double)
просечен број на скокови на играчот оваа сезона (double)
За потребите на класата да се дефинираат:

default конструктор и конструктор со аргументи
copy constructor и оператор =
деструктор
метод rating() кој го враќа рејтингот на кошаркарот кој се пресметува како:

45% од поените + 30% од асистенциите + 25% од скоковите

метод print() кој го печати играчот во следниот формат:

Име - тим

Points: поени

Assists: асистенции

Rebounds: скокови

Rating: рејтинг

AllStarPlayer
Од претходната класа NBAPlayer да се изведе класата AllStarPlayer за која дополнително ќе се чуваат и:

просечен број на поени на играчот од All Star натпреварите (double)
просечен број на асистенции на играчот од All Star натпреварите (double)
просечен број на скокови на играчот од All Star натпреварите (double)
За потребите на класата да се дефинираат:

default конструктор
конструктор кој прима објект од NBAPlayer и плус додатните информации (погледни main)
конструктор кој ги прима сите аргументи (погледни main)
copy constructor, оператор =, деструктор
метод allStarRating() кој го враќа рејтингот на кошаркарот од All Star натпреварите и кој се пресметува како:

30% од поените + 40% од асистенциите + 30% од скоковите

Да се препокријат методите:

rating() кој го враќа просекот од обичниот рејтинг на кошаркарот и неговиот All Star рејтинг
print() кој покрај основните информации за кошаркарот печати и:

All Star Rating: рејтингот од All Star натпреварите

New Rating: просечниот рејтинг*/

class NBAPlayer{
    char *name;
    char tim[40];
    double prosekPoeni;
    double prosekAsist;
    double prosekSkokovi;
public:
    NBAPlayer(char *_name="/", char tim[40]="/", double prosekPoeni=0, double prosekAsist=0, double prosekSkokovi=0){
        name=new char[strlen(_name)+1];
        strcpy(this->name,_name);
        strcpy(this->tim,tim);
        this->prosekPoeni=prosekPoeni;
        this->prosekAsist=prosekAsist;
        this->prosekSkokovi=prosekSkokovi;
    }
    NBAPlayer(NBAPlayer const &other){
        name=new char[strlen(other.name)+1];
        strcpy(this->name,other.name);
        strcpy(this->tim,other.tim);
        this->prosekPoeni=other.prosekPoeni;
        this->prosekAsist=other.prosekAsist;
        this->prosekSkokovi=other.prosekSkokovi;
    }
    NBAPlayer const &operator=(NBAPlayer const &other){
        if(this!=&other){
        name=new char[strlen(other.name)+1];
        strcpy(this->name,other.name);
        strcpy(this->tim,other.tim);
        this->prosekPoeni=other.prosekPoeni;
        this->prosekAsist=other.prosekAsist;
        this->prosekSkokovi=other.prosekSkokovi;}
        else
            return *this;
    }
    ~NBAPlayer(){
        delete [] name;
    }
    double rating(){
        return 0.45*prosekPoeni+0.30*prosekAsist+0.25*prosekSkokovi;
    }
    void print(){
        cout<<name<<" - "<<tim<<endl;
        cout<<"Points: "<<prosekPoeni<<endl;
        cout<<"Assists: "<<prosekAsist<<endl;
        cout<<"Rebounds: "<<prosekSkokovi<<endl;
        cout<<"Rating: "<<rating()<<endl;
    }
};

class AllStarPlayer: public NBAPlayer{
    double alstarppoeni;
    double alstarpassist;
    double alstarpskok;
public:
    AllStarPlayer(char *_name="/", char tim[40]="/", double prosekPoeni=0, double prosekAsist=0, double prosekSkokovi=0,
                  double alstarppoeni=0, double alstarpassist=0, double alstarpskok=0): NBAPlayer(_name, tim, prosekPoeni, prosekAsist, prosekSkokovi){
        this->alstarppoeni=alstarppoeni;
        this->alstarpassist=alstarpassist;
        this->alstarpskok=alstarpskok;
    }
    AllStarPlayer(NBAPlayer other, double alstarppoeni=0, double alstarpassist=0, double alstarpskok=0): NBAPlayer(other){
        this->alstarppoeni=alstarppoeni;
        this->alstarpassist=alstarpassist;
        this->alstarpskok=alstarpskok;
    }
    AllStarPlayer(AllStarPlayer const &other): NBAPlayer(other){
        this->alstarppoeni=other.alstarppoeni;
        this->alstarpassist=other.alstarpassist;
        this->alstarpskok=other.alstarpskok;
    }
    AllStarPlayer const &operator=(AllStarPlayer const &other){
        NBAPlayer::operator=(other);
        this->alstarppoeni=other.alstarppoeni;
        this->alstarpassist=other.alstarpassist;
        this->alstarpskok=other.alstarpskok;
    }
    //~AllStarPlayer(){
      //  delete [] name;
    //}
    double allStarRating(){
        return 0.3*alstarppoeni+0.4*alstarpassist+0.3*alstarpskok;
    }
    double rating(){
        return (NBAPlayer::rating()+allStarRating())/2;
    }
    void print(){
        NBAPlayer::print();
        cout<<"All Star Rating: "<<allStarRating()<<endl;
        cout<<"New Rating: "<<AllStarPlayer::rating()<<endl;
    }

};

int main() {

  char name[50];
  char team[40];
  double points;
  double assists;
  double rebounds;
  double allStarPoints;
  double allStarAssists;
  double allStarRebounds;

  NBAPlayer * players = new NBAPlayer[5];
  AllStarPlayer * asPlayers = new AllStarPlayer[5];
  int n;
  cin >> n;

  if (n == 1) {

    cout << "NBA PLAYERS:" << endl;
    cout << "=====================================" << endl;
    for (int i = 0; i < 5; ++i) {
      cin >> name >> team >> points >> assists >> rebounds;
      players[i] = NBAPlayer(name,team,points,assists,rebounds);
      players[i].print();
    }
  }
  else if (n == 2) {

    for (int i=0; i < 5; ++i){
      cin >> name >> team >> points >> assists >> rebounds;
      cin >> allStarPoints >> allStarAssists >> allStarRebounds;
      players[i] = NBAPlayer(name,team,points,assists,rebounds);
      asPlayers[i] = AllStarPlayer(players[i],allStarPoints,allStarAssists,allStarRebounds);
    }

    cout << "NBA PLAYERS:" << endl;
    cout << "=====================================" << endl;
    for (int i=0; i < 5; ++i)
      players[i].print();

    cout << "ALL STAR PLAYERS:" << endl;
    cout << "=====================================" << endl;
    for (int i=0; i < 5; ++i)
      asPlayers[i].print();

    }
    else if (n == 3) {

      for (int i=0; i < 5; ++i){
        cin >> name >> team >> points >> assists >> rebounds;
        cin >> allStarPoints >> allStarAssists >> allStarRebounds;
        asPlayers[i] = AllStarPlayer(name, team, points, assists, rebounds,
                                     allStarPoints,allStarAssists,allStarRebounds);
      }
      cout << "ALL STAR PLAYERS:" << endl;
      cout << "=====================================" << endl;
      for (int i=0; i < 5; ++i)
        asPlayers[i].print();

    }

    delete [] players;
    delete [] asPlayers;
}
