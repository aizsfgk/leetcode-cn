//给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4,5], k = 2
//输出：[4,5,1,2,3]
// 
//
// 示例 2： 
//
// 
//输入：head = [0,1,2], k = 4
//输出：[2,0,1]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 500] 内 
// -100 <= Node.val <= 100 
// 0 <= k <= 2 * 109 
// 
// Related Topics 链表 双指针 
// 👍 648 👎 0


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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) {
            return head;
        }
        int n = 0;
        ListNode *tmp = head;

        while (tmp) {
            n++;
            tmp = tmp->next;
        }

        if (n == 1 || k % n == 0) {
            return head;
        }

        if (k > n) {
            k = k % n;
        }

        // 开始双指针移动
        ListNode *one, *one_pre, *two, *two_pre;
        one = head;
        two = head;

        while (k > 0) {
            one_pre = one;
            one = one->next;
            k--;
        }

        while (one) {
            one_pre = one;
            one = one->next;

            two_pre = two;
            two = two->next;
        }

        ListNode *newHead = two_pre->next;
        two_pre->next = nullptr;
        one_pre->next = head;

        return newHead;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
