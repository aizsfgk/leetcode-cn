//给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。 
//
// 回文串 是正着读和反着读都一样的字符串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "aab"
//输出：[["a","a","b"],["aa","b"]]
// 
//
// 示例 2： 
//
// 
//输入：s = "a"
//输出：[["a"]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 16 
// s 仅由小写英文字母组成 
// 
// Related Topics 字符串 动态规划 回溯 
// 👍 954 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
// 分割回文串
/*
    如何解题?

    既可以回溯 ， 又可以dp.

*/
private:
    vector<vector<string>> ans;
    vector<string> path;
public:
    // 是否是回文串：辅助函数
    bool isPalindrome(const string &s, int startIdx, int endIdx) {
        while (startIdx < endIdx) {
            if (s[startIdx] != s[endIdx]) {
                return false;
            }
            startIdx++;
            endIdx--;
        }
        return true;
    }

    void backtracking(const string &s, int startIdx) {
        if (startIdx >= s.size()) {
            ans.push_back(path);
            return;
        }

        for (int i=startIdx; i<s.size(); i++) {
            if (isPalindrome(s, startIdx, i))  { // 是回文串
                string str = s.substr(startIdx, i-startIdx+1); // 获取子串
                path.push_back(str);
            } else {
                continue;
            }

            backtracking(s, i+1);
            path.pop_back();
        }

    }
    vector<vector<string>> partition(string s) {
        int size = s.size();
        if (size == 0)
            return ans;

        backtracking(s, 0);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
