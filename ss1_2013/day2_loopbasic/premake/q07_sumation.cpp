#include<iostream>
using namespace std;
int main()
{
    int min=99999,max=0,sum=0,i=0,u=0;
    while(u>=0)
    {
        sum+=u;
        if(min>u)
            min=u;
        if(max<u)
            max=u;
        cin >> u;
        i++;
    }
    if(i!=1)
        cout << min << " "<< max <<" "<< (float)sum/i;

}
