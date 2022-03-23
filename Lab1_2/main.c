#include <stdio.h>
#include <stdlib.h>
/*
Да се напише структура која ќе опишува отсечка во дводимензионален простор (две точки).
Потоа да се напише функција која ќе проверува дали две отсечки се сечат.
For example:

Input	       Result
-2 -2  2  0    0
 0  1  1  3
*/
typedef struct tocka
{
    float x, y;
}tocka;

typedef struct otsecka
{
    tocka t1;
    tocka t2;
}otsecka;

int se_secat (otsecka o1, otsecka o2)
{
    float pravec1 = (o1.t1.y-o1.t2.y)/(o1.t1.x-o1.t2.x);
    float pravec2= (o2.t1.y-o2.t1.y)/(o2.t1.x-o2.t2.x);
    if(pravec1==pravec2)
        return 0;
    else if(o2.t1.x>o1.t1.x && o2.t2.x>o1.t1.x && o2.t2.x>o1.t1.x && o2.t2.x>o1.t2.x)
        return 0;
    else if(o1.t1.x>o2.t1.x && o1.t2.x>o2.t1.x && o1.t2.x>o2.t1.x && o1.t2.x>o2.t2.x)
        return 0;
    else if(o2.t1.y>o1.t1.y && o2.t2.y>o1.t1.y && o2.t2.y>o1.t1.y && o2.t2.y>o1.t2.y)
        return 0;
    else if(o1.t1.y>o2.t1.y && o1.t2.y>o2.t1.y && o1.t2.y>o2.t1.y && o1.t2.y>o2.t2.y)
        return 0;
    else
        return 1;
}

int main()
{
    float x1, y1, x2, y2;
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

