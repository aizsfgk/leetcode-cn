//给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。 
//
// 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [4,2,1,3]
//输出：[1,2,3,4]
// 
//
// 示例 2： 
//
// 
//输入：head = [-1,5,3,4,0]
//输出：[-1,0,3,4,5]
// 
//
// 示例 3： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 5 * 104] 内 
// -105 <= Node.val <= 105 
// 
//
// 
//
// 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？ 
// Related Topics 链表 双指针 分治 排序 归并排序 
// 👍 1533 👎 0


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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *slow = head, *fast = head;

        ListNode *brk;
        while (fast && fast->next) {
            fast = fast->next->next;
            if (!fast || !fast->next)
                brk = slow;
            slow = slow->next;
        }

        brk->next = nullptr; // 断开

        ListNode *head1 = sortList(head);
        ListNode *head2 = sortList(slow);

        ListNode dummy(-1), *cur = &dummy;

        // 只要有一个节点
        while (head1 || head2) {
            if (!head1 || (head1 && head2 && head2->val <= head1->val)) {
                cur->next = head2;
                head2 = head2->next;
                cur = cur->next;
            } else {
                cur->next = head1;
                head1 = head1->next;
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
