//给定一个有序整数数组，元素各不相同且按升序排列，编写一个算法，创建一棵高度最小的二叉搜索树。示例: 给定有序数组: [-10,-3,0,5,9], 一个可能
//的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：           0          / \        -3 
//  9        /   /      -10  5 Related Topics 树 二叉搜索树 数组 分治 二叉树 
// 👍 106 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

private:
    TreeNode *sort(vector<int> &nums, int begin, int end) {
        if (begin > end) {
            return nullptr;
        }

        int mid = (begin + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sort(nums, begin, mid-1);
        root->right = sort(nums, mid+1, end);
        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }
        TreeNode *root = sort(nums, 0, nums.size()-1);
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
