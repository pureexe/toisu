#include<iostream>
using namespace std;
 long long int a;
int main()
{
    int i,n;
    while(1){
    cin >> n;
    if(n==0)
        return 0;
    a=((long long)n*(long long)n)-(long long)n+(long long)1;
    cout << "Y "<< a << "\n";
    }
    return 0;
}
