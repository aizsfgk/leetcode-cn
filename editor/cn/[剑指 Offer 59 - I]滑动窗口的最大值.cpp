//给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。 
//
// 示例: 
//
// 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
//输出: [3,3,5,5,6,7] 
//解释: 
//
//  滑动窗口的位置                最大值
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7 
//
// 
//
// 提示： 
//
// 你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。 
//
// 注意：本题与主站 239 题相同：https://leetcode-cn.com/problems/sliding-window-maximum/ 
// Related Topics 队列 滑动窗口 单调队列 堆（优先队列） 
// 👍 370 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    // class 必须  ; 号
    class MonotoneQueue {
    private:
        deque<int> data;
    public:
        void push(int n) {
            while(!data.empty() && data.back() < n) {
                data.pop_back();
            }

            data.push_back(n);
        }

        int max() {
            return data.front();
        }

        void pop(int n) {
            // 使用的是if
            if (!data.empty() && data.front() == n) {
                data.pop_front();
            }
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        MonotoneQueue window;

        for (int i=0; i<nums.size(); i++) {
            if (i < k-1) {
                window.push(nums[i]);
            } else {
                window.push(nums[i]);
                ans.push_back(window.max());
                window.pop(nums[i-k+1]);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
