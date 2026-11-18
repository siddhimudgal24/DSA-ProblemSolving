// Build Binary search Tree
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left =right = NULL;
    }
};
Node* insert(Node* root,int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }
    if(val<root->data){
        root->left = insert(root->left,val);
    }else{
        root->right = insert(root->right,val);
    }
    return root;
}
Node* buildBST(vector<int>nodes,int n){
    Node* root = NULL;
    for(int i =0;i<n;i++){
        root = insert(root,nodes[i]);
    }
    return root;
}
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}
// Inorder Traversal for any Binary Search Tree always gives a Sorted Order
int main(){
    vector<int>nodes = {5,1,3,4,2,7};
    Node* root = buildBST(nodes,6);
    inorder(root);
    return 0;
}