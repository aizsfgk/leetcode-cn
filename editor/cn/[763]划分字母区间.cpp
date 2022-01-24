//字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。 
//
// 
//
// 示例： 
//
// 
//输入：S = "ababcbacadefegdehijhklij"
//输出：[9,7,8]
//解释：
//划分结果为 "ababcbaca", "defegde", "hijhklij"。
//每个字母最多出现在一个片段中。
//像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
// 
//
// 
//
// 提示： 
//
// 
// S的长度在[1, 500]之间。 
// S只包含小写字母 'a' 到 'z' 。 
// 
// Related Topics 贪心 哈希表 双指针 字符串 
// 👍 643 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        // hash表
        int hash[27] = {0};
        // 记录每个字符的最右边索引
        for (int i=0; i<s.size(); i++) {
            hash[s[i] - 'a'] = i;
        }

        // 区间边界
        int left = 0;
        int right = 0;
        vector<int> ans;
        for (int i=0; i<s.size(); i++) {
            right = max(right, hash[s[i] - 'a']);

            // 如果索引相等，放入结果集
            if (right == i) {
                ans.push_back(right - left+1);
                left = i+1;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
