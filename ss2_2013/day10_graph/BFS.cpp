//#include<iostream>
#include<vector>
// #include<utility>
#include<cstdio>
using namespace std;
vector<int> que;
vector<int> result;
int front = -1;
int db[1000][1000],size;
int parent[1000];
int result_queue[1000];
void enqueue(int b) {
    que.push_back(b);
}
int dequeue() {
    return que[++front];
}
bool isinqueue(int u) {
    int i;
    for(i=0; i<que.size(); i++) {
        if(u==que[i])
            return true;
    }
    return false;
}
void BFS(int put) {
    int i,x;
    enqueue(put);
    parent[put]=-1;
    while(front!=que.size()-1) {
        x = dequeue();
        result.push_back(x);
        result_queue[x] = front;
        for(i=0; i<size; i++) {
            if(db[x][i]!=0&&!isinqueue(i)) {
                enqueue(i);
                parent[i]=x;
            }
        }
    }
    for(i=0; i<size; i++) {
        if(!isinqueue(i)) {
            BFS(i);
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
    BFS(0);
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
