#include<iostream>
using namespace std;
int main()
{
    int i,u;
    while(1)
    {
        cin >> u;
        if(u<=0)
            return 0;
        for(i=0;i<u;i++)
            cout <<'*';
        cout << '\n';
    }
    return 0;
}
