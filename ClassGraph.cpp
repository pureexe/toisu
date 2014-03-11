#include<iostream>
#include<map>
#include<vector>
//#define TYPE int
using namespace std;
template<class TYPE>
class Graph
{
    private:
        class Node // ใช้เก็บปมเป็นซับคลาสของกราฟ
        {
            private:
                TYPE vertex;
                map<TYPE,int> linkcnt;
            public:
                Node(){};
                Node(TYPE v){
                    vertex=v;
                };
                ~Node(){};
                TYPE getKey(){
                    return vertex;
                }
                void link(Node* v){
                    linkcnt[v->getKey()]++;
                }
                void link(TYPE v){
                    linkcnt[v]++;
                }
                void unlink(TYPE v){
                    if(linkcnt[v]>0){
                        linkcnt[v]--;
                    }
                }
                void unlink(Node* v){
                    int vx = v->getKey();
                    if(linkcnt[vx]>0){
                        linkcnt[vx]--;
                    }
                }
            protected:
        };
        map<TYPE,Node*> NodeBox;
    public:
        Graph(){};
        ~Graph(){};
        void addEdge(TYPE a,TYPE b){
            Node* node_a=NULL,*node_b=NULL;
            node_a = NodeBox[a];
            if(node_a ==NULL){
                node_a=new Node(a);
                NodeBox[a]=node_a;
            }
            node_b = NodeBox[b];
            if(node_b ==NULL){
                node_b =new Node(b);
                NodeBox[b]=node_b;
            }
            node_a -> link(b);
            node_b -> link(a);
        }
        void removeEdge(){
        }
        int getMaxDegree() // หาดีกรีมากที่สุดจากทุกโนด
        {
        }
        int getSumDegree() {// หาผลรวมดีกรี
            return 0;
        }
        bool isEalurianGraph(){ // เช็คว่าทุกโหนดเป็นจำนวนคู่
        }
        /*
        vector<int> getEalurianpath{ // เช็คว่าทุกโหนดเป็นจำนวนคู่
        }
        */
        /*
        Shorttestpath
        */
        vector<TYPE> getVectorNode(){ // ใช้แสดงช่ื่อโหนดทั้งหมด
            vector<TYPE> return_vex;
            for(map<TYPE,Node*>::iterator i=NodeBox.begin();i!=NodeBox.end();i++){
                 return_vex.push_back(i->first);
            }
            return return_vex;
        }
    protected:


};
int main(){
    Graph<int> g;
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(1,3);
    vector<int> a;
    a = g.getVectorNode();
    for(int i=0;i<a.size();i++){
        cout << a[i] << " ";
    }
    return 0;
}
