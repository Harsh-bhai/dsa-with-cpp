#include <bits/stdc++.h>
using namespace std;

class Element
{
public:
    int i, j, x; // i,j are indexes and x is the element
};

class Sparse
{
private:
    int m, n, total; // total= total no. of nonzero elements ,m,n are dimensions
    Element *arr;

public:
    Sparse(int m, int n, int total)
    {
        this->m = m;
        this->n = n;
        this->total = total;
        arr = new Element[this->total];
    }
    ~Sparse()
    {
        delete[] arr;
    }

    void set()
    {   
        cout << "enter matrix elements" << endl;
        for (int i = 0; i < total; i++)
        {
            cout << "enter " << i + 1 << " non zero element" << endl;
            cin >> arr[i].i >> arr[i].j >> arr[i].x;
        }
    }

    void display()
    {
        int k = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[k].i == i && arr[k].j == j)
                    cout << arr[k++].x << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }

    Sparse add(Sparse s1)
    {
        Sparse s2(m, n, s1.total + total);
        int i = 0, j = 0, k = 0;
        while (i < total && j < s1.total)
        {
            if (arr[i].i < s1.arr[j].i)
                s2.arr[k] = arr[i];
            else if (arr[i].i > s1.arr[j].i)
                s2.arr[k++] = s1.arr[j++];
            else
            {
                if (arr[i].j < s1.arr[j].j)
                    s2.arr[k++] = arr[i++];
                else if (arr[i].j > s1.arr[j].j)
                    s2.arr[k++] = s1.arr[j++];
                else
                {
                    s2.arr[k] = arr[i];
                    s2.arr[k++].x = arr[i++].x + s1.arr[j++].x;
                }
            }
        }
        for (; i < total; i++)
            s2.arr[k++]=arr[i];        
        for (; j < (s1.total); j++)
            s2.arr[k++]=s1.arr[j];        
        s2.total=k;
        return s2;
    }
};
int main()
{
    Sparse s(3, 3, 2);
    Sparse s1(3, 3, 2);
    s.set();
    s1.set();
    Sparse s3 = s.add(s1);
    s3.display();

    return 0;
}