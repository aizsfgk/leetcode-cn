//给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "aaabb", k = 3
//输出：3
//解释：最长子串为 "aaa" ，其中 'a' 重复了 3 次。
// 
//
// 示例 2： 
//
// 
//输入：s = "ababbc", k = 2
//输出：5
//解释：最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 104 
// s 仅由小写英文字母组成 
// 1 <= k <= 105 
// 
// Related Topics 哈希表 字符串 分治 滑动窗口 
// 👍 614 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestSubstring(string s, int k) {
        // 滑动窗口思路
        //
        // 因为题干是小写字母，则符合条件的字串最多含有26类字母；遍历这26类字母；从做向右滑动
        //

        /*
        二段性质：
        题目说明了只包含小写字母（26 个，为有限数据），我们可以枚举最大长度所包含的字符类型数量，
        答案必然是 [1, 26]，即最少包含 1 个字母，最多包含 26 个字母。

        你会发现，当确定了长度所包含的字符种类数量时，区间重新具有了二段性质。

        当我们使用双指针的时候：

        右端点往右移动必然会导致字符类型数量增加（或不变）
        左端点往右移动必然会导致字符类型数量减少（或不变）


        */


        int ans = 0;
        vector<int> cnt(26, 0);

        // 遍历26种字符
        // p 表示当前限定的字符种类个数
        for (int p=1; p<=26; p++) {
             cnt.assign(26, 0);

             int left = 0, right = 0; // left表示左边界；right表示右边界
             // total 表示 [left, right] 区间所有的字符种类数量
             // sum 代表满足【出现次数不少于k】的字符种类数量
             int total = 0, sum = 0;

             while (right < s.size()) {
                int ci = s[right] - 'a';
                right++;
                cnt[ci]++;

                // 如果添加cnt后==1，说明字符总数+1
                if (cnt[ci] == 1) total++;

                // 如果添加cnt后 == k, 说明该字符从不达标到达标了，达标数+1
                if (cnt[ci] == k) sum++;

                // 当区间所包含的字符数量 total 超过了 当前的限定数量p
                // 需要缩小可行解了
                while (total > p) {
                    int di = s[left] - 'a';
                    left++; // 收缩左边类型种类
                    cnt[di]--;

                    // 如果添加到cnt之后为0， 说明字符总数-1
                    if (cnt[di] == 0) total--;

                    // 如果添加到 cnt 之后等于 k - 1, 说明该字符从达标变为不达标，达标数量-1
                    if (cnt[di] == k-1) sum--;
                }

                // 总的类型种类和符合要求的类型种类一样
                // 当前所有字符都符合要求，更新答案
                if (total == sum) ans = max(ans , right-left); // 这里left已经在 while里边+1了
             }
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
