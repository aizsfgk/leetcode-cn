//给定一棵二叉搜索树，请找出其中第 k 大的节点的值。 
//
// 
//
// 示例 1: 
//
// 
//输入: root = [3,1,4,null,2], k = 1
//   3
//  / \
// 1   4
//  \
//   2
//输出: 4 
//
// 示例 2: 
//
// 
//输入: root = [5,3,6,2,4,null,null,1], k = 3
//       5
//      / \
//     3   6
//    / \
//   2   4
//  /
// 1
//输出: 4 
//
// 
//
// 限制： 
//
// 
// 1 ≤ k ≤ 二叉搜索树元素个数 
// 
// Related Topics 树 深度优先搜索 二叉搜索树 二叉树 
// 👍 308 👎 0


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
//private:
//    vector<int> ans;
//
//    void dfs(TreeNode *root) {
//        if (!root)
//            return;
//        dfs(root->left);
//        ans.push_back(root->val);
//        dfs(root->right);
//    }
//public:
//    int kthLargest(TreeNode* root, int k) {
//        dfs(root);
//
//        if (k > ans.size()) return -1;
//        return ans[ans.size() - k];
//    }

private:
    int ans;
    int innerK;
    void dfs(TreeNode *root) {
        if (!root) return;

        dfs(root->right);
        if (--innerK == 0) ans = root->val;
        dfs(root->left);
    }
public:
    int kthLargest(TreeNode* root, int k) {
        innerK = k;
        dfs(root);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
