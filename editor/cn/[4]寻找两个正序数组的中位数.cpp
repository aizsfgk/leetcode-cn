//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。 
//
// 算法的时间复杂度应该为 O(log (m+n)) 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums1 = [1,3], nums2 = [2]
//输出：2.00000
//解释：合并数组 = [1,2,3] ，中位数 2
// 
//
// 示例 2： 
//
// 
//输入：nums1 = [1,2], nums2 = [3,4]
//输出：2.50000
//解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
// 
//
// 示例 3： 
//
// 
//输入：nums1 = [0,0], nums2 = [0,0]
//输出：0.00000
// 
//
// 示例 4： 
//
// 
//输入：nums1 = [], nums2 = [1]
//输出：1.00000
// 
//
// 示例 5： 
//
// 
//输入：nums1 = [2], nums2 = []
//输出：2.00000
// 
//
// 
//
// 提示： 
//
// 
// nums1.length == m 
// nums2.length == n 
// 0 <= m <= 1000 
// 0 <= n <= 1000 
// 1 <= m + n <= 2000 
// -106 <= nums1[i], nums2[i] <= 106 
// 
// Related Topics 数组 二分查找 分治 
// 👍 4924 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // time complexity: O(m+n)
    // space complexity: O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int sum = m + n;

        int left = 0, right = 0;
        int idx1 = 0, idx2 = 0;

        for (int i=0; i <= sum / 2; i++) { //
            left = right;
            if (idx1 < m && (idx2 >= n || nums1[idx1] < nums2[idx2])) {
                right = nums1[idx1++];
            } else {
                right = nums2[idx2++];
            }
        }

        if (sum % 2 == 0) {
            return (double)((left+right) / 2.0); // 除数必须是 double;
        } else {
            return (double)right;
        }
    }

    // test
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    }
};
//leetcode submit region end(Prohibit modification and deletion)
