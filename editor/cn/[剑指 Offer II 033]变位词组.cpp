//给定一个字符串数组 strs ，将 变位词 组合在一起。 可以按任意顺序返回结果列表。 
//
// 注意：若两个字符串中每个字符出现的次数都相同，则称它们互为变位词。 
//
// 
//
// 示例 1: 
//
// 
//输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
//输出: [["bat"],["nat","tan"],["ate","eat","tea"]] 
//
// 示例 2: 
//
// 
//输入: strs = [""]
//输出: [[""]]
// 
//
// 示例 3: 
//
// 
//输入: strs = ["a"]
//输出: [["a"]] 
//
// 
//
// 提示： 
//
// 
// 1 <= strs.length <= 10⁴ 
// 0 <= strs[i].length <= 100 
// strs[i] 仅包含小写字母 
// 
//
// 
//
// 注意：本题与主站 49 题相同： https://leetcode-cn.com/problems/group-anagrams/ 
// Related Topics 数组 哈希表 字符串 排序 👍 32 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    map<char, int> str2map(const string &str) {
        map<char, int> ans;
        for (char c : str) {
            ans[c]++;
        }
        return ans;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        map<map<char,int>, vector<string>> box;

        for (int i=0; i<strs.size(); i++) {
            auto mp = str2map(strs[i]);

            auto it = box.find(mp);
            if (it != box.end()) {
                (it->second).push_back(strs[i]);
                continue;
            }

            box[mp] = vector<string>();
            box[mp].push_back(strs[i]);
        }

        for (auto it = box.begin(); it != box.end(); it++) {
            ans.push_back(it->second);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
