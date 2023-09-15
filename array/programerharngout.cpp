#include<bits/stdc++.h>
using namespace std;
class Array
{
private:
    int length;
    int size;
    int *arr;

public:
    Array()
    {
        size = 10;
        length = 0;
        arr = new int[size];
    }

    Array(int s)
    {
        size = s;
        length = 0;
        arr = new int[size];
    }
        void setArray(int a[], int l)
    {

        for (int i = 0; i < l; i++)
        {
            arr[i] = a[i];
        }
        length = l;
    }
    void display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

      Array merge(Array a)
    {
        int i = 0, j = 0, k = 0;
        Array result;

        while (i < length && j < a.length)
        {
            if (arr[i] < a.arr[j])
            {
                result.arr[k] = arr[i];
                i++;
                k++;
            }
            else
            {
                result.arr[k] = a.arr[j];
                j++;
                k++;
            }
        }
        for (; i < length; i++)
        {
            result.arr[k] = arr[i];
            k++;
        }
        for (; j < a.length; j++)
        {
            result.arr[k] = a.arr[j];
            k++;
        }

        result.length = k;
        result.size = length + a.length;
        return result;
    }
};
int main()
{
    Array arr(10);
    Array arr2(10);
    int a[] = {1, 3, 4, 5,6};
    int a2[] = {10, 2, 3, 4, 5};
    arr.setArray(a, 5);
    arr2.setArray(a2, 5);
    Array a3 = arr.merge(arr2);
    a3.display();
    return 0;
}