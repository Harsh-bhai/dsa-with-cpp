#include <bits/stdc++.h>
using namespace std;

/*
A-Z=65-90
a-z=97-122
*/

int getlen(char arr[])
{
    int len = 0;
    while (arr[len] != '\0')
        len++;
    return len;
}

int masking(int a, int index)
{
    // ANDing->checking whether
    int b = 1;
    b = b << index;
    return a & b;
}
void merging(int &a, int index)
{
    // ORing
    int b = 1;
    b = b << index;
    a = a | b;
}

class String
{
private:
    // int size;
    int len;
    char *arr;

public:
    String(char a[])
    {
        arr = a;
        len = getlen(arr);
    }

    ~String()
    {
        delete[] arr;
    }

    int length()
    {
        len = 0;
        while (arr[len] != '\0')
            len++;
        return len;
    }
    void display()
    {
        for (int i = 0; i < len; i++)
            cout << arr[i];
    }

    void swapcase()
    {
        for (int i = 0; i < len; i++)
        {
            if (arr[i] >= 65 && arr[i] <= 90)
                arr[i] += 32;
            else if (arr[i] >= 97 && arr[i] <= 122)
                arr[i] -= 32;
        }
    }

    void toLowerCase()
    {
        for (int i = 0; i < len; i++)
        {
            if (arr[i] >= 65 && arr[i] <= 90)
                arr[i] += 32;
        }
    }

    void reverse()
    {
        int j = len - 1, temp;
        for (int i = 0; i < j; i++)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

    void reverse2()
    {
        char a[len];
        int j = len - 1;
        for (int i = 0; i < len; i++, j--)
            a[i] = arr[j];

        for (int i = 0; i < len; i++)
            arr[i] = a[i];
    }

    void findVowelsAndConsonants()
    {
        int vowel = 0, consonants = 0;

        for (int i = 0; i < len; i++)
        {
            if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u' || arr[i] == 'A' || arr[i] == 'E' || arr[i] == 'I' || arr[i] == 'O' || arr[i] == 'U')
                vowel++;
            else if ((arr[i] >= 65 && arr[i] <= 97) || (arr[i] >= 97 && arr[i] <= 122))
                consonants++;
        }
        cout << "vowels :" << vowel << " consontants :" << consonants << endl;
    }

    void findDuplicatesHashing()
    {
        int a[25];
        toLowerCase();
        for (int i = 0; i < 25; i++)
            a[i] = 0;

        for (int i = 0; i < len; i++)
            a[(int)arr[i] - 97]++;

        for (int i = 0; i < 25; i++)
        {
            if (a[i] > 1)
                cout << char(97 + i) << ":" << a[i] << endl;
        }
    }

    void findDuplicatesBits()
    {
        int result = 0;
        toLowerCase();
        for (int i = 0; i < len; i++)
        {
            // cout<<result<<endl;
            if (masking(result, arr[i] - 97))
                cout << arr[i] << endl;
            else
                merging(result, arr[i] - 97);
        }
    }

    bool isAnagram(String s1)
    {
        // anagram ex: decimal and medical
        int result;
        bool anagram = false;
        s1.toLowerCase();
        toLowerCase();
        for (int i = 0; i < s1.len; i++)
            merging(result, s1.arr[i] - 97);

        for (int i = 0; i < len; i++)
        {
            if (masking(result, arr[i]))
                anagram = true;
            else
                anagram = false;
        }
        if (anagram)
            return true;
        return false;
    }

    void premutations(int k = 0)
    {
        // state space tree,backtracking:go back and take another route,brute force:getting all the possibilites.
        // recursion->backtracking->brutefore.
        /*
        abc            result={'a','b','c'}
        /                       i
       a               available={0 ,0 ,0}
      / \
     b   c
    /     \
   c       b
   this is the first case ,similar case for b and c also
        */

        char result[len + 1];
        int available[len + 1];
        for (int i = 0; i < len + 1; i++) // initalize array with 0s
            available[i] = 0;
        int i;
        if(k>len){
            for (int j = 0; j < len; j++)
                cout << result[j] << endl;
        }
      else
      {
          for (i = 0; i < len + 1; i++)
            if (available[i] == 0)
            {
                result[k] = arr[i];
                available[i] = 1; // 1 means not available and 0 means available
                premutations(k + 1);
                available[i] = 0;
            }
      }
      
    }
};

int main()
{
    char a[] = "decimal";
    char b[] = "medical";
    String s1(a), s2(b);
    s1.premutations();
    return 0;
}