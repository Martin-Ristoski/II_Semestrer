#include <stdio.h>
#include <stdlib.h>
/*
Да се напише програма во која од стандарден влез се вчитува N (бројот на производи),
а потоа се вчитуваат податоците за N производи (име, цена, количина).
Програмата треба на стандарден излез да ја отпечати листата на купени производи и вкупната сума која треба да се плати во следниот облик (пример):

1. Flips    10.00 x 3 = 30.00
2. CocaCola 75.00 x 2 = 150.00
3. ChokoBanana  5.00 x 10 = 50.00
Total: 230.00
*/

typedef struct proizvod{
    char ime[30];
    float cena;
    float kolicina;
}proizvod;

int main(){
    int N,i;
    float vkupnop,total=0;
    proizvod p[50];
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%s%f%f",&p[i].ime,&p[i].cena,&p[i].kolicina);
    }
    for(i=0;i<N;i++){
        vkupnop=0;
        vkupnop=p[i].cena*p[i].kolicina;
        printf("%d. %s\t%.2f x %.1f = %.2f\n",i+1,p[i].ime,p[i].cena,p[i].kolicina,vkupnop);
        total+=vkupnop;

    }
    printf("Total: %.2f",total);
    return 0;
}
/* to check
3
Flips 10 3
CocaCola 75 2
ChokoBanana 5 10
*/
