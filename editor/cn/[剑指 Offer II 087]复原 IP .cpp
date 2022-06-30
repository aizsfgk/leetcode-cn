//给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。你可以按任何顺序返回答案。 
//
// 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。 
//
// 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 
//和 "192.168@1.1" 是 无效 IP 地址。 
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
//输入：s = "10203040"
//输出：["10.20.30.40","102.0.30.40","10.203.0.40"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 3000 
// s 仅由数字组成 
// 
//
// 
//
// 注意：本题与主站 93 题相同：https://leetcode-cn.com/problems/restore-ip-addresses/ 
// Related Topics 字符串 回溯 👍 31 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<string> ans;
    vector<string> path;

    string path2IP(const vector<string> &path) {
        string ip;
        for (string p : path) {
            ip += p + ".";
        }
        ip.pop_back();
        return ip;
    }

    bool isValid(const string &s) {
        //
        if (s.size() == 0 || s.size() > 3) return false;

        // 0.0.0.0 这种情况判断
        if (s.size() > 1 && s[0] == '0') return false;

        int idx = 0;
        int ret = 0;

        while (idx < s.size()) {
            ret = ret * 10 + (s[idx] - '0');
            idx++;
        }

        if (ret >= 0 && ret <= 255) {
            return true;
        }
        return false;
    }

    void backtracking(const string &s, int idx) {
        if (path.size() > 4 || idx > s.size()) return;

        if (path.size() == 4 && idx >= s.size()) {
            ans.push_back(path2IP(path));
            return;
        }

        for (int i=idx; i<s.size(); i++) {
            string substr = s.substr(idx, i-idx+1);
            if (isValid(substr)) {
                path.push_back(substr);
            } else {
                continue;
            }

            backtracking(s, i+1);
            path.pop_back();
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        //
        // 字符串切割问题
        //
        if (s.empty()) return ans;

        backtracking(s, 0);

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
