//给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,2,1]
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：head = [1,2]
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点数目在范围[1, 105] 内 
// 0 <= Node.val <= 9 
// 
//
// 
//
// 进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？ 
// Related Topics 栈 递归 链表 双指针 
// 👍 1172 👎 0


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
    bool isPalindromeArray(vector<int> &num) {
        int size = num.size();

        if (size == 0) {
           return true;
        }

        int i = 0;
        int j = size - 1;

        while (i < j) {
          if (num[i] == num[j]) {
             i++;
             j--;
          } else {
             return false;
          }
        }

        return true;
    }

    // 遍历称为数组，然后判断是否是回文数组
    bool isPalindrome(ListNode* head) {
        vector<int> num;

        while (head) {
            num.push_back(head->val);
            head = head->next;
        }

        return isPalindromeArray(num);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
