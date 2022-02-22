//n 张多米诺骨牌排成一行，将每张多米诺骨牌垂直竖立。在开始时，同时把一些多米诺骨牌向左或向右推。 
//
// 每过一秒，倒向左边的多米诺骨牌会推动其左侧相邻的多米诺骨牌。同样地，倒向右边的多米诺骨牌也会推动竖立在其右侧的相邻多米诺骨牌。 
//
// 如果一张垂直竖立的多米诺骨牌的两侧同时有多米诺骨牌倒下时，由于受力平衡， 该骨牌仍然保持不变。 
//
// 就这个问题而言，我们会认为一张正在倒下的多米诺骨牌不会对其它正在倒下或已经倒下的多米诺骨牌施加额外的力。 
//
// 给你一个字符串 dominoes 表示这一行多米诺骨牌的初始状态，其中： 
//
// 
// dominoes[i] = 'L'，表示第 i 张多米诺骨牌被推向左侧， 
// dominoes[i] = 'R'，表示第 i 张多米诺骨牌被推向右侧， 
// dominoes[i] = '.'，表示没有推动第 i 张多米诺骨牌。 
// 
//
// 返回表示最终状态的字符串。 
// 
//
// 示例 1： 
//
// 
//输入：dominoes = "RR.L"
//输出："RR.L"
//解释：第一张多米诺骨牌没有给第二张施加额外的力。
// 
//
// 示例 2： 
//
// 
//输入：dominoes = ".L.R...LR..L.."
//输出："LL.RR.LLRRLL.."
// 
//
// 
//
// 提示： 
//
// 
// n == dominoes.length 
// 1 <= n <= 105 
// dominoes[i] 为 'L'、'R' 或 '.' 
// 
// Related Topics 双指针 字符串 动态规划 
// 👍 167 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();

        queue<int> que; // 位置队列，表示该位置发生了一个作用力
        vector<int> time(n, -1); // 表示该指定位置发生在变化的第几次
        vector<string> force(n); // 表示指定位置被作用了几个力

        for (int i=0; i<n; i++) {
            if (dominoes[i] != '.') {
                que.push(i);
                time[i] = 0; // 首次
                force[i].push_back(dominoes[i]); // 放入该位置作用的力
            }
        }

        string ans(n, '.'); // 结果答案
        while (!que.empty()) {
            int idx = que.front(); que.pop(); // 拿到第一个作用的位置

            // 开始都是一个作用力
            // 走一轮，然后再看看结果
            if (force[idx].size() == 1) { // 只有一个作用力才继续王下走
                auto c = force[idx][0];
                ans[idx] = c;

                int newIdx = c == 'L' ? idx-1 : idx+1;
                if (newIdx >= 0 && newIdx < n) { // 这是一个合法的索引位置
                    int curTimeVal = time[idx]; // 之前的一个轮数

                    if (time[newIdx] == -1) { // 从来没有访问过
                        que.push(newIdx); // 入队
                        time[newIdx] = curTimeVal + 1;
                        force[newIdx].push_back(c);
                    } else if (time[newIdx] == curTimeVal + 1) { /// 新位置直接等于之前的论数，则直接放到作用力的对应的string中
                        force[newIdx].push_back(c);
                    }
                }
            }
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
