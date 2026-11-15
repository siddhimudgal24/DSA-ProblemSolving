#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data){
        this->val = data;
        left = right = NULL;
    }
};
class Solution {
public:
// this helper function is for preorder traversal
    vector<int>helper1(TreeNode* root,vector<int>&ans1){
        if(root == NULL){
            return {};
        }
        ans1.push_back(root->val);
        helper1(root->left,ans1);
        helper1(root->right,ans1);
        return ans1;
    }
// this helper function is for postorder traversal 
    vector<int>helper2(TreeNode* root,vector<int>&ans2){
        if(root == NULL){
            return {};
        }
        helper2(root->left,ans2);
        helper2(root->right,ans2);
        ans2.push_back(root->val);
        return ans2;
    }
    bool isSymmetric(TreeNode* root) {
        vector<int>ans1;
        vector<int>ans2;
        vector<int>preorder = helper1(root,ans1);
        vector<int>postorder = helper2(root,ans2);
        bool isSym = true;
        for(int i =0,j = postorder.size()-1;i<preorder.size(),j>=0;i++,j--){
            if(preorder[i]!=postorder[j]){
                isSym = false;
                break;
            }
        }
        return isSym;
    }
};