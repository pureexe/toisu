#include<iostream>
using namespace std;
template<typename TYPE>
class Node
{
    private:

        TYPE info;
        Node* link;
    public:

        Node(){
            link=NULL;
        };
        void setInfo(TYPE inf){
            info = inf;
        }
        TYPE getInfo(){
            return info;
        }
        void setLink(Node *u){
            link =  u;
        }
        Node* getLink(){
            return link;
        }
        ~Node(){};
    protected:

};
int main(){
    Node<int> *head = NULL ;
    Node<int> *trav,*trav_old=NULL;

    /***  ใส่ค่าจากหลังมาหน้า
    for(int i=1;i<=5;i++){
        Node<int> *newNode = new Node<int>();
        int data;
        cin >> data;
        trav=head;
        if(head==NULL){
            newNode->setInfo(data);
            head = newNode;
            continue;
        }
        while(trav!=NULL&&trav->getLink()!=NULL){
                trav=trav->getLink();
        }
            newNode->setInfo(data);
            newNode->setLink(NULL);
            trav->setLink(newNode);
    }
    ***/
    /*
            while(trav!=NULL&&trav->getLink()!=NULL){
                if(data<=trav->getLink()->getInfo())
                    break;
                trav=trav->getLink();
        }
    */
    for(int i=1;i<=5;i++){
        Node<int> *newNode = new Node<int>();
        int data;
        cin >> data;
        trav=head;
        if(head==NULL){
            newNode->setInfo(data);
            head = newNode;
            continue;
        }
        while((trav!=NULL)&&trav->getInfo()<data){
                trav_old=trav;
                trav=trav->getLink();
        }
        newNode->setLink(trav);
        if(trav==head)
            head=newNode;
        else
            trav_old->setLink(newNode);
    }

    trav=head;
    while(trav!=NULL){
            cout << trav->getInfo() << " ";
        trav=trav->getLink();
    }
}
