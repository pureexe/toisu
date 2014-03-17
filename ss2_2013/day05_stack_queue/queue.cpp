#include<iostream>
using namespace std;
template<typename TYPE>
class Queue
{
    private:
        int arr_size,size,front,rear;
        TYPE* arr;
    public:
        Queue():Queue(10){};
        Queue(int a){
            arr_size = a-1;
             arr=new TYPE[a];
              size=0;
              front =0;
              };
        void Enqueue(TYPE x){
            size++;
            arr[(front+size-1)%arr_size]=x;
        }
        void Dequeue(){
            if(!isEmpty()){
                front=(front+1)%arr_size;
                size--;
            }
            else{
                cout << "Error queue underflow \n";
            }
        }
        TYPE Front(){
            if(isEmpty()){
                cout << "Error queue underflow \n";
            }
            else{
                return arr[front];
            }
        }
        TYPE Back(){
            if(isEmpty()){
                cout << "Error queue underflow \n";
            }
            else{
                return arr[(front+size-1)%arr_size];
            }
        }
        bool isEmpty(){
            return size==0;
        }
        void DisplayQueue(){
            int i;
            for(i=0;i<size;i++)
                cout << arr[(front+i)%arr_size];
                cout << "\n";
        }
        ~Queue(){};
    protected:

};


int main(){
    Queue<int> q;
    q.Enqueue(7);

    q.Enqueue(6);
    q.Enqueue(8);
        q.DisplayQueue();
    q.Dequeue();
    q.DisplayQueue();
    return 0;
}
