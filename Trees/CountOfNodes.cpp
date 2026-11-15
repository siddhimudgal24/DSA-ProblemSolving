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
int countOfNodes(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftcount = countOfNodes(root->left);
    int rightcount = countOfNodes(root->right);
    int currcount = leftcount+ rightcount+1;
    return currcount;
}
int main(){
    vector<int>nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);
    cout<<"The root of the Tree"<<" ";
    cout<<root->data<<endl;
    cout<<"The height of the tree is "<<" ";
    cout<<countOfNodes(root)<<endl;
    return 0;
}