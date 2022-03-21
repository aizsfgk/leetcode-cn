//给定一个二叉搜索树 root 和一个目标结果 k，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。 
//
// 
//
// 示例 1： 
//
// 
//输入: root = [5,3,6,2,4,null,7], k = 9
//输出: true
// 
//
// 示例 2： 
//
// 
//输入: root = [5,3,6,2,4,null,7], k = 28
//输出: false
// 
//
// 
//
// 提示: 
//
// 
// 二叉树的节点个数的范围是 [1, 104]. 
// -104 <= Node.val <= 104 
// root 为二叉搜索树 
// -105 <= k <= 105 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉搜索树 哈希表 双指针 二叉树 
// 👍 335 👎 0


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
    unordered_set<int> search;
    bool ans = false;
public:
    bool findTarget(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }

    void dfs(TreeNode *root, int k) {
        if (root == nullptr)
            return;

        int remain = k - root->val;
        if (search.find(remain) != search.end()) {
            ans = true;
            return;
        }
        search.insert(root->val);

        dfs(root->left, k);
        dfs(root->right, k);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
