#include<iostream>
#include<cstdlib>
using namespace std;
template<typename TYPE>
class RecordArray {
private:
    TYPE *root;
    int root_size;
    int current_node;
    void ram_cls(){
    int i;
        for(i=0; i<root_size; i++) {
            root[i] = 0;
        }
    }
    void memAlloc(int box){
        root = (TYPE*)malloc(sizeof(TYPE)*box);
        root_size = box;
        current_node = 0;
        ram_cls();

    }
public:
    RecordArray() {
        memAlloc(10);
    };
    RecordArray(int box) {
        memAlloc(box);
    };
    ~RecordArray() {};
    void push_back(TYPE k) {
        if(current_node<root_size)
            root[current_node++]=k;
        else
            cout << "Array Overflow :P";
    }
    void insert(int i,TYPE k){
        root[i]=k;
    };
    void input(){
        int i;
        for(i=0;i<root_size;i++)
        {
            cin >> root[i];
        }
    }
    void print() {
        int i;
        for(i=0; i<root_size; i++) {
            cout << root[i] << " ";
        }
    }
protected:

};

int main() {
    RecordArray<double> a(20);
    a.push_back(6);
    a.push_back(1);
    a.push_back(8);
    a.insert(17,7);
    a.print();
    return 0;
}
