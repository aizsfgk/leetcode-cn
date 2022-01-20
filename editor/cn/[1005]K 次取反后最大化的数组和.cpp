//给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组： 
//
// 
// 选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。 
// 
//
// 重复这个过程恰好 k 次。可以多次选择同一个下标 i 。 
//
// 以这种方式修改数组后，返回数组 可能的最大和 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [4,2,3], k = 1
//输出：5
//解释：选择下标 1 ，nums 变为 [4,-2,3] 。
// 
//
// 示例 2： 
//
// 
//输入：nums = [3,-1,0,2], k = 3
//输出：6
//解释：选择下标 (1, 2, 2) ，nums 变为 [3,1,0,2] 。
// 
//
// 示例 3： 
//
// 
//输入：nums = [2,-3,-1,5,-4], k = 2
//输出：13
//解释：选择下标 (1, 4) ，nums 变为 [2,3,-1,5,4] 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 104 
// -100 <= nums[i] <= 100 
// 1 <= k <= 104 
// 
// Related Topics 贪心 数组 排序 
// 👍 206 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static bool cmp(int a, int b) {
        return abs(a) > abs(b); // > 从大到小; < 从小到大
    }
    //  k 次取反最大数组和
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // 第一步进行排序， 排序规则是，绝对值大的值在左边，绝对值小的值在右边；这样可以充分利用 绝对值属性
        sort(nums.begin(), nums.end(), cmp);

        // 开始从大绝对值 到 小绝对值处理
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] < 0 && k>0) {
                nums[i] *= -1;
                k--;
            }
        }

        // 第三步， 看看 k是否还是 剩下 奇数个
        if (k % 2 == 1)
            nums[nums.size() - 1] *= -1;

        // 第四步：求总和
        return accumulate(nums.begin(), nums.end(), 0);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
