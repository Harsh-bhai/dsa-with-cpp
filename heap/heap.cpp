#include <bits/stdc++.h>
using namespace std;

class Heap{
    private:
        int *arr;
        int size=0;
    public:
        Heap(int root){
            arr=new int[1];
            arr[size++]=root;
        }

        Heap(int *a,int len){
            arr=new int[len];
            for (int i = 0; i < len; i++)   //time complexity: nlogn
                insert(a[i]);
        }

        void insert(int element){           //time complexity: logn
            int i=size;
            arr[size++]=element;
            while(i>=1 && element>arr[i/2]){  //parent=arr[i/2]
                arr[i]=arr[i/2];             // replace parent(i/2) element with i
                i=i/2;                       // go to its parent
            }
            arr[i]=element;
        }

        void display(){
            for (int i = 0; i < size; i++)
                cout << arr[i] << " ";
        }

        void Delete(){                      // always root element is deleted, time complexity : logn 
            int maxElement=arr[0];// take out first/max element of heap
            int i=0,j=2*i; //check here witch 2*i+1                //take 2 pointer, i start from 1, j points to the left element of i
            arr[0]=arr[size-1];      //make last element as root
            while (i<size-2 && j<size-2)               //as last element is no more in heap 
            {
               if(arr[j+1]>arr[j])        // take out the largest element among left-right sibling
                    j++;

                if(arr[i]<arr[j]){        // if root(last element) < largest sibling
                    swap(arr[i],arr[j]);  //swap
                    i=j;                  // go to j position
                    j=2*j;                // go to its left element  and repeat the procedure
                }
                else
                    break;                // last element gets its place 
            }
            arr[size-1]=maxElement;
            size--;
        }
        
        // void displayArray(){
        //     for (int i = 0; i < 7; i++)
        //         cout << arr[i] << " ";
        // }


        // deleted elements are stored at the last postion of array, so all the max elements and stored a last of array, hence we gets deleted and we get the sorted list
        void HeapSort(int * a, int originalLength){  
            Heap h(a,originalLength);
            for (int i = 0; i <originalLength; i++)
                h.Delete();
            for (int i = 0; i <originalLength; i++)
                cout << h.arr[i] <<" ";        }
};
int main() {
    int arr[]={1,10,34,2,3,4,5};
    Heap h(1);
    h.HeapSort(arr,7);
    return 0;
}