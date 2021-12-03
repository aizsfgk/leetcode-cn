//给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。 
//
// 叶子节点 是指没有子节点的节点。 
// 
//
// 示例 1： 
//
// 
//输入：root = [1,2,3,null,5]
//输出：["1->2->5","1->3"]
// 
//
// 示例 2： 
//
// 
//输入：root = [1]
//输出：["1"]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数目在范围 [1, 100] 内 
// -100 <= Node.val <= 100 
// 
// Related Topics 树 深度优先搜索 字符串 二叉树 
// 👍 612 👎 0


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
    vector<string> ret;

    // 采用深度优先遍历
    //
    void btp(TreeNode *root, string path) {
        if (root == nullptr) {
            return;
        }

        // 遍历的过程中记下来临时路径
        path += to_string(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            // 在叶子节点的时候，放入vector
            ret.push_back(path);
        } else {
            path += "->";
            btp(root->left, path);
            btp(root->right, path);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        btp(root, "");
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
