//nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。 
//
// 给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。 
//
// 对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，并且在 nums2 确定 num
//s2[j] 的 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。 
//
// 返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums1 = [4,1,2], nums2 = [1,3,4,2].
//输出：[-1,3,-1]
//解释：nums1 中每个值的下一个更大元素如下所述：
//- 4 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
//- 1 ，用加粗斜体标识，nums2 = [1,3,4,2]。下一个更大元素是 3 。
//- 2 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。 
//
// 示例 2： 
//
// 
//输入：nums1 = [2,4], nums2 = [1,2,3,4].
//输出：[3,-1]
//解释：nums1 中每个值的下一个更大元素如下所述：
//- 2 ，用加粗斜体标识，nums2 = [1,2,3,4]。下一个更大元素是 3 。
//- 4 ，用加粗斜体标识，nums2 = [1,2,3,4]。不存在下一个更大元素，所以答案是 -1 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums1.length <= nums2.length <= 1000 
// 0 <= nums1[i], nums2[i] <= 104 
// nums1和nums2中所有整数 互不相同 
// nums1 中的所有整数同样出现在 nums2 中 
// 
//
// 
//
// 进阶：你可以设计一个时间复杂度为 O(nums1.length + nums2.length) 的解决方案吗？ 
// Related Topics 栈 数组 哈希表 单调栈 
// 👍 635 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    /*
        // 最普通的hash解法
        unordered_map<int,int> myMap;
        for (int i=0; i<nums2.size(); i++) {
           myMap[nums2[i]] = i;
        }

        int n = nums1.size();
        vector<int> ans;
        for (int i=0; i<n; i++) {
            auto it = myMap.find(nums1[i]);
            if (it != myMap.end()) {
                int idx = it->second;
                int ele = -1;
                while ( ++idx < nums2.size()) {
                    if (nums2[idx] > it->first) {
                        ele = nums2[idx];
                        break;
                    }
                }
                ans.push_back(ele);
            }
        }

        // 单调栈如何解决 ???

        return ans;

    */

    /*


        //输入：nums1 = [4,1,2], nums2 = [1,3,4,2].
        //输出：[-1,3,-1]

    */

        int n = nums1.size();
        int m = nums2.size();

        stack<int> monoStk;
        unordered_map<int,int> arrMap;

        // 后续遍历
        // 递减单调栈
        for (int i=m-1; i>=0; i--) {
            int x = nums2[i];
            while (!monoStk.empty() && x >= monoStk.top()) {
                monoStk.pop();
            }

            arrMap[x] = !monoStk.empty() ? monoStk.top() : -1;

            monoStk.push(x);
        }

        vector<int> ans;
        for (int i=0; i<n; i++) {
            ans.push_back(arrMap[nums1[i]]);
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
