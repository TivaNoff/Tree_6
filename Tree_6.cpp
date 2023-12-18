#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }

private:
    int maxPathSumHelper(TreeNode* node, int& maxSum) {
        if (!node) return 0;

        int leftMax = std::max(0, maxPathSumHelper(node->left, maxSum));
        int rightMax = std::max(0, maxPathSumHelper(node->right, maxSum));

        maxSum = std::max(maxSum, leftMax + rightMax + node->val);

        return std::max(leftMax, rightMax) + node->val;
    }
};

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    Solution solution1;
    std::cout << "Example 1 Output: " << solution1.maxPathSum(root1) << std::endl;

    TreeNode* root2 = new TreeNode(-10);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(20);
    root2->right->left = new TreeNode(15);
    root2->right->right = new TreeNode(7);

    Solution solution2;
    std::cout << "Example 2 Output: " << solution2.maxPathSum(root2) << std::endl;

    return 0;
}
