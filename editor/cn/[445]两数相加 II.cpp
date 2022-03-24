//给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。 
//
// 你可以假设除了数字 0 之外，这两个数字都不会以零开头。 
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
// 进阶：如果输入链表不能翻转该如何解决？ 
// Related Topics 栈 链表 数学 
// 👍 495 👎 0


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
        if (!l1 && !l2) {
            return nullptr;
        } else if (!l1) {
            return l2;
        } else if (!l2) {
            return l1;
        }

        stack<int> stk1;
        stack<int> stk2;

        ListNode *cur1 = l1, *cur2 = l2;
        while (cur1) {
            stk1.push(cur1->val);
            cur1 = cur1->next;
        }
        while (cur2) {
            stk2.push(cur2->val);
            cur2 = cur2->next;
        }

        // 开始拼接
        int remain = 0, curNum = 0;


        // 头插法的使用
        ListNode *head = new ListNode(-1);
        ListNode *p;
        while (remain > 0 || !stk1.empty() || !stk2.empty()) {
            int num1 = 0, num2 = 0;
            if (!stk1.empty()) {
                num1 = stk1.top(); stk1.pop();
            }

            if (!stk2.empty()) {
                num2 = stk2.top(); stk2.pop();
            }

            curNum = (num1 + num2 + remain) % 10;
            remain = (num1 + num2 + remain) / 10;

            p = new ListNode(curNum);
            p->next = head->next;
            head->next = p;

        }

        return head->next;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
