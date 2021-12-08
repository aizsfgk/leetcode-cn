//给定一棵二叉树，设计一个算法，创建含有某一深度上所有节点的链表（比如，若一棵树的深度为 D，则会创建出 D 个链表）。返回一个包含所有深度的链表的数组。 
//
// 
//
// 示例： 
//
// 输入：[1,2,3,4,5,null,7,8]
//
//        1
//       /  \ 
//      2    3
//     / \    \ 
//    4   5    7
//   /
//  8
//
//输出：[[1],[2,3],[4,5,7],[8]]
// 
// Related Topics 树 广度优先搜索 链表 二叉树 
// 👍 61 👎 0


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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> ans;
        if(tree == nullptr) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(tree);
        while (!q.empty()) {
            int sz = q.size();
            ListNode *dummy = new ListNode(-1);
            ListNode *cur = dummy;

            for (int i=0; i<sz; i++) {
                TreeNode* ele = q.front();q.pop();
                cur->next = new ListNode(ele->val);
                cur = cur->next;

                if(ele->left) {
                    q.push(ele->left);
                }
                if(ele->right) {
                    q.push(ele->right);
                }
            }
            ans.push_back(dummy->next);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
