/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
/**
 * Given the root of a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
*/
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) {
            return result;
        }
        vector<TreeNode*> queue{root};
        vector<TreeNode*> next_queue;
        while (!queue.empty()) {
            next_queue.clear();  // O(1)
            result.push_back(queue.back()->val);  // last element is always the most right
            for (TreeNode* cur_node: queue) {
                if (cur_node->left) {
                    next_queue.push_back(cur_node->left);
                }
                if (cur_node->right) {
                    next_queue.push_back(cur_node->right);
                }
            }
            queue = move(next_queue);  //  O(1)
        }
        return result;
    }
};