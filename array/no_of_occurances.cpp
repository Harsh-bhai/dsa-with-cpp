#include <iostream>
using namespace std;
int main()
{
    int a, count{};
    int arr[10] = {1, 2, 3, 4, 5, 1, 2, 1, 5, 7};
    int length = sizeof(arr) / sizeof(arr[0]);
    cout << "enter value to find no of occurance" << endl;
    cin >> a;
    for (int i = 0; i < length; i++)
    {
        if (a == arr[i])
        {
            count++;
        }
    }
    cout << a << " occured " << count << " times";

    return 0;
}