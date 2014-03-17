#include<iostream>
#include<vector>
using namespace std;
#define TYPE int
class Edge;
        class Node { // ใช้เก็บปมเป็นซับคลาสของกราฟ
            private:
                TYPE vertex;

            public:
                vector<Edge*> edge;
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
                    int i;
                        Edge *b = edge[i];
                        b->getFisrtKey();
                    for(i=0;i<edge.size();i++)
                    {

//                        if(e->fisrt == edge[i].first)
//                            return ;
                      /*  if(e->first == this->edge[i]->first && e->second == this->edge[i]->second && e->weight == this->edge[i]->weight){
                            edge.erase(i);
                            break;
                        }*/
                    }
                }
                void printEdge(){
                    cout << edge.size() << "\n";
                }
            protected:
        };
        class Edge{ // เก็บเส้นเชื่อมของกราฟ
            private:

            public:
                Node* first,*second;
                double weight;
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
                TYPE getFisrtKey(){
                    return first->getKey();
                }
                ~Edge(){};
            protected:

        };
int main(){
    Node *a,*b;
    Edge *c;

    a= new Node(1);
    b= new Node(2);
    a->addEdge(new Edge(a,new Node(2)));
    a->addEdge(new Edge(a,new Node(3)));
    a->addEdge(new Edge(a,new Node(4)));
    a->addEdge(new Edge(a,new Node(5)));
    //cout << a->edge[2]->getFisrtKey();
/*    a->printEdge();
    a->removeEdge(new Edge(a,new Node(2)));
    a->printEdge();
*/

}
