// Search in a Binary Search Tree
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
    cout<<root->data<<" ";
    inorder(root->right);
}
// Inorder Traversal for any Binary Search Tree always gives a Sorted Order
bool Search(Node* root,int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(root->data > key){
        return Search(root->left,key);
    }
    return Search(root->right,key);
}
int main(){
    vector<int>nodes = {5,1,3,4,2,7};
    Node* root = buildBST(nodes,6);
    cout<<endl;
    int key;
    cout<<" enter the value of key that you want to check:";
    cin>>key;
    if(Search(root,key)){
        cout<<"TRUE"<<endl;
    }else{
        cout<<"FALSE"<<endl;
    }
    inorder(root);
    return 0;
}