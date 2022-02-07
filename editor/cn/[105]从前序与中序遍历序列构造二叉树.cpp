//给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并
//返回其根节点。 
//
// 
//
// 示例 1: 
//
// 
//输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//输出: [3,9,20,null,null,15,7]
// 
//
// 示例 2: 
//
// 
//输入: preorder = [-1], inorder = [-1]
//输出: [-1]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= preorder.length <= 3000 
// inorder.length == preorder.length 
// -3000 <= preorder[i], inorder[i] <= 3000 
// preorder 和 inorder 均 无重复 元素 
// inorder 均出现在 preorder 
// preorder 保证 为二叉树的前序遍历序列 
// inorder 保证 为二叉树的中序遍历序列 
// 
// Related Topics 树 数组 哈希表 分治 二叉树 
// 👍 1407 👎 0


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
    unordered_map<int, int> inorderIdxMap;

public:
    TreeNode* myBuildTree(const vector<int> &preorder, const vector<int> &inorder,
                int preIdxLeft, int preIdxRight, int inIdxLeft, int inIdxRight) {

        // 索引跨界，返回nullptr
        if (preIdxLeft > preIdxRight)
            return nullptr;

        // 前序遍历，第一个节点，就是根节点
        int preIdxRoot = preIdxLeft;
        // 在中序遍历中定位根节点
        int inIdxRoot = inorderIdxMap[preorder[preIdxRoot]];

        // 1. 先建立根节点
        TreeNode *root = new TreeNode(preorder[preIdxRoot]);
        // 2. 得到左子树节点个数
        int leftTreeSize = inIdxRoot - inIdxLeft;
        // 3. 递归地构造左右子树，并连接到根节点

        // 先序遍历中: preIdxLeft + 1 <-> preIdxLeft + leftTreeSize 对应 中序遍历的: inIdxLeft <-> inIdxRoot-1
        root->left = myBuildTree(preorder, inorder, preIdxLeft+1, preIdxLeft+leftTreeSize, inIdxLeft, inIdxRoot-1);

        // 先序遍历中: preIdxLeft+leftTreeSize+1, preIdxRight 对应 中序遍历的：inIdxRoot+1, inIdxRight
        root->right = myBuildTree(preorder, inorder, preIdxLeft+leftTreeSize+1, preIdxRight, inIdxRoot+1, inIdxRight);


        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //
        // 思路：
        //      1. 利用二叉树性质
        //      2. 递归构建

        int n = inorder.size();
        for (int i=0; i<n; i++) {
            inorderIdxMap[inorder[i]] = i; // 中序遍历每一个数字的索引位置
        }

        // 开始构建
        return myBuildTree(preorder, inorder, 0, n-1, 0, n-1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
