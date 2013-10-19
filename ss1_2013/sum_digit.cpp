#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a;
    cin >> a;
    int i=0,n,s=0;
    n=a.length();
    for(i=0;i<n;i++)
        s+=a.at(i)-'0';
        cout << s;
    return 0;
}
