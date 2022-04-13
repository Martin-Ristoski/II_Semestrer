#include <iostream>
using namespace std;

class Krug {
float radius;
const float PI=3.14;
public:
Krug(){
    radius=0;
}
Krug(float r){
    radius=r;
}
float perimetar(){
    return radius*2*PI;
};
float plostina(){
    return radius*radius*PI;
};
int ednakvi(){
    if(plostina()==perimetar())
    return 1; else return 0;
};
};

int main() {
	float r;
	cin >> r;
	Krug k(r);
	cout << k.perimetar() << endl;
	cout << k.plostina() << endl;
	cout << k.ednakvi() <<endl;
    Krug krug;
	return 0;
}
