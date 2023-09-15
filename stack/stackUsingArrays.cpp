#include <bits/stdc++.h>
using namespace std;
template <class T>
class Stack
{
private:
    T top = -1;
    T *arr;
    T size;

public:
    Stack(T size)
    {
        this->size = size;
        arr = new T[size];
    }

    Stack(T a[], T size)
    {
        this->size = size;
        arr = new T[size];
        for (T i = 0; i < size; i++)
        {
            arr[i] = a[i];
            top++;
        }
    }

    void display()
    {
        for (T i = top; i > -1; i--)
            cout << arr[i] << " ";
    }

    bool isFull()
    {
        if (top == size - 1)
            return true;
        return false;
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        return false;
    }

    T peek(T index)
    {
        index += 1; // since peek(2) will return 4 in {1,2,3,4,5}
        T i = top;
        i = i - index;
        return arr[i];
    }

    T stackTop()
    {
        return arr[top];
    }

    void push(T element)
    {
        if (isFull())
            return;
        top++;
        arr[top] = element;
    }

    T pop()
    {
        T deletedElement;
        if (isEmpty())
            return -1;
        deletedElement = arr[top];
        top--;
        return deletedElement;
    }
};

bool checkParanthesis(string str)
{
    Stack<char> s(str.length());
    const char *arr = str.data();
    for (int i = 0; i < str.length(); i++)
    {
        if (arr[i] == '(')
            s.push('(');
        else if (arr[i] == ')')
        {
            if (s.isEmpty())
                return false;
            s.pop();
        }
    }
    return s.isEmpty() ? true : false;
}

bool AdvanceCheckParanthesis(string str){
    //difference of ( and ) { and } [ and ] in ascii code is either 1 or 2 
    Stack<char> s(str.length());
    const char *arr=str.data();
    char a;
    for (int i = 0; i < str.length(); i++)
    {
        if(arr[i]=='(' || arr[i]=='{' || arr[i]=='[')
            s.push(arr[i]);
        else if(arr[i]==')' || arr[i]=='}' || arr[i]==']'){
            a=s.pop();
            if(!(abs(arr[i]-a)==1 || abs(arr[i]-a)==2  ))
                return false;
        }
    }
    return s.isEmpty()?true:false;
}

bool isOperand(char chr){
    if(chr=='+' || chr=='-' || chr=='*' || chr=='/' || chr=='^' || chr=='=')
        return false;
    return true;
}
bool isBracket(char chr){
    if(chr=='(' || chr==')' || chr == '{' || chr=='}' || chr=='[' || chr==']')
        return true;
    return false;
}

int precedence (char chr){
    if(chr=='^')
        return 3;
    else if(chr=='*' || chr=='/')
        return 2;
    else if(chr=='+' || chr=='-')
        return 1;
    return 0;
}

string infixToPostfix(string str){  //ABC*EF-/+
    const char *arr=str.data();
    Stack<char> s(str.length());
    string result="";
    char popped;
    for (int i=0; i < str.length();i++)
    {   
        if(isBracket(arr[i]))
            i++;
        if(isOperand(arr[i])){
            result+=arr[i];
        }
        else{
            if( precedence(s.stackTop())<precedence(arr[i]))
                s.push(arr[i]);
            else{
                while(precedence(s.stackTop()) >=precedence(arr[i])){
                    popped=s.pop();
                    result+=popped;
                }
                s.push(arr[i]);
                
            }
        }
    }
    while (!s.isEmpty())
        result+=s.pop();
    
    return result;
}

int eval(string str){
    const char* arr=str.data();
    Stack<int> s(str.length());
    for (int i = 0; i < str.length(); i++)
    {
        if(isOperand(arr[i]))
            s.push(arr[i]);
        else{
            if(s.isEmpty())
                return -1;
            int val1=s.pop()-48;  //ascii value of 0 is 48
            int val2=s.pop()-48;
            switch (arr[i]) {
                case '+':
                    s.push((val2 + val1)+48);
                    break;
                case '-':
                    s.push((val2 - val1)+48);
                    break;
                case '*':
                    s.push((val2 * val1)+48);
                    break;
                case '/':
                    s.push((val2 / val1)+48);
                    break;
                case '^':
                    s.push((val2 ^ val1)+48);
                    break;
                default:
                    break;
            }
        }
    }
    return (s.stackTop()-48);
    
}
int main()
{
    // int arr[5]={1,2,3,4,5};
    // Stack<int> s(arr,5);
    // s.push(3);
    // s.push(4);
    // s.pop();
    // cout << s.peek(2) << endl;
    // s.display();
    // cout << checkParanthesis("(abc)");
    // cout <<AdvanceCheckParanthesis("([}])") << endl;
    // cout << infixToPostfix("2*3+5") << endl;
    cout << eval("23*5+") << endl;
    return 0;
}