#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
struct student{
    string id,name,surname;
    float grade;
};
bool cmp(struct student a,struct student b)
{
    return a.grade<b.grade;
}
struct student stu[101];
int main()
{
    int i,n;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> stu[i].id >> stu[i].name >> stu[i].surname >> stu[i].grade;
    }
    struct student* best=max_element(stu,stu+n,cmp);
    cout << best->id <<" "<< best->name <<" "<< best-> surname<< " ";
    printf("%.2f",best->grade);
    return 0;
}
