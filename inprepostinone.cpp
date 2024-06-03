#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int>> PreInPostTraversal(TreeNode* root){
    stack<pair<TreeNode*,int>>st;
    vector<int> pre,post,in;
    st.push({root,1});
    if(root==NULL)
        return {pre,in,post};
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        if(it.second==1){ //this is preorder
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->left)
                st.push({it.first->left,1});
        }
        else if(it.second==2){//this is inorder
            in.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->right)
                st.push({it.first->right,1});
        }
        else if(it.second==3){
            post.push_back(it.first->val);
        }
    
}
return {pre,in,post};
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = PreInPostTraversal(root);

     cout << "Preorder: ";
    for (int i = 0; i < result[0].size(); i++) {
        cout << result[0][i] << " ";
    }
    cout << endl;

    cout << "Inorder: ";
    for (int i = 0; i < result[1].size(); i++) {
        cout << result[1][i] << " ";
    }
    cout << endl;

    cout << "Postorder: ";
    for (int i = 0; i < result[2].size(); i++) {
        cout << result[2][i] << " ";
    }
    cout << endl;

    return 0;
    
    // cout << "Preorder: ";
    // for (int val : result[0]) {
    //     cout << val << " ";
    // }
    // cout << endl;

    // cout << "Inorder: ";
    // for (int val : result[1]) {
    //     cout << val << " ";
    // }
    // cout << endl;

    // cout << "Postorder: ";
    // for (int val : result[2]) {
    //     cout << val << " ";
    // }
    // cout << endl;
}
