#include<stdio.h>
int tab[50001],lot[21];
int main()
{
    int i,n,sum,k,j,ct=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&tab[i]);
    }
    scanf("%d",&k);
    for(i=0;i<k;i++){
        scanf("%d",&lot[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<k;j++){
            if(tab[i]%1000==lot[j])
            {
                ct++;
            }
        }
    }
    printf("%d",ct);
    return 0;
}
