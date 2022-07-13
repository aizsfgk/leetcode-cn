//给定一个整数数组 nums 和一个整数 k ，请返回其中出现频率前 k 高的元素。可以按 任意顺序 返回答案。 
//
// 
//
// 示例 1: 
//
// 
//输入: nums = [1,1,1,2,2,3], k = 2
//输出: [1,2]
// 
//
// 示例 2: 
//
// 
//输入: nums = [1], k = 1
//输出: [1] 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁵ 
// k 的取值范围是 [1, 数组中不相同的元素的个数] 
// 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的 
// 
//
// 
//
// 进阶：所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。 
//
// 
//
// 注意：本题与主站 347 题相同：https://leetcode-cn.com/problems/top-k-frequent-elements/ 
// Related Topics 数组 哈希表 分治 桶排序 计数 快速选择 排序 堆（优先队列） 👍 32 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    unordered_map<int, pair<int,int>> memo;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        for (auto num : nums) {
            if (memo.count(num) > 0) {
                memo[num].second++;
            } else {
                memo[num] = {num ,1};
            }
        }

        auto cmp = [](const pair<int,int> &a, const pair<int,int> &b) {
            return a.second > b.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> que {cmp};


        for (auto ele : memo) {
            que.push(ele.second);
        }

        while (que.size() > k) {
            que.pop();
        }

        while (!que.empty()) {
            ans.push_back(que.top().first); que.pop();
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
