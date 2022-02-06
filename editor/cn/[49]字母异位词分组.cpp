//给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。 
//
// 字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。 
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
// 1 <= strs.length <= 104 
// 0 <= strs[i].length <= 100 
// strs[i] 仅包含小写字母 
// 
// Related Topics 哈希表 字符串 排序 
// 👍 987 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    map<char, int> scanWords2Map(string &str) {
        map<char, int> ans;
        for (int i=0; i<str.size(); i++) {
            ans[str[i]]++;
        }
        return ans;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

//        set<map<char,int>> mySet;
//        for (int i=0; i<n; i++) {
//            mySet.insert(scanWords2Map(strs[i]));
//        }
//
//        vector<vector<string>> ans;
//        for (auto it = mySet.begin(); it != mySet.end(); it++) {
//            ans.push_back(vector<string>());
//            for (int i=0; i<n; i++) {
//                if (*it == scanWords2Map(strs[i])) {
//                    ans.back().push_back(strs[i]);
//                }
//            }
//        }
        map<map<char, int>, vector<string>> myMap;
        for (int i=0; i<n; i++) {

            map<char, int> tmpMap = scanWords2Map(strs[i]);

            auto it = myMap.find(tmpMap);
            if (it == myMap.end()) {
                myMap[tmpMap] = vector<string>();
            }

            myMap[tmpMap].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for (auto it = myMap.begin(); it != myMap.end(); it++) {
            ans.push_back(it->second);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
