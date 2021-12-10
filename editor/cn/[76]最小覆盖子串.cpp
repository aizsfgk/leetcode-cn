//给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。 
//
// 
//
// 注意： 
//
// 
// 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。 
// 如果 s 中存在这样的子串，我们保证它是唯一的答案。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "ADOBECODEBANC", t = "ABC"
//输出："BANC"
// 
//
// 示例 2： 
//
// 
//输入：s = "a", t = "a"
//输出："a"
// 
//
// 示例 3: 
//
// 
//输入: s = "a", t = "aa"
//输出: ""
//解释: t 中两个字符 'a' 均应包含在 s 的子串中，
//因此没有符合条件的子字符串，返回空字符串。 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length, t.length <= 105 
// s 和 t 由英文字母组成 
// 
//
// 
//进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？ Related Topics 哈希表 字符串 滑动窗口 
// 👍 1474 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string minWindow(string s, string t) {
        // 使用map, 进行匹配统计
        unordered_map<char, int> need;
        unordered_map<char, int> window;

        // 更新need map
        for (char c : t)
            need[c]++;

        // 窗口左右索引; 左闭右开
        int left = 0, right = 0;

        // 结果子串需要的条件
        int start = 0;
        int minLen = INT_MAX;

        // 匹配数
        int match = 0;

        // 开始移动窗口
        while (right < s.size()) {
            char c = s[right];
            right++;

            // 如果找到则窗口map++;
            if (need.count(c)) {
                window[c]++;
                // 只有个数完全一致， match才++
                if (window[c] == need[c]) {
                    match++;
                }
            }

            // 此时找到可行解
            while (match == need.size()) {

                // 拿到解
                if (right - left < minLen) {
                    start = left;
                    minLen= right - left;
                }

                char d = s[left];
                left++;

                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        match--;
                    }
                    window[d]--;
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
