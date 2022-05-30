//请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。 
//
// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。 
//
// 1 
// / \ 
// 2 2 
// / \ / \ 
//3 4 4 3 
//但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的: 
//
// 1 
// / \ 
// 2 2 
// \ \ 
// 3 3 
//
// 
//
// 示例 1： 
//
// 输入：root = [1,2,2,3,4,4,3]
//输出：true
// 
//
// 示例 2： 
//
// 输入：root = [1,2,2,null,3,null,3]
//输出：false 
//
// 
//
// 限制： 
//
// 0 <= 节点个数 <= 1000 
//
// 注意：本题与主站 101 题相同：https://leetcode-cn.com/problems/symmetric-tree/ 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 
// 👍 345 👎 0


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
    /*
    对称二叉树定义： 对于树中 任意两个对称节点 LL 和 RR ，一定有：
        L.val = R.valL.val=R.val ：即此两对称节点值相等。
        L.left.val = R.right.valL.left.val=R.right.val ：即 LL 的 左子节点 和 RR 的 右子节点 对称；
        L.right.val = R.left.valL.right.val=R.left.val ：即 LL 的 右子节点 和 RR 的 左子节点 对称。
    */

    bool dfs(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if (!left || !right || left->val != right->val) return false;

        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        // 树是否是对称二叉树

        return root == nullptr ? true : dfs(root->left, root->right);
    }

/*
     // 分层不行； 解决不了 同层相同元素的情况
     bool isSymmetric(TreeNode* root) {
         if (!root)
            return true;

         queue<TreeNode*> que;
         que.push(root);

         vector<int> layer;

         while (!que.empty()) {
            int size = que.size();

            layer.clear();
            for (int i=0; i<size; i++) {
                auto ele = que.front(); que.pop();

                layer.push_back(ele->val);

                if (ele->left) {
                    que.push(ele->left);
                }

                if (ele->right) {
                    que.push(ele->right);
                }
            }

            if (layer.size() > 1) {
                int l = 0, r = layer.size() - 1;
                while (l < r) {
                    if (layer[l] == layer[r]) {
                        l++;
                        r--;
                    } else {
                        return false;
                    }
                }
            }
         }

         return true;
     }
*/
};
//leetcode submit region end(Prohibit modification and deletion)
