#include <iostream>
using namespace std;

bool isInputPresent(int target, int array[], int size)
{
    for (int i = 0; i < size; i++){
        if (array[i] == target){
            return true;
        }
    }
    return false;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 1, 2, 1, 5, 7};
    int length = sizeof(arr) / sizeof(arr[0]);
    int a;
    cout << "enter element to find 1st and last occurance " << endl;
    cin >> a;
    int first, last;
    int present = isInputPresent(a, arr, length);
    if (present){
        for (int i = 0; i < length; i++){
            if (a == arr[i]){
                first = i;
                break;
            }
        }
        if (first + 1 < length){
            for (int i = first + 1; i < length; i++){
                if (a == arr[i]){
                    last = i;
                }
            }
        }
        else{
            last = first;
        }
        cout << "first occurance of " << a << ": " << first << endl;
        cout << "last occurance of " << a << ": " << last << endl;
    }
    else{
        cout << a << "is not present in array" << endl;
    }

    return 0;
}