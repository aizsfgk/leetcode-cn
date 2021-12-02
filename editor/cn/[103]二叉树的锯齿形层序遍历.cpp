//给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。 
//
// 例如： 
//给定二叉树 [3,9,20,null,null,15,7], 
//
// 
//    3
//   / \
//  9  20
//    /  \
//   15   7
// 
//
// 返回锯齿形层序遍历如下： 
//
// 
//[
//  [3],
//  [20,9],
//  [15,7]
//]
// 
// Related Topics 树 广度优先搜索 二叉树 
// 👍 550 👎 0


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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;

        if (root == nullptr) {
            return ret;
        }

        queue<TreeNode *> q;
        q.push(root);
        stack<TreeNode *> s;

        int flag = 0;

        while (!q.empty()) {
            flag ++;

            int size = q.size();
            ret.push_back(vector<int>());


            for (int i=1; i<=size; i++) {
                auto ele = q.front(); q.pop();

                if (flag % 2 == 0) {
                    s.push(ele);
                } else {
                    ret.back().push_back(ele->val);
                }


                if (ele->left) {
                    q.push(ele->left);
                }

                if (ele->right) {
                    q.push(ele->right);
                }
            }

            while (!s.empty()) {
                ret.back().push_back(s.top()->val);
                s.pop();
            }
        }

        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
