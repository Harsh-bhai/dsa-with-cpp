#include <bits/stdc++.h>
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
    ~Array()
    {
        delete[] arr;
    }

    void insert(int index, int element)
    //first check index is valid or not i.e, greater than 0 and less than length.start i from behind and copy one element back (arr[i+1]=arr[i]) and then set the value.and increase the length
    {
        if (index >= 0 && index < length)
        {
            for (int i = length - 1; i > index; i--)
            {
                arr[i + 1] = arr[i];
            }
            arr[index] = element;
            length++;
        }
    }

    int remove(int index)
    //first check the index is valid or not . the go to the index and copy arr[i]=arr[i+1] and reduce the length
    {
        int removeElement = 0;
        if (index >= 0 && index < length)
        {
            removeElement = arr[index];
            for (int i = 0; i < length; i++)
            {
                arr[i] = arr[i + 1];
            }
            length--;
        }
        return removeElement;
    }

    void display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void initailizeWithZero()
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
            length++;
        }
    }

    void setArray(int a[], int l)
    {

        for (int i = 0; i < l; i++)
        {
            arr[i] = a[i];
        }
        length = l;
    }

    int linearSearch(int element)
    {
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == element)
                return i;
        }
        return -1;
    }

    int binarySearch(int element)
    {
        int low = 0;
        int mid;
        int high = length - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (element == arr[mid])
            {
                // cout << "element found at " << mid << "th index" << endl;
                return mid;
            }
            else if (element < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }

    int binarySearchReccursive(int element, int low, int high)
    {
        if (low <= high)
        {
            int mid = (low + high) / 2;
            if (element == arr[mid])
                return mid;
            else if (element < arr[mid])
                return binarySearchReccursive(element, low, mid - 1);
            else
                return binarySearchReccursive(element, mid + 1, high);
        }
        return -1;
    }

    void get(int index)
    {
        cout << arr[index] << endl;
    }
    int max()
    {
        int m = arr[0];
        for (int i = 0; i < length; i++)
        {
            if (arr[i] > m)
                m = arr[i];
        }
        return m;
    }
    int min()
    {
        int m = arr[0];
        for (int i = 0; i < length; i++)
        {
            if (arr[i] < m)
                m = arr[i];
        }
        return m;
    }

    float avg()
    {
        float result;
        float sum = 0;
        for (int i = 0; i < length; i++)
        {
            sum = sum + arr[i];
        }
        result = (float)sum / length;
        return result;
    }

    void reverse1()
    //create an array and copy the elements from behind i.e., from j=length-1.the copy the elements from starting into the original array
    {
        int a[length], i, j;
        j = length - 1;
        i = 0;
        while (i < length)
        {
            a[j] = arr[i];
            j--;
            i++;
        }
        i = 0;
        while (i < length)
        {
            arr[i] = a[i];
            i++;
        }
        display();
    }
    void reverse2()
    //{1,2,3,4,5}
    // i       j
    //swap i and j and i++;j--;
    {
        int i, j;
        j = length - 1;
        i = 0;
        while (i <= j)
        {
            swap(arr[i], arr[j]);
            j--;
            i++;
        }
        display();
    }

    bool isSorted()
    {
        for (int i = 0; i < length - 1; i++)
        {
            if (!(arr[i] < arr[i + 1]))
                return false;
        }
        return true;
    }

    bool in(int element)
    {
        int i = binarySearch(element);
        if (i != -1)
            return true;
        return false;
    }

    Array merge(Array a)
    //merge procedure: take 3 variables i=0,j=0,k=0 and 3 arrays if element at i is small than j(arr[i]<arr[j]) copy smaller one i.e., arr[i] ;arr[k]=arr[i];i++;k++ and vice versa . these will be present in while loop and condition is i<length and j <length. copy remaining elements from array using for loop .

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

    Array Union(Array a)
    //use merge procedure with modifications.if element is equal ,copy only once i++;j++;k++; if i is small copy i;i++;k++; if j is small copy j;j++;k++;
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
            else if (arr[i] == a.arr[j])
            {
                result.arr[k] = arr[i];
                i++;
                j++;
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

    Array intersection(Array a)
    //use merge procedure with modifications.if elemnts are equal ,copy them i++;j++;k++; if i is small i++; if j is small j++;
    {
        int i = 0, j = 0, k = 0;
        Array result;

        while (i < length && j < a.length)
        {
            if (arr[i] < a.arr[j])
                i++;
            else if (arr[i] == a.arr[j])
            {
                result.arr[k] = arr[i];
                i++;
                j++;
                k++;
            }
            else
                j++;
        }

        result.length = k;
        result.size = length + a.length;
        return result;
    }

    Array difference(Array a)
    //use merge procedure with modifications.if element is equal,dont copy i++;j++; .if i is smaller copy that one i++;j++;k++; if j is smaller j++;.If any other elements are present in i copy that ones.
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
            else if (arr[i] == a.arr[j])
            {
                i++;
                j++;
            }
            else
                j++;
        }
        for (; i < length; i++)
        {
            result.arr[k] = arr[i];
            k++;
        }

        result.length = k;
        result.size = length + a.length;
        return result;
    }

    void findMissingELementInSequence()
    //use element-index technique.Create a diff = arr[0]-0,then check whether diff is constant, if not-> then element is missing .Find element =index + diff. In case of multiple missing element ,use a while loop till diff+index<element;diff++;cout<<elements. 
    {
        int difference = arr[0] - 0;
        for (int i = 0; i < length; i++)
        {
            if (arr[0] - i != difference)
            {
                while (difference + i < arr[i])
                {
                    cout << difference + i << endl;
                    difference++;
                }
            }
        }
    }
    void findMissingELementInSequenceHashing()
    //using concept of hashing increase the element at arr[i] postion of new array and then print 0 elements
    {
        int range = max();
        int low = min();
        Array a(range + 1);
        for (int i = 0; i < a.size; i++)
        {
            a.arr[i] = 0;
            a.length++;
        }

        for (int i = 0; i < length; i++)
            a.arr[arr[i]]++;

        for (int i = low; i < a.length; i++)
        {
            if (a.arr[i] == 0)
                cout << i << endl;
        }
    }

    int findNumberOfZeros()
    {
        int count = 0;
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == 0)
                count++;
        }
        return count;
    }
    void findDuplicatesHashing()
    {
        int range = max();
        int low = min();
        Array a(range + 1);
        a.initailizeWithZero();
        for (int i = 0; i < length; i++)
            a.arr[arr[i]]++;
        for (int i = low; i < a.length; i++)
        {
            if (a.arr[i] > 1)
                cout << i << ":" << a.arr[i] << " times" << endl;
        }
    }

    void findDuplicates()
    //create a variable named lastduplicate to remember if there is more than 1 duplicate element
    //check the i with i+1 postion and arr[i] is not equal to lastduplicate
    {
        int lastduplicate = 0;
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == arr[i + 1] && arr[i] != lastduplicate)
            {
                cout << arr[i] << endl;
                lastduplicate = arr[i];
            }
        }
    }

    void pairOfSumHashing(int number)
    {
        //create a new array and initailaze with 0, store the element at the arr[i] position of new array and then check if newarray[number-arr[i]]!=0
        Array a(max());
        a.initailizeWithZero();
        for (int i = 0; i < a.length; i++){
        if(arr[i]<a.length && a.arr[number-arr[i]]!=0)
            cout << arr[i]<<"+"<<number-arr[i]<<"="<<number << endl;
        a.arr[arr[i]]++;
        }
    }

    void pairOfSumSorted(int number){
        //{1,2,3,4,5}
        // i j______ compare i and j 
        for (int i = 0; i < length-1; i++)
        {
            for (int j = i+1; j < length; j++)
            {
                if(arr[j]==number-arr[i])
                    cout << arr[j]<<"+"<<number-arr[j]<<"="<<number << endl;
            }
        }
    }

    void pairOfsum(int number){
        //{1,2,3,4,5} number=4
        // i       j  
        //in this we will decrement the j if arr[i]+arr[j]<number and vise-versa.Because if number is greater then we must reduce j and i is as it is(small number + large number =number)
        int j=length-1;
        int i=0;
        while( i<j)
        {
            if(arr[i]+arr[j]==number){
                cout << arr[j]<<"+"<<number-arr[j]<<"="<<number << endl;
                j--;i++;
            }
            else if(arr[i]+arr[j]<number)
                j--;
            else
                i++;
        }
        
    }
};

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
int main()
{
    Array arr(10);
    Array arr2(10);
    int a[] = {0,1,2,3,4};
    int a2[] = {1, 2, 3, 4, 5};
    arr.setArray(a, 5);
    arr2.setArray(a2, 5);
    // Array a3 = arr.difference(arr2);
    // arr.findMissingELementInSequenceHashing();
    // arr.display();
    // arr.pairOfSumHashing(4);
    arr.pairOfsum(4);
    // a3.display();

    // arr.reverse2();
    // arr.display();
    // cout << arr.avg();
    return 0;
}