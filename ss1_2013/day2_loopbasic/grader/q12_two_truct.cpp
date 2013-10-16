#include<stdio.h>
int main()
{
    int i,n,truck1=0,truck2=0,u;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&u);
        if(truck1+u<=20000)
        {
            printf("1\n");
            truck1+=u;
        }
        else if(truck2+u<=20000)
        {
            printf("2\n");
            truck2+=u;
        }
        else{
            printf("0\n");
        }
    }
}
