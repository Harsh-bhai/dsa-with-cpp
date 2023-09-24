#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int arr[],int size){

    bool flag=false;                  // to check adaptive

    for (int i = 0; i < size-1; i++)  // loop for comparisons, max : n-1
    {
        for (int j = 0; j < size-i-1; j++) // loop for swapping, max : n-1
        {
            if(arr[j+1]<arr[j]){            // if first element in comparison is greater, swap it. Becuase bigger  element should be in last position
                swap(arr[j+1],arr[j]);
                flag=true;                  //true if no comparisons 
            }
        }
        if(flag==false)                      // in the first pass we can identify array is sorted or not
            cout << "Already Sorted" << endl;
    }
    // printing array
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
int main() {
    int arr[]={4,7,32,6,87,41};
    BubbleSort(arr,6);
    return 0;
}