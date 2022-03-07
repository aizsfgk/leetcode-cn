//给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。
//
// 两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串： 
//
// 
// s = s1 + s2 + ... + sn 
// t = t1 + t2 + ... + tm 
// |n - m| <= 1 
// 交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ... 
// 
//
// 注意：a + b 意味着字符串 a 和 b 连接。 
//
// 
//
// 示例 1： 
//
// 
//输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
//输出：truez
// 
//
// 示例 2： 
//
// 
//输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
//输出：false
// 
//
// 示例 3： 
//
// 
//输入：s1 = "", s2 = "", s3 = ""
//输出：true
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s1.length, s2.length <= 100 
// 0 <= s3.length <= 200 
// s1、s2、和 s3 都由小写英文字母组成 
// 
//
// 
//
// 进阶：您能否仅使用 O(s2.length) 额外的内存空间来解决它? 
// Related Topics 字符串 动态规划 
// 👍 642 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/*
1. 回溯 -> 递归
2. 带备忘录的递归
3. 动态规划

*/
class Solution {
private:
    bool check(const string &s1, int i,
            const string &s2, int j,
            const string &s3, int k,
            vector<vector<int>> &memo) {

        if ( memo[i][j] != 0) {
            return memo[i][j] > 0 ? true : false;
        }

        if (k == s3.size()) {
            memo[i][j] = 1;
            return true;
        }

        bool isValid = false;
        if (i < s1.size() && s1[i] == s3[k]) {
            isValid = check(s1, i+1, s2, j, s3, k+1, memo);
        }
        if (j < s2.size() && s2[j] == s3[k]) {
            isValid = isValid || check(s1, i, s2, j+1, s3, k+1, memo);
        }
        memo[i][j] = isValid ? 1 : -1;
        return isValid;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        // 回溯可以进行多分支选择，如果这个分支不合法，退回状态
        // 选择另一个分支。
        // 回溯法的本质。


        if (s1.size() + s2.size() != s3.size())
            return false;
        // 为何需要+1 ??? i+1, 或者 k+1
        vector<vector<int>> memo(s1.size()+1, vector<int>(s2.size()+1));

        // 没有剪枝; 会超时
        return check(s1, 0, s2, 0, s3, 0, memo);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
