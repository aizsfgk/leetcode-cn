//现有一种使用英语字母的外星文语言，这门语言的字母顺序与英语顺序不同。 
//
// 给定一个字符串列表 words ，作为这门语言的词典，words 中的字符串已经 按这门新语言的字母顺序进行了排序 。 
//
// 请你根据该词典还原出此语言中已知的字母顺序，并 按字母递增顺序 排列。若不存在合法字母顺序，返回 "" 。若存在多种可能的合法字母顺序，返回其中 任意一种
// 顺序即可。 
//
// 字符串 s 字典顺序小于 字符串 t 有两种情况： 
//
// 
// 在第一个不同字母处，如果 s 中的字母在这门外星语言的字母顺序中位于 t 中字母之前，那么 s 的字典顺序小于 t 。 
// 如果前面 min(s.length, t.length) 字母都相同，那么 s.length < t.length 时，s 的字典顺序也小于 t 。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：words = ["wrt","wrf","er","ett","rftt"]
//输出："wertf"
// 
//
// 示例 2： 
//
// 
//输入：words = ["z","x"]
//输出："zx"
// 
//
// 示例 3： 
//
// 
//输入：words = ["z","x","z"]
//输出：""
//解释：不存在合法字母顺序，因此返回 "" 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= words.length <= 100 
// 1 <= words[i].length <= 100 
// words[i] 仅由小写英文字母组成 
// 
//
// 
//
// 注意：本题与主站 269 题相同： https://leetcode-cn.com/problems/alien-dictionary/ 
// Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 数组 字符串 👍 120 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    unordered_map<char, vector<char>> edges;
    unordered_map<char, int> indegrees;
    bool valid = true;

    string alienOrder(vector<string>& words) {
        int length = words.size();
        for (auto word : words) {
            int wordLength = word.size();
            for (int j = 0; j < wordLength; j++) {
                char c = word[j];
                if (!edges.count(c)) {
                    edges[c] = vector<char>();
                }
            }
        }
        for (int i = 1; i < length && valid; i++) {
            addEdge(words[i - 1], words[i]);
        }
        if (!valid) {
            return "";
        }
        queue<char> qu;
        for (auto [u, _] : edges) {
            if (!indegrees.count(u)) {
                qu.emplace(u);
            }
        }
        string order;
        while (!qu.empty()) {
            char u = qu.front();
            qu.pop();
            order.push_back(u);
            for (char v : edges[u]) {
                indegrees[v]--;
                if (indegrees[v] == 0) {
                    qu.emplace(v);
                }
            }
        }
        return order.size() == edges.size() ? order : "";
    }

    void addEdge(string before, string after) {
        int length1 = before.size(), length2 = after.size();
        int length = min(length1, length2);
        int index = 0;
        while (index < length) {
            char c1 = before[index], c2 = after[index];
            if (c1 != c2) {
                edges[c1].emplace_back(c2);
                indegrees[c2] += 1;
                break;
            }
            index++;
        }
        if (index == length && length1 > length2) {
            valid = false;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
