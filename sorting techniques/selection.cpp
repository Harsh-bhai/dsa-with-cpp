#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    int k;  // k points the min element
    for (int i = 0; i < n-1; i++)
    {
        for (int j= k = i; j < n; j++) 
        {
            if(arr[j]<arr[k])   // if any element found less than k
                k=j;            // bring k there
        }
        swap(arr[i],arr[k]);  // swap k with i so that smaller element will get its position
    }

    for (int i = 0; i < n; i++)   //printing elements
        cout<<arr[i]<<" ";
    
}

int main()
{
    int arr[]={3,5,6,1,2};
    selectionSort(arr,5);
    return 0;
}