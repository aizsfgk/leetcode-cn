//序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。 
//
// 设计一个算法来序列化和反序列化 二叉搜索树 。 对序列化/反序列化算法的工作方式没有限制。 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序
//列化为最初的二叉搜索树。 
//
// 编码的字符串应尽可能紧凑。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [2,1,3]
//输出：[2,1,3]
// 
//
// 示例 2： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数范围是 [0, 104] 
// 0 <= Node.val <= 104 
// 题目数据 保证 输入的树是一棵二叉搜索树。 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 设计 二叉搜索树 字符串 二叉树 
// 👍 258 👎 0


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
class Codec {
public:
    string serialize(TreeNode* root) {
        // 层序遍历；空指针改成#
        if (root == nullptr) {
            return "#,";
        }

        string ans;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            auto ele = que.front(); que.pop();
            if (ele == nullptr) {
                ans += "#,"; // 先导放入
            } else {
                ans += to_string(ele->val) + ","; // 我这个最后要有个逗号
                que.push(ele->left);
                que.push(ele->right);
            }
        }

        // while (!que.empty()) { /// 这种方式是错误的
        //     int n = que.size();
        //     for (int i=0;i<n; i++) {
        //         auto ele = que.front(); que.pop();
        //         ans.push_back(ele->val + '0');
        //         if (ele->left) {
        //             que.push(ele->left);
        //         } else {
        //             ans.push_back('#');
        //         }
        //         if (ele->right) {
        //             que.push(ele->right);
        //         } else {
        //             ans.push_back('#');
        //         }
        //     }
        // }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> dataVec = str2arr(data);
        if (dataVec.size() == 1 && dataVec[0] == "#") {
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(dataVec[0]));
        queue<TreeNode *> que;
        que.push(root);
        int cursor = 1;


        while (cursor < dataVec.size() && !que.empty()) {
            TreeNode *node = que.front(); que.pop();

            string leftVal = dataVec[cursor];
            string rightVal = dataVec[cursor+1];

            if (leftVal != "#" && node != nullptr) {
                node->left = new TreeNode(stoi(leftVal));
                que.push(node->left);
            }

            if (rightVal != "#" && node != nullptr) {
                node->right = new TreeNode(stoi(rightVal));
                que.push(node->right);
            }
            cursor += 2;
        }
        return root;
    }

    vector<string> str2arr(const string &s) {
        vector<string> ans;

        int startIdx = 0;
        for (int i=1; i<s.size(); i++) {
            if (s[i] == ',') {
                string substr = s.substr(startIdx, i-startIdx);
                ans.push_back(substr);
                startIdx = i+1;
            }
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
//leetcode submit region end(Prohibit modification and deletion)
