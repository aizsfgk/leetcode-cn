//给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。 
//
// 假定 BST 有如下定义： 
//
// 
// 结点左子树中所含结点的值小于等于当前结点的值 
// 结点右子树中所含结点的值大于等于当前结点的值 
// 左子树和右子树都是二叉搜索树 
// 
//
// 例如： 
//给定 BST [1,null,2,2], 
//
//    1
//    \
//     2
//    /
//   2
// 
//
// 返回[2]. 
//
// 提示：如果众数超过1个，不需考虑输出顺序 
//
// 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内） 
// Related Topics 树 深度优先搜索 二叉搜索树 二叉树 
// 👍 379 👎 0


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
    int flag;
    int pre;
    int cur;
    int max = 1;
    int temp = 1;


public:
    void orderTravel(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        orderTravel(root->left);

        // flag == 0 表示是一个开始, 初始化数据
        if (flag == 0) {
            flag = 1;
            pre = root->val;
            ret.push_back(root->val);

        } else {

            cur = root->val;
            if (pre == cur) {
                temp ++;
            } else {
                temp = 1;
            }


            if (temp > max) {
                max = temp;
                ret.clear();
                ret.push_back(pre); // cur  或者 prev 都行
            } else if (temp == max) {
                ret.push_back(cur);
            }

            pre = cur;
        }


        orderTravel(root->right);

    }
    vector<int> findMode(TreeNode* root) {
    // 1次遍历
    //
    //
    //

        if (root == nullptr)
            return ret;

        orderTravel(root);
        return ret;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
