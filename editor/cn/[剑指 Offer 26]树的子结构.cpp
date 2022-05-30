//输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构) 
//
// B是A的子结构， 即 A中有出现和B相同的结构和节点值。 
//
// 例如: 
//给定的树 A: 
//
// 3 
// / \ 
// 4 5 
// / \ 
// 1 2 
//给定的树 B： 
//
// 4 
// / 
// 1 
//返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。 
//
// 示例 1： 
//
// 输入：A = [1,2,3], B = [3,1]
//输出：false
// 
//
// 示例 2： 
//
// 输入：A = [3,4,5,1,2], B = [4,1]
//输出：true 
//
// 限制： 
//
// 0 <= 节点个数 <= 10000 
// Related Topics 树 深度优先搜索 二叉树 
// 👍 564 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    // 判断两个数是否相同
    // leetcode 的 572 判断不太一样；因为 (约定空树不是任意一个树的子结构)
    // 需要注意
    bool dfs(TreeNode *A, TreeNode *B) {
        if (B == nullptr) // B为空了，所以结束了
            return true;
        if (A == nullptr || A->val != B->val) // 不是子树
            return false;

        return dfs(A->left, B->left) && dfs(A->right, B->right); // 依次寻找
    }


public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        // (约定空树不是任意一个树的子结构)
        // 所以 A != nullptr && B != nullptr
        return (A != nullptr && B != nullptr) && ( dfs(A, B)|| isSubStructure(A->left, B) || isSubStructure(A->right, B) ) ;
    }
};
//class Solution {
//
//private:
//    // 检测两颗树是否完全相同
//    bool isSameTree(TreeNode* p, TreeNode* q) {
//         // 深度优先
//        if (p == nullptr && q == nullptr) {
//            return true;
//        } else if (p == nullptr || q == nullptr) {
//            return false;
//        } else if ( p->val != q->val) {
//            return false;
//        } else {
//            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//        }
//
//    }
//public:
//    bool isSubStructure(TreeNode* root, TreeNode* subRoot) {
//
//        if (root == nullptr && subRoot == nullptr) {
//            return true;
//        }
//
//        if (subRoot == nullptr) {
//            return true;
//        }
//
//        stack<TreeNode *> s;
//        s.push(root);
//
//        TreeNode *node = nullptr;
//        bool ret = false;
//
//        while (!s.empty()) {
//
//            node = s.top(); s.pop();
//
//            ret = isSameTree(node, subRoot);
//            if (ret) {
//                return true;
//            }
//
//            if (node->right) {
//                s.push(node->right);
//            }
//
//            if (node->left) {
//                s.push(node->left);
//            }
//        }
//
//        return false;
//    }
//};
//leetcode submit region end(Prohibit modification and deletion)
