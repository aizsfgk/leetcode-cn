5//给定一个单链表 L 的头节点 head ，单链表 L 表示为：
//
// 
//L0 → L1 → … → Ln - 1 → Ln
// 
//
// 请将其重新排列后变为： 
//
// 
//L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → … 
//
// 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：head = [1,2,3,4]
//输出：[1,4,2,3] 
//
// 示例 2： 
//
// 
//
// 
//输入：head = [1,2,3,4,5]
//输出：[1,5,2,4,3] 
//
// 
//
// 提示： 
//
// 
// 链表的长度范围为 [1, 5 * 104] 
// 1 <= node.val <= 1000 
// 
// Related Topics 栈 递归 链表 双指针 
// 👍 722 👎 0


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
    void reorderList(ListNode* head) {
        // 合并链表
        if (head == nullptr)
            return;

        ListNode *mid = GetMidNode(head);

        ListNode *l1 = head;
        ListNode *l2 = mid->next;
        mid->next = nullptr; // 断开链表

        l2 = reverseListNode(l2); // 翻转l2链表

        head = mergeListNode(l1, l2); // 合并1，2链表

    }

    // 获取中间结点
    ListNode *GetMidNode(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // 翻转链表
    ListNode* reverseListNode(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }

    // 合并链表
    ListNode* mergeListNode(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1), *cur = &dummy;

        while (l1 && l2) {
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;

            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
        }

        if (l1) {
            cur->next = l1;
        } else {
            cur->next = l2;
        }

        return dummy.next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
