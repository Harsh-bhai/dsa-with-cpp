#include <iostream>
using namespace std;
bool isInputPresent(int element, int arr[], int length)
{

    for (int i = 0; i < length; i++)
    {
        if (element == arr[i])
        {
            cout << i << endl;
            return true;
        }
        else
        {cout << i << endl;
            return false;
        }
    }
}
int main() {
        int arr[10] = {1, 2, 3, 4, 5, 1, 2, 1, 5, 7};
        isInputPresent(5,arr,10);
    return 0;
}