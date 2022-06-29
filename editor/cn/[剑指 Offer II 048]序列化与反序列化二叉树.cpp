//序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方
//式重构得到原数据。 
//
// 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反
//序列化为原始的树结构。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [1,2,3,null,null,4,5]
//输出：[1,2,3,null,null,4,5]
// 
//
// 示例 2： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：root = [1]
//输出：[1]
// 
//
// 示例 4： 
//
// 
//输入：root = [1,2]
//输出：[1,2]
// 
//
// 
//
// 提示： 
//
// 
// 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，也可以采用其他的方法解决这
//个问题。 
// 树中结点数在范围 [0, 104] 内 
// -1000 <= Node.val <= 1000 
// 
//
// 
//
// 注意：本题与主站 297 题相同：https://leetcode-cn.com/problems/serialize-and-deserialize-b
//inary-tree/ 
// Related Topics 树 深度优先搜索 广度优先搜索 设计 字符串 二叉树 
// 👍 46 👎 0


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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        if (!root) {
            ans += "#,";
            return ans;
        }

        queue<TreeNode *> que;
        que.push(root);

        while (!que.empty()) {
            root = que.front(); que.pop();

            if (root) {
                ans += to_string(root->val) + ",";
                que.push(root->left);
                que.push(root->right);
            } else {
                ans += "#,";
            }
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // 字符串转换为二叉树
        vector<string> dataArray = string2array(data);

        if (dataArray.size() == 1 && dataArray[0] == "#") return nullptr;

        TreeNode *root = new TreeNode(stoi(dataArray[0]));

        int cursor = 1;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            TreeNode *cur = que.front(); que.pop();

            string leftVal = dataArray[cursor];
            string rightVal = dataArray[cursor+1];

            if (leftVal != "#") {
                cur->left = new TreeNode(stoi(leftVal));
                que.push(cur->left);
            }

            if (rightVal != "#") {
                cur->right = new TreeNode(stoi(rightVal));
                que.push(cur->right);
            }
            cursor += 2;
        }
        return root;
    }

    vector<string> string2array(const string &data) {
        vector<string> ans;

        int startIdx = 0;
        for (int i=0; i<data.size(); i++) {
            if (data[i] == ',') {
                string sub = data.substr(startIdx, i-startIdx);
                ans.push_back(sub);
                startIdx = i+1;
            }
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
//leetcode submit region end(Prohibit modification and deletion)
