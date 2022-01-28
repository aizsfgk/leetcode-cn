//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。 
//
// 注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。 
//
// 
//
// 示例 1: 
//
// 
//输入: num1 = "2", num2 = "3"
//输出: "6" 
//
// 示例 2: 
//
// 
//输入: num1 = "123", num2 = "456"
//输出: "56088" 
//
// 
//
// 提示： 
//
// 
// 1 <= num1.length, num2.length <= 200 
// num1 和 num2 只能由数字组成。 
// num1 和 num2 都不包含任何前导零，除了数字0本身。 
// 
// Related Topics 数学 字符串 模拟 
// 👍 823 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        // 1. 字符串转数组,颠倒一下
        vector<int> A, B;

        int n = num1.size();
        int m = num2.size();
        for (int i=n-1; i>=0; i--) A.push_back(num1[i] - '0');
        for (int i=m-1; i>=0; i--) B.push_back(num2[i] - '0');

        vector<int> C(n+m, 0);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                C[i+j] += A[i] * B[j];
            }
        }

        // 2. 从个位开始
        int t = 0; // 存储进位
        for (int i=0; i<C.size(); i++) {
            t += C[i];
            C[i] = t % 10;
            t /= 10;
        }

        // 3. 去除前导0
        int k = C.size() - 1;
        while (k >= 0) {
            if (C[k] != 0) {
                break;
            }
            k--;
        }

        // 4. 返回真实结果
        string ans;
        while(k >=0) {
            ans.push_back(C[k]+'0');
            k--;
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
