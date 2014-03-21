#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int size;
int db1[1000][1000],db2[1000][1000];
int getDeg1(int a){
    int i,cnt=0;
    for(i=0;i<size;i++){
        if(i!=a&&db1[a][i]!=0){
            cnt++;
        }
    }
    return cnt;
}
int getDeg2(int a){
    int i,cnt=0;
    for(i=0;i<size;i++){
        if(i!=a&&db2[a][i]!=0){
            cnt++;
        }
    }
    return cnt;
}
vector<int> getChildDeg1(int a){
    int i;
    vector<int> ans;
    for(i=0;i<size;i++){
        if(i!=a&&db1[a][i]!=0){
            ans.push_back(getDeg1(i));
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
vector<int> getChildDeg2(int a){
    int i;
    vector<int> ans;
    for(i=0;i<size;i++){
        if(i!=a&&db1[a][i]!=0){
            ans.push_back(getDeg2(i));
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
void cmp(){
    int i,j;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
                cout << "!";
            if(getDeg1(i)==getDeg2(j)){
                cout << "(" << i << "," << j << ")\n";
            }
        }
    }
}
int main(){
    int loop,i,j,a,b;
    cin >> size >> loop;
    for(i=0; i<loop; i++) {
        cin >> a >> b;
        db1[a][b]++;
        if(a!=b)
            db1[b][a]++;
    }
    for(i=0; i<loop; i++) {
        cin >> a >> b;
        db2[a][b]++;
        if(a!=b)
            db2[b][a]++;
    }
    cmp();
//    cout << getDeg1();
}
