#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next,*prev;
};
class DoublyLinkedList{
    public:
        Node *head;
        DoublyLinkedList(){
            head=NULL;
        }
        DoublyLinkedList(int arr[],int n){
            Node* t,*last;
            head= new Node;
            head->data=arr[0];
            head->next=NULL;
            head->prev=NULL;
            last=head;
            for (int i = 1; i < n; i++)
            {
                t= new Node;
                t->data=arr[i];
                t->prev=last;
                last->next=t;
                t->next=NULL;
                last=t;
            }
        }

  ~DoublyLinkedList()
    {
        Node *p = head;
        while (head)
        {
            head = head->next;
            delete p;
            p = head;
        }
    }

        void display(){
            Node * ptr=head;
            while (ptr)
            {
                cout<<ptr->data<<" ";
                ptr=ptr->next;
            }
        }

        void insert(int index,int element){
            Node *ptr=head;
            Node *t=new Node;
            t->data=element;
            if(index==0){
                t->prev=NULL;
                t->next=ptr;
                ptr->prev=t;
                head=t;
            }
            else{
                for (int i = 0; i < index-1; i++)
                    ptr=ptr->next;
                t->next=ptr->next;
                t->prev=ptr;
                ptr->next=t;
            }
        }

        int Delete(int index){
            Node *ptr=head;
            Node *q=NULL;
            int data;
            if(index==0){
                head=head->next;
                data=ptr->data;
                head->prev=NULL;
            }
            else
            {
                for (int i = 0; i < index; i++){
                    q=ptr;
                    ptr=ptr->next;
                }
                ptr->next->prev=q;
                q->next=ptr->next;
            }
            delete ptr;
            return data;
        }

        void reverse(){
            Node *ptr=head;
            Node *temp=NULL;
            while(ptr){
                temp=ptr->next;
                ptr->next=ptr->prev;
                ptr->prev=temp;
                ptr=ptr->prev;
                if(ptr!=NULL){
                    head=ptr;
                }
            }
        }

        
};
int main() {
    
    int arr[5]={1,2,3,4,5};
    DoublyLinkedList d(arr,5);
    d.display();
    d.reverse();
    cout <<  endl;
    d.display();
    return 0;
}