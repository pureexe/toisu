#include<stdio.h>
int tab[1000000];
int main()
{
    int n=0,i,down=0,up=0;
    do{
        scanf("%d",&tab[n]);
        n++;
    }while(tab[n-1]!=0);
    for(i=1;i<n-2;i++)
    {
        if(tab[i-1]<tab[i]&&tab[i]>tab[i+1])
            down++;
        if(tab[i-1]>tab[i]&&tab[i]<tab[i+1])
            up++;
    }
    printf("%d\n%d",down,up);
    return 0;
}
