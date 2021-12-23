//所有 DNA 都由一系列缩写为 'A'，'C'，'G' 和 'T' 的核苷酸组成，例如："ACGAATTCCG"。在研究 DNA 时，识别 DNA 中的重复
//序列有时会对研究非常有帮助。 
//
// 编写一个函数来找出所有目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
//输出：["AAAAACCCCC","CCCCCAAAAA"]
// 
//
// 示例 2： 
//
// 
//输入：s = "AAAAAAAAAAAAA"
//输出：["AAAAAAAAAA"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 105 
// s[i] 为 'A'、'C'、'G' 或 'T' 
// 
// Related Topics 位运算 哈希表 字符串 滑动窗口 哈希函数 滚动哈希 
// 👍 313 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //
    // Rabin-Karp匹配算法 + 前缀数组
    //
    // 说明这是一个31进制的数
    unsigned long long prime = 31;
    vector<string> findRepeatedDnaSequences(string s) {

        // 结果数据
        vector<string> ans;

        // 原串大小
        int n = s.size();
        // 子串大小
        int m = 10;

        // 特殊情况去除
        if (n < 10) {
            return ans;
        }

        // 计算hash 和 次方基数
        unsigned long long hash = 0;
        unsigned long long power = 1;

        // 前10个字符串的hash值
        for (int i=0; i<m; i++) {
            hash = hash * prime + (s[i] - 'a');
            power *= prime;
        }

        // 辅助数据结构map
        unordered_map<unsigned long long, int> mp;
        // 首字母10个放入hash
        mp[hash] = 1;


        // 寻找所有的10字符子串
        for (int i=m; i<n; i++) {

            // 掐头去尾
            hash = hash * prime - power * (s[i-m] - 'a') + (s[i] - 'a');

            // 如果有，则将重复的放入结果池
            if (mp[hash] == 1) {
                ans.push_back(s.substr(i-10+1, 10));
            }

            // 入map
            mp[hash]++;
        }

        // 返回答案
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
