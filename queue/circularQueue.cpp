#include <bits/stdc++.h>
using namespace std;
//here block where front is pointing should be empty as initially front=0;if(front==rear) then it should be empty according to condition 
//also -1 will never come when we use mod operator. it can only be from 0 to size.
class CircularQueue{
    private:
        int size;
        int front=0;
        int rear=0;
        int *arr;

    public:
        CircularQueue(int size){
            this->size=size+1;  //since intialized as front=rear=0 and front is not storing value where it is pointing so thats why we have to increase the size by 1
            arr=new int[size];
        }

        bool isFull(){
            if((rear+1)%size==front)
                return true;
            return false;
        }

        bool isEmpty(){
            if(front==rear)
                return true;
            return false;
        }

        void enqueue(int element){
            if(isFull())
                return;
            rear=(rear+1)%size;
            arr[rear]=element;
        }

        int dequeue(){
            int deletedElement;
            if(isEmpty())
                return -1;
            front=(front+1)%size;
            deletedElement=arr[front];
            return deletedElement;
        }

        void display(){
            for (int i = front+1; i <=rear; i++)
                cout << arr[i] << " ";
        }
};
int main() {
    CircularQueue q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    cout<<endl;
    q.dequeue();
    q.display();
    return 0;
}