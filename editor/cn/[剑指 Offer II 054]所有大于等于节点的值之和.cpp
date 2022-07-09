//给定一个二叉搜索树，请将它的每个节点的值替换成树中大于或者等于该节点值的所有节点值之和。 
//
// 
//
// 提醒一下，二叉搜索树满足下列约束条件： 
//
// 
// 节点的左子树仅包含键 小于 节点键的节点。 
// 节点的右子树仅包含键 大于 节点键的节点。 
// 左右子树也必须是二叉搜索树。 
// 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
//输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
// 
//
// 示例 2： 
//
// 
//输入：root = [0,null,1]
//输出：[1,null,1]
// 
//
// 示例 3： 
//
// 
//输入：root = [1,0,2]
//输出：[3,3,2]
// 
//
// 示例 4： 
//
// 
//输入：root = [3,2,4,1]
//输出：[7,9,4,10]
// 
//
// 
//
// 提示： 
//
// 
// 树中的节点数介于 0 和 10⁴ 之间。 
// 每个节点的值介于 -10⁴ 和 10⁴ 之间。 
// 树中的所有值 互不相同 。 
// 给定的树为二叉搜索树。 
// 
//
// 
//
// 注意： 
//
// 
// 本题与主站 538 题相同： https://leetcode-cn.com/problems/convert-bst-to-greater-tree/ 
//
// 本题与主站 1038 题相同：https://leetcode-cn.com/problems/binary-search-tree-to-
//greater-sum-tree/ 
// 
// Related Topics 树 深度优先搜索 二叉搜索树 二叉树 👍 30 👎 0


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
    int dfs(TreeNode *root) {
        // 返回当前结点右子树的全部和
        if (!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);
        int val = root->val;

        return left+right+val;
    }

    int sum = 0;
    void midVisit(TreeNode *root) {
        if (!root) return;

        stack<TreeNode *> stk;
        // stk.push(root);

        while (root != nullptr || !stk.empty()) {

            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }

            // 拿到当前结点
            root = stk.top(); stk.pop();

            // 记录结点值
            int curVal = root->val;
            // 修改结点值
            root->val = sum;
            // 更新sum
            sum -= curVal;

            root = root->right;
        }

    }


    TreeNode* convertBST(TreeNode* root) {
        if (!root) return root;

        sum = dfs(root);
        midVisit(root);

        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
