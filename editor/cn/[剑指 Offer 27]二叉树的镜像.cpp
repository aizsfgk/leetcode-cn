<<<<<<< HEAD

//请完成一个函数，输入一个二叉树，该函数输出它的镜像。
=======
//请完成一个函数，输入一个二叉树，该函数输出它的镜像。 
>>>>>>> d19ee2ea040727c98624c90ba43bf6fa30591a24
//
// 例如输入： 
//
// 4 
// / \ 
// 2 7 
// / \ / \ 
//1 3 6 9 
//镜像输出： 
//
// 4 
// / \ 
// 7 2 
// / \ / \ 
//9 6 3 1 
//
// 
//
// 示例 1： 
//
// 输入：root = [4,2,7,1,3,6,9]
//输出：[4,7,2,9,6,3,1]
// 
//
// 
//
// 限制： 
//
// 0 <= 节点个数 <= 1000 
//
// 注意：本题与主站 226 题相同：https://leetcode-cn.com/problems/invert-binary-tree/ 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 
// 👍 262 👎 0


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
public:
<<<<<<< HEAD
    void myMirrorTree(TreeNode* root) {
         //
        if (root == nullptr)
            return;

        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        mirrorTree(root->left);
        mirrorTree(root->right);
    }

    TreeNode* mirrorTree(TreeNode* root) {
        myMirrorTree(root);
        return root;
=======
    TreeNode* mirrorTree(TreeNode* root) {

>>>>>>> d19ee2ea040727c98624c90ba43bf6fa30591a24
    }
};
//leetcode submit region end(Prohibit modification and deletion)
