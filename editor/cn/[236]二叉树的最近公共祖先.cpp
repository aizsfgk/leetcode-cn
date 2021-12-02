//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。 
//
// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（
//一个节点也可以是它自己的祖先）。” 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
//输出：3
//解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
// 
//
// 示例 2： 
//
// 
//输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
//输出：5
//解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。
// 
//
// 示例 3： 
//
// 
//输入：root = [1,2], p = 1, q = 2
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [2, 105] 内。 
// -109 <= Node.val <= 109 
// 所有 Node.val 互不相同 。 
// p != q 
// p 和 q 均存在于给定的二叉树中。 
// 
// Related Topics 树 深度优先搜索 二叉树 
// 👍 1402 👎 0


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
private:
//    unordered_map<int, TreeNode*> all;
//    unordered_map<int, bool> vis;
public:
//    void dfs(TreeNode *root) {
//        if (root == nullptr) {
//            return;
//        }
//
//        if (root->left) {
//            all[root->left->val] = root;
//            dfs(root->left);
//        }
//
//        if (root->right) {
//            all[root->right->val] = root;
//            dfs(root->right);
//        }
//    }
//
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        all[root->val] = nullptr;
//        dfs(root);
//
//        // 遍历寻找
//        while(p != nullptr) {
//            vis[p->val] = true;
//            p = all[p->val];
//        }
//
//        while(q != nullptr) {
//            if (vis[q->val]) return q;
//            q = all[q->val];
//        }
//
//        return nullptr;
//
//    }

    /// 1. 通过前序遍历找到节点，确定返回，从上往下
    /// 2. 通过后续遍历， 从底层向上层，找到解
    // 使用递归的方式
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 使用前序遍历的方法
        // 递归的方法，就要确定如何让递归结束
        // 一轮遍历

        // 找到节点/或者没有找到，就返回; 终止条件
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);


        /// 返回之后才做的处理

        // 1. 左右子树都没有找到
        //    则没有，返回nullptr (子树， 会存在这种情况）
        if (left == nullptr && right == nullptr) {
            return nullptr;
        }

        // 2. 只在右子树找到，则返回右树
        if (!left) {
            return right;
        }

        // 3. 只在左子树找到，返回左子树
        if (!right) {
            return left;
        }

        // 4. 左右子树都能找到，那就直接返回根节点
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
