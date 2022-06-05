//输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。 
//
// 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。 
//
// 
//
// 示例 1： 
//
// 输入：target = 9
//输出：[[2,3,4],[4,5]]
// 
//
// 示例 2： 
//
// 输入：target = 15
//输出：[[1,2,3,4,5],[4,5,6],[7,8]]
// 
//
// 
//
// 限制： 
//
// 
// 1 <= target <= 10^5 
// 
//
// 
// Related Topics 数学 双指针 枚举 
// 👍 445 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        if (target < 3) return ans;

        int left = 1;
        int right = 2;
        vector<int> ele;

        // 滑动窗口
        int sum = 0;
        while (right <= target) {
            sum = (left+right) * (right-left+1)/2;
            if (sum == target) {
                ele.clear();
                for (int i=left; i<=right; i++) {
                    ele.push_back(i);
                }
                if (ele.size() >= 2) {
                    ans.push_back(ele);
                }
                right ++;
            } else if (sum < target) {
                right++;
            } else {
                left++;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
