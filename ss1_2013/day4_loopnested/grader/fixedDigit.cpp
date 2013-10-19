#include<iostream>
using namespace std;
int main()
{
    int a,b,c,i,j,ct=0;
    cin >> a >> b >> c;
    a=a*100;
    b=b*1000;
    for(i=a;i<a+100;i++)
        for(j=b;j<b+1000;j++)
            if(((i*j)/10000)%10==c&&(i*j)/100000<10)
                ct++;
    cout << ct;

}
