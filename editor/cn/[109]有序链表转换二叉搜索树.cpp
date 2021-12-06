//给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。 
//
// 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。 
//
// 示例: 
//
// 给定的有序链表： [-10, -3, 0, 5, 9],
//
//一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
//
//      0
//     / \
//   -3   9
//   /   /
// -10  5
// 
// Related Topics 树 二叉搜索树 链表 分治 二叉树 
// 👍 629 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    // 获取中间节点使用的是双指针算法
    // 获取中间节点
    ListNode *getMedian(ListNode* left, ListNode *right) {
        ListNode *fast = left;
        ListNode *slow = left;
        while (fast != right && fast->next != right) {
            fast = fast->next;
            fast = fast->next;

            slow = slow->next;
        }

        return slow;
    }
public:
    // 通过递归，进行分治
    TreeNode* buildBST(ListNode *left, ListNode *right) {
        if (left == right) {
            return nullptr;
        }

        ListNode *mid = getMedian(left, right);
        TreeNode *root = new TreeNode(mid->val);

        root->left = buildBST(left, mid);
        root->right = buildBST(mid->next, right);

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        //
        // 有序链表 转化为 平衡二叉树
        //
        return buildBST(head, nullptr);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
