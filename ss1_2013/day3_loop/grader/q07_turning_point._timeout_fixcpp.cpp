#include<stdio.h>
int tab[1000000];
int main()
{
    int n=0,i,down=0,up=0;
    do{
        if(n>=3)
        {if(tab[n-3]<tab[n-2]&&tab[n-2]>tab[n-1])
            down++;
        if(tab[n-3]>tab[n-2]&&tab[n-2]<tab[n-1])
            up++;
        }
        scanf("%d",&tab[n]);
        n++;
    }while(tab[n-1]!=0);

    printf("%d\n%d",down,up);
    return 0;
}
