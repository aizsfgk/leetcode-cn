//在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“
//房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。 
//
// 计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。 
//
// 示例 1: 
//
// 输入: [3,2,3,null,3,null,1]
//
//     3
//    / \
//   2   3
//    \   \ 
//     3   1
//
//输出: 7 
//解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7. 
//
// 示例 2: 
//
// 输入: [3,4,5,1,3,null,1]
//
//     3
//    / \
//   4   5
//  / \   \ 
// 1   3   1
//
//输出: 9
//解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.
// 
// Related Topics 树 深度优先搜索 动态规划 二叉树 
// 👍 1099 👎 0


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
    /*
    int rob(TreeNode* root) {
        // 为何有种层序遍历的感觉??? 不是
        //
        //
        //

        // dp
        // time：O(n)
        // space: O(logn)

        vector<int> rs = robTree(root);
        return max(rs[0], rs[1]);
    }

    // 长度为2的数组，0不偷，1偷
    vector<int> robTree(TreeNode *cur) {
        if (cur == nullptr)
            return vector<int>{0, 0};
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        // 偷cur
        // 如果是偷当前节点，那么左右孩⼦就不能偷，val1 = cur->val + left[0] + right[0]; （如果对下标含义不
        // 理解就在回顾⼀下dp数组的含义）
        int val1 = cur->val + left[0] + right[0];

        // 不偷cur
        // 如果不偷当前节点，那么左右孩⼦就可以偷，⾄于到底偷不偷⼀定是选⼀个最⼤的，所以：val2 =
        // max(left[0], left[1]) + max(right[0], right[1]);
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);

        return {val2, val1};
    }
    */

    int rob(TreeNode* root) {
        vector<int> rs = robTree(root);
        return max(rs[0], rs[1]);
    }

    vector<int> robTree(TreeNode *root) {
        if (!root) {
            return {0,0};
        }

        vector<int> left = robTree(root->left);
        vector<int> right = robTree(root->right);

        // 后续遍历

        // 0 : 不偷
        // 1 : 偷
        int idx0 = max(left[0], left[1]) + max(right[0], right[1]);
        int idx1 = root->val + left[0] + right[0];

        return {idx0, idx1};
    }
};
//leetcode submit region end(Prohibit modification and deletion)
