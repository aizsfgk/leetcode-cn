//给定一个单链表 L 的头节点 head ，单链表 L 表示为： 
//
// L0 → L1 → … → Ln-1 → Ln 
//请将其重新排列后变为： 
//
// L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → … 
//
// 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入: head = [1,2,3,4]
//输出: [1,4,2,3] 
//
// 示例 2: 
//
// 
//
// 
//输入: head = [1,2,3,4,5]
//输出: [1,5,2,4,3] 
//
// 
//
// 提示： 
//
// 
// 链表的长度范围为 [1, 5 * 10⁴] 
// 1 <= node.val <= 1000 
// 
//
// 
//
// 注意：本题与主站 143 题相同：https://leetcode-cn.com/problems/reorder-list/ 
// Related Topics 栈 递归 链表 双指针 👍 63 👎 0


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
    void PrintLink(ListNode *head) {
        while (head) {
            cout << head->val << ", ";
            head = head->next;
        }
        cout << endl;
    }

     void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast -> next != NULL){ // 都可以
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        ListNode* dummyHead = new ListNode(-1);
        ListNode* p = dummyHead;
        fast = slow -> next;
        slow -> next = NULL; //断链

//        PrintLink(fast);
//        cout << "||||" << endl;
        fast = reverseLink(fast);
        slow = head;
        while(slow != NULL && fast != NULL){
            p -> next = slow;
            slow = slow -> next;
            p = p -> next;
            p -> next = fast;
            fast = fast -> next;
            p = p -> next;
        }
        if(fast != NULL) slow = fast;
        while(slow != NULL){
            p -> next = slow;
            slow = slow -> next;
            p = p -> next;
        }
        p = dummyHead -> next;
        delete dummyHead;
    }
    /*
    void reorderList(ListNode* head) {

        if (head == nullptr) return;

        ListNode *fast = head, *slow = head;

        // 这样slow->next 是下一个节点
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        fast = slow->next;
        slow->next = nullptr;

        fast = reverseLink(fast);
        slow = head;

        ListNode dummy(-1), *cur = &dummy;
        while (slow && fast) {
            cur->next = slow;
            slow = slow->next;
            cur = cur->next;

            cur->next = fast;
            fast = fast->next;
            cur = cur->next;
        }
        while (slow) {
            cur->next = slow;
            slow = slow->next;
            cur = cur->next;
        }

        return;
    }
    */

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

};
//leetcode submit region end(Prohibit modification and deletion)
