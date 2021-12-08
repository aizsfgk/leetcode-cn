//给定一个二叉树，编写一个函数来获取这个树的最大宽度。树的宽度是所有层中的最大宽度。这个二叉树与满二叉树（full binary tree）结构相同，但一些节
//点为空。 
//
// 每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的null节点也计入长度）之间的长度。 
//
// 示例 1: 
//
// 
//输入: 
//
//           1
//         /   \
//        3     2
//       / \     \  
//      5   3     9 
//
//输出: 4
//解释: 最大值出现在树的第 3 层，宽度为 4 (5,3,null,9)。
// 
//
// 示例 2: 
//
// 
//输入: 
//
//          1
//         /  
//        3    
//       / \       
//      5   3     
//
//输出: 2
//解释: 最大值出现在树的第 3 层，宽度为 2 (5,3)。
// 
//
// 示例 3: 
//
// 
//输入: 
//
//          1
//         / \
//        3   2 
//       /        
//      5      
//
//输出: 2
//解释: 最大值出现在树的第 2 层，宽度为 2 (3,2)。
// 
//
// 示例 4: 
//
// 
//输入: 
//
//          1
//         / \
//        3   2
//       /     \  
//      5       9 
//     /         \
//    6           7
//输出: 8
//解释: 最大值出现在树的第 4 层，宽度为 8 (6,null,null,null,null,null,null,7)。
// 
//
// 注意: 答案在32位有符号整数的表示范围内。 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 
// 👍 273 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    struct SData {
        long long val;
        TreeNode *root;
        SData() : val(0), root(nullptr) {}
        SData(long long x) : val(x), root(nullptr) {}
        SData(long long x, TreeNode *r) : val(x), root(r) {}
    };
public:
    long long ans;

    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        queue<SData*> q;
        q.push(new SData(0, root));

        long long v = 0;
        long long width = 0;
        while (!q.empty()) {
            int size = q.size();
            width = q.back()->val - q.front()->val + 1;

            for (int i=0; i< size; i++) {
                SData *node = q.front(); q.pop();

                if (node->root->left) {
                    v = node->val * 2 + 1;
                    q.push(new SData(v, node->root->left));
                }

                if (node->root->right) {
                    v = node->val * 2 + 2;
                    q.push(new SData(v, node->root->right));
                }
            }

            ans = max(ans, width);

        }

        return (int)ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
