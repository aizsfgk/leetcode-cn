//给定一个整数数组 nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。 
//
// 
//
// 示例 1： 
//
// 
//输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
//输出： True
//说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。 
//
// 示例 2: 
//
// 
//输入: nums = [1,2,3,4], k = 3
//输出: false 
//
// 
//
// 提示： 
//
// 
// 1 <= k <= len(nums) <= 16 
// 0 < nums[i] < 10000 
// 每个元素的频率在 [1,4] 范围内 
// 
// Related Topics 位运算 记忆化搜索 数组 动态规划 回溯 状态压缩 
// 👍 502 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    int target;
    vector<bool> visited;


    // 回溯和深度优先遍历是一个东西吗?
    bool backtracking(vector<int>& nums, int idx, int kSum, int k) {
        // 结束条件
        if (k==0) {
            return true;
        }

        for (int i=idx; i<nums.size(); i++) {
            if (visited[i]) { // 同枝去重
                continue;
            }

            int tmp = kSum + nums[i];
            if (tmp > target) continue; // 目标和不符合跳过

            int nextKSum = (tmp == target) ? 0 : tmp;  // 如果找到则继续从0找
            int nextIdx = (tmp == target) ? 0 : i+1;
            int nextK = (tmp == target) ? k-1 : k;

            // 同层去重;
            // 上一个相同元素没有使用，说明不符合条件
            // 那么本轮肯定也不符合啊，所以不选了
            if (i > 0 && nums[i-1] == nums[i] && !visited[i-1]) continue;

            visited[i] = true;
            if (backtracking(nums, nextIdx, nextKSum, nextK)) return true;
            visited[i] = false;

        }
        return false;
    }


    int sum(vector<int>& nums) {
        int ret = 0;
        for (int num : nums) {
            ret += num;
        }
        return ret;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int acc = sum(nums);
        if (acc % k != 0) {
            return false;
        }

        // 全局变量
        target = acc / k;
        visited.resize(nums.size(), false);

        // 排序预处理
        sort(nums.begin(), nums.end());
        // 回溯
        return backtracking(nums, 0, 0, k);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
