//计算给定二叉树的所有左叶子之和。 
//
// 示例： 
//
// 
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24 
//
// 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 
// 👍 366 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
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
class Solution {
private:
    int sum;
public:
    // 是不是左节点，只有根节点知道
    // 直接告诉子节点，你是不是左节点
    void dfs(TreeNode* root, bool isLeft) {
        if (root == nullptr) {
            return;
        }
        // 叶子节点
        if (root->left == nullptr && root->right == nullptr) {
            if (isLeft) {
                sum += root->val;
            }
        } else {
            dfs(root->left, true);
            dfs(root->right, false);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root, false);
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
