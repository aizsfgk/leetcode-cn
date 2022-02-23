//给定一个字符串 s 和一些 长度相同 的单词 words 。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。 
//
// 注意子串要与 words 中的单词完全匹配，中间不能有其他字符 ，但不需要考虑 words 中单词串联的顺序。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "barfoothefoobarman", words = ["foo","bar"]
//输出：[0,9]
//解释：
//从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
//输出的顺序不重要, [9,0] 也是有效答案。
// 
//
// 示例 2： 
//
// 
//输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
//输出：[6,9,12]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 104 
// s 由小写英文字母组成 
// 1 <= words.length <= 5000 
// 1 <= words[i].length <= 30 
// words[i] 由小写英文字母组成 
// 
// Related Topics 哈希表 字符串 滑动窗口 
// 👍 597 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // 暴力解法
        vector<int> ans;

        int n = s.size(), m = words.size(), len = words[0].size();

        unordered_map<string, int> search;
        for (int i=0; i<m; i++) {
            search[words[i]]++;
        }

        for (int i=0, j=0; i<n - m*len + 1; i++) {
            unordered_map<string, int> sub;
            for (j=0; j<m; j++) {
                auto word = s.substr(i+ j*len, len);

                if (!search.count(word)) break;
                if (++sub[word] > search[word]) break;
            }

            if (j == m) {
                ans.push_back(i);
            }

        }

        return ans;

        // TODO 滑动窗口
    }
};
//leetcode submit region end(Prohibit modification and deletion)
