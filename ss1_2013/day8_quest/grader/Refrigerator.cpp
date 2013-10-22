#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int _main(){
    vector<int> lst;
    int i,n,u,ct=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> u;
        lst.push_back(u);
    }
    while(1){
        if(lst[0]==0)
        {
            cout << ct-1 << "\n";
            break;
        }
        sort(lst.begin(),lst.end());
        for(i=1;i<n;i++)
            lst[i]--;
            ct++;
    }
    return 0;
}
int main()
{
    int i,T;
    cin >> T;
    for(i=0;i<T;i++)
        _main();
    return 0;
}
