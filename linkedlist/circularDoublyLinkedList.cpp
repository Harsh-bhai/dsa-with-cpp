#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *prev;
        Node *next;
};
class CircularDoublyLinkedList{
    public:
        Node *head;
        CircularDoublyLinkedList(){
            head=NULL;
        }
        CircularDoublyLinkedList(int arr[],int n){
            Node *last,*t;
            head=new Node;
            head->data=arr[0];
            head->next=NULL;
            head->prev=NULL;
            last=head;
            for (int i = 1; i < n; i++)
            {
                t=new Node;
                t->data=arr[i];
                last->next=t;
                t->next=head;
                t->prev=last;
                last=t;
            }
        }

        void display(){
            Node *ptr=head;
            do{
                cout << ptr->data <<" ";
                ptr=ptr->next;
            }while(ptr!=head);
        }
};
int main() {
    int arr[5]={1,2,3,4,5};
    CircularDoublyLinkedList c(arr,5);
    c.display();
    return 0;
}