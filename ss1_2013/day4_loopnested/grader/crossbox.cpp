#include<stdio.h>
bool isBar(int i,int j,int n)
{
    if(i==0||j==0||i==n-1||j==n-1)
        return true;
    if(i==j||j==n-i-1)
        return true;
    return false;
}
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(isBar(i,j,n))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
