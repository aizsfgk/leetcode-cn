//给你一个正整数数组 nums，请你帮忙从该数组中找出能满足下面要求的 最长 前缀，并返回该前缀的长度： 
//
// 
// 从前缀中 恰好删除一个 元素后，剩下每个数字的出现次数都相同。 
// 
//
// 如果删除这个元素后没有剩余元素存在，仍可认为每个数字都具有相同的出现次数（也就是 0 次）。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [2,2,1,1,5,3,3,5]
//输出：7
//解释：对于长度为 7 的子数组 [2,2,1,1,5,3,3]，如果我们从中删去 nums[4] = 5，就可以得到 [2,2,1,1,3,3]，里面每个数
//字都出现了两次。
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,1,1,2,2,2,3,3,3,4,4,4,5]
//输出：13
// 
//
// 
//
// 提示： 
//
// 
// 2 <= nums.length <= 10⁵ 
// 1 <= nums[i] <= 10⁵ 
// 
//
// Related Topics 数组 哈希表 👍 91 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, set<int>> freqSet; // 维护每个词频的元素
        unordered_map<int, int> freq; // 每个元素的词频
        set<int> st; // 词频的种类

        int ans = 1;
        for (int i=0; i<nums.size(); i++) {
            if (freq.count(nums[i]) == 0) {
                freq[nums[i]] = 1;
                freqSet[1].insert(nums[i]);
                st.insert(1);
            } else {
                int pre = freq[nums[i]];
                freqSet[freq[nums[i]]++].erase(nums[i]); // 删除之前的词频，集合中的元素; 然后++
                if (freqSet[pre].empty()) {
                    st.erase(pre); // 删除词频种类
                }

                freqSet[freq[nums[i]]].insert(nums[i]); // 新的词频，新加入词频集合
                st.insert(freq[nums[i]]);
            }


            if (st.size() == 1) { // 只有1种词频种类
                int value = *st.begin();
                if (value == 1) ans = i+1;
                else if (freqSet[value].size() == 1) ans = i+1;
            } else if (st.size() == 2) {
                int right = *st.rbegin();
                int left = *st.begin();
                if (right - left == 1) {
                    if (freqSet[right].size() == 1) {
                        ans = i+1; continue;
                    }
                }
                if (left == 1 && freqSet[1].size() == 1) ans = i+1;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
