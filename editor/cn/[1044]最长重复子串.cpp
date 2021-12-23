//给你一个字符串 s ，考虑其所有 重复子串 ：即，s 的连续子串，在 s 中出现 2 次或更多次。这些出现之间可能存在重叠。 
//
// 返回 任意一个 可能具有最长长度的重复子串。如果 s 不含重复子串，那么答案为 "" 。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "banana"
//输出："ana"
// 
//
// 示例 2： 
//
// 
//输入：s = "abcd"
//输出：""
// 
//
// 
//
// 提示： 
//
// 
// 2 <= s.length <= 3 * 104 
// s 由小写英文字母组成 
// 
// Related Topics 字符串 二分查找 后缀数组 滑动窗口 哈希函数 滚动哈希 
// 👍 243 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    unsigned long long prime = 31;
    int check(string &s, int len) {
        int n = s.size();
        int m = len;
        if (n == 0) {
            return -1;
        }

        unsigned long long hash = 0;
        unsigned long long power = 1;
        for (int i=0; i<m; i++) {
            hash = hash * prime + (s[i] - 'a');
            power *= prime;
        }

        unordered_map<unsigned long long, int> mp;

        mp[hash] = 1;
        for (int i=m; i<n; i++) {
            hash = hash * prime - power * (s[i-m] - 'a') + (s[i] - 'a');

            if (mp[hash] == 1) {
                return i-m+1; // m = j - i + 1 ==> i = j -m +1
            }

            mp[hash]++;
        }
        return -1;
    }
public:
    string longestDupSubstring(string s) {
        // RK算法 + 二分查找
        int l = 0;
        int r = s.size() - 1;

        int pos = -1, len = 0;
        while (l <= r) {
            int mid = l + (r-l)/2;

            int start = check(s, mid);

            if (start != -1) {
                len = mid;
                pos = start;
                l = mid + 1;
            } else {
                r = mid -1;
            }
        }
        if (pos == -1) {
            return "";
        }
        return s.substr(pos, len);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
