//给定一个头结点为 head 的非空单链表，返回链表的中间结点。 
//
// 如果有两个中间结点，则返回第二个中间结点。 
//
// 
//
// 示例 1： 
//
// 
//输入：[1,2,3,4,5]
//输出：此列表中的结点 3 (序列化形式：[3,4,5])
//返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
//注意，我们返回了一个 ListNode 类型的对象 ans，这样：
//ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = 
//NULL.
// 
//
// 示例 2： 
//
// 
//输入：[1,2,3,4,5,6]
//输出：此列表中的结点 4 (序列化形式：[4,5,6])
//由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
// 
//
// 
//
// 提示： 
//
// 
// 给定链表的结点数介于 1 和 100 之间。 
// 
// Related Topics 链表 双指针 
// 👍 523 👎 0


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
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        int sum = 0;
        ListNode *cur = head;
        while (cur) {
            cur = cur->next;
            sum++;
        }

//        bool hasTwo = false;
//        if (sum % 2 == 0) {
//            hasTwo = true;
//        }

        int mid = sum/2 + 1;

        ListNode *cur2 = head;
        int num = 0;
        while (cur2) {
            num++;
            if (num == mid) {
//                if (hasTwo) {
//                    cur2->next->next = nullptr;
//                } else {
//                    cur2->next = nullptr;
//                }
                break;
            }
            cur2 = cur2->next;
        }
        return cur2;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
