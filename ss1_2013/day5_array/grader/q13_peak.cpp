#include<stdio.h>
int a[1005][1005],ans[1000000][3],c=0;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<n-1;j++)
        {
            if(a[i][j]>a[i-1][j-1]&&a[i][j]>a[i][j-1]&&a[i][j]>a[i+1][j-1]&&a[i][j]>a[i-1][j]&&a[i][j]>a[i+1][j]&&a[i][j]>a[i-1][j+1]&&a[i][j]>a[i][j+1]&&a[i][j]>a[i+1][j+1])
            {
                ans[c][0]=a[i][j];
                ans[c][1]=i;
                ans[c][2]=j;
                c++;
            }
        }
    }
    printf("%d\n",c);
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<3;j++)
            printf("%d ",ans[i][j]);
        printf("\n");
    }
}
