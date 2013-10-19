#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> vex;
    int i,u;
    while(1)
    {
        cin >> u;
        if(u==0)
        {
            break;
        }
        vex.push_back(u);
    }
    for(i=vex.size()-1;i>=0;i--)
        cout << vex[i] << " ";
    return 0;
}
