//我们定义，在以下情况时，单词的大写用法是正确的： 
//
// 
// 全部字母都是大写，比如 "USA" 。 
// 单词中所有字母都不是大写，比如 "leetcode" 。 
// 如果单词不只含有一个字母，只有首字母大写， 比如 "Google" 。 
// 
//
// 给你一个字符串 word 。如果大写用法正确，返回 true ；否则，返回 false 。 
//
// 
//
// 示例 1： 
//
// 
//输入：word = "USA"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：word = "FlaG"
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= word.length <= 100 
// word 由小写和大写英文字母组成 
// 
// Related Topics 字符串 
// 👍 197 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool detectCapitalUse(string word) {
        // 大写小写
        int n = word.size();
        if (n <= 0) {
            return false;
        }

        int bigNum = 0;
        int littleNum = 0;
        for (int i=0; i<n; i++) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                bigNum++;
            }

            if (word[i] >= 'a' && word[i] <= 'z') {
                littleNum++;
            }
        }

        if (bigNum == n || littleNum == n) {
            return true;
        }

        if (bigNum == 1 && littleNum == n-1 && word[0] >= 'A' && word[0] <= 'Z') {
            return true;
        }

        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
