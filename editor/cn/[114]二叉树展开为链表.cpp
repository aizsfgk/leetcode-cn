//给你二叉树的根结点 root ，请你将它展开为一个单链表： 
//
// 
// 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。 
// 展开后的单链表应该与二叉树 先序遍历 顺序相同。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,2,5,3,4,null,6]
//输出：[1,null,2,null,3,null,4,null,5,null,6]
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
//输入：root = [0]
//输出：[0]
// 
//
// 
//
// 提示： 
//
// 
// 树中结点数在范围 [0, 2000] 内 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 进阶：你可以使用原地算法（O(1) 额外空间）展开这棵树吗？ 
// Related Topics 栈 树 深度优先搜索 链表 二叉树 
// 👍 987 👎 0


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
    // 展开
    void flatten(TreeNode* root) {
        // 本质就是一次前序遍历
        // 在前序遍历的过程中，借助栈，保存左右子树的信息
        // 栈为空，结果也就生成了。

        if (root == nullptr) {
            return;
        }

        stack<TreeNode *> s;

        s.push(root);
        TreeNode *prev = nullptr;

        while (!s.empty()) {
            TreeNode* cur = s.top(); s.pop();

            if (prev != nullptr) {
                prev->left = nullptr;
                prev->right = cur;
            }

            if (cur->right) {
                s.push(cur->right);
            }

            if (cur->left) {
                s.push(cur->left);
            }

            prev = cur;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
