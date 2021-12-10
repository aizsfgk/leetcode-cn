//给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。如果是，返回 true ；否则，返回 false 。 
//
// 换句话说，s1 的排列之一是 s2 的 子串 。 
//
// 
//
// 示例 1： 
//
// 
//输入：s1 = "ab" s2 = "eidbaooo"
//输出：true
//解释：s2 包含 s1 的排列之一 ("ba").
// 
//
// 示例 2： 
//
// 
//输入：s1= "ab" s2 = "eidboaoo"
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s1.length, s2.length <= 104 
// s1 和 s2 仅包含小写字母 
// 
// Related Topics 哈希表 双指针 字符串 滑动窗口 
// 👍 510 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;

        for (char c : s1) {
            need[c]++;
        }

        int left = 0, right = 0;
        int match = 0;

        while (right < s2.size()) {
            char c = s2[right];
            right++;

            if (need.count(c)) {
                window[c]++;

                if (need[c] == window[c]) {
                    match++;
                }
            }


/// 这里是错误的
//            if (right - left >= s1.size()) {
//                // 符合条件
//                if (match == need.size()) {
//                    return true;
//                }
//            }


            /// 此时获取可行解
            /// 窗口长度必须是 2
            while (right - left >= s1.size()) {
                // 符合条件
                // 相等就是符合条件
                if (match == need.size()) {
                    return true;
                }

                char d = s2[left];
                left++;
                if (need.count(d)) {
                    // 先判断
                    if (need[d] == window[d]) {
                        match--;
                    }
                    window[d]--;
                }
            }
        }

        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
