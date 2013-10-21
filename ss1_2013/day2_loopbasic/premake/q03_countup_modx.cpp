#include<iostream>
using namespace std;
int main()
{
    int i,n,x;
    cin >> n >> x;
    for(i=1;i<=n;i++)
        if(i%x==0)
            cout << i << " ";
    cout << "\n---------------------------\n";
    i=0;
    while(i<=n)
    {
        if(i%x==0)
        cout << i << " ";
        i++;
    }
    cout << "\n---------------------------\n";
    i=0;
    do
    {
        if(i%x==0)
        cout << i << " ";
        i++;
    }while(i<=n);

    return 0;
}
