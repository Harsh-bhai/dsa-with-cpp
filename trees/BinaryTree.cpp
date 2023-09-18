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
        queue<TreeNode**> q ;
        
    
    public:

        void initBinaryTree(){
            root=new TreeNode;
            root->left=NULL;
            root->right=NULL;
            cout << "Enter root :" << endl;
            cin >> root->data;
            q.push(&(root));
            while(!q.empty()){
                TreeNode *t;
                TreeNode** p=q.front();
                q.pop();
                int ldata,rdata;
                cout << "Enter Left child:" << endl;
                cin >> ldata;
                if(ldata!=-1){
                    t=new TreeNode;
                    t->data=ldata;
                    t->left=t->right=NULL;
                    (*p)->left=t;
                    q.push(&(t));
                }
                cout << "Enter Right child:" << endl;
                cin >> rdata;
                if(rdata!=-1){
                    t=new TreeNode;
                    t->data=rdata;
                    t->left=t->right=NULL;
                    (*p)->right=t;
                    q.push(&t);
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
    
    void iterativePreOrder(){
        if(root){
            cout << "Iterative Pre Order :" << endl;
            iterativePreOrder(root);
        }
    }
    void iterativePreOrder(TreeNode * node){
        stack<TreeNode*> s;
        while(node!=NULL || s.empty()){
            if(node){
                cout << node->data << " ";
                s.push(node);
                node=node->left;
            }
            else{
                node =s.top();
                s.pop();
                node=node->right;
            }
        }
    }

    void levelOrder(){
        cout << "Level Order Traversal :" << endl;
        levelOrder(root);
    }

    void levelOrder(TreeNode * node){
        queue<TreeNode *> q;
        cout << node->data << " ";
        q.push(node);
        while(!q.empty()){
            node=q.front();
            q.pop();
            if(node->left){
                cout << node->left->data << " ";
                q.push(node->left);
            }
            if(node->right){
                cout << node->right->data << " ";
                q.push(node->right);
            }
        }
    }

int sum(){
    return sum(root);
}
int sum(TreeNode * node){
    int leftCount,rightCount;
    if(node){
        leftCount=sum(node->left);
        rightCount=sum(node->right);
        return leftCount+rightCount+node->data;
    }
    return 0;
}
int height(){
    return height(root);
}
int height(TreeNode * node){
    int leftHeight=0,rightHeight=0;
    if(node){
        leftHeight=height(node->left);
        rightHeight=height(node->right);
        if(leftHeight>rightHeight)
            return leftHeight+1;
        return rightHeight+1;
    }
    return 0;
}
int countNode(){
    return countNode(root);
}
int countNode(TreeNode * node){
    int leftCount,rightCount;
    if(node){
        leftCount=countNode(node->left);
        rightCount=countNode(node->right);
        return leftCount+rightCount+1;
    }
    return 0;
}
int leafNodes(){
    return leafNodes(root);
}
int leafNodes(TreeNode * node){
    int leftCount,rightCount;
    if(node){
        leftCount=leafNodes(node->left);
        rightCount=leafNodes(node->right);
        if(node->left && node->right)
            return leftCount+rightCount;
        return leftCount+rightCount+1;
    }
    return 0;
}
int degree2(){
    return degree2(root);
}
int degree2(TreeNode * node){
    int leftCount,rightCount;
    if(node){
        leftCount=degree2(node->left);
        rightCount=degree2(node->right);
        if(node->left && node->right)
            return leftCount+rightCount+1;
        return leftCount+rightCount;
    }
    return 0;
}
// int internalNodes(){
//     return internalNodes(root);
// }
// int internalNodes(TreeNode * node){
//     int leftCount,rightCount;
//     if(node){
//         leftCount=internalNodes(node->left);
//         rightCount=internalNodes(node->right);
//         if(node->left || node->right)
//             return leftCount+rightCount;
//         return leftCount+rightCount+1;
//     }
//     return 0;
// }
//  This is a template function, u can calculate height,no of 2 degree,1 degree nodes etc.
// int countNode(){        
//     return countNode(root);
// }
// int countNode(TreeNode * node){
//     int leftCount,rightCount;
//     if(node){
//         leftCount=countNode(node->left);
//         rightCount=countNode(node->right);
//         return leftCount+rightCount+1;
//     }
//     return 0;
// }

};
int main() {
    BinaryTree b;
    b.initBinaryTree();
    b.postOrder();
    return 0;
}