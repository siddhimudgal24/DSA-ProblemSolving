#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};
static int idx = -1;
Node* buildTree(vector<int>nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
    Node* curr = new Node(nodes[idx]);
    curr->left = buildTree(nodes);
    curr->right = buildTree(nodes);
    return curr;
}
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int currHeight = max(leftHeight,rightHeight)+1;
    return currHeight;
}
int diameter(Node* root){
    if(root == NULL){
        return 0;
    }
    int currDiameter = height(root->left)+height(root->right)+1;
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    return max(currDiameter,max(leftDiameter,rightDiameter));
}
int main(){
    vector<int>nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);
    cout<<"The root of the Tree"<<" ";
    cout<<root->data<<endl;
    cout<<"The diameter of the tree is "<<" ";
    cout<<diameter(root)<<endl;
    return 0;
}