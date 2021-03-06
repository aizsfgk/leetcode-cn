//给定一个二叉树，判断它是否是高度平衡的二叉树。 
//
// 本题中，一棵高度平衡二叉树定义为： 
//
// 
// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：root = [1,2,2,3,3,null,null,4,4]
//输出：false
// 
//
// 示例 3： 
//
// 
//输入：root = []
//输出：true
// 
//
// 
//
// 提示： 
//
// 
// 树中的节点数在范围 [0, 5000] 内 
// -104 <= Node.val <= 104 
// 
// Related Topics 树 深度优先搜索 二叉树 
// 👍 819 👎 0


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
//private:
//    int abs(int a) {
//        if (a >= 0) {
//            return a;
//        } else {
//            return -a;
//        }
//    }
//
//    int max(int a, int b) {
//        if (a>b) {
//            return a;
//        } else {
//            return b;
//        }
//    }
public:
    int height(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        } else {
            return 1 + max(height(root->left), height(root->right));
        }
    }
    bool isBalanced(TreeNode* root) {
        // 1. 如果一个树是平衡二叉树，那么其左子树和右子树都是平衡二叉树
        // 2. 先求一个树的左右子树高度，看绝对值是否<=1
        // 3. 分别判断左右子树

        // note: nullptr 是平衡二叉树
        if (root == nullptr) {
            return true;
        } else {
            return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
