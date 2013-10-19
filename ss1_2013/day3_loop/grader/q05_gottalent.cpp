#include<stdio.h>
bool getPass(int t1,int t2,int t3){
    int u=0;
    if(t1>=8)
        u++;
    if(t2>=8)
        u++;
    if(t3>=8)
        u++;
    if(u>=2)
        return true;
    else
        return false;
}
int main()
{
    int i,n,k,t1,t2,t3,ct=0;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&t1,&t2,&t3);
        if(getPass(t1,t2,t3)&&ct<k)
        {
            printf("Yes\n");
            ct++;
        }
        else
            printf("No\n");
    }
    printf("%d",ct);
    return 0;
}
