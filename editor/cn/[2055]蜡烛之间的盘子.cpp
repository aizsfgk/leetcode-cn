//给你一个长桌子，桌子上盘子和蜡烛排成一列。给你一个下标从 0 开始的字符串 s ，它只包含字符 '*' 和 '|' ，其中 '*' 表示一个 盘子 ，'|'
// 表示一支 蜡烛 。 
//
// 同时给你一个下标从 0 开始的二维整数数组 queries ，其中 queries[i] = [lefti, righti] 表示 子字符串 s[left
//i...righti] （包含左右端点的字符）。对于每个查询，你需要找到 子字符串中 在 两支蜡烛之间 的盘子的 数目 。如果一个盘子在 子字符串中 左边和右边
// 都 至少有一支蜡烛，那么这个盘子满足在 两支蜡烛之间 。 
//
// 
// 比方说，s = "||**||**|*" ，查询 [3, 8] ，表示的是子字符串 "*||**|" 。子字符串中在两支蜡烛之间的盘子数目为 2 ，子字符
//串中右边两个盘子在它们左边和右边 都 至少有一支蜡烛。 
// 
//
// 请你返回一个整数数组 answer ，其中 answer[i] 是第 i 个查询的答案。 
//
// 
//
// 示例 1: 
//
// 
//
// 输入：s = "**|**|***|", queries = [[2,5],[5,9]]
//输出：[2,3]
//解释：
//- queries[0] 有两个盘子在蜡烛之间。
//- queries[1] 有三个盘子在蜡烛之间。
// 
//
// 示例 2: 
//
// 
//
// 输入：s = "***|**|*****|**||**|*", queries = [[1,17],[4,5],[14,17],[5,11],[15,16
//]]
//输出：[9,0,0,0,0]
//解释：
//- queries[0] 有 9 个盘子在蜡烛之间。
//- 另一个查询没有盘子在蜡烛之间。
// 
//
// 
//
// 提示： 
//
// 
// 3 <= s.length <= 105 
// s 只包含字符 '*' 和 '|' 。 
// 1 <= queries.length <= 105 
// queries[i].length == 2 
// 0 <= lefti <= righti < s.length 
// 
// Related Topics 数组 字符串 二分查找 前缀和 
// 👍 47 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
/*
    从[动态规划]到[前缀和+二分]



*/
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        // 思路1 ： 动态规划
        int n = s.size();
        vector<int> f(n, 0);

        // 动态规划，计算[0,i] 合法盘子数
        // 1. 计算 0 - i 区间的合法盘子数
        int flag = 0, cnt = 0;
        if (s[0] == '|') flag = 1;
        for (int i=1; i<n; i++) {
            if (flag == 0 && s[i] == '|') {
                flag = 1;
            } else if (flag == 1 && s[i] == '*') {
                cnt++;
            } else if (flag == 1 && s[i] == '|') {
                f[i] = cnt;
                cnt = 0;
            }
            f[i] += f[i-1];
        }

        // i - j 的合法盘子数 等于 j的盘子数 - i 的盘子数， 而i的合法右边界是i右边的盘子索引
        // 也就是计算每个位置的右侧蜡烛位置
        vector<int> right(n, n-1);
        for (int i=n-2; i>=0; i--) {
            if (s[i] == '|') {
                right[i] = i;
            } else {
                right[i] = right[i+1];
            }
        }

        // 查询计算
        vector<int> ans;
        for (auto query : queries) {
            int l = query[0];
            int r = query[1];

            // l的右边蜡烛 >= l ; 则没有合法的盘子，所以为0
            if (right[l] >= r) {
                ans.push_back(0);
            } else {
                // 合法情况；右边位置，减去 左边位置，得到合法的盘子数
                ans.push_back(f[r] - f[right[l]]);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
