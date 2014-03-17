#include<iostream>
#include"../Class/ClassLinkedList.hpp"
template<typename TYPE>
class Stack
{
    private:
        LinkedList<TYPE> lst;
    public:
        Stack(){};
        ~Stack(){};
        void Push(TYPE x){
            lst.insertHead(x);
        }
        void Pop(){
            if(!lst.isEmpty())
                lst.deleteHead();
            else
                cout << "Error stack underflow \n";

        }
        TYPE Peek(){
            if(lst.isEmpty()){
                cout << "Error stack underflow \n";
            }
            else{
                lst.getFront();
            }
        }
        bool isEmpty(){
            return lst.isEmpty();
        }
        void print(){
            lst.print();
        }
    protected:

};

int main(){
    Stack<int> st;
    st.Push(5.0);
    st.Push(6.5);
    st.Push(-3.0);
    st.Push(-8.0);
    st.print();
    cout << "Top:" << st.Peek() <<"\n";
    st.Pop();
    cout << "Top:" << st.Peek() << "\n";
    st.Pop();
    st.Pop();
    st.Pop();
    while(!st.isEmpty())st.Pop();
   st.print();
    return 0;
}
