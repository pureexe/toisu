#include<stdio.h>
int boky[8],n,cx=0;
void getBoky()
{
    int i;
    for(i=0; i<8; i++)
    {
        if(n+boky[i]<=50)
        {
            printf("%d ",i+1);
            cx=1;
        }
    }
    if(cx==0)
        {
            printf("0");
        }

}
int main()
{
    int i;
    for(i=0; i<8; i++)
        scanf("%d",&boky[i]);
    scanf("%d",&n);
    getBoky();
    return 0;
}
