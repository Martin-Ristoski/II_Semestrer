#include <iostream>
using namespace std;

class Agol {
    int stepeni;
    int minuti;
    int sekundi;
    public:
    void set_stepeni(int deg){
        stepeni=deg;
    };
    void set_minuti(int min){
        minuti=min;
    };
    
    void set_sekundi(int sec){
        sekundi=sec;
    };
    
    int getSekundi(){
        return sekundi;
    };
    
    int to_sekundi(){
       return sekundi+60*minuti+3600*stepeni; 
    };
};


bool changeOfSeconds(Agol a, int sec){
	return a.getSekundi()!=sec;
}
bool proveri(int deg, int min, int sec){
        if(deg>=0 && deg<91 && min>=0 && min<61 && sec>=0 && sec<61)
        return true;
        else return false;
    }

int main() {
    
    Agol a1;
    int deg, min, sec;
    cin >> deg >> min >> sec;
    
    if (proveri(deg, min, sec)) {
    
    	a1.set_stepeni(deg);
        a1.set_minuti(min);
        a1.set_sekundi(sec);
        cout << a1.to_sekundi();
        if (changeOfSeconds(a1,sec))
			cout << "Ne smeete da gi menuvate sekundite vo ramkite na klasata!" << endl;
        
    }
    else
    cout<<"Nevalidni vrednosti za agol"<<endl;
    
    return 0;
}
