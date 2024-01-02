#include <bits/stdc++.h>
using namespace std;

int Partiton(int arr[],int n,int low,int high){
    int pivot=arr[low];
    int p=low+1;
    int q=high;
    while(p<q){
        if(arr[p]<pivot)   // p looks for the element greater than pivot, if less than pivot found=> p++
            p++;
        if(arr[q]>pivot)   // q looks for the element small than pivot, if greater  found=> q--
            q--;
        if(p<q)
            swap(arr[p],arr[q]);
    }
    swap(pivot,arr[q]);   // if p crosses q (p>q) then swap q with pivot
    return q;
}

void quicksort(int arr[],int n,int low,int high){
    int pivot=Partiton(arr,n,low,high);
    quicksort(arr,n,low,pivot-1);  //do quicksort on pivot left
    quicksort(arr,n,pivot+1,high); //do quicksort on pivot right


    
}



int main() {
    int arr[]={2,4,5,1,3};
    quicksort(arr,5,0,4);
        for (int i = 0; i < 5; i++)
        cout<<arr[i]<<" ";
    return 0;
}