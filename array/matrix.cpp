#include <bits/stdc++.h>

using namespace std;
// destructor and get(index)

class DiagonalMatrix
{ // if i==j --> non zero, else zero
private:
    int n; // dimension
    int *arr;

public:
    DiagonalMatrix()
    {
        n = 2;
        arr = new int[2];
    }
    DiagonalMatrix(int dim)
    {
        n = dim;
        arr = new int[n];
    }

    void setDimension(int dim)
    {
        n = dim;
    }
    void set(int a[])
    {
        for (int i = 0; i < n; i++)
            arr[i] = a[i];
    }
    void set()
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Enter element" << i + 1 << " :";
            cin >> arr[i];
        }
    }

    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    cout << arr[i] << " ";
                else
                    cout << 0 << " ";
            }
            cout << endl;
        }
    }
};
class LowerTriangularMatrix
{
    // if i>j-->non zero, else zero
private:
    int n; // dimension
    int *arr;

public:
    LowerTriangularMatrix()
    {
        n = 2;
        arr = new int[n * (n + 1) / 2];
    }
    LowerTriangularMatrix(int dim)
    {
        n = dim;
        arr = new int[n * (n + 1) / 2];
    }

    void setDimension(int dim)
    {
        n = dim;
    }
    void setElement(int i, int j, int x)
    {
        if (i >= j)
            arr[i * (i - 1) / 2 + j - 1] = x;
    }
    void setMatrix()
    {
        int x;
        cout << "enter matrix" << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> x;
                setElement(i, j, x);
            }
        }
    }

    void display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i >= j)
                    cout << arr[i * (i - 1) / 2 + j - 1] << " ";
                else
                    cout << 0 << " ";
            }
            cout << endl;
        }
    }
};
class UpperTriangularMatrix
{
    // if i>j-->non zero, else zero
private:
    int n; // dimension
    int *arr;

public:
    UpperTriangularMatrix()
    {
        n = 2;
        arr = new int[n * (n + 1) / 2];
    }
    UpperTriangularMatrix(int dim)
    {
        n = dim;
        arr = new int[n * (n + 1) / 2];
    }

    void setDimension(int dim)
    {
        n = dim;
    }
    void setElement(int i, int j, int x)
    {
        if (j >= i)
            arr[j * (j - 1) / 2 + i - 1] = x;
    }
    void setMatrix()
    {
        int x;
        cout << "enter matrix" << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> x;
                setElement(j, i, x);
            }
        }
    }

    void display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j >= i)
                    cout << arr[j * (j - 1) / 2 + i - 1] << " ";
                else
                    cout << 0 << " ";
            }
            cout << endl;
        }
    }
};
class TriDiagonalMatrix //|i-j|<=1
{
private:
    int n; // dimension
    int *arr;

public:
    TriDiagonalMatrix()
    {
        n = 2;
        arr = new int[3 * n - 2];
    }
    TriDiagonalMatrix(int dim)
    {
        n = dim;
        arr = new int[3 * n - 2];
    }

    void setDimension(int dim)
    {
        n = dim;
    }
    void setElement(int i, int j, int x)
    {
        if (i - j == 1)
            arr[j - 1] = x;
        else if (i - j == 0)
            arr[n - 1 + j - 1] = x;
        else if (i - j == -1)
            arr[2 * n - 1 + j - 1] = x;
    }
    void setMatrix()
    {
        int x;
        cout << "enter matrix" << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> x;
                setElement(i, j, x);
            }
        }
    }

    void display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i - j == 1)
                    cout << arr[j - 1] << " ";
                else if (i - j == 0)
                    cout << arr[n - 1 + j - 1] << " ";
                else if (i - j == -1)
                    cout << arr[2 * n - 1 + j - 1] << " ";
                else
                    cout << 0 << " ";
            }
            cout << endl;
        }
    }
};

class Symmetric
{ // a[i][j]==a[j][i] non zero else zero
  // if i>j-->non zero, else zero
private:
    int n; // dimension
    int *arr;

public:
    Symmetric()
    {
        n = 2;
        arr = new int[n * (n + 1) / 2];
    }
    Symmetric(int dim)
    {
        n = dim;
        arr = new int[n * (n + 1) / 2];
    }

    void setDimension(int dim)
    {
        n = dim;
    }
    void setElement(int i, int j, int x)
    {
        if (i >= j)
            arr[i * (i - 1) / 2 + j - 1] = x;
    }
    void setMatrix()
    {
        int x;
        cout << "enter matrix" << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> x;
                setElement(i, j, x);
            }
        }
    }

    void displayArr()
    {
        for (int i = 0; i < n * (n + 1) / 2; i++)
        {
            cout << arr[i] << endl;
        }
    }

    void display()
    {
        int offset = 0, acc = 0;
        for (int i = 1; i < n; i++)
        {
            offset += i;
            for (int j = i - 1; j < n; j++)
                cout << arr[j] << " ";
            for (int k = i; k < n - 1; k++)
            {
                acc = offset + i;
                cout << arr[acc + i] << " ";
            }
            cout << endl;
        }
    }
};

class Toeplitz
{
    // a[i][j]=aa[i-1,j-1]
    // every element in the diagonal are same .storing a row and column is sufficient i.e., n+(n-1) elements
private:
    int n; // dimension
    int *arr;

public:
    Toeplitz()
    {
        n = 2;
        arr = new int[2 * n - 1];
    }
    Toeplitz(int dim)
    {
        n = dim;
        arr = new int[2 * n - 1];
    }

    void setDimension(int dim)
    {
        n = dim;
    }
    void setElement(int i, int j, int x)
    {
        if (i <= j)
            arr[j - i] = x;
        else
            arr[n + i - j] = x;
    }
    void setMatrix()
    {
        int x;
        cout << "enter matrix" << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> x;
                setElement(i, j, x);
            }
        }
    }

    void display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i <= j)
                    cout << arr[j - i] << " ";
                else
                    cout << arr[n + i - j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Toeplitz d(3);
    // int a[6] = {1, 2, 3, 4, 5, 6};
    d.setMatrix();
    // d.displayArr();
    // d.set();
    d.display();
    return 0;
}