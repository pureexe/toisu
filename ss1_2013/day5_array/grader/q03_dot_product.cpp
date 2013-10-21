#include<stdio.h>
int a[1001],b[1001],u;
int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    for(i=0;i<n;i++)
    {
        u+=a[i]*b[i];
    }
    printf("%d",u);
}
