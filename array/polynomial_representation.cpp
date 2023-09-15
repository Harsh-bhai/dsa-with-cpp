#include <bits/stdc++.h>
using namespace std;
class term{
public:
    int coeff;
    int power;
};
class polynomial{
private:
    int numOfElements;
    term * arr;
public:
    polynomial(int n){
        numOfElements=n;
        arr=new term[numOfElements];
    }
    ~polynomial(){
        delete []arr;
    }
    void set(){
        for (int i = 0; i < numOfElements; i++)
        {
            cout << "enter term "<<i+1<< endl;
            cin >> arr[i].coeff >> arr[i].power;
        }
    }

    void display(){
        for (int i = 0; i < numOfElements; i++)
        {
            printf("%dx^%d ",arr[i].coeff,arr[i].power);
            if(i<numOfElements-1)
                cout<<"+ ";
        }
    }

    polynomial add(polynomial a){
        int i=0,j=0,k=0;
        polynomial p(numOfElements +a.numOfElements);
       while(i<numOfElements && j<a.numOfElements)
        {
            if(arr[i].power>a.arr[j].power)   //copy higest power
                p.arr[k++]=arr[i++];
            else if(arr[i].power<a.arr[j].power)
                p.arr[k++]=arr[j++];
            else{
                p.arr[k]=arr[i];
                p.arr[k++].coeff=arr[i++].coeff+a.arr[j++].coeff;
            }
        }
        for (; i < numOfElements; i++)
            p.arr[k++]=arr[i];
        for (; j < a.numOfElements; j++)
            p.arr[k++]=arr[j];
        a.numOfElements=k;
        return p;
    }
};
int main() {
    polynomial p(3);
    polynomial p1(3);
    p.set();
    p1.set();
    polynomial p2=p.add(p1);
    p2.display();
    return 0;
}