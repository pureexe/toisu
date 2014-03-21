#include<iostream>
using namespace std;
int db1[1000][1000],marker[1000],size;
void DFS(int put) {
    cout << put << " ";
    marker[put]=1;
    for(int i=0; i<size; i++) {
        if(db1[put][i]!=0&&marker[i]==0) {
            DFS(i);
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
    DFS(0);
    return 0;
}
