#include <stdio.h>
#include <stdlib.h>
//Glavna poenta na zadachata e da se najde kako se sogleduva dali dve otsechki se sechat, shto ne e moja cel na uchenje.
//Ostanatoto e ednostavna rabota so strukturi, koja e izrabotena.
/*
Да се напише структура која ќе опишува отсечка во дводимензионален простор (две точки).
Потоа да се напише функција која ќе проверува дали две отсечки се сечат.
For example:

Input	Result
-2 -2   2 0
 0  1   1 3
 0

*/
typedef struct tocka{
int x;
int y;
}tocka;

typedef struct otsecka{
tocka t1;
tocka t2;
}otsecka;

int se_secat(){
if(se_secat) return 1;
else return 0;
return 0;
}

int main()
{
    double x1, y1, x2, y2;
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    tocka t1 = { x1, y1 };
    tocka t2 = { x2, y2 };
    otsecka o1 = { t1, t2 };
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    tocka t3 = { x1, y1 };
    tocka t4 = { x2, y2 };
    otsecka o2 = { t3, t4 };
    printf("%d\n", se_secat(o1, o2));
    return 0;
}

