#include<bits/stdc++.h>
using namespace std;
// lets create a class Node for the node structure of the tree
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

// lets create a buildTree function for creating a tree or building a tree using a given array preorder
static int idx= -1;// creating a static global variable idx
//we will be using the recursion to solve the problems for tree like first calling the function for left subtree and then calling the same function for right subtree
Node* buildTree(vector<int>nodes){
    idx++;
    if(nodes[idx]==-1){// base case
        return NULL;
    }
    Node *currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);
    return currNode;
}
Node* ans = NULL;
int LCA(Node* root,Node* p,Node* q){
    if(root == NULL){
        return 0;
    }
    int left = LCA(root->left,p,q);
    int right = LCA(root->right,p,q);
    int self = 0;
    if(root == p || root == q){
        self = 1;
    }
    int total = left+self+right;
    if(total == 2 && ans == NULL){
        ans = root;
    }
    return total;
}
int main(){
    vector<int>nodes = {3,5,6,-1,-1,2,7,-1,-1,4,-1,-1,1,0,-1,-1,8,-1,-1};// p = 5,q = 1
    Node* root = buildTree(nodes);
    Node* p = root->left;
    Node* q = root->right;
    cout<<root->data<<endl;
    int total = LCA(root,p,q);
    cout<<ans->data<<endl;
}
