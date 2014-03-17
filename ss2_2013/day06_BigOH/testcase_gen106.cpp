#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
    int i;
    srand(time(NULL));
    cout << 1000000 << " ";
    for(i=0;i<1000000;i++){
        int u = rand()%1000;
        if(rand()%2){
            u *=-1;
        }
    cout << u <<" ";
    }
}
