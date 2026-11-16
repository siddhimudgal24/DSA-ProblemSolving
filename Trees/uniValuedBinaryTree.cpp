// leetcode - 965 (brute force approach)
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
vector<int>preorder(Node* root,vector<int>&ans){
    if(root == NULL){
            return {};
        }
    ans.push_back(root->data);
    preorder(root->left,ans);
    preorder(root->right,ans);
    return ans;
}
int main(){
    vector<int>nodes = {1, 1, 1, -1, -1, 1, -1, -1, 1, -1, 1, -1, -1};
    Node* root = buildTree(nodes);
    cout<<"The root of the Tree"<<" ";
    cout<<root->data<<endl;
    vector<int>ans;
    vector<int>finalans = preorder(root,ans);
    bool isUnivalue = true;
    for(int i =1;i<finalans.size();i++){
    if(finalans[i]!=finalans[i-1]){
        isUnivalue = false;
        break;
        }
    }
    if(isUnivalue == 1){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    return 0;
}