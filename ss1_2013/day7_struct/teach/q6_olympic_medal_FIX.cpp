#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct country
{
    int id,gold,silver,copper,sum;
    country(int i,int a,int b,int c)
    {
        id=i;
        gold=a;
        silver=b;
        copper=c;
        sum=a+b+c;
    }
};
vector<struct country> lst;
int country_size;
bool cmpid(struct country a,struct country b)
{
    return a.id<b.id;
}
bool cmpgold(struct country a,struct country b)
{
    return a.gold<b.gold;
}
bool cmpsilver(struct country a,struct country b)
{
    return a.silver<b.silver;
}
bool cmpcopper(struct country a,struct country b)
{
    return a.copper<b.copper;
}
bool cmpsum(struct country a,struct country b)
{
    return a.sum<b.sum;
}
int main()
{
    int i,t_a,t_b,t_c,t_d,u;
    cin >> country_size;
    for(i=0; i<country_size; i++)
    {
        cin >> t_a >> t_b >> t_c >> t_d;
        lst.push_back(country(t_a,t_b,t_c,t_d));
    }
    //sort(lst_id.begin(),lst_id.end(),cmpid);
    vector<struct country>::iterator max_gold=max_element(lst.begin(),lst.end(),cmpgold);
    vector<struct country>::iterator max_silver=max_element(lst.begin(),lst.end(),cmpsilver);
    vector<struct country>::iterator max_copper=max_element(lst.begin(),lst.end(),cmpcopper);
    vector<struct country>::iterator max_sum=max_element(lst.begin(),lst.end(),cmpsum);
    //vector<struct country>::iterator lower_b;
    while(1)
    {
        cin >> u;
        i=0;
        if(u<=0)
        {
            cout << "good bye";
            return 0;
        }
        switch(u)
        {

        case 1001:
            //cout << "MAXGOLD<" << max_gold->id <<">";
            for(i=0; i<country_size; i++)
            {
                if(max_gold->gold==lst[i].gold)
                    cout << lst[i].id <<" ";
            }
            break;
        case 1002:
            for(i=0; i<country_size; i++)
            {
                if(max_silver->silver==lst[i].silver)
                    cout << lst[i].id <<" ";
            }
            break;
        case 1003:
            for(i=0; i<country_size; i++)
            {
                if(max_copper->copper==lst[i].copper)
                    cout << lst[i].id <<" ";
            }
            break;
        case 2000:
            for(i=0; i<country_size; i++)
            {
                if(max_sum->sum==lst[i].sum)
                    cout << lst[i].id <<" ";
            }
            break;
        case 3000:
            for(i=0; i<country_size; i++)
            {
                if(lst[i].sum!=0)
                    cout << lst[i].id << " ";
            }
            break;
        default:
//            lower_b=lower_bound(lst.begin(),lst.end(),u,cmpid);
//            if(lower_b==lst.end())
//                cout << "invalid code";
//            else
//                cout << lower_b->gold <<" "<< lower_b->silver <<" " << lower_b->copper << " " << lower_b->sum
            t_a=0;
            for(i=0; i<country_size; i++)
            {
                if(u==lst[i].id)
                {
                    cout << lst[i].gold <<" "<< lst[i].silver <<" " << lst[i].copper << " " << lst[i].sum;
                    t_a=1;
                }
            }
            if(t_a==0)
                cout << "invalid code";
        }
             cout << "\n";

    }
}
