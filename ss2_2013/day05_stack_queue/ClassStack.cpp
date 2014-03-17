#include<iostream>
using namespace std;
template<typename TYPE>
class Stack
{
    private:
        int maxTop;
        int top;
        TYPE* values;
    public:
        Stack() : Stack(10){};
        Stack(int i){
            maxTop = i-1;
            values = new TYPE[i];
            top = -1;
        };
        ~Stack(){};
        bool isEmpty(){
            return top==-1;
        }
        bool isFull(){
            return top ==maxTop;
        }
        TYPE Peek(){
            if(!isEmpty()){
                return values[top];
            }
            else
            {
                cout << "ERROR underflow peak";
                return NULL;
            }
        }
        void Push(TYPE x){
            if(!isFull())
                values[++top]=x;
            else
                cout << "Stack Overflow!\n";
        }
        void Pop(){
            if(!isEmpty())
                top--;
            else
                cout << "Stack Underflow \n";
        }
        void print(){
            int i;
            for(i=0;i<=top;i++)
                cout << values[i] << " ";
                cout << "\n";
        }
    protected:

};
int main(){
    Stack<int> st(5);
    st.Push(5.0);
    st.Push(6.5);
    st.Push(-3.0);
    st.Push(-8.0);
    st.print();
    cout << "Top:" << st.Peek() <<"\n";
    st.Pop();
    cout << "Top:" << st.Peek() << "\n";
    while(!st.isEmpty())st.Pop();
    st.print();
}


