#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        TreeNode * left;
        TreeNode * right;
        int data;
        int height;
};

class AVL{
    public:
        TreeNode * root=NULL;

        int nodeHeight(TreeNode * node){
            if(node){
                int leftCount,rightCount;
                leftCount=nodeHeight(node->left);
                rightCount=nodeHeight(node->right);
                return leftCount>rightCount?leftCount+1:rightCount+1;
            }
            return 0;
        }

        int BalanceFactor(TreeNode * node){
            if(node){
                int leftCount,rightCount;
                leftCount=nodeHeight(node->left);
                rightCount=nodeHeight(node->right);
                return leftCount-rightCount;
            }
            return 0;
        }

        // Use rotation.md file as reference for better understanding
        TreeNode * LLrotation(TreeNode * node){
            TreeNode * nodel=node->left;  //new root, for more info go to rotation.md image
            TreeNode * nodelr=nodel->right;
                // Link nodes
            nodel->right=node;
            node->left=nodelr;   //no need to update height of nodelr
                // Adjust Heights
            node->height=nodeHeight(node);
            nodel->height=nodeHeight(nodel);

            if(node==root)
                root=nodel;
            return nodel;
        }
        TreeNode * LRrotation(TreeNode * node){
            TreeNode * nodel=node->left;
            TreeNode * nodelr=nodel->right;  //new root 
                // Link nodes
            nodel->right=nodelr->left;
            node->left=nodelr->right;
            nodelr->left=nodel;
            nodelr->right=node;
                // Adjust Heights
            nodel->height=nodeHeight(nodel);
            node->height=nodeHeight(node);
            nodelr->height=nodeHeight(nodelr);

            if(node==root)
                root=nodelr;
            return nodelr;
        }
        TreeNode * RRrotation(TreeNode * node){
            TreeNode * noder=node->right;
            TreeNode * noderl=noder->left;

            noder->left=node;
            node->right=noderl;

            noderl->height=nodeHeight(noderl);
            node->height=nodeHeight(node);

            if(node==root)
                root=noder;
            return noder;
        }
        TreeNode * RLrotation(TreeNode * node){
            TreeNode * noder=node->right;
            TreeNode * noderl=noder->left; //new root

            node->right=noderl->left;
            noder->left=noderl->right;
            noderl->right=noder;
            noderl->left=node;

            noderl->height=nodeHeight(noderl);
            node->height=nodeHeight(node);
            noder->height=nodeHeight(noder);

            if(node==root)
                root=noderl;
            return noderl;
        }
        void insert(int key){
            root=insert(root,key);
        }
        TreeNode * insert(TreeNode * node,int key){
            TreeNode * t=new TreeNode;
            if(node==NULL){
                t->data=key;
                t->right=t->left=NULL;
                t->height=1;  //starting height from 1 instead of 0
                node=t;
                return node;
            }
            else if(key<node->data)
                node->left=insert(node->left,key);
            else if(key>node->data)
                node->right=insert(node->right,key);
            else
                return NULL;
            node->height=nodeHeight(node);  //updating height
            if(BalanceFactor(node)==2 && BalanceFactor(node->left)==1)
                return LLrotation(node);
            else if(BalanceFactor(node)==2 && BalanceFactor(node->left)==-1)
                return LRrotation(node);
            else if(BalanceFactor(node)==-2 && BalanceFactor(node->left)==-1)
                return RRrotation(node);
            else if(BalanceFactor(node)==-2 && BalanceFactor(node->left)==11)
                return RLrotation(node);
            return node;
        }

        void inOrder(){
            inOrder(root);
        }

        void inOrder(TreeNode * node){
            if(node){
                inOrder(node->left);
                cout << node->data <<" ";
                inOrder(node->right);
            }
        }
};
int main() {
    AVL a;
    a.insert(10);
    a.insert(15);
    a.insert(12);
    a.inOrder();
    return 0;
}