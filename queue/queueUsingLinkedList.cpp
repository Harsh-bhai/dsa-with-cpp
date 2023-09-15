#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node *next;
        int data;
};

class Queue{
    private:
        Node *front;
        Node *rear;
        Node *t;
    
    public:
        Queue(int element){
           t=new Node;
           t->data=element;
           t->next=NULL;
           front=rear=t; 
        }

        bool isFull(){
            Node *t=new Node;
            if(t==NULL)
                return false;
            return true;
        }

        bool isEmpty(){
            if(front==NULL)
                return true;
            return false;
        }

        void enqueue(int element){
            t=new Node;
            t->data=element;
            t->next=NULL;
            rear->next=t;
            if(isEmpty())
                front=rear=t; 
            else
                rear=t;
        }

        void dequeue(){
            t=front;
            front=front->next;
            delete t;
        }

        void display(){
            t=front;
            while(t!=NULL){
                cout<<t->data<<" ";
                t=t->next;
            }
        }

};
int main() {
    Queue q(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    q.dequeue();cout <<  endl;
    q.display();
    return 0;
}