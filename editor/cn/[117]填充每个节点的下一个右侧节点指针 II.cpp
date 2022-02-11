//给定一个二叉树 
//
// 
//struct Node {
//  int val;
//  Node *left;
//  Node *right;
//  Node *next;
//} 
//
// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。 
//
// 初始状态下，所有 next 指针都被设置为 NULL。 
//
// 
//
// 进阶： 
//
// 
// 你只能使用常量级额外空间。 
// 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。 
// 
//
// 
//
// 示例： 
//
// 
//
// 
//输入：root = [1,2,3,4,5,null,7]
//输出：[1,#,2,3,#,4,5,7,#]
//解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化输出按层序遍历顺序（由 next 指
//针连接），'#' 表示每层的末尾。 
//
// 
//
// 提示： 
//
// 
// 树中的节点数小于 6000 
// -100 <= node.val <= 100 
// 
//
// 
//
// 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 链表 二叉树 
// 👍 506 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // 这道题的要求是不能使用队列。
        // 思路:我们需要在一层中遍历时选取下一层最左边的结点保留下来用作下一层的循环时


        // 记录最左侧节点
        Node *l = root;

        // 左侧节点不为空
        while (l != nullptr) {
            // 则当前点就是最左侧点
            Node *cur = l;
            // 之前的点更新为空
            Node *pre = nullptr;
            // 最左侧点设置为空；方便找到下层最左侧点
            l = nullptr;

            // 开始更新本层点
            while (cur != nullptr) {
                // 存在左孩子
                if (cur->left) {
                    // 跟新下层最左边的节点
                    if (l == nullptr) l = cur->left;

                    // 之前不为空；则进行连接
                    if (pre != nullptr) {
                        pre->next = cur->left;
                    }

                    // 更新之前的节点
                    pre = cur->left;
                }

                // 存在右孩子
                if (cur->right) {
                    if (l == nullptr) l = cur->right;

                    if (pre != nullptr) {
                        pre->next = cur->right;
                    }

                    pre = cur->right;
                }

                // 当前元素改为下一个元素
                cur = cur->next;
            }
        }

        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
