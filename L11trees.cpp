#include<bits/stdc++.h>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Postorderusing2stack{
    public:
    vector<int> Postorder2stack(TreeNode* root){
        vector<int> postorder;
        if(root==NULL)
            return postorder;
        stack<TreeNode*> st1,st2;
        st1.push(root);
        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);
            if(root->left){
                st1.push(root->left);
            }
            if(root->right){
                st1.push(root->right);
            }
        }
        while(!st2.empty()){
            root = st2.top();
            st2.pop();
            postorder.push_back(root->val);
        }
        return postorder;
    }
};
