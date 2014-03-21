#include<iostream>
#include<vector>
using namespace std;
int db[1000][1000],size;
vector<int> runner;
vector<int> result;
int marker[1000];
bool found = false;
void getCycle(int put) {
    marker[put]=1;
    runner.push_back(put);
    bool check_do = false;
    for(int i=0;i<size;i++){
            if(db[put][i]!=0&&marker[i]==0&&!found){
                getCycle(i);
                check_do=true;
            }
    }
    if(check_do==false&&db[put][runner[0]]==1&&runner.size()==size){
        found =true;
        result=runner;
    }
    runner.pop_back();
    marker[put]=0;
}
int main() {
    int loop,i,a,b;
    cin >> size >> loop;
    for(i=0; i<loop; i++) {
        cin >> a >> b;
        db[a][b]=1;
        db[b][a]=1;
    }
    getCycle(0);
    cout << "\n";
    if(!result.empty()){
        for(i=0;i<result.size();i++){
            cout << result[i] << " ";
        }
        cout << "0";
    } else {
        cout << "Not Found";
    }
    return 0;
}
