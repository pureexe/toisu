#include<iostream>
#include<string>
using namespace std;
struct student{
    string id,name,surname;
    int cls;
};    struct student stu[200001];

int main()
{
    int i,n,u,chk=0;
    cin >> n;
    for(i=0;i<n;i++)
            cin >> stu[i].id >> stu[i].name >>stu[i].surname >> stu[i].cls;
    cin >> u;
    for(i=0;i<n;i++){
        if(stu[i].cls==u)
        {
            cout << stu[i].id <<" "<< stu[i].name <<" "<< stu[i].surname << "\n";
            chk=1;
        }
    }
    if(chk==0)
        cout << "None";
    return 0;
}
