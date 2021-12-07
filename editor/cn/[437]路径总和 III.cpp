//给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。 
//
// 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
//输出：3
//解释：和等于 8 的路径有 3 条，如图所示。
// 
//
// 示例 2： 
//
// 
//输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
//输出：3
// 
//
// 
//
// 提示: 
//
// 
// 二叉树的节点个数的范围是 [0,1000] 
// -109 <= Node.val <= 109 
// -1000 <= targetSum <= 1000 
// 
// Related Topics 树 深度优先搜索 二叉树 
// 👍 1159 👎 0


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
    int ans = 0;

    void pSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return;
        }



        // 何时使用remainSum
        // 很重要啊; 不要使用else
        // 找到了一条，之后可以继续找；不要断了
        if (targetSum == root->val) {
            ans++;
        }

        pSum(root->left, targetSum - root->val);
        pSum(root->right, targetSum - root->val);

    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }

        pSum(root, targetSum);

        /// 对每个节点，都进行这样的查找
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
