### 解题思路
因为`k`有可能大于链表长度，所以首先**获取一下链表长度`len`**。如果`k % len == 0`，等于不用旋转，直接返回头结点。否则：
1. 快指针先走`k`步。
2. 慢指针和快指针一起走。
3. 快指针走到链表尾部时，慢指针刚好走到**旋转链表**（返回的链表）的尾部。把快指针指向的节点连到原链表头部，慢指针指向的节点断开和下一节点的联系。
4. 返回结束时慢指针指向节点的下一节点。

### 代码

```java
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null || k == 0){
            return head;
        }
        ListNode temp = head;
        ListNode fast = head;
        ListNode slow = head;
        int len = 0;
        while(head != null){
            head = head.next;
            len++;
        }
        if(k % len == 0){
            return temp;
        }
        while((k % len) > 0){
            k--;
            fast = fast.next;
        }
        while(fast.next != null){
            fast = fast.next;
            slow = slow.next;
        }
        ListNode res = slow.next;
        slow.next = null;
        fast.next = temp;
        return res;
    }
}
```