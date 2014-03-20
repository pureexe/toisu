#include<iostream>
#include<map>
using namespace std;
map<int,map<int,int> > graph;
void print_map(int a,int b){
    int i,j;
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
                cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

}
int main(){

    int round,deg,a,b,i;
    cin >> deg >> round;
    for(i=0;i<round;i++){
        cin >> a >> b;
        graph[a][b]++;
        graph[b][a]++;
    }
    print_map(deg,deg);
}
