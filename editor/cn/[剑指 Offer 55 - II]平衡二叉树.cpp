//输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。 
//
// 
//
// 示例 1: 
//
// 给定二叉树 [3,9,20,null,null,15,7] 
//
// 
//    3
//   / \
//  9  20
//    /  \
//   15   7 
//
// 返回 true 。 
// 
//示例 2: 
//
// 给定二叉树 [1,2,2,3,3,null,null,4,4] 
//
// 
//       1
//      / \
//     2   2
//    / \
//   3   3
//  / \
// 4   4
// 
//
// 返回 false 。 
//
// 
//
// 限制： 
//
// 
// 0 <= 树的结点个数 <= 10000 
// 
//
// 注意：本题与主站 110 题相同：https://leetcode-cn.com/problems/balanced-binary-tree/ 
//
// 
// Related Topics 树 深度优先搜索 二叉树 
// 👍 281 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // 判断是否是平衡二叉树
        int hi = dfs(root);
        return hi == -1 ? false : true;
    }

    int dfs(TreeNode *root) {
        // 后序遍历

        // 空指针高度为0
        if (root == nullptr)
            return 0;

        // 查看 左右子书的高度
        int left = dfs(root->left);
        int right = dfs(root->right);
        // 其中一个不符合，则返回 -1
        if (left == -1 || right == -1) return -1;

        // 左右高度差 < 2 则返回当前高度，否则返回-1
        return  abs(left - right) < 2 ? max(left, right) + 1 : -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
