// Given an array arr[] of size N-1 with integers in the range of [1, N], the task is to find the missing number from the first N integers
using namespace std;
int max(int arr[],int length){
    int max=arr[0];
    for (int i = 0; i < length; i++){
        if(max<arr[i])
         max=arr[i];
    }
    return max;
}
int main() {
    int arr[]={1,2,4,5,6,7,8};
    int length=sizeof(arr)/sizeof(arr[0]);
    int maxval=max(arr,length);
    for (int  i = 0; i < maxval; i++)
    {
     //bad me dekhte h ab , sorted hona padega comparison ke liye , tabhi to compare kr payega ki arr1 aur arr2 ko    
    }
    
    return 0;
}