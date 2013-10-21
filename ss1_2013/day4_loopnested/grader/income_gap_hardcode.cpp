#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int i,n,j,var[5],v_min=200172134,v_max=-200172134;
    scanf("%d",&n);
    if(n<=0)
        return 0;
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d %d",&var[0],&var[1],&var[2],&var[3],&var[4]);

        sort(var,var+5);
        if(v_max<var[4]-var[0])
            v_max=var[4]-var[0];
        if(v_min>var[4]-var[0])
            v_min=var[4]-var[0];
    }
        printf("%d %d %d",v_max,v_min,v_max-v_min);
    return 0;
}
