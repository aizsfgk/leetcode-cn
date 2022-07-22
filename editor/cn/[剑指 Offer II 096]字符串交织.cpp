//给定三个字符串 s1、s2、s3，请判断 s3 能不能由 s1 和 s2 交织（交错） 组成。 
//
// 两个字符串 s 和 t 交织 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串： 
//
// 
// s = s1 + s2 + ... + sn 
// t = t1 + t2 + ... + tm 
// |n - m| <= 1 
// 交织 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ... 
// 
//
// 提示：a + b 意味着字符串 a 和 b 连接。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
//输出：true
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
// 注意：本题与主站 97 题相同： https://leetcode-cn.com/problems/interleaving-string/ 
// Related Topics 字符串 动态规划 👍 24 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
<<<<<<< HEAD
public:
    bool isInterleave(string s1, string s2, string s3) {

    }
};
=======
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

        vector<vector<int>> memo(s1.size()+1, vector<int>(s2.size()+1));

        // 没有剪枝; 会超时
        return check(s1, 0, s2, 0, s3, 0, memo);
    }
};

>>>>>>> 0cc0f34f5081b86e23effd53b578d35cab26243b
//leetcode submit region end(Prohibit modification and deletion)
