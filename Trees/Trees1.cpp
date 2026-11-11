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

// now lets write the code for tree traversals 
// there are three types of tree traversals that are : - preorder,inorder,postorder(recursive approach)  and level order(iterative approach)
// in these tree traversals code also we will use recursion because for tree questions recursion is easier than the iterative approach
void preorder(Node* root){
   if(root == NULL){
       return;
   }
   cout<<root->data<<" ";
   preorder(root->left);
   preorder(root->right);
}
 
void inorder(Node* root){
   if(root == NULL){
       return;
   }
   inorder(root->left);
   cout<<root->data<<" ";
   inorder(root->right);
}

void postorder(Node* root){
   if(root == NULL){
       return;
   }
   postorder(root->left);
   postorder(root->right);
   cout<<root->data<<" ";
}

int main(){
    vector<int>nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);
    cout<<root->data<<endl;
    cout<<"the preorder traversal is:";
    preorder(root);
    cout<<endl;
    cout<<"The inorder Traversal is:";
    inorder(root);
    cout<<endl;
    cout<<"The postorder traversal is:";
    postorder(root);
    cout<<endl;

}
