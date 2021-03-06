//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。 
//
// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。 
//
// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。 
//
// 示例： 
//
// 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807
// 
// Related Topics 链表 数学


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 双链表; 时间复杂度如何计算???
        //

        // 1. 先设置一个哑节点
        // 2. 然后把哑节点的值复制给一个指针
        ListNode dummy(0), *cur = &dummy;
        // 3. 进位
        int carry = 0;

        while (l1 || l2 || carry) {
            // 4. 求和
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            // 5. 计算 进位值
            carry = sum / 10;
            // 6. 新建节点
            cur->next = new ListNode(sum % 10);
            // 7. 移动p指针
            cur = cur->next;
            // 8. 遍历链表
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return dummy.next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
