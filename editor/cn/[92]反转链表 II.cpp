//给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链
//表节点，返回 反转后的链表 。
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4,5], left = 2, right = 4
//输出：[1,4,3,2,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [5], left = 1, right = 1
//输出：[5]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点数目为 n 
// 1 <= n <= 500 
// -500 <= Node.val <= 500 
// 1 <= left <= right <= n 
// 
//
// 
//
// 进阶： 你可以使用一趟扫描完成反转吗？ 
// Related Topics 链表 
// 👍 1076 👎 0


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
private:
    void reverseListNode(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;

        // 链表反转
        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy, *cur = &dummy;
        dummy.next = head;

        ListNode *pre = cur;
        // 1. 找到前置节点
        for (int i=0; i<left-1; i++) {
            pre = pre->next;
        }

        // 2. 找到后继节点; 再走 right - left + 1 步
        ListNode *rightNode = pre;
        for (int i=0; i<right-left+1; i++) {
            rightNode = rightNode->next;
        }

        // 3. 切断链表
        ListNode *leftNode = pre->next;
        ListNode *curr = rightNode->next;

        pre->next = nullptr;
        rightNode->next = nullptr;

        // 4. 反转子链表
        reverseListNode(leftNode);

        // 5. 接回原先的链表
        pre->next = rightNode;
        leftNode->next = curr;

        return dummy.next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
