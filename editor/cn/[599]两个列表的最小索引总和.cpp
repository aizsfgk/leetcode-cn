//假设 Andy 和 Doris 想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。 
//
// 你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设答案总是存在。 
//
// 
//
// 示例 1: 
//
// 
//输入: list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]，list2 = ["Piat
//ti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
//输出: ["Shogun"]
//解释: 他们唯一共同喜爱的餐厅是“Shogun”。
// 
//
// 示例 2: 
//
// 
//输入:list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]，list2 = ["KFC",
// "Shogun", "Burger King"]
//输出: ["Shogun"]
//解释: 他们共同喜爱且具有最小索引和的餐厅是“Shogun”，它有最小的索引和1(0+1)。
// 
//
// 
//
// 提示: 
//
// 
// 1 <= list1.length, list2.length <= 1000 
// 1 <= list1[i].length, list2[i].length <= 30 
// list1[i] 和 list2[i] 由空格 ' ' 和英文字母组成。 
// list1 的所有字符串都是 唯一 的。 
// list2 中的所有字符串都是 唯一 的。 
// 
// Related Topics 数组 哈希表 字符串 
// 👍 158 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> memo1;
        unordered_map<string, int> memo2;
        for (int i=0; i<list1.size(); i++) {
            memo1[list1[i]] = i;
        }
        for (int i=0; i<list2.size(); i++) {
            memo2[list2[i]] = i;
        }

        vector<string> ans;
        int maxIdx = INT_MAX;
        for (auto it = memo1.begin(); it != memo1.end(); it++) {
            if (memo2.find(it->first) != memo2.end()) {
                if (it->second + memo2[it->first] == maxIdx) {
                    ans.push_back(it->first);
                } else if (it->second + memo2[it->first] < maxIdx) {
                    ans.clear();
                    ans.push_back(it->first);
                    maxIdx = it->second + memo2[it->first];
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
