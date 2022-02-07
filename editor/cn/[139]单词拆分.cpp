//给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。 
//
// 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。 
//
// 
//
// 示例 1： 
//
// 
//输入: s = "leetcode", wordDict = ["leet", "code"]
//输出: true
//解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
// 
//
// 示例 2： 
//
// 
//输入: s = "applepenapple", wordDict = ["apple", "pen"]
//输出: true
//解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
//     注意，你可以重复使用字典中的单词。
// 
//
// 示例 3： 
//
// 
//输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//输出: false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 300 
// 1 <= wordDict.length <= 1000 
// 1 <= wordDict[i].length <= 20 
// s 和 wordDict[i] 仅有小写英文字母组成 
// wordDict 中的所有字符串 互不相同 
// 
// Related Topics 字典树 记忆化搜索 哈希表 字符串 动态规划 
// 👍 1363 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    set<string> mySet;
public:
    // 必须每一步都是 true, 最后才是true
    bool backtracking(const string &s, map<int, bool> &memo, int startIdx) {
        // 可以遍历到结尾，则成功true
        if (startIdx >= s.size()) {
            return true;
        }

        // 加入记忆化
        // 这里相当于减枝
        auto it = memo.find(startIdx);
        if (it != memo.end()) {
            return it->second;
        }

        for (int i=startIdx; i<s.size(); i++) {
            string subStr = s.substr(startIdx, i-startIdx+1);
            auto it = mySet.find(subStr);
            if (it != mySet.end() && backtracking(s, memo, i+1)) {
                memo[startIdx] = true;
                return true;
            }
        }

        memo[startIdx] = false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // 1. 构建一个集合
        for (int i=0; i<wordDict.size(); i++) {
            mySet.insert(wordDict[i]);
        }

        // 2. 备忘录
        map<int, bool> memo;

        // 进行回溯
        return backtracking(s, memo, 0);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
