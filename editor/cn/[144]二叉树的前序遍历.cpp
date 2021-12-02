//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,null,2,3]
//输出：[1,2,3]
// 
//
// 示例 2： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：root = [1]
//输出：[1]
// 
//
// 示例 4： 
//
// 
//输入：root = [1,2]
//输出：[1,2]
// 
//
// 示例 5： 
//
// 
//输入：root = [1,null,2]
//输出：[1,2]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [0, 100] 内 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 进阶：递归算法很简单，你可以通过迭代算法完成吗？ 
// Related Topics 栈 树 深度优先搜索 二叉树 
// 👍 689 👎 0


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
public:
    vector<int> ret;

//    void pre(TreeNode *root) {
//        if (root == nullptr) {
//            return;
//        }
//
//        ret.push_back(root->val);
//        pre(root->left);
//        pre(root->right);
//    }
//
//    vector<int> preorderTraversal(TreeNode* root) {
//       pre(root);
//       return ret;
//    }

    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return ret;
        }

        stack<TreeNode*> s;
        s.push(root);

        TreeNode *ele;
        while (!s.empty()) {
            ele = s.top();s.pop();
            ret.push_back(ele->val);

            // 先放入右孩子
            if (ele->right) {
                s.push(ele->right);
            }

            // 再放入左孩子
            if (ele->left) {
                s.push(ele->left);
            }
        }

        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
