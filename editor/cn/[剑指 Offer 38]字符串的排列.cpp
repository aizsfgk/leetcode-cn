//输入一个字符串，打印出该字符串中字符的所有排列。 
//
// 
//
// 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。 
//
// 
//
// 示例: 
//
// 输入：s = "abc"
//输出：["abc","acb","bac","bca","cab","cba"]
// 
//
// 
//
// 限制： 
//
// 1 <= s 的长度 <= 8 
// Related Topics 字符串 回溯 
// 👍 565 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<string> ans;
    string path;

public:
    void backtracking(const string &s, vector<bool> &used) {
        // visited
        if (path.size() == s.size()) {
            ans.push_back(path);
            return;
        }

        int layerUsed[256] = {0}; // 同层去重
        for (int i=0; i<s.size(); i++) {
            if (used[i]) {
                continue;
            }

            if (layerUsed[s[i]] == 1) {
                continue;
            }

            used[i] = true; // 同一枝叶去重
            layerUsed[s[i]] = 1;

            path.push_back(s[i]);
            backtracking(s, used);
            path.pop_back();

            used[i] = false;
        }
    }

    vector<string> permutation(string s) {
        // 回溯算法
        if (s.empty())
            return ans;

        vector<bool> used(s.size(), false);
        backtracking(s, used);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
