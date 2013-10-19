#include<cstdio>
#include<vector>
using namespace std;
int tab[1001][1001];
struct box{
    int i,j,h;
    box(int a,int b,int c)
    {
        i=a;
        j=b;
        h=c;
    }
};
bool isHigh(int a,int b)
{
    if(a!=2&&b!=1)
        return false;
    if(tab[a][b-1]>=tab[a][b])
        return false;
    if(tab[a][b+1]>=tab[a][b])
        return false;
    if(tab[a-1][b]>=tab[a][b])
        return false;
    if(tab[a+1][b]>=tab[a][b])
        return false;
    if(tab[a-1][b-1]>=tab[a][b])
        return false;
    if(tab[a+1][b+1]>=tab[a][b])
        return false;
    if(tab[a+1][b-1]>=tab[a][b])
        return false;
    if(tab[a-1][b+1]>=tab[a][b])
        return false;
    return true;
}
int main(){
    int i,j,n;
    vector<box> vex;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&tab[i][j]);
        }
    }
    for(i=1;i<n-1;i++)
    {
        for(j=1;j<n-1;j++)
        {
            if(isHigh(i,j))
            {
                vex.push_back(box(i,j,tab[i][j]));
            }
        }
    }
    printf("%d\n",vex.size());
    for(i=0;i<vex.size();i++)
    {
        printf("%d %d %d",vex[i].h,vex[i].i,vex[i].j);
    }

    return 0;
}
