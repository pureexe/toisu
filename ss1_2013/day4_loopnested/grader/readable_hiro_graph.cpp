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
        for(i=1;i<=u;i++)
            {
                if(i==u)
                {
                        cout << i%10;
                }
                else if(i%5==0)
                {
                    cout << 'X';
                }
                else
                    cout << '*';

            }
        cout << '\n';
    }
    return 0;
}
