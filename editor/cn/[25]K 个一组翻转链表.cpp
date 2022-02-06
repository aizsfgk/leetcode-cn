//给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。 
//
// k 是一个正整数，它的值小于或等于链表的长度。 
//
// 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。 
//
// 进阶： 
//
// 
// 你可以设计一个只使用常数额外空间的算法来解决此问题吗？ 
// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4,5], k = 2
//输出：[2,1,4,3,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [1,2,3,4,5], k = 3
//输出：[3,2,1,4,5]
// 
//
// 示例 3： 
//
// 
//输入：head = [1,2,3,4,5], k = 1
//输出：[1,2,3,4,5]
// 
//
// 示例 4： 
//
// 
//输入：head = [1], k = 1
//输出：[1]
// 
//
// 
// 
//
// 提示： 
//
// 
// 列表中节点的数量在范围 sz 内 
// 1 <= sz <= 5000 
// 0 <= Node.val <= 1000 
// 1 <= k <= sz 
// 
// Related Topics 递归 链表 
// 👍 1338 👎 0


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
class Solution {
public:

    // 反转单个链表
    ListNode* reverse(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *next;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    // 反转一次链表
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        // 记录当前待翻转段的前一个结点
        ListNode *pre = dummy;
        // 记录当前待翻转端的最后一个结点
        ListNode *end = dummy;

        while (end->next != nullptr) {
            // 找到本来结尾结点
            for (int i=0; i<k && end != nullptr; i++) end = end->next;

            // 如果结尾结点为空，表示已经结束，break;
            if (end == nullptr)
                break;

            // 开始结点
            ListNode *start = pre->next;
            // 下一个待翻转链表的开始结点
            ListNode *next = end->next;
            // 本次尾部结点断开
            end->next = nullptr;
            // 翻转
            pre->next = reverse(start);
            // 此时， start 是本段链表的结尾了
            start->next = next;

            // 跟新 新的prev
            pre = start;
            end = pre; // end 和 start 一致
        }

        return dummy->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
