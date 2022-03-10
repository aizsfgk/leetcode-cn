//给定单链表的头节点 head ，将所有索引为奇数的节点和索引为偶数的节点分别组合在一起，然后返回重新排序的列表。 
//
// 第一个节点的索引被认为是 奇数 ， 第二个节点的索引为 偶数 ，以此类推。 
//
// 请注意，偶数组和奇数组内部的相对顺序应该与输入时保持一致。 
//
// 你必须在 O(1) 的额外空间复杂度和 O(n) 的时间复杂度下解决这个问题。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入: head = [1,2,3,4,5]
//输出: [1,3,5,2,4] 
//
// 示例 2: 
//
// 
//
// 
//输入: head = [2,1,3,5,6,4,7]
//输出: [2,3,6,7,1,5,4] 
//
// 
//
// 提示: 
//
// 
// n == 链表中的节点数 
// 0 <= n <= 104 
// -106 <= Node.val <= 106 
// 
// Related Topics 链表 
// 👍 547 👎 0


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
    ListNode* oddEvenList(ListNode* head) {
        // nullptr 节点和只有一个节点直接返回
        if (head == nullptr || head->next == nullptr)
            return head;

        // 奇节点头，奇节点指针，偶节点头，头节点指针
        ListNode *oddHead = head, *odd=head, *evenHead = head->next, *even = head->next;

        // 定义当前节点，便于判断
        ListNode *cur = head->next->next;

        // 遍历一遍
        // 当前节点判断
        while (cur && cur->next) {
            odd->next = cur;
            odd = cur;
            even->next = cur->next;
            even = cur->next;
            cur = cur->next->next;
        }

        // 如果存在cur，表示奇节点还有一个节点
        if (cur) {
            odd->next = cur;
            odd = cur;
        }

        // 连接奇偶链表
        odd->next = evenHead;
        even->next = nullptr;

        // 返回奇节点头
        return oddHead;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
