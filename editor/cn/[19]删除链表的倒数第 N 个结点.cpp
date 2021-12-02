//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。 
//
// 进阶：你能尝试使用一趟扫描实现吗？ 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4,5], n = 2
//输出：[1,2,3,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [1], n = 1
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：head = [1,2], n = 1
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 链表中结点的数目为 sz 
// 1 <= sz <= 30 
// 0 <= Node.val <= 100 
// 1 <= n <= sz 
// 
// Related Topics 链表 双指针 
// 👍 1625 👎 0


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return nullptr;
        }

        // 设置一个哑节点
        ListNode dummy = ListNode(0), *cur = &dummy, *pre = nullptr;
        // 先跑节点指向哪里?
        ListNode *tail = &dummy;

        // 哑节点指向头节点
        dummy.next = head;

        // 先跑指针，跑完
        while (n > 0) {
            tail = tail->next;
            n--;
        }

        // 先跑指针一直合法
        while (tail) {
            // 更新先跑指针
            tail = tail->next;
            // 记录前节点
            pre = cur;
            // 更新当前节点
            cur = cur->next;
        }

        // 删除当前节点
        pre->next = cur->next;
        delete(cur);

        return dummy.next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
