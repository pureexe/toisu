#include<iostream>
//#include<sstream>
//#include<vector>
using namespace std;
int vex[3000000],vex_size=1;
bool isprime(int i)
{
    int j;
    for(j=0; vex[j]*vex[j]<=i; j++)
    {
        if(i%vex[j]==0)
            return false;
    }
    return true;
}
int main()
{
    vex[0]=2;
    int i,n;
    cin >> n;
    for(i=3; i<=n; i++)
    {

        if(isprime(i))
        {
            vex[vex_size]=i;
            vex_size++;
        }
    }
    cout << vex_size;

}
