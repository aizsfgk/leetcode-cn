//括号。设计一种算法，打印n对括号的所有合法的（例如，开闭一一对应）组合。 
//
// 说明：解集不能包含重复的子集。 
//
// 例如，给出 n = 3，生成结果为： 
//
// 
//[
//  "((()))",
//  "(()())",
//  "(())()",
//  "()(())",
//  "()()()"
//]
// 
// Related Topics 字符串 动态规划 回溯 👍 113 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<string> ans;
    string path;

    void backtrack(string box, int n, int left, int right) {
        if (left > n || right > n || left < right)
            return;

        if (path.size() == 2 *n) {
            ans.push_back(path);
            return;
        }

        for (int i=0; i<box.size(); i++) {
            path.push_back(box[i]);

            if (box[i] == '(') {
                backtrack(box, n, left+1, right);
            } else {
                backtrack(box, n, left, right+1);
            }
            path.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {};
        if (n == 1) return {"()"};

        backtrack("()", n, 0, 0);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
