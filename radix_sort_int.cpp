#include<cstdio>
#include<queue>
#include<map>
#include<cmath>
using namespace std;
void print_r(int *arr,int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ",arr[i]);
}
void radix_sort(int *data,int n,int loop)
{
    map<int,queue<int> > que;
    int l,i,ct,j,x;
    for(l=0; l<loop; l++)
    {
        for(i=0; i<n; i++)
        {
            que[(int)(data[i]/(int)pow(10,l))%10].push(data[i]);
        }
        ct=0;
        for(i=0; i<10; i++)
        {
            x=que[i].size();
            for(j=0; j<x; j++)
            {
                data[ct]=que[i].front();
                que[i].pop();
                ct++;
            }
        }

    }
}
int main()
{
    int data[]= {348,143,361,423,538,128,321,543,366},n=9,loop=3;
    radix_sort(data,n,loop);
    print_r(data,n);
    return 0;
}
