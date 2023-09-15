#include <bits/stdc++.h>
using namespace std;

// template<class T>
class Queue{
    private:
        int size;
        int front=-1;
        int rear=-1;
        int *arr;
    
    public:
        Queue(){
            size=1;
            arr=new int[size];
        }
        Queue(int size){
            this->size=size;
            arr=new int[size];
        }

        //make array constructor also
        void resize(int size){
            this->size=size;
            arr=new int[size];
            front==rear==0;
        }

        bool isEmpty(){
            if(front==rear)
                return true;
            return false;
        }

        bool isFull(){
            if((rear+1)%size==front)
                return true;
            return false;
        }

        void enqueue(int element){
            if(isFull())
                return;
            rear++;
            arr[rear]=element;
        }
        int dequeue(){
            int deletedElement=-1;
            if(isEmpty())
                return -1;
            front++;
            deletedElement=arr[front];
            return deletedElement;
        }

        void display(){
            if(isEmpty())
                return;
            for (int i = front+1; i <= rear; i++)
                cout<<arr[i]<<' ';
        }

        void insertFromFront(int element){
            if(front==-1)
                return;
            else
                arr[front--]=element;
        }
        void deleteFromRear(){
            int deletedElement;
            if(rear==size-1)
                return;
            else
                deletedElement=arr[rear--];
        }
};


int main() {
    Queue q(3);
    q.enqueue(1);
    q.dequeue();
    q.enqueue(3);
    q.enqueue(31);
    q.display();
    q.insertFromFront(10);
    cout<<endl;
    q.display();
    return 0;
}