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

// in this level order traversal we will print the elements level wise in a 2d array
vector<vector<int>>levelOrder2(Node* root){
    vector<vector<int>>ans;
    if(root == NULL){
        return ans;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        vector<int>level;
        int size = q.size();
        for(int i =0;i<size;i++){
            Node* curr = q.front();
            q.pop();
            level.push_back(curr->data);
            if(curr->left!=NULL){
                q.push(curr->left);
            }if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
        ans.push_back(level);
    }
    return ans;
}
int main(){
    vector<int>nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);
    cout<<root->data<<endl;
    vector<vector<int>>levelorder = levelOrder2(root);
    for(int i =0;i<levelorder.size();i++){
        for(int j = 0;j<levelorder[i].size();j++){
            cout<<levelorder[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}