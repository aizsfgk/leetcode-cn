//给你二叉搜索树的根节点 root ，该树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。 
//
// 进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用常数空间的解决方案吗？ 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,3,null,null,2]
//输出：[3,1,null,null,2]
//解释：3 不能是 1 左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
// 
//
// 示例 2： 
//
// 
//输入：root = [3,1,4,null,null,2]
//输出：[2,1,4,null,null,3]
//解释：2 不能在 3 的右子树中，因为 2 < 3 。交换 2 和 3 使二叉搜索树有效。 
//
// 
//
// 提示： 
//
// 
// 树上节点的数目在范围 [2, 1000] 内 
// -231 <= Node.val <= 231 - 1 
// 
// Related Topics 树 深度优先搜索 二叉搜索树 二叉树 
// 👍 598 👎 0


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
    vector<int> nums;
    void midOrder(TreeNode *root) {
        if (root == nullptr)
            return;
        midOrder(root->left);
        nums.push_back(root->val);
        midOrder(root->right);
    }

    void preOrder(TreeNode *root, vector<int> &points) {
        if (root == nullptr)
            return;

        if (root->val == points.front()) {
            root->val = points.back();
        } else if (root->val == points.back()) {
            root->val = points.front();
        }

        preOrder(root->left, points);
        preOrder(root->right, points);
    }
public:
    void recoverTree(TreeNode* root) {
        midOrder(root);
        vector<int> nums2(nums.begin(), nums.end());
        sort(nums2.begin(), nums2.end());

        vector<int> points;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != nums2[i]) {
                points.push_back(nums[i]);
            }
        }

        preOrder(root, points);
        return;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
