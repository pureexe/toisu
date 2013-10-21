#include<iostream>
#include<string>
using namespace std;
struct student{
    string id;
    int s;
};
struct student stu[10001];
int main()
{

    int i,sum=0,n,ct=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> stu[i].id;
        cin >> stu[i].s;
        sum+=stu[i].s;
    }
    float avg=(float)sum/n;
    for(i=0;i<n;i++)
    {
        if(stu[i].s>=avg)
            ct++;
    }
    cout << ct << "\n";
    for(i=0;i<n;i++)
    {
        if(stu[i].s>=avg)
            cout << stu[i].id <<"\n";
    }
    return 0;
}
