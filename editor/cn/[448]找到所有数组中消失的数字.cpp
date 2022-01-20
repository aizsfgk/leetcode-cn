 //给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数
//字，并以数组的形式返回结果。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [4,3,2,7,8,2,3,1]
//输出：[5,6]
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,1]
//输出：[2]
// 
//
// 
//
// 提示： 
//
// 
// n == nums.length 
// 1 <= n <= 105 
// 1 <= nums[i] <= n 
// 
//
// 进阶：你能在不使用额外空间且时间复杂度为 O(n) 的情况下解决这个问题吗? 你可以假定返回的数组不算在额外空间内。 
// Related Topics 数组 哈希表 
// 👍 880 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
//        int n = nums.size();
//
//        vector<int> used(n+1, 0);
//
//        for (int i=0; i<n; i++) {
//            used[nums[i]] = 1;
//        }
//
//        vector<int> ans;
//        for (int i=1; i<=n; i++) {
//            if (used[i] == 0) {
//                ans.push_back(i);
//            }
//        }
//
//        return ans;

          int n = nums.size();
          if (n == 0)
            return nums;

          // 找到每个索引，然后+n
          for (int i=0; i<n; i++) {
                int idx = (nums[i] - 1) % n;
                nums[idx] += n;
          }

          vector<int> ans;
          for (int i=0; i<n; i++) {
            if (nums[i] <= n) {
                ans.push_back(i+1);
            }
          }
          return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
