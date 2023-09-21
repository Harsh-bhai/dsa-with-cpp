#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }
    LinkedList(int a[], int n)
    {
        Node *last, *t; // last -> to denote the last node of linkedlist , t-> is for new node
        head = new Node;
        head->data = a[0];
        head->next = NULL;
        last = head;

        for (int i = 1; i < n; i++)
        {
            t = new Node;
            t->data = a[i];
            t->next = NULL;
            last->next = t; // we use last node to insert new node
            last = t;
        }
    }

    ~LinkedList()
    {
        Node *p = head;
        while (head->next != NULL)
        {
            head = head->next;
            delete p;
            p = head;
        }
    }

    void display()
    {
        Node *p = head;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }

    int length()
    {
        Node *p = head;
        int count = 0;
        while (p)
        {
            count++;
            p = p->next;
        }
        cout << "Length :" << count << endl;
        return count;
    }

    int sum()
    {
        Node *p = head;
        int s = 0;
        while (p)
        {
            s += p->data;
            p = p->next;
        }
        cout << "Sum :" << s << endl;
        return s;
    }

    int max()
    {
        Node *p = head;
        int m = p->data;   //assuming m as max value
        p = p->next;
        while (p)
        {
            if (m < p->data)
                m = p->data;
            p = p->next;
        }
        cout << "max :" << m << endl;
        return m;
    }

    bool search(int element)
    {
        Node *p = head;
        while (p)
        {
            if (p->data == element)
                return true;
            p = p->next;
        }
        return false;
    }
    // Node *findNode(int element)
    // {
    //     Node *p = head;
    //     while (p)
    //     {
    //         if (p->data == element)
    //             return p;
    //         p=p->next;
    //     }
    // return NULL;
    // }
    Node *fastSearch(int element)
    {
        Node *p, *q;
        p = head;
        q = NULL;
        while (p)
        {
            if (p->data == element)
            {
                q = p->next;
                p->next = head;
                head = p;
                return p;
            }
            q = p;
            p = p->next;
        }
        return NULL;
    }

    void insert(int index, int element)
    {
        Node *p = head;
        Node *t = new Node;
        t->data = element;
        if (index == 0)
        {
            t->next = head;
            head = t;
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
                p = p->next;
            t->next = p->next;
            p->next = t;
        }
    }

    void append(int element){
        Node* p=head;
        Node *t=new Node;
        t->data=element;
        if(head==NULL){
            t->next=NULL;
            head=t;
        }
        else{
            while(p->next)
            p=p->next;
            cout << p->data << endl;
            p->next=t;
            t->next=NULL;
        }
    }

    //take a pointer and check its next.data<element or not 
    //if greater, then stop and attach new node to pointer.next 
    //else pointer++
    Node* insertSorted(int element){
        Node* p=head;
        Node* t=new Node;
        t->data=element;
        if(element<p->data){
            t->next=head;
            head=t;
        }
        else{
            while(p && p->next->data<element)
                p=p->next;
            t->next=p->next;
            p->next=t;
        }
        return t;
    }


    int Delete(int index){
        Node *ptr=head;
        Node *q=NULL;
        int deletedValue;
        if(index==0){
            deletedValue=ptr->data;
            head=head->next;
        }
        else{
            for (int i = 0; i < index; i++){
                q=ptr;
                ptr=ptr->next;
            }
                q->next=ptr->next;
        }
            delete ptr;
        return deletedValue;
    }

    //take 2 pointers(1 tail pointer, let say i, j respectively) and then check whether j>i, if yes then sorted 
    bool isSorted(){
        Node* ptr=head;
        while(ptr->next){
            if(!(ptr->data<ptr->next->data))
                return false;
            ptr=ptr->next;
        }
        return true;
    }

    void removeDuplicates(){
        Node *ptr=head->next;  //tail pointer
        Node *q=head;
        while (ptr)
        {
            if(ptr->data==q->data){
            q->next=ptr->next;
            delete ptr;
            ptr=q->next;
        }
            else
            {   
                q=ptr;
                ptr=ptr->next;
            }
        }
    }

    // take an array and copy linked list data in it , then reverse copy the data from end into linkedlist
    void reverse(){
        int len=length();
        int arr[len],i=0;
        Node* ptr=head;
        while(ptr){
            arr[i++]=ptr->data;
            ptr=ptr->next;
        }
        i--;
        ptr=head;
        while (i>=0)
        {
          ptr->data=arr[i--];
          ptr=ptr->next;
        }
    }

    //take 3 pointers such that r is tail of q,q is tail of p.
    void reverse2(){
        Node*p=head;
        Node*q=NULL;
        Node*r=NULL;
        while(p){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        head=q;
    }

    void reverseRecursive(Node *p,Node *q){
        if(p!=NULL){
            reverseRecursive(p,p->next);
            p->next=q;
        }
        else
            head=q;

    }

    void concatenate(Node *p){
        Node* ptr=head;
        while(ptr->next)
            ptr=ptr->next;
        ptr->next=p;
    }

    LinkedList merge(LinkedList l){
        Node* q=l.head;
        Node *p=head;
        Node *last;
        LinkedList newl;
        if(p->data<q->data){
            newl.head=last=p;
            p=p->next;
        }
        else {
           newl.head=last=q;
           q=q->next;
        }
        while(p && q){
            if(p->data<q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
            else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
        }
        if(p)
            last->next=p;
        if(q)
            last->next=q;
        return newl;
    }

    bool isLoop(){
        Node *p,*q;
        p=q=head;
        while(q && p){
            p=p->next;
            q=q->next;
            if(q)
                q=q->next;
            else{
                q=NULL;
                return false;
            }
            if(p->next==q->next){
                return true;
            }
        }
        return false;
    }

    Node * findMiddle(){
        Node *ptr=head;
        Node* q=head;
        while (ptr->next)
        {
            q=q->next;
            ptr=ptr->next;
            if(ptr)
                ptr=ptr->next;

        }
        cout << q->data << endl;
        return q;
    }

/*
Another method: By using STACK
push all elements address of linkedlist in stack
then do no.of elements/2 and pop back that much elements
then the top value gives the middle address of stack
*/
    

    void findIntersection(){
        /*
        Intersection of LinkedListsL:

                1->2->3->4->5->6
                        /
                7->8->9
        above 2 linkedlist have an intersection node , so we have to find this

        procedure: USING STACKS
        1.take 2 stacks to store addresses of 2 linkedlists
        2.start poping out elements if elements in both stacks are same. Also maintain a copy of last poped out address.
        3.if element is different , STOP. Last copy is the intersection Node
        */
    }
};
int main()
{
    int arr[] = {1, 3, 3, 5, 9};
    LinkedList l(arr, 5);
    int arr2[] = {11, 31, 31, 51, 91};
    LinkedList l2(arr2, 5);
    // l2.fastSearch(11);
    l2.reverse2();
    // l.findMiddle();
    // LinkedList l;
    // l.display();
    // l.display();
    // l.length();
    // l.sum();
    // l.max();
    // Node *node=l.fastSearch(3);
    // cout<<node->data;
    // l.insert(0, 10);
    // l.insertSorted(7);
    // l.display();
    // l.Delete(2);
    // cout<<endl;
    // cout<<l.isSorted();
    // cout<<l.isLoop();
    // cout<<endl;
    return 0;
}