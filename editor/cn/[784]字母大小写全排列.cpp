//给定一个字符串 s ，通过将字符串 s 中的每个字母转变大小写，我们可以获得一个新的字符串。 
//
// 返回 所有可能得到的字符串集合 。以 任意顺序 返回输出。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "a1b2"
//输出：["a1b2", "a1B2", "A1b2", "A1B2"]
// 
//
// 示例 2: 
//
// 
//输入: s = "3z4"
//输出: ["3z4","3Z4"]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= s.length <= 12 
// s 由小写英文字母、大写英文字母和数字组成 
// 
// Related Topics 位运算 字符串 回溯 👍 391 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<string> ans;
    string path;

    map<char, string> table;

    map<char, string> makeTable() {
        map<char, string> ans;
        for (int i=0; i<=9; i++) {
            ans[i+'0'] = to_string(i);
        }

        for (int i='a'; i<= 'z'; i++) {
            ans[i] = "";
            ans[i].push_back(i);
            ans[i].push_back(i-32);
        }

        for (int i='A'; i<= 'Z'; i++) {
            ans[i] = "";
            ans[i].push_back(i);
            ans[i].push_back(i+32);
        }
        return ans;
    }

    void printMap() {
        for (auto it = table.begin(); it != table.end(); it++) {
            cout << it->first << ": " << it->second << ";" << endl;
        }
    }

    void backtracking(const string &s, int idx) {
        if (path.size() == s.size()) {
            ans.push_back(path);
            return;
        }

        string ele = table[s[idx]];

        for (int i=0; i<ele.size(); i++) {
            path.push_back(ele[i]);
            backtracking(s, idx+1);
            path.pop_back();
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        // 构建map
        table = makeTable();
//        printMap();

        backtracking(s, 0);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
