//给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。 
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
// 1 <= nums.length <= 105 
// k 的取值范围是 [1, 数组中不相同的元素的个数] 
// 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的 
// 
//
// 
//
// 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。 
// Related Topics 数组 哈希表 分治 桶排序 计数 快速选择 排序 堆（优先队列） 
// 👍 1007 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    /*
        思路： hashTable + priority_queue
    */
    map<int, int> myMap;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for (int i=0; i<nums.size(); i++) {
            myMap[nums[i]]++;
        }

        auto my_cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second < b.second; // 大根堆
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(my_cmp)> pQue {my_cmp};

        for (auto it=myMap.begin(); it != myMap.end(); it++) {
            pQue.push({it->first, it->second});
        }

        vector<int> ans;
        while (k > 0) {
            auto ele = pQue.top(); pQue.pop();
            ans.push_back(ele.first);
            k--;
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
