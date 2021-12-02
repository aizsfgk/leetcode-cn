  &emsp;我看了大部分的双指针法都是通过数学公式来推导，可能因为我刷的题还比较少，想了很久没想到官方给出的解题思路。我自己的方法也是双指针法，正好我前两天刷了LeetCode19. 删除链表的倒数第 N 个结点，然后有了本题的思路。
  &emsp;解题步骤还是两步：step 1.先判断是否有环 step 2.寻找环的入口。
  &emsp;step 1.判断是否有环
  &emsp;快指针fast和慢指针slow都从头结点开始遍历，fast每次移动两个节点，slow每次移动一个节点。如果存在环，fast和slow最终都会进入环，并且因为fast移动的速度快，fast和slow指针最终一定会在环内某个节点相遇，并用一个临时节点记录下相遇处的节点。其实就像两个人在环形操场跑步，跑的快的人和跑的慢的人最终一定会遇见。
  &emsp;step 2.寻找环的入口
  &emsp;首先认识到环入口处的节点cur有一个特点，cur的上一个节点的指向和当前链表最后一个节点的指向都是cur。
![circularlinkedlist.png](https://pic.leetcode-cn.com/1633861445-bAASgJ-circularlinkedlist.png)
  &emsp;就如上图所示，值为3的节点和值为-4的节点都指向值为2的节点，我所说的链表最后一个节点时是指值为-4的节点。
  &emsp;我们在step 1中记录下了相遇的节点temp，然后我们让step 1中的slow指针在环内不断遍历，不断slow++，一直到指针再次指向temp节点，通过slow在环内移动的次数，我们可以统计出环内有n个节点。
  &emsp;此时倒数第n个节点正好就是环入口的节点，那么我们就可以把问题转化为寻找链表的倒数第n个节点。
  &emsp;这个时候双指针又派上用场了，让fast和slow指针重新指向head节点，然后移动fast指针n-1次，让fast和slow指针之间间隔n-1个节点。接着同时移动fast和slow，即fast++和slow++，当Fast.next==slow，说明fast移动到最后一个节点，这个时候slow指针指向的就是倒数第n个节点，也就是环入口处的节点。不知道这样讲大家能不能看懂，大家有疑问可以在评论下方打出，我很乐意同大家交流学习。另外，大家对于寻找单链表倒数第n个节点不太清楚的，也可以参考[https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/](力扣19. 删除链表的倒数第 N 个结点)。
&emsp;代码如下：
```
// 双指针法
    // 1先确定是否有环，2找到环入口
    public ListNode detectCycle(ListNode head) {
        if (head == null)
            return head;
        ListNode fast = head;
        ListNode slow = head;
        while (fast != null && fast.next != null) {//判断是否有环，如果快慢指针最终相遇，说明存在环
            slow = slow.next;
            fast = fast.next.next;
            if (fast == slow) {//相遇了，说明有环，结束循环
                break;
            }
        }
        if (fast == null || fast.next == null) //无环
            return null;
        ListNode temp = fast;//保存相遇节点
        int lenCir = 0;//环内节点数量-1
        while (fast.next != temp) {
            fast = fast.next;
            lenCir++;
        }
        //接下来相当于寻找倒数第(lenCir+1)个节点
        fast = head;
        slow = head;
        while (lenCir > 0) {
            fast = fast.next;
            lenCir--;
        }
        while (slow != fast.next) {
            slow = slow.next;
            fast = fast.next;
        }
        return slow;
    }
```
时间复杂度分析：判断是否有环时间复杂度为O(n)，计算环内节点时间复杂度为O(n)，最后寻找倒数第n个节点时间fast指针遍历整个链表，时间复杂度为O(n)，总的时间复杂度为O(n)。
空间复杂度分析：只用到了常数级别的节点，因此空间复杂度为O(1)。

