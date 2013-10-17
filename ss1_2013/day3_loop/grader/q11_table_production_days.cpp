#include<stdio.h>
#include<math.h>
    int a,b,m,n;
bool isBig()
{
    if(a==0)
        return false;
    if(b==0)
        return true;
    if((float)m/(a*6)>(float)n/(b*10))
        return true;
    return false;
}
int main()
{

    scanf("%d %d %d %d",&a,&b,&m,&n);
    if((a==0&&m!=0)||(b==0&&n!=0))
        printf("Unable to finish order");
    else if(isBig())
        printf("%.0f",ceil((float)m/(a*6)));
    else
        printf("%.0f",ceil((float)n/(b*10)));

    return 0;
}
