#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct box{
    float per;
    int series;
    box(int a,float b)
    {
        series=a;
        per=b;
    }
};
bool cmpmin(box a,box b)
{
    return a.per<b.per;
}
bool cmpmax(box a,box b)
{
    return a.per>b.per;
}
int main()
{
    int u,i=1,much;
    vector<box> vex;
    cin >> much;

    while(1)
    {
        if(much==0||u==0)
            break;
        cin >> u;
        if(u==0)
            break;
        else if(u<0)
        {
            i++;
            cin >> much;
        }
        else{
            vex.push_back(box(i,(float)u/(float)much*100));
        }
    }
    vector<box>::iterator c_min=min_element(vex.begin(),vex.end(),cmpmin);
    vector<box>::iterator c_max=min_element(vex.begin(),vex.end(),cmpmax);
    printf("%d %.2f\n",c_min->series,c_min->per);
    printf("%d %.2f\n",c_max->series,c_max->per);

    return 0;
}
