#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
};
class CircularLinkedList{
    public:
        Node *head;
        CircularLinkedList(){
            head=NULL;
        }
        CircularLinkedList(int arr[],int n){
            Node *last,*t;
            head=new Node;
            head->data=arr[0];
            head->next=NULL;
            last=head;

            for (int i = 1; i < n; i++)
            {
                t=new Node;
                t->data=arr[i];
                t->next=NULL;
                last->next=t;
                last=t;
            }
            last->next=head;
        }

        ~CircularLinkedList(){
            Node *ptr=head;
            do
            {
                delete ptr;
                head=head->next;
                ptr=head;
                
            } while (ptr!=head);
            
        }

        void display(){
            Node *ptr=head;
            do
            {
                cout<<ptr->data<<" ";
                ptr=ptr->next;
            } while (ptr!=head);
        }

        void recursiveDisplay(Node *ptr){
            int flag=0;
            if(ptr!=head || (flag==0)){
                flag=1;
                cout<<ptr->data;
                recursiveDisplay(ptr->next);
            }
            flag=0;
        }

        void insert(int index,int value){
            Node *t=new Node;
            t->data=value;
            t->next=NULL;
            Node *ptr=head;
            if(index==0){
                while(ptr->next!=head)
                    ptr=ptr->next;
                t->next=head;
                ptr->next=t;
                head=t;
            }
            else{
                for (int i = 0; i < index-1; i++)
                    ptr=ptr->next;
                t->next=ptr->next;
                ptr->next=t;
            }
        }

        int Delete(int index){
            Node *ptr=head;
            Node *q=NULL;
            int data;
            if(index==0){
                while(ptr->next!=head)
                    ptr=ptr->next;
                ptr->next=head->next;
                q=head;
                head=head->next;
                delete q;
            }
            else{
                for (int i = 0; i < index; i++){
                    q=ptr;
                    ptr=ptr->next;
                }
                q->next=ptr->next;
                delete ptr;
            }
        return data;
        }
};
int main() {
    int arr[5]={1,2,3,4,5};
    CircularLinkedList c(arr,5);
    c.display();
    cout<<endl;
    c.Delete(1);
    c.display();
    return 0;
}