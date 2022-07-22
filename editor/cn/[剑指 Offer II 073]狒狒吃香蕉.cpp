//狒狒喜欢吃香蕉。这里有 n 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 h 小时后回来。 
//
// 狒狒可以决定她吃香蕉的速度 k （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 k 根。如果这堆香蕉少于 k 根，她将吃掉这堆的所有香蕉，然后
//这一小时内不会再吃更多的香蕉，下一个小时才会开始吃另一堆的香蕉。 
//
// 狒狒喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。 
//
// 返回她可以在 h 小时内吃掉所有香蕉的最小速度 k（k 为整数）。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 
//输入：piles = [3,6,7,11], h = 8
//输出：4
// 
//
// 示例 2： 
//
// 
//输入：piles = [30,11,23,4,20], h = 5
//输出：30
// 
//
// 示例 3： 
//
// 
//输入：piles = [30,11,23,4,20], h = 6
//输出：23
// 
//
// 
//
// 提示： 
//
// 
// 1 <= piles.length <= 10⁴ 
// piles.length <= h <= 10⁹ 
// 1 <= piles[i] <= 10⁹ 
// 
//
// 
//
// 注意：本题与主站 875 题相同： https://leetcode-cn.com/problems/koko-eating-bananas/ 
// Related Topics 数组 二分查找 👍 32 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
<<<<<<< HEAD
/*
每次比较 当前速度k消耗的总小时数 和 h 的大小关系。

时间复杂度nlogC，空间复杂度1（n为piles大小，C为piles里的最大元素值）
*/
private:
    int getHour(vector<int> &piles, int k) {
        int hour = 0;
        int n = piles.size();
        for (int &pile : piles) {
            // 每一堆消耗的小时数
            hour += (pile+k-1)/k;
        }
        return hour;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (getHour(piles, mid) <= h) r = mid-1; // r 右侧满足小时数小于等于h
            else l = mid+1;
        }
        return r+1;
=======
public:
    int minEatingSpeed(vector<int>& piles, int h) {

>>>>>>> 0cc0f34f5081b86e23effd53b578d35cab26243b
    }
};
//leetcode submit region end(Prohibit modification and deletion)
