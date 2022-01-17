//给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。 
//
// 返回符合要求的 最少分割次数 。 
//
// 
// 
// 
//
// 示例 1： 
//
// 
//输入：s = "aab"
//输出：1
//解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
// 
//
// 示例 2： 
//
// 
//输入：s = "a"
//输出：0
// 
//
// 示例 3： 
//
// 
//输入：s = "ab"
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 2000 
// s 仅由小写英文字母组成 
// 
// 
// 
// Related Topics 字符串 动态规划 
// 👍 526 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    int minNum = INT_MAX;

public:
    bool isPalindrome(const string &s, int startIdx, int endIdx) {
        while(startIdx < endIdx) {
            if (s[startIdx] != s[endIdx]) {
                return false;
            }
            startIdx++;
            endIdx--;
        }
        return true;
    }

    // 回溯会超时；结果可用
    void backtrack(const string &s, int startIdx, int cutNum) {
        if (startIdx >= s.size()) {
            minNum = min(minNum, cutNum);
            return;
        }

        for (int i=startIdx; i<s.size(); i++) {
            if (isPalindrome(s, startIdx, i)) {
                string str = s.substr(startIdx, i-startIdx+1);
            } else {
                continue;
            }
            backtrack(s, i+1, cutNum+1);
        }
    }

    int minCut(string s) {
        if (s.size() == 0) {
            return 0;
        }

        if (isPalindrome(s, 0, s.size() - 1)) {
            return 0;
        }

        backtrack(s, 0, -1);
        return minNum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
