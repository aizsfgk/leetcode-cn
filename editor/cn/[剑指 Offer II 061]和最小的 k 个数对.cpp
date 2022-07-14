//给定两个以升序排列的整数数组 nums1 和 nums2 , 以及一个整数 k 。 
//
// 定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。 
//
// 请找到和最小的 k 个数对 (u1,v1), (u2,v2) ... (uk,vk) 。 
//
// 
//
// 示例 1: 
//
// 
//输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
//输出: [1,2],[1,4],[1,6]
//解释: 返回序列中的前 3 对数：
//    [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
// 
//
// 示例 2: 
//
// 
//输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
//输出: [1,1],[1,1]
//解释: 返回序列中的前 2 对数：
//     [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
// 
//
// 示例 3: 
//
// 
//输入: nums1 = [1,2], nums2 = [3], k = 3 
//输出: [1,3],[2,3]
//解释: 也可能序列中所有的数对都被返回:[1,3],[2,3]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= nums1.length, nums2.length <= 10⁴ 
// -10⁹ <= nums1[i], nums2[i] <= 10⁹ 
// nums1, nums2 均为升序排列 
// 1 <= k <= 1000 
// 
//
// 
//
// 注意：本题与主站 373 题相同：https://leetcode-cn.com/problems/find-k-pairs-with-smallest-
//sums/ 
// Related Topics 数组 堆（优先队列） 👍 38 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*
        优先级队列

    */
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&nums1, &nums2](const pair<int,int> &a, const pair<int,int> &b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> priQue{cmp};

        int m = nums1.size();
        int n = nums2.size();


        // 肯定是满足条件，所以不需要 > k的m里边的元素了
        for (int i=0; i<min(m, k); i++) {
            priQue.push({i, 0});
        }

        vector<vector<int>> ans;
        // k --
        // 并且 优先级队列不为空
        while (k-- && !priQue.empty()) {
            auto [x, y] = priQue.top(); priQue.pop();

            ans.push_back({nums1[x], nums2[y]});
            if (y+1 < n) {
                priQue.push({x, y+1});
            }
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
