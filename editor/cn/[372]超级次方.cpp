//你的任务是计算 ab 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。 
//
// 
//
// 示例 1： 
//
// 
//输入：a = 2, b = [3]
//输出：8
// 
//
// 示例 2： 
//
// 
//输入：a = 2, b = [1,0]
//输出：1024
// 
//
// 示例 3： 
//
// 
//输入：a = 1, b = [4,3,3,8,5,2]
//输出：1
// 
//
// 示例 4： 
//
// 
//输入：a = 2147483647, b = [2,0,0]
//输出：1198
// 
//
// 
//
// 提示： 
//
// 
// 1 <= a <= 231 - 1 
// 1 <= b.length <= 2000 
// 0 <= b[i] <= 9 
// b 不含前导 0 
// 
// Related Topics 数学 分治 
// 👍 260 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    int base = 1337;
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) {
            return 1;
        }

        int lastBit = b.back(); b.pop_back();

        int part1 = myPow(a, lastBit);
        int part2 = myPow(superPow(a, b), 10);

        return (part1 * part2) % base;
    }

    int myPow(int a, int b) {
        if (b == 0)
            return 1;

        a %= base;
        if (b % 2 == 0)
            return myPow( (a % base)*(a % base) % base, b/2);
        else
            return ((a % base) * myPow(a, b-1)) % base;

        // (a*b) % k ==> [(a % k ) * (b % k)] % k
    }
};
//leetcode submit region end(Prohibit modification and deletion)
