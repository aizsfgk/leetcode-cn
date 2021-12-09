//给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
// 
// 
// 每条从根节点到叶节点的路径都代表一个数字： 
//
// 
// 例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。 
// 
//
// 计算从根节点到叶节点生成的 所有数字之和 。 
//
// 叶节点 是指没有子节点的节点。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,2,3]
//输出：25
//解释：
//从根到叶子节点路径 1->2 代表数字 12
//从根到叶子节点路径 1->3 代表数字 13
//因此，数字总和 = 12 + 13 = 25 
//
// 示例 2： 
//
// 
//输入：root = [4,9,0,5,1]
//输出：1026
//解释：
//从根到叶子节点路径 4->9->5 代表数字 495
//从根到叶子节点路径 4->9->1 代表数字 491
//从根到叶子节点路径 4->0 代表数字 40
//因此，数字总和 = 495 + 491 + 40 = 1026
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数目在范围 [1, 1000] 内 
// 0 <= Node.val <= 9 
// 树的深度不超过 10 
// 
// 
// 
// Related Topics 树 深度优先搜索 二叉树 
// 👍 449 👎 0


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
    int ans;

//    int sumNum(TreeNode* root, int preNum) {
//        // 套路1，都是这样的
//        // 1. 根节点为空， 直接返回0
//        if (root == nullptr) {
//            return 0;
//        }
//        // 套路1.的其他情况，计算该节点值，然后思考这个值何时返回???
//        // 2. 节点不为空， 计算该节点值
//        int val = preNum * 10 + root->val;
//
//        // 第二步的节点计算结果值后，何时返回???; 当为叶子节点的时候
//        // 3. 如果是叶子节点，则返回该值
//        if (root->left == nullptr && root->right == nullptr) {
//            return val;
//        } else {
//            // 看根节点；需要做的逻辑处理，也就是其他节点的逻辑处理
//            // 如果不是叶子节点；则将结果加起来
//            return sumNum(root->left, val) + sumNum(root->right, val);
//        }
//
//    }
    int sumNum(TreeNode* root, int preNum) {
        if (root == nullptr) {
            return 0;
        }

        int val = preNum * 10 + root->val;

        if (root->left == nullptr && root->right == nullptr) {
            return val;
        } else {
            int left = sumNum(root->left, val);
            int right = sumNum(root->right, val);
            return left + right;
        }
    }

public:
    int sumNumbers(TreeNode* root) {
       ans = sumNum(root, 0);

       return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
