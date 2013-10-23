#include<iostream>
//#include<sstream>
#include<cmath>
#define PRIME 5000000
using namespace std;
int tab[PRIME+1];
bool isprime(int i)
{
    int j;
    for(j=2; j*j<=i; j++)
    {

        if(i%j==0)
            return false;
    }
    return true;
}
int main()
{
    //stringstream sout;
    int i,j,k,ct=0;
    for(i=2; i<=PRIME; i++)
    {
//
//        if(tab[i]==0)
//        {
            if(isprime(i))
            {
//                for(j=i+i; j<=PRIME; j+=i)
//                    tab[j]=1
ct++;
            }
      //  }
    }
    for(i=2; i<PRIME; i++)
    {
        if(tab[i]==0)
            //sout << i << "\n";
            ct++;
    }
    cout << ct;
    //cout << sout.str();
}
