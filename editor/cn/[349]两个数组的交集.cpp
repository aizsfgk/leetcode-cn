//给定两个数组，编写一个函数来计算它们的交集。 
//
// 
//
// 示例 1： 
//
// 输入：nums1 = [1,2,2,1], nums2 = [2,2]
//输出：[2]
// 
//
// 示例 2： 
//
// 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//输出：[9,4] 
//
// 
//
// 说明： 
//
// 
// 输出结果中的每个元素一定是唯一的。 
// 我们可以不考虑输出结果的顺序。 
// 
// Related Topics 数组 哈希表 双指针 二分查找 排序 
// 👍 476 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        unordered_map<int, int> myMap;
        for (int i=0; i<nums1.size(); i++) {
            if (myMap[nums1[i]] == 0) {
                myMap[nums1[i]] = 1;
            }
        }

        for (int i=0; i<nums2.size(); i++) {
            auto it = myMap.find(nums2[i]);
            if (it != myMap.end() && it->second == 1) {
                myMap[nums2[i]]++;
                ans.push_back(nums2[i]);
            }
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
