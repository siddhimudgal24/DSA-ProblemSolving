#include<bits/stdc++.h>
using namespace std;
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

// this was basic level order traversal
vector<int>levelOrder(Node* root){
    vector<int>ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* currNode = q.front();
        q.pop();
        ans.push_back(currNode->data);
        if(currNode->left!=NULL){
            q.push(currNode->left);
        }if(currNode->right!=NULL){
            q.push(currNode->right);
        }
    }
    return ans;
}
int main(){
    vector<int>nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);
    cout<<root->data<<endl;
    vector<int>levelorder = levelOrder(root);
    for(int i =0;i<levelorder.size();i++){
        cout<<levelorder[i]<<endl;
    }
    return 0;
}