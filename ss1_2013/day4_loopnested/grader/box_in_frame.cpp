#include<stdio.h>
bool isFrame(int i,int j,int n)
{
    if((j==1||j==n-2)&&(i!=0&&i!=n-1))
        return true;
    if((i==1||i==n-2)&&(j!=0&&j!=n-1))
        return true;
    return false;
}
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++){
            if(isFrame(i,j,n))
            printf(" ");
            else
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
