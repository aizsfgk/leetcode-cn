//我们有一些二维坐标，如 "(1, 3)" 或 "(2, 0.5)"，然后我们移除所有逗号，小数点和空格，得到一个字符串S。返回所有可能的原始字符串到一个列表
//中。 
//
// 原始的坐标表示法不会存在多余的零，所以不会出现类似于"00", "0.0", "0.00", "1.0", "001", "00.01"或一些其他更小的数
//来表示坐标。此外，一个小数点前至少存在一个数，所以也不会出现“.1”形式的数字。 
//
// 最后返回的列表可以是任意顺序的。而且注意返回的两个数字中间（逗号之后）都有一个空格。 
//
// 
//
// 
//示例 1:
//输入: "(123)"
//输出: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]
// 
//
// 
//示例 2:
//输入: "(00011)"
//输出:  ["(0.001, 1)", "(0, 0.011)"]
//解释: 
//0.0, 00, 0001 或 00.01 是不被允许的。
// 
//
// 
//示例 3:
//输入: "(0123)"
//输出: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 
//3)"]
// 
//
// 
//示例 4:
//输入: "(100)"
//输出: [(10, 0)]
//解释: 
//1.0 是不被允许的。
// 
//
// 
//
// 提示: 
//
// 
// 4 <= S.length <= 12. 
// S[0] = "(", S[S.length - 1] = ")", 且字符串 S 中的其他元素都是数字。 
// 
//
// 
// Related Topics 字符串 回溯 👍 43 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<string> ans;
    vector<string> num;
    vector<string> num1;
    vector<string> num2;

    unordered_set<string> memo;

    void backtracking(const string &s, string curStr, int idx) {

        // 添加了小数点
        if (curStr.find('.') != string::npos && curStr.size() == s.size() + 1) {
            if (curStr.back() == '0') return; // 1. 最后一位是0；不合法

//            string sub = curStr.substr(0, curStr.find('.'));
//            if (sub.size() > 1 && sub[0] == '0') return; // 2. .号前有2位 且 前导0不合法

            num.push_back(curStr);
            return;
        // 没有添加小数点
        } else if (curStr.find('.') == string::npos && curStr.size() == s.size()) {
            if (curStr.size() > 1 && curStr[0] == '0') return; // 3. 大于2位，且前导0

            num.push_back(curStr);
            return;
        }

        for (int i=idx; i<s.size(); i++) {
            curStr.push_back(s[i]);

            if (curStr.size() > 1 && curStr[0] == '0' && curStr[1] == '0') continue; // 2 个0


            if (curStr.find('.') == string::npos && i != s.size()-1) {

                if (curStr.size() > 1 && curStr[0] == '0') continue; // .号前有2位 且 前导0不合法

                curStr.push_back('.');
            }

            backtracking(s, curStr, i+1);
            curStr.pop_back();
        }
    }

    void combine(const vector<string> &num1, const vector<string> &num2) {
        for (auto l1 : num1) {
            for (auto l2 : num2) {
                string path = "(" + l1 + ", " + l2 + ")";
                if (memo.find(path) != memo.end()) {
                    continue;
                }

                memo.insert(path);
                ans.push_back(path);
            }
        }
    }

public:
    vector<string> ambiguousCoordinates(string s) {
        if (s.empty()) return ans;

        for (int i=1; i<=s.size()-2; i++) {

            string preSegment = s.substr(1, i); // 前半部分数字
            string nextSegment = s.substr(i+1, s.size() - 2 - i); //后半部分数字
            if (preSegment.empty() || nextSegment.empty())
                continue;

            backtracking(preSegment, "", 0);
            num1.assign(num.begin(), num.end());
            num.clear();

            backtracking(nextSegment,"", 0);
            num2.assign(num.begin(), num.end());
            num.clear();

            combine(num1, num2);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
