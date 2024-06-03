#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL || q == NULL)
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Helper function to create a new TreeNode
TreeNode* newNode(int data) {
    TreeNode* node = new TreeNode(data);
    node->left = node->right = NULL;
    return node;
}

// Main function to test the isSameTree function
int main() {
    Solution solution;

    // Creating test trees:
    // Tree 1:
    //     1
    //    / \
    //   2   3
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    // Tree 2:
    //     1
    //    / \
    //   2   3
    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

    // Tree 3 (different structure):
    //     1
    //    / \
    //   2   4
    TreeNode* tree3 = new TreeNode(1);
    tree3->left = new TreeNode(2);
    tree3->right = new TreeNode(4);

    // Testing if tree1 and tree2 are the same
    bool result1 = solution.isSameTree(tree1, tree2);
    cout << "Tree 1 and Tree 2 are " << (result1 ? "the same" : "different") << "." << endl;

    // Testing if tree1 and tree3 are the same
    bool result2 = solution.isSameTree(tree1, tree3);
    cout << "Tree 1 and Tree 3 are " << (result2 ? "the same" : "different") << "." << endl;

    return 0;
}

