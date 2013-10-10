#include<stdio.h>
int chk[1000001];
void sort(int *a,int n)
{
    int i;
    for(i=0; i<n; i++)
        chk[a[i]]++;
}
int main()
{
    int i,j,n=10,a[]= {3,5,2,8,1,9,7,6,0,4};
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    sort(a,n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<chk[i]; j++)
        {
            printf("%d ",i);
        }
    }
    return 0;
}
