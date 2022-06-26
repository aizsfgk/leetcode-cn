//给定两个 非空链表 l1和 l2 来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。 
//
// 可以假设除了数字 0 之外，这两个数字都不会以零开头。 
//
// 
//
// 示例1： 
//
// 
//
// 
//输入：l1 = [7,2,4,3], l2 = [5,6,4]
//输出：[7,8,0,7]
// 
//
// 示例2： 
//
// 
//输入：l1 = [2,4,3], l2 = [5,6,4]
//输出：[8,0,7]
// 
//
// 示例3： 
//
// 
//输入：l1 = [0], l2 = [0]
//输出：[0]
// 
//
// 
//
// 提示： 
//
// 
// 链表的长度范围为 [1, 100] 
// 0 <= node.val <= 9 
// 输入数据保证链表代表的数字无前导 0 
// 
//
// 
//
// 进阶：如果输入链表不能修改该如何处理？换句话说，不能对列表中的节点进行翻转。 
//
// 
//
// 注意：本题与主站 445 题相同：https://leetcode-cn.com/problems/add-two-numbers-ii/ 
// Related Topics 栈 链表 数学 👍 58 👎 0


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stk1, stk2;
        while (l1) {
            stk1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            stk2.push(l2->val);
            l2 = l2->next;
        }

        int cur = 0;
        int carry = 0;
        ListNode dummy(-1), *curPtr = &dummy;
        while (!stk1.empty() && !stk2.empty()) {
            int sum = stk1.top() + stk2.top() + carry;
            cur = sum % 10;
            carry = sum / 10;
            stk1.pop(); stk2.pop();

            ListNode *next = curPtr->next;
            curPtr->next = new ListNode(cur);
            curPtr->next->next = next;
        }

        while (!stk1.empty()) {
            int sum = stk1.top()  + carry;
            cur = sum % 10;
            carry = sum / 10;
            stk1.pop();

            ListNode *next = curPtr->next;
            curPtr->next = new ListNode(cur);
            curPtr->next->next = next;
        }

        while (!stk2.empty()) {
            int sum =  stk2.top() + carry;
            cur = sum % 10;
            carry = sum / 10;
            stk1.pop();

            ListNode *next = curPtr->next;
            curPtr->next = new ListNode(cur);
            curPtr->next->next = next;
        }

        if (carry) {
            ListNode *next = curPtr->next;
            curPtr->next = new ListNode(carry);
            curPtr->next->next = next;
        }

        return dummy.next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
