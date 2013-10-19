#include<stdio.h>
int main()
{
    int ct=-1,u;
    do{
        ct++;
        scanf("%d",&u);
    }while(u!=0);
    printf("%d",ct);
    return 0;
}
