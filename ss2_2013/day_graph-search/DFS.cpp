//#include<iostream>
// #include<utility>
#include<cstdio>
using namespace std;
int front = -1;
int db[1000][1000],size;
int parent[1000];
int result_queue[1000];
int marker[1000];
void DFS(int put) { /// Stupid recursive :P
    result_queue[put]=++front;
    marker[put]=1;
    for(int i=0; i<size; i++) {
        if(db[put][i]!=0&&marker[i]==0) {
            parent[i]=put;
            DFS(i);
        }
    }
}
int main() {
    int loop,i,a,b;
    scanf("%d %d",&size,&loop);
    for(i=0; i<loop; i++) {
        scanf("%d %d",&a,&b);
        db[a][b]=1;
        db[b][a]=1;
    }
    for(i=0; i<size; i++) {
        if(marker[i]==0) {
            parent[i]=-1;
            DFS(i);
        }
    }
    for(i=0; i<size; i++) {
        printf("%3d ",i);
    }
    printf("\n");
    for(i=0; i<size; i++) {
        printf("%3d ",parent[i]);
    }
    printf("\n");
    for(i=0; i<size; i++) {
        printf("%3d ",result_queue[i]);
    }
    return 0;
}
