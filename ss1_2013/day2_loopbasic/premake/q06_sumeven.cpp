#include<iostream>
using namespace std;
int main()
{
    int sum=0,i,x,y;
    cin >> x >> y;
    if(x%2==1)
        x++;
    if(y%2==1)
        y--;
    for(i=x;i<=y;i+=2)
        sum+=i;
    cout << sum;
    return 0;
}
