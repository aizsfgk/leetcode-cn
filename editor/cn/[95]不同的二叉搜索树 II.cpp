//给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。 
//
// 
//
// 
// 
// 示例 1： 
//
// 
//输入：n = 3
//输出：[[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 8 
// 
// 
// 
// Related Topics 树 二叉搜索树 动态规划 回溯 二叉树 
// 👍 1048 👎 0


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
    vector<TreeNode*> generateTreesNew(int start, int end) {

        if (start > end) {
            return { nullptr };
        }

        vector<TreeNode *> allTrees;
        // 可枚举根
        for (int i=start; i<=end; i++) {
            // 获取所有可能的左子树集合
            vector<TreeNode *> leftTrees = generateTreesNew(start, i-1);

            vector<TreeNode *> rightTrees = generateTreesNew(i+1, end);

            // 从左子数集合中选取一棵左子树，从右子树集合中选一棵右子树，拼接到根结点上
            for (auto &left : leftTrees) {
                for (auto &right : rightTrees) {
                    TreeNode *curTree = new TreeNode(i);
                    curTree->left = left;
                    curTree->right = right;

                    // 加到结果中
                    allTrees.push_back(curTree);
                }
            }
        }

        return allTrees;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        if (!n) {
            return {};
        }

        return generateTreesNew(1, n);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
