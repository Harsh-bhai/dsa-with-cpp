#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        TreeNode * left;
        TreeNode * right;
        int data;
};

class BinarySearchTree{
    public:
        TreeNode* root=NULL;
        void insert(int key){
            root=insert(root,key);
        }
        TreeNode * insert(TreeNode* &node,int key){
            TreeNode *t,*tail=NULL;
            if(node==NULL){
                t=new TreeNode;
                t->data=key;
                t->left=t->right=NULL;
                node=t;
                return node;
            }
            while(node!=NULL){
                tail=node;
                if(node->data==key)
                    return NULL;
                else if(key<node->data)
                    node=node->left;
                else
                    node=node->right;
            }
                t=new TreeNode;
                t->data=key;
                t->left=t->right=NULL;
            
            if(key<tail->data)
                tail->left=t;
            else
                tail->right=t;
            return tail;
        }

        void inOrder(){
            inOrder(root);
        }

        void inOrder(TreeNode * node){
            if(node){
                inOrder(node->left);
                cout << node->data << " ";
                inOrder(node->right);
            }
        }

        bool search(int element){
           return search(root,element);
        }
        bool search(TreeNode * node,int element){
            while(node){
                if(node->data==element)
                    return true;
                else if(element<node->data)
                    node=node->left;
                else
                    node=node->right;
            }
            return false;
        }

        void recursiveInsert(int element){
            root=recursiveInsert(root,element);
        }
        TreeNode * recursiveInsert(TreeNode * node,int element){
            TreeNode *t=new TreeNode;
            if(node==NULL){
                t->data=element;
                t->left=t->right=NULL;
                node=t;
                return node;
            }
            else if(element<node->data)
                node->left=recursiveInsert(node->left,element);
            else if(element>node->data)
                node->right=recursiveInsert(node->right,element);
            else
                return NULL;
        return node;
        }

        int height(){
            return height(root)-1;
        }

        int height(TreeNode * node){
            int leftCount,rightCount;
            if(node){
                leftCount=height(node->left);
                rightCount=height(node->right);
                return leftCount>rightCount?leftCount+1:rightCount+1;
            }
            return 0;
        }

        TreeNode * inOrderPreceder(){
            return inOrderPreceder(root);
        }
        TreeNode * inOrderSucessor(){
            return inOrderSucessor(root);
        }

        TreeNode * inOrderPreceder(TreeNode * node){
            while(node && node->right){
               node=node->right; 
            }
            return node;
        }
        TreeNode * inOrderSucessor(TreeNode * node){
            while(node && node->left){
               node=node->left; 
            }
            return node;
        }

        void Delete(int key){
            Delete(root,key);
        }

        TreeNode * Delete(TreeNode * node,int key){
            TreeNode *temp;
            if(node->left==NULL && node->right==NULL){
                if(node==root)
                    root=NULL;
                delete node;
                return NULL;
            }
            if(key<node->data)
                node->left=Delete(node->left,key);
            else if(key>node->data)
                node->right=Delete(node->right,key);
            else{
                if(height(node->left)>height(node->right)){
                    temp=inOrderPreceder(node->left);
                    node->data=temp->data;
                    node->left=Delete(node->left,temp->data);
                }
                else{
                    temp=inOrderSucessor(node->right);
                    node->data=temp->data;
                    node->right=Delete(node->right,temp->data);
                }
            }
            return node;
        }
        
};
int main() {
    BinarySearchTree b;
    b.recursiveInsert(5);
    b.recursiveInsert(6);
    b.recursiveInsert(4);
    b.recursiveInsert(3);
    b.recursiveInsert(2);
    b.recursiveInsert(1);
    b.Delete(5);
    // cout<<b.height();
    b.inOrder();
    // cout<<b.search(4);
    return 0;
}