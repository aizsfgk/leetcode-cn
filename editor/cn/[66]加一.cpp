//给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。 
//
// 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。 
//
// 你可以假设除了整数 0 之外，这个整数不会以零开头。 
//
// 
//
// 示例 1： 
//
// 
//输入：digits = [1,2,3]
//输出：[1,2,4]
//解释：输入数组表示数字 123。
// 
//
// 示例 2： 
//
// 
//输入：digits = [4,3,2,1]
//输出：[4,3,2,2]
//解释：输入数组表示数字 4321。
// 
//
// 示例 3： 
//
// 
//输入：digits = [0]
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= digits.length <= 100 
// 0 <= digits[i] <= 9 
// 
// Related Topics 数组 数学 
// 👍 887 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // 简单题
        // ch - '0' ==> 获取数字
        // 一个/
        // 一个%
        vector<int> ans;
        int n = digits.size();
        if (n == 0) {
            return ans;
        }

        int tmp = 1;
        int num = 0;
        for (int i=n-1; i>=0; i--) {
            if (tmp) {
                num = (digits[i] + 1 ) % 10;
                ans.insert(ans.begin(), num);
                tmp = (digits[i] + 1 ) / 10;
            } else {
                ans.insert(ans.begin(), digits[i]);
            }
        }

        if (tmp) {
           ans.insert(ans.begin(), 1);
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
