#include<stdio.h>

int check_min(int x, int y, int w, int h)
{
    int minx = w - x;
    int miny = h - y;

    if(minx > x)
        minx = x;
    if(miny > y)
        miny = y;

    if(minx > miny)
        return miny;
    else return minx;
}

int main(void)
{
    int x, y, w, h;

    scanf("%d %d %d %d", &x, &y, &w, &h);
    printf("%d", check_min(x, y ,w, h));

    return (0);
}