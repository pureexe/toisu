#include<iostream>
using namespace std;
int main()
{
    int i,n,x,sum=0;
    cin >> x >> n;
    for(i=0;x+i<=n;i++)
            sum+=(x+i)*(x+i);
    cout << sum;
    return 0;
}
