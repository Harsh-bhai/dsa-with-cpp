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

int removeHighestPriorityFirst(Queue q1,Queue q2,Queue q3){
    if(!(q1.isEmpty()))
        return q1.dequeue();
    else if(!(q2.isEmpty()))
        return q2.dequeue();
    else
        return q3.dequeue();
}



int main() {
    int arr[]={1,2,3,1,2};
    int len=sizeof(arr)/sizeof(arr[0]);
    Queue q1(len);
    Queue q2(len);
    Queue q3(len);
    for (int i = 0; i < len; i++)
    {
        switch (arr[i])
        {
        case 1:
            q1.enqueue(arr[i]);
            break;
        case 2:
            q2.enqueue(arr[i]);
            break;
        case 3:
            q3.enqueue(arr[i]);
            break;
        }
    }
    q1.display();
    removeHighestPriorityFirst(q1,q2,q3);
    cout <<  endl;
    q1.display();
    return 0;
}