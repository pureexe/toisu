#include<iostream>
using namespace std;
int main()
{
    int i,n;
    cin >> n;
    for(i=n;i>0;i--)
        if(i%2==0)
            cout << i << " ";
    cout << "\n---------------------------\n";
    i=n;
    while(i>0)
    {
        if(i%2==0)
        cout << i << " ";
        i--;
    }
    cout << "\n---------------------------\n";
    i=n;
    do
    {
        cout << i << " ";
        i--;
    }while(i>0);

    return 0;
}
