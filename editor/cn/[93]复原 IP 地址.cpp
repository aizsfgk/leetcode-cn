//有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。 
//
// 
// 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 
//和 "192.168@1.1" 是 无效 IP 地址。 
// 
//
// 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你不能重新排序
//或删除 s 中的任何数字。你可以按 任何 顺序返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "25525511135"
//输出：["255.255.11.135","255.255.111.35"]
// 
//
// 示例 2： 
//
// 
//输入：s = "0000"
//输出：["0.0.0.0"]
// 
//
// 示例 3： 
//
// 
//输入：s = "1111"
//输出：["1.1.1.1"]
// 
//
// 示例 4： 
//
// 
//输入：s = "010010"
//输出：["0.10.0.10","0.100.1.0"]
// 
//
// 示例 5： 
//
// 
//输入：s = "101023"
//输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
// 
//
// 
//
// 提示： 
//
//
// 0 <= s.length <= 20 
// s 仅由数字组成 
// 
// Related Topics 字符串 回溯 
// 👍 771 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<string> ans;
    vector<string> path;

public:
    string joinIP(vector<string> &ipArr) {
        string ret;
        for (int i=0; i<ipArr.size(); i++) {
            if (i == 0) {
                ret += ipArr[i];
            } else {
                ret += "." + ipArr[i];
            }
        }
        return ret;
    }

    bool isValidIP(const string &s) {
        if (s.size() == 0 || s.size() > 3) {
            return false;
        }

        if (s.size() > 1 && s[0] == '0') {
            return false;
        }

        int idx = 0;
        int ret = 0;
        while (idx < s.size()) {
            char a = s[idx];
            ret = ret * 10 + (a - '0');
            idx++;
        }

        // cout << "ipNum: " << ret << endl;

        if (ret >=0 && ret <= 255) {
            return true;
        }
        return false;
    }

    void backtracking(const string &s, int startIdx) {

        // 符合条件的字串,放入ans
        if (startIdx >= s.size() && path.size() == 4) {
            // cout << "path.size:" << path.size() << endl;

            ans.push_back(joinIP(path));
            return;
        }

        for (int i=startIdx; i<s.size(); i++) {
            // 找到所有的子串
            string str = s.substr(startIdx, i-startIdx+1);
            bool tmp = isValidIP(str);

            // cout << "str: " << str <<"; tmp: " << tmp << endl;

            if (tmp) {
                path.push_back(str);
            } else {
                continue;
            }

            backtracking(s, i+1);
            path.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.size() == 0)
            return ans;

        backtracking(s, 0);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
