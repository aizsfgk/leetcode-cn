//给你一个数组 nums，我们可以将它按一个非负整数 k 进行轮调，这样可以使数组变为 [nums[k], nums[k + 1], ... nums[num
//s.length - 1], nums[0], nums[1], ..., nums[k-1]] 的形式。此后，任何值小于或等于其索引的项都可以记作一分。 
//
// 
// 例如，数组为 nums = [2,4,1,3,0]，我们按 k = 2 进行轮调后，它将变成 [1,3,0,2,4]。这将记为 3 分，因为 1 > 0 
//[不计分]、3 > 1 [不计分]、0 <= 2 [计 1 分]、2 <= 3 [计 1 分]，4 <= 4 [计 1 分]。 
// 
//
// 在所有可能的轮调中，返回我们所能得到的最高分数对应的轮调下标 k 。如果有多个答案，返回满足条件的最小的下标 k 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [2,3,1,4,0]
//输出：3
//解释：
//下面列出了每个 k 的得分：
//k = 0,  nums = [2,3,1,4,0],    score 2
//k = 1,  nums = [3,1,4,0,2],    score 3
//k = 2,  nums = [1,4,0,2,3],    score 3
//k = 3,  nums = [4,0,2,3,1],    score 4
//k = 4,  nums = [0,2,3,1,4],    score 3
//所以我们应当选择 k = 3，得分最高。 
//
// 示例 2： 
//
// 
//输入：nums = [1,3,0,2,4]
//输出：0
//解释：
//nums 无论怎么变化总是有 3 分。
//所以我们将选择最小的 k，即 0。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 105 
// 0 <= nums[i] < nums.length 
// 
// Related Topics 数组 前缀和 
// 👍 144 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
/*
    思考过程：
    1. 常规思考过程：
        1. 把每种的轮调方式都一一枚举出来，然后依次计算每种情况的得分 O(n^2) 的时间复杂度；[0-(n-1)]种方案；每个方案都需要遍历一遍
        2. 怎么分割 :
            例如：k = 1, (i - 1 + n ) % n -> 0 变成n-1; 1变成0 ==> (i-k+n) % n 是该数字的新index
        3.

           int maxS = 0;
           int bestK = 0;
           for (int k=0; k<n; i++) { // 1-(n-1) 种K的方法; // 相当于从k的角度出发；n^2的时间复杂度会超时
              int score = 0;
              // 计算每个K的分数
              for (int i=0; i<n; i++) {
                if (nums[(i-k+n)%n] <= i) {
                    score++;
                }
              }
              if (score > maxS) {
                maxS = score;
                bestK = k;
              }
           }
           return bestK;

    2. 差分数组解法
        1. 既然从 k 的角度思考，会超时，是否可以从分数的角度思考呢??? 什么情况下+分，什么情况下-分，频繁的对区间+-操作
        考虑等差数组

        基本性质：
        a. nums[i] <= (i-k+n) % n  : 此时得分
        b. 新下标必须处于[0, n-1]; 0 <= (i-k+n)%n <= n-1
        c. k <= (i - nums[i] +n) % n
        d. (i+1)%nk <= (i+n) % n
        e. i => nums[i] : 取得加分的一个区间是：[(i+1)%n, (i-nums[i]+n)%n]

        01234567
        XXXX2XXX

        nums[i] - 1 : 位置开始0
        也就是移动几步 (i - (nums[i] - 1)) ，开始0

        0步
        i-(nums[i]-1) 步
        i+1 步



*/
public:
    int bestRotation(vector<int>& nums) {
        // 差分数组
        int n = nums.size();
        vector<int> move(n, 0); // 记录的是移动每个位置 对计分的变化情况
        // move 是差分数组


        for (int i=0; i<n; i++) {
            // 分析两种情况
            if (nums[i] <= i) {
                // nums[i]一开始在的位置可以得分
                move[0]++; // 不移动nums[i]就产生贡献
                move[(i-nums[i] + 1)%n]--; // 左移 i - nums[i] + 1 则差首次为正，贡献取消；继续左移也不会产生新贡献
                move[(i+1)%n]++; // 直到移动到坐标小于0的位置； 变成移动到最右边； 贡献产生
            } else {
                // 一开始所在位置不可得分；左移是没有用的；只有移动到边界时，才会产生变化
                move[(i+1)%n]++;
                // 继续左移动；则会再次到达 值和下标相同的临界点； 继续左移一位则得分取消
                move[(n - (nums[i] - i)+1)%n]--;
            }
        }

        int score = 0, maxS = 0, best = 0;
        for (int i=0; i<n; i++) {
            score += move[i];
            if (score > maxS) {
                maxS = score;
                best = i;
            }
        }
        return best;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
