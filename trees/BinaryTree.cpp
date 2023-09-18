#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        TreeNode *left;
        TreeNode *right;
        int data;
};

class BinaryTree{
    private:
        TreeNode* root;
        queue<int*> q ;
        
    
    public:

        void initBinaryTree(){
            root=new TreeNode;
            root->left=NULL;
            root->right=NULL;
            cout << "Enter root :" << endl;
            cin >> root->data;
            q.push(&(root->data));
            while(!q.empty()){
                TreeNode *t;
                int* p=q.front();
                q.pop();
                int ldata,rdata;
                cout << "Enter Left child:" << endl;
                cin >> ldata;
                if(ldata!=-1){
                    t=new TreeNode;
                    t->data=ldata;
                    t->left=t->right=NULL;
                    root->left=t;
                    q.push(&ldata);
                }
                cout << "Enter Right child:" << endl;
                cin >> rdata;
                if(rdata!=-1){
                    t=new TreeNode;
                    t->data=rdata;
                    t->left=t->right=NULL;
                    root->right=t;
                    q.push(&rdata);
                }
            }   
        }
    void inOrder(){
        if(root){
           cout << "In Order Traversal:" << endl; 
           inOrder(root);
           cout<<endl;
        }
    }

    void inOrder(TreeNode* node){
        if(node){
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }
    void postOrder(){
        if(root){
           cout << "Post Order Traversal:" << endl; 
           postOrder(root);
           cout<<endl;
        }
    }

    void postOrder(TreeNode* node){
        if(node){
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << " ";
        }
    }
    void preOrder(){
        if(root){
           cout << "Pre Order Traversal:" << endl; 
           preOrder(root);
           cout<<endl;
        }
    }

    void preOrder(TreeNode* node){
        if(node){
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
    

};
int main() {
    BinaryTree b;
    b.initBinaryTree();
    b.preOrder();
    b.inOrder();
    b.postOrder();
    return 0;
}