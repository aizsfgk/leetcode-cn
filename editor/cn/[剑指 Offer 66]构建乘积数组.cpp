//给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 即 B[
//i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。 
//
// 
//
// 示例: 
//
// 
//输入: [1,2,3,4,5]
//输出: [120,60,40,30,24] 
//
// 
//
// 提示： 
//
// 
// 所有元素乘积之和不会溢出 32 位整数 
// a.length <= 100000 
// 
// Related Topics 数组 前缀和 
// 👍 237 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        if (n == 0) return {};

        vector<int> ans(n, 1);

        // 1. 求 i之前的元素 乘积
        int p = 1;
        for (int i=0; i<n; i++) {
            ans[i] *= p;
            p *= a[i];
        }

        // 2. 求 i之后元素的乘积
        p = 1;
        for (int i=n-1; i>=0; i--) {
            ans[i] *= p;
            p *= a[i];
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
