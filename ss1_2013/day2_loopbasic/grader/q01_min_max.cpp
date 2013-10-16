#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> vex;
    int i,u;
    for(i=0;i<8;i++)
    {
        cin >> u;
        if(u>0)
        vex.push_back(u);
    }
    cout << *max_element(vex.begin(),vex.end()) << "\n" <<  *min_element(vex.begin(),vex.end());
    return 0;
}
