#include<stdio.h>
//int f(int* a,int p)
//{
//    int i;
//    if(p>=3)
//        return 0;
//    for(i=0;i<10;i++)
//    {
//        a[i]++;
//        f(a,p+1);
//    }
//}
int f(int* a)
{
    int i;
    for(i=0;i<1000;i++)
    {
        a[i%10]++;
        a[(i/10)%10]++;
        a[(i/100)%10]++;
    }

}
int main()
{
    int i,a[10];
    for(i=0;i<10;i++)
      a[i]=0;
    f(a);
    for(i=0;i<10;i++)
        printf("%d = %d\n",i,a[i]);
    return 0;
}
