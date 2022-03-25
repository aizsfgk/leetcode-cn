//编写一个函数来查找字符串数组中的最长公共前缀。 
//
// 如果不存在公共前缀，返回空字符串 ""。 
//
// 示例 1: 
//
// 输入: ["flower","flow","flight"]
//输出: "fl"
// 
//
// 示例 2: 
//
// 输入: ["dog","racecar","car"]
//输出: ""
//解释: 输入不存在公共前缀。
// 
//
// 说明: 
//
// 所有输入只包含小写字母 a-z 。 
// Related Topics 字符串


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";


        // 1次遍历
        string prefix = strs[0];
        for (int i=1; i<strs.size(); i++) {
            while (strs[i].find(prefix) != 0) { // 没有找到前缀
                prefix = prefix.substr(0, prefix.size()-1);
                if (prefix.empty()) {
                    return "";
                }
            }
        }
        return prefix;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
