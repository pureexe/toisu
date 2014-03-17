#include<iostream>
#include"../Class/ClassLinkedList.hpp"
template<typename TYPE>
class Queue
{
    private:
        LinkedList<TYPE> lst;
    public:
        Queue(){};
        ~Queue(){};
        void Enqueue(TYPE x){
            lst.insertTail(x);
        }
        void Dequeue(){
            if(!lst.isEmpty())
                lst.deleteHead();
            else
                cout << "Error queue underflow \n";

        }
        TYPE Front(){
            if(lst.isEmpty()){
                cout << "Error queue underflow \n";
            }
            else{
                lst.getFront();
            }
        }
        TYPE Back(){
            if(lst.isEmpty()){
                cout << "Error queue underflow \n";
            }
            else{
                lst.getBack();
            }
        }
        bool isEmpty(){
            return lst.isEmpty();
        }
        void DisplayQueue(){
            lst.print();
            cout << "\n";
        }
    protected:

};

int main(){
    Queue<int> queue;
    cout << "Enqueue 5 items\n";
    for(int x = 0 ;x<5;x++)
        queue.Enqueue(x);
    cout << "Now attempting to enqueue again...\n";
    queue.Enqueue(5);
    queue.DisplayQueue();
    cout << queue.Front() << "\n";
    cout << queue.Back() << "\n";
    double value;
    value = queue.Front();
    queue.Dequeue();
    cout << "Retrieved element = " << value << "\n";
    queue.DisplayQueue();

    return 0;
}
