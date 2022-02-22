//给你一个整数数组 nums 。如果 nums 的一个子集中，所有元素的乘积可以表示为一个或多个 互不相同的质数 的乘积，那么我们称它为 好子集 。 
//
// 
// 比方说，如果 nums = [1, 2, 3, 4] ：
//
// 
// [2, 3] ，[1, 2, 3] 和 [1, 3] 是 好 子集，乘积分别为 6 = 2*3 ，6 = 2*3 和 3 = 3 。 
// [1, 4] 和 [4] 不是 好 子集，因为乘积分别为 4 = 2*2 和 4 = 2*2 。 
// 
// 
// 
//
// 请你返回 nums 中不同的 好 子集的数目对 109 + 7 取余 的结果。 
//
// nums 中的 子集 是通过删除 nums 中一些（可能一个都不删除，也可能全部都删除）元素后剩余元素组成的数组。如果两个子集删除的下标不同，那么它们被视
//为不同的子集。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3,4]
//输出：6
//解释：好子集为：
//- [1,2]：乘积为 2 ，可以表示为质数 2 的乘积。
//- [1,2,3]：乘积为 6 ，可以表示为互不相同的质数 2 和 3 的乘积。
//- [1,3]：乘积为 3 ，可以表示为质数 3 的乘积。
//- [2]：乘积为 2 ，可以表示为质数 2 的乘积。
//- [2,3]：乘积为 6 ，可以表示为互不相同的质数 2 和 3 的乘积。
//- [3]：乘积为 3 ，可以表示为质数 3 的乘积。
// 
//
// 示例 2： 
//
// 
//输入：nums = [4,2,3,15]
//输出：5
//解释：好子集为：
//- [2]：乘积为 2 ，可以表示为质数 2 的乘积。
//- [2,3]：乘积为 6 ，可以表示为互不相同质数 2 和 3 的乘积。
//- [2,15]：乘积为 30 ，可以表示为互不相同质数 2，3 和 5 的乘积。
//- [3]：乘积为 3 ，可以表示为质数 3 的乘积。
//- [15]：乘积为 15 ，可以表示为互不相同质数 3 和 5 的乘积。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 105 
// 1 <= nums[i] <= 30 
// 
// Related Topics 位运算 数组 数学 动态规划 状态压缩 
// 👍 41 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*
    思路：什么是状态压缩?


    */
    const static int mod = 1e9 + 7;
    vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}; // 质数

    vector<int> cnts;

    int numberOfGoodSubsets(vector<int>& nums) {
        cnts.resize(35);

        int n = nums.size();
        for(auto i : nums) cnts[i]++; // 计数

        int mask = 1 << 10; // 1024
        vector<long long> f(mask);
        f[0] = 1;
        for(int i = 2; i <= 30; i++){
            if(!cnts[i]) continue;

            // ************* 试除逻辑 ************** //
            // 对 i 进行试除
            int cur = 0, x = i;
            bool ok = true;
            for(int j = 0; j < 10; j++){
                int t = p[j], c = 0;
                while(x % t == 0){
                    cur |= (1 << j);
                    x /= t, c++;
                }
                // 如果 i 能够被同一质数试除多次，说明 i 不能加到子集，跳过 i
                if(c > 1){
                    ok = false;
                    break;
                }
            }

            if(!ok) continue;
            // ************* 试除逻辑 ************** //


            // ************** 动态规划逻辑 *************** //
            // 枚举前一状态 prev
            for(int prev = mask - 1; prev >= 0; prev--) {
                // 只有当前选择数与前一状态不冲突，则能够进行转移，将方案数进行累加
                if((prev & cur) != 0) continue;
                f[prev | cur] = (f[prev | cur] + f[prev] * cnts[i]) % mod;
            }
            // ************** 动态规划逻辑 *************** //
        }

        int ans = 0;
        // 统计所有非空集的方案数
        for(int i = 1; i < mask; i++) ans = (ans + f[i]) % mod;

        // 对1特殊处理
        for(int i = 0; i < cnts[1]; i++) ans = ans * 2 % mod;

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
