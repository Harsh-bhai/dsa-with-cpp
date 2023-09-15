// #include <bits/stdc++.h>
// using namespace std;
// class Node{
//     public:
//         int col,element;
//         Node * next;
// };

// class SparseMatrix{
//     public:
//         int m,n;
//         Node ** arr;
//         SparseMatrix(int m,int n){
//             this->m=m;
//             this->n=n;
//             arr=new Node*[m];
//         }

//         void set(int row,int column,int value){
//             arr[row]=new Node;
//             arr[row]->col=column;
//             arr[row]->element=value;
//             arr[row]->next=NULL;
//         }
//         void display(){
//             for (int i = 0; i < m; i++)
//             {
//                 Node *ptr=arr[i];
//                 for (int j = 0; j < n; j++)
//                 {
//                     if(ptr->col==j){
//                         cout << ptr->element << " ";
//                         ptr=ptr->next;
//                 }
//                     else
//                         cout << "0" << " ";
//             }
//                 cout << endl;
//             }
            
//         }
// };
// int main() {
//     SparseMatrix s(3,3);
//     s.set(0,1,1);
//     s.set(1,1,4);
//     s.display();
//     return 0;
// }

#include <iostream>
using namespace std;

class Node {
public:
    int col, element;
    Node* next;

    Node(int c, int e) {
        col = c;
        element = e;
        next = nullptr;
    }
};

class SparseMatrix {
public:
    int m, n;
    Node** arr;

    SparseMatrix(int m, int n) {
        this->m = m;
        this->n = n;
        arr = new Node*[m];
        for (int i = 0; i < m; i++) {
            arr[i] = nullptr;
        }
    }

    void set(int row, int column, int value) {
        if (row < 0 || row >= m || column < 0 || column >= n) {
            cout << "Invalid position." << endl;
            return;
        }

        Node* newNode = new Node(column, value);
        Node* current = arr[row];

        if (current == nullptr || current->col > column) {
            newNode->next = current;
            arr[row] = newNode;
        } else {
            while (current->next != nullptr && current->next->col <= column) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void display() {
        for (int i = 0; i < m; i++) {
            Node* current = arr[i];
            for (int j = 0; j < n; j++) {
                if (current != nullptr && current->col == j) {
                    cout << current->element << " ";
                    current = current->next;
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    SparseMatrix s(3, 3);
    s.set(0, 1, 1);
    s.set(1, 1, 4);
    s.display();

    return 0;
}
