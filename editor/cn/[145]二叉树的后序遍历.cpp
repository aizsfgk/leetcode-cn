//给定一个二叉树，返回它的 后序 遍历。 
//
// 示例: 
//
// 输入: [1,null,2,3]  
//   1
//    \
//     2
//    /
//   3 
//
//输出: [3,2,1] 
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？ 
// Related Topics 栈 树 深度优先搜索 二叉树 
// 👍 717 👎 0


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
    vector<int> ret;
public:
// 递归版本:
//    void post(TreeNode *root) {
//        if (root == nullptr) {
//            return;
//        }
//        post(root->left);
//        post(root->right);
//        ret.push_back(root->val);
//    }
//
//    vector<int> postorderTraversal(TreeNode* root) {
//        post(root);
//        return ret;
//    }

    // 非递归版本
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return ret;
        }

        stack<TreeNode *> s;
        // 记录之前的节点
        TreeNode *prev = nullptr;

        // 1. 根对象不为空； 或者 栈不为空
        while(root != nullptr || !s.empty()) {
            // 2. 把所有的左对象都入栈
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }

            // 3. 出栈；相当于回溯到上一个节点
            root = s.top(); s.pop();

            // a. 如果右节点为空，则左右都为空，需要入栈
            // b. 如果该右节点已经入过栈了，则无需二次入栈
            // 上边两种情况，则直接将该节点打印
            // 其他情况需要
            // c. 把该节点再次入栈
            // d. 当前节点修改为右孩子节点
            //
            // 4. 没有右对象，或者右边对象入过栈； 放入当前节点
            if (root->right == nullptr || root->right == prev) {
                ret.push_back(root->val);
                prev = root; // 记录前一个放入的节点
                root = nullptr;
            } else {
                // 5. 否则， 放入该节点
                s.push(root);
                root = root->right;
            }
        }

        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
