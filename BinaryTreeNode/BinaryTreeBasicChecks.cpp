#include "BinaryTreeStruct.hpp"
#include <iostream>
using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        } else {
            if (p == NULL || q == NULL || p->val != q->val) {
                return false;
            } else {
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            }
        }
    }
    // Given the root of a binary tree and an integer targetSum, return true if
    // the tree has a root-to-leaf path such that adding up all the values
    // along the path equals targetSum. A leaf is a node with no children.
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return false;
        }
        if (root->left == NULL && root->right == NULL && root->val == targetSum) {
            return true;
        }
        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }
};

void testIsSameTree() {
    Solution solution;
    cout << "testIsSameTree" << endl;

    // Test case 1: Both trees are empty
    TreeNode* tree1 = nullptr;
    TreeNode* tree2 = nullptr;
    cout << "Test case 1: " << (solution.isSameTree(tree1, tree2) ? "Passed" : "Failed") << endl;

    // Test case 2: Both trees are the same
    tree1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    tree2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    cout << "Test case 2: " << (solution.isSameTree(tree1, tree2) ? "Passed" : "Failed") << endl;

    // Clean up memory
    delete tree1->left;
    delete tree1->right;
    delete tree1;
    delete tree2->left;
    delete tree2->right;
    delete tree2;

    // Test case 3: Trees have different structures
    tree1 = new TreeNode(1, new TreeNode(2), nullptr);
    tree2 = new TreeNode(1, nullptr, new TreeNode(2));
    cout << "Test case 3: " << (solution.isSameTree(tree1, tree2) ? "Failed" : "Passed") << endl;

    // Clean up memory
    delete tree1->left;
    delete tree1;
    delete tree2->right;
    delete tree2;
}


void testHasPathSum() {
    Solution solution;

    // Test case 1: Tree has a path that sums to target
    TreeNode* root1 = new TreeNode(5,
        new TreeNode(4,
            new TreeNode(11,
                new TreeNode(7),
                new TreeNode(2)
            ), nullptr
        ),
        new TreeNode(8,
            new TreeNode(13),
            new TreeNode(4, nullptr, new TreeNode(1))
        )
    );

    cout << "testHasPathSum" << endl;
    cout << "Test case 1: " << (solution.hasPathSum(root1, 22) ? "Passed" : "Failed") << endl;

    // Test case 2: Tree does not have a path that sums to target
    TreeNode* root2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    cout << "Test case 2: " << (solution.hasPathSum(root2, 5) ? "Failed" : "Passed") << endl;

    // Test case 3: Empty tree
    TreeNode* root3 = nullptr;
    cout << "Test case 3: " << (solution.hasPathSum(root3, 0) ? "Failed" : "Passed") << endl;

    // Clean up memory
    delete root1->left->left->left;
    delete root1->left->left->right;
    delete root1->left->left;
    delete root1->left;
    delete root1->right->right;
    delete root1->right->left;
    delete root1->right;
    delete root1;

    delete root2->left;
    delete root2->right;
    delete root2;
}

int main() {
    testIsSameTree();
    testHasPathSum();
    return 0;
}
