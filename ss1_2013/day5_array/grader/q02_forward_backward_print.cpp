#include<iostream>
using namespace std;
int main()
{
    int n,i,u[5001],b;
    cin >> n;
    for(i=0;i<n;i++)
        cin >>u[i];
    cin >> b;
    for(i=0;i<n;i++)
        cout <<u[i]+b <<" ";
    return 0;
}
