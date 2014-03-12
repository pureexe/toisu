#include<iostream>
#include<vector>
//#define TYPE int
using namespace std;
template<class TYPE>
class Graph
{
    private:
        class Edge;
        class Node { // ใช้เก็บปมเป็นซับคลาสของกราฟ
            private:
                TYPE vertex;
                vector<Edge*> edge;
            public:
                Node(){};
                Node(TYPE v){
                    vertex=v;
                };
                ~Node(){};
                TYPE getKey(){
                    return vertex;
                }
                void addEdge(Edge* e){
                    edge.push_back(e);
                }
                void removeEdge(Edge* e){
                    vector<Edge*>::iterator i;
                    for(i=edge.begin();i!=edge.end();i++)
                    {
                        if(e == i){
                            edge.erase(i)
                            break;
                        }
                    }
                }
            protected:
        };
        class Edge{ // เก็บเส้นเชื่อมของกราฟ
            private:
                Node* first,*second;
                double weight;
            public:
                Edge(Node* f,Node* s){
                    weight = 0;
                    first = f;
                    second = s;
                };
                Edge(Node* f,Node* s,double w){
                    weight = w;
                    first = f;
                    second = s;
                };
                ~Edge(){};
            protected:

        };

        vector<Edge*> edgeBox;
        vector<Node*> nodeBox;
    public:
        Graph(){};
        ~Graph(){};
        void addEdge(TYPE a,TYPE b){
            return addEdge(a,b,0);
        }
        Node* findNode(TYPE v){
            //for(vector<Node>)
        }
        void addEdge(TYPE a,TYPE b,double c){ // เพิ่มเส้นเชื่อม แต่ความเร็วกากมาก ต้องแต่งภายหลัง
            Node* node_a=NULL,*node_b=NULL;
            node_a = findNode(a);
            if(node_a ==NULL){
                node_a=new Node(a);
                nodeBox.push_back(node_a);
            }
            node_b = findNode(b);
            if(node_b ==NULL){
                node_b =new Node(b);
                nodeBox.push_back(node_b);
            }
            node_a -> link(b);
            node_b -> link(a);
            Edge* e = new Edge(node_a,node_b,c);
            edgeBox.push_back(e);
            node_a->addEdge(e);
            node_b->addEdge(e);
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
        vector<TYPE> getEalurianpath(){ // เช็คว่าทุกโหนดเป็นจำนวนคู่
        }
        vector<TYPE> getShortestpath(){ // หสมสงเดิยมร่สั้นที่สุด
        }

        vector<TYPE> getVectorNode(){ // ใช้แสดงช่ื่อโหนดทั้งหมด
            return nodeBox;
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
