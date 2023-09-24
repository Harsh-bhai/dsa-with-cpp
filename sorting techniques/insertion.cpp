#include <bits/stdc++.h>
using namespace std;
// insert the elements in the sorted array in the sorted position
// {1,3,4,6,8}  insert 5 in this  

void insertionSort(int arr[],int n){
    int i,j,toBeInserted;
    for (i = 1; i < n; i++)  // n-1 comparisons, as first element is assumed to be sorted
    {
        j=i-1;
        toBeInserted=arr[i];  // i th element is to be inserted in the sorted array
        while (j>-1 && arr[j]>toBeInserted)  //check whether the element to be inserted < sorted array elements
        {
            arr[j+1]=arr[j];     //shift elements backward
            j--;
        }
        arr[j+1]=toBeInserted;   // place the element at j+1 place 
    }
    // printing
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main() {
    int arr[]={3,5,6,32,56};
    insertionSort(arr,4);
    return 0;
}