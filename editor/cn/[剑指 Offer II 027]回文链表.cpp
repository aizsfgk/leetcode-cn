//给定一个链表的 头节点 head ，请判断其是否为回文链表。 
//
// 如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入: head = [1,2,3,3,2,1]
//输出: true 
//
// 示例 2： 
//
// 
//
// 
//输入: head = [1,2]
//输出: false
// 
//
// 
//
// 提示： 
//
// 
// 链表 L 的长度范围为 [1, 10⁵] 
// 0 <= node.val <= 9 
// 
//
// 
//
// 进阶：能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？ 
//
// 
//
// 注意：本题与主站 234 题相同：https://leetcode-cn.com/problems/palindrome-linked-list/ 
// Related Topics 栈 递归 链表 双指针 👍 62 👎 0


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
    ListNode *reverseLink(ListNode *head) {
        ListNode *prev = nullptr, *cur = head;

        while (cur) {
            ListNode *next = cur->next;
            cur->next = prev;

            prev = cur;
            cur = next;
        }
        return prev;
    }

    void printLink(ListNode *head) {
        while (head) {
            cout << head->val << ",";
            head = head->next;
        }
        cout << ";" << endl;
    }


    bool isPalindrome(ListNode* head) {
        // 分割列表
        ListNode *slow  = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        fast = slow->next;
        slow->next = nullptr; // 端口
        slow = head; // 投节点

        // 翻转链表
        fast = reverseLink(fast);


        // 同步比较
        while (fast) {
            if (fast->val != slow->val) {
                return false;
            }

            fast = fast->next;
            slow = slow->next;
        }

        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
