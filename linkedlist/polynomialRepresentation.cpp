#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int coeff;
    int pow;
    Node *next;
};

class Polynomial
{
public:
    Node *head;
    Polynomial(int max)
    {
        Node *last, *t;
        head = new Node;
        head->coeff = -1;
        head->pow = -1;
        last = head;
        for (int i = 0; i < max; i++)
        {
            t = new Node;
            cout << "enter element" << i + 1 << endl;
            cin >> t->coeff >> t->pow;
            last->next = t;
            t->next = NULL;
            last=t;
        }
    }

    void display(){
        head=head->next;
        Node *ptr=head;
        while (ptr)
        {
            printf("%dx^%d ",ptr->coeff,ptr->pow);
            if(ptr->next)cout<<"+ ";
            ptr=ptr->next;
        }
    }
};
int main()
{
    Polynomial p(3);
    p.display();
    return 0;
}