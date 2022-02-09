//给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 输入："ab-cd"
//输出："dc-ba"
// 
//
// 示例 2： 
//
// 输入："a-bC-dEf-ghIj"
//输出："j-Ih-gfE-dCba"
// 
//
// 示例 3： 
//
// 输入："Test1ng-Leet=code-Q!"
//输出："Qedo1ct-eeLg=ntse-T!"
// 
//
// 
//
// 提示： 
//
// 
// S.length <= 100 
// 33 <= S[i].ASCIIcode <= 122 
// S 中不包含 \ or " 
// 
// Related Topics 双指针 字符串 
// 👍 100 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        if (n<=1) {
            return s;
        }
        // if((ch=97) && (ch<=122))
        int left = 0;
        int right = n - 1;
        while (left < right) {
            while (!isChar(s[left]) && left < right) left ++;
            while (!isChar(s[right]) && left < right) right--;

            if (left < right) {
                swap(s[left], s[right]);
            } else {
                break;
            }


            left++;
            right--;
        }

        return s;
    }

    bool isChar(char a) {
        return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z');
    }
};
//leetcode submit region end(Prohibit modification and deletion)
