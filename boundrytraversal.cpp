#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int>* root){
    if(root==NULL) return true;
    if(root->left==NULL && root->right==NULL)
        return true;
    else
        return false;
}
void addLeftBoundry(TreeNode<int>* root, vector<int>&result){
   
    TreeNode<int>* curr = root->left;
    while (curr) {
        if (!isLeaf(curr))
          result.push_back(curr->val);
        if (curr->left)
          curr = curr->left;
        else
          curr = curr->right;
    }
}
void addRightBoundry(TreeNode<int>* root,vector<int>&result){
    TreeNode<int>* curr = root->right;
    vector<int> tmp;
    while(curr){
        if(!isLeaf(curr))
            tmp.push_back(curr->val);
        if(curr->right)
            curr=curr->right;
        else
            curr= curr->left;
    }
    for(int i= tmp.size()-1;i>=0;i--)
        result.push_back(tmp[i]);
}
void addLeaves(TreeNode<int>* root,vector<int>&result){
    if (isLeaf(root)) {
        result.push_back(root->val);
        return;
    }
    if(root->left)
        addLeaves(root->left, result);
    if(root->right)
        addLeaves(root->right, result);

}
vector<int> boundaryTraversal(TreeNode<int> *root)
{
    vector<int> result;
    if(root==NULL)
        return result;
    if(!isLeaf(root))
        result.push_back(root->val);
    addLeftBoundry(root,result);
    addLeaves(root,result);
    addRightBoundry(root,result);

    return result;
}
