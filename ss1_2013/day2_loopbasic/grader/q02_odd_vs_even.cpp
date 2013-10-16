#include<iostream>
using namespace std;
int main(){
    int odd=0,even=0,i,u,n;
    for(i=0;i<8;i++)
    {
        cin >> u;
        if(u%2==0)
            even+=u;
        else
            odd+=u;
    }
    if(odd==even)
        cout << "equal\n";
    else if(odd>even)
        cout << "odd\n";
    else
        cout << "even\n";
    cout << even << "\n"<< odd;
    return 0;
}
