//假设有从 1 到 n 的 n 个整数。用这些整数构造一个数组 perm（下标从 1 开始），只要满足下述条件 之一 ，该数组就是一个 优美的排列 ： 
//
// 
// perm[i] 能够被 i 整除 
// i 能够被 perm[i] 整除 
// 
//
// 给你一个整数 n ，返回可以构造的 优美排列 的 数量 。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 2
//输出：2
//解释：
//第 1 个优美的排列是 [1,2]：
//    - perm[1] = 1 能被 i = 1 整除
//    - perm[2] = 2 能被 i = 2 整除
//第 2 个优美的排列是 [2,1]:
//    - perm[1] = 2 能被 i = 1 整除
//    - i = 2 能被 perm[2] = 1 整除
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 15 
// 
// Related Topics 位运算 数组 动态规划 回溯 状态压缩 👍 303 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    int ans = 0;
    vector<int> path;
//    bool check(const vector<int> &path) {
//        for (int i=0; i<path.size(); i++) {
//            if ((path[i] % (i+1) != 0) && ((i+1) % (path[i]) != 0)) {
//                return false;
//            }
//        }
//        return true;
//    }

//    void printVector(const vector<int> &path) {
//        for (auto num : path) {
//            cout << num << ",";
//        }
//        cout << endl;
//    }
    void backtracking(int n, int idx, vector<bool> &used) {
        if (idx > n) {
            ans++;
            return;
        }


        for (int i=1; i<=n; i++) {
            if (used[i]) {
                continue;
            }

            used[i] = true;
//            path.push_back(i+1);
            if (i%idx == 0 || idx%i == 0) {
                backtracking(n, idx+1, used);
            }

//            path.pop_back();
            used[i] = false;
        }
    }
public:
    int countArrangement(int n) {
        if (n <= 1) return n;

        vector<bool> used(n);
        backtracking(n, 1, used);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
