//给你一个二叉树的根结点 root ，请返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。 
//
// 一个结点的 「子树元素和」 定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入: root = [5,2,-3]
//输出: [2,-3,4]
// 
//
// 示例 2： 
//
// 
//
// 
//输入: root = [5,2,-5]
//输出: [2]
// 
//
// 
//
// 提示: 
//
// 
// 节点数在 [1, 104] 范围内 
// -105 <= Node.val <= 105 
// 
// Related Topics 树 深度优先搜索 哈希表 二叉树 
// 👍 143 👎 0


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
    vector<int> ans;
    unordered_map<int, int> memo;

    int postOrder(TreeNode *root) {
        if (root == nullptr)
            return 0;


        int left = postOrder(root->left);
        int right = postOrder(root->right);

        int num = root->val;

        int sum = left + right + num;
        memo[sum]++;
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        postOrder(root);

        int maxNum = 0;
        for (auto it = memo.begin(); it != memo.end(); it++) {
            if (it->second > maxNum) {
                ans.clear();
                maxNum = it->second;
                ans.push_back(it->first);
            } else if (it->second == maxNum) {
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
