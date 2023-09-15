#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *next;
    int data;
};

class Stack
{
public:
    Node *top;
    Stack(){
        top=new Node;
        top->data=-1;
        top->next=NULL;
    }
    Stack(int element){
        top=new Node;
        top->data=element;
        top->next=NULL;
    }
    Stack(int arr[], int len)
    {
        top = new Node;
        Node *t;
        top->data = arr[0];
        top->next = NULL;
        for (int i = 1; i < len; i++)
        {
            t = new Node;
            t->data = arr[i];
            t->next = top;
            top = t;
        }
    }

    void display()
    {
        Node *t=top;
        while (t)
        {
            cout << t->data << " ";
            t = t->next;
        }
    }

    void push(int element)
    {
        Node *t = new Node;
        if (t == NULL) // checking if heap is full, as it can't overflow
                       //  because we can add infinite  elemetns in linked list
            cout << "Stack Overflow" << endl;
        else
        {
            t->data = element;
            t->next = top;
            top = t;
        }
    }

    int pop()
    {
        int deletedElement;
        if (top == NULL)
            cout << "Stack Underflow" << endl;
        else
        {
            deletedElement = top->data;
            Node *p = top;
            top = top->next;
            delete p;
        }
        return deletedElement;
    }

    int peek(int index)
    {
        Node *ptr = top;
        for (int i = 0; ptr != NULL && i < index - 1; i++)
            ptr = ptr->next;
        if (ptr == NULL)
            return -1;
        return ptr->data;
    }

    void enqueue(Stack s2,int element){
        push(element);
    }
    int dequeue(Stack s2){
        if(s2.top->data==-1){
            s2.pop();
            while(this->top)
                s2.push(this->pop());
        }
            
        int element=s2.pop();
        // if(element==-1)
        //     element=s2.pop();
        return element;
    }

    int QueueUsingStack(){
        int arr[]={1,2,3};
        Stack s1(arr,3);
        Stack s2;
        // s2.pop();
        s1.display();
        cout<<endl;
        return s1.dequeue(s2);
    }
};
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    // Stack s(arr, 5);
    // // s.push(12);
    // // s.pop();
    // // s.display();
    // // cout << "=====" << endl;
    // cout << s.peek(1) << endl;
    Stack s;
    cout<<s.QueueUsingStack();
    return 0;
}