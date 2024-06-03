#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int maxPath(TreeNode* root, int &maxi) {
        if (root == NULL)
            return 0;

        // Compute the maximum path sum of the left and right subtrees
        int left = max(0, maxPath(root->left, maxi));
        int right = max(0, maxPath(root->right, maxi));

        // Update the maximum path sum considering the current node
        maxi = max(maxi, root->val + left + right);

        // Return the maximum path sum that can be extended to the parent
        return max(left, right) + root->val;
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPath(root, maxi);
        return maxi;
    }
};

// Helper function to create a new TreeNode
TreeNode* newNode(int data) {
    TreeNode* node = new TreeNode(data);
    node->left = node->right = NULL;
    return node;
}

// Main function to test the maxPathSum function
int main() {
    Solution solution;

    // Creating a test binary tree:
    //         -10
    //         /  \
    //        9   20
    //           /  \
    //          15   7
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Finding the maximum path sum
    int result = solution.maxPathSum(root);
    cout << "Maximum Path Sum: " << result << endl;

    

    return 0;
}

