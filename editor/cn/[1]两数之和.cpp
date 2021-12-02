//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。 
//
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。 
//
// 
//
// 示例: 
//
// 给定 nums = [2, 7, 11, 15], target = 9
//
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回 [0, 1]
// 
// Related Topics 数组 哈希表


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> num_map;
        for (int i=0; i<nums.size(); i++) {
            auto iter = num_map.find(target - nums[i]);
            if (iter != num_map.end() && iter->second != i) {
                if (iter->second > i) {
                    res.push_back(i);
                    res.push_back(iter->second);
                } else {
                    res.push_back(iter->second);
                    res.push_back(i);
                }
            }
            num_map.insert({nums[i], i});
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
