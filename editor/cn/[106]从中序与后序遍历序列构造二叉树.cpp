//给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并
//返回这颗 二叉树 。 
//
// 
//
// 示例 1: 
//
// 
//输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
//输出：[3,9,20,null,null,15,7]
// 
//
// 示例 2: 
//
// 
//输入：inorder = [-1], postorder = [-1]
//输出：[-1]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= inorder.length <= 3000 
// postorder.length == inorder.length 
// -3000 <= inorder[i], postorder[i] <= 3000 
// inorder 和 postorder 都由 不同 的值组成 
// postorder 中每一个值都在 inorder 中 
// inorder 保证是树的中序遍历 
// postorder 保证是树的后序遍历 
// 
// Related Topics 树 数组 哈希表 分治 二叉树 
// 👍 685 👎 0


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
    map<int, int> memo;
    TreeNode* myBuildTree(const vector<int> &postorder,
            int inStart, int inEnd, int postStart, int postEnd) {

        // 终止条件
        if (inEnd < inStart || postEnd < postStart) return nullptr;

        // 根节点
        int root = postorder[postEnd];
        // 根节点在中序遍历中的索引
        int rootIdx = memo[root];

        /*
        在找到根节点位置以后，我们要确定下一轮中，左子树和右子树在中序数组和后续数组中的左右边界的位置。
        1. 左子树-中序数组 `is = is`, `ie = ri - 1`
        2. 左子树-后序数组 `ps = ps`, `pe = ps + ri - is - 1`
            (pe计算过程解释，后续数组的起始位置加上左子树长度-1 就是后后序数组结束位置了，
             左子树的长度 = 根节点索引-左子树)
        3. 右子树-中序数组 `is = ri + 1, ie = ie`
        4. 右子树-后序数组` ps = ps + ri - is, pe - 1`

        */
        TreeNode *node = new TreeNode(root);
        node->left = myBuildTree(postorder, inStart, rootIdx-1, postStart, postStart + rootIdx - inStart -1);
        node->right = myBuildTree(postorder, rootIdx+1, inEnd, postStart + rootIdx - inStart, postEnd-1);

        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 从中序和后续遍历构造二叉树
        // 后续遍历确定根节点
        // 中序遍历确定左右子树
        for (int i=0; i<inorder.size(); i++) {
            memo[inorder[i]] = i;
        }
        return myBuildTree(postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
