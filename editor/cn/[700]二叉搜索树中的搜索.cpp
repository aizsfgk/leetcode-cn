//给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。 
//
// 例如， 
//
// 
//给定二叉搜索树:
//
//        4
//       / \
//      2   7
//     / \
//    1   3
//
//和值: 2
// 
//
// 你应该返回如下子树: 
//
// 
//      2     
//     / \   
//    1   3
// 
//
// 在上述示例中，如果要找的值是 5，但因为没有节点值为 5，我们应该返回 NULL。 
// Related Topics 树 二叉搜索树 二叉树 
// 👍 220 👎 0


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
    TreeNode* searchBST(TreeNode* root, int val) {
//        // 中序遍历
//
//        if (root == nullptr) {
//            return nullptr;
//        }
//
//        stack<TreeNode *> s;
//        s.push(root);
//
//        while(root != nullptr || !s.empty()) {
//            while (root) {
//                s.push(root);
//                root = root->left;
//            }
//
//            root = s.top(); s.pop();
//
//            if (root->val == val) {
//                return root;
//            }
//
//            if (root->right) {
//                root = root->right;
//            }
//        }
//
//
//        return nullptr;

        // 二分查找
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val == val) {
            return root;
        } else if (root->val > val) {
            return searchBST(root->left, val);
        } else {
            return searchBST(root->right, val);
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
