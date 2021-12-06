//给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。 
//
// 
//
// 示例 1： 
//
// 输入：
//    3
//   / \
//  9  20
//    /  \
//   15   7
//输出：[3, 14.5, 11]
//解释：
//第 0 层的平均值是 3 ,  第1层是 14.5 , 第2层是 11 。因此返回 [3, 14.5, 11] 。
// 
//
// 
//
// 提示： 
//
// 
// 节点值的范围在32位有符号整数范围内。 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 
// 👍 302 👎 0


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
    vector<double> ret;
public:
    vector<double> averageOfLevels(TreeNode* root) {
        // 二叉树的层序遍历
        if (root == nullptr) {
            return ret;
        }

        queue<TreeNode *> q;

        q.push(root);


        int size = 0;
        double sum = 0.0;
        double one = 0.0;

        while (!q.empty()) {
            size = q.size();
            sum = 0.0;

            for (int i=0; i<size; i++) {
                auto ele = q.front(); q.pop();
                sum += ele->val;

                if (ele->left) {
                    q.push(ele->left);
                }

                if (ele->right) {
                    q.push(ele->right);
                }
            }

            one = sum / size;
            ret.push_back(one);
        }

        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
