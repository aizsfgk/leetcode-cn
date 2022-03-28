//给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4,5], k = 2
//输出：[4,5,1,2,3]
// 
//
// 示例 2： 
//
// 
//输入：head = [0,1,2], k = 4
//输出：[2,0,1]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 500] 内 
// -100 <= Node.val <= 100 
// 0 <= k <= 2 * 109 
// 
// Related Topics 链表 双指针 
// 👍 648 👎 0


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
    ListNode* rotateRight(ListNode* head, int k) {
        /*
            1. 非法状态剔除
            2. 找到最后一个节点，并计算节点个数
            3. 最后节点链接到头节点
            4. 再前进步数
            5. 当前节点之后节点为新的头节点；当前节点之后设为nullptr
            6. 返回 newHead;
        */
        if (!head || !head->next) {
            return head;
        }

        int num = 1;
        ListNode *prev = head;
        while (prev->next) {
            prev = prev->next;
            num++;
        }

        prev->next = head;

        int n = num - k % num;
        ListNode *cur = prev;
        while (n) {
            cur = cur->next;
            n--;
        }

        ListNode *newHead = cur->next;
        cur->next = nullptr;
        return newHead;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
