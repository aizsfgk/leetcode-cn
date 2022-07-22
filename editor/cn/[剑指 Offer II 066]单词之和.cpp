//实现一个 MapSum 类，支持两个方法，insert 和 sum： 
//
// 
// MapSum() 初始化 MapSum 对象 
// void insert(String key, int val) 插入 key-val 键值对，字符串表示键 key ，整数表示值 val 。如果键 
//key 已经存在，那么原来的键值对将被替代成新的键值对。 
// int sum(string prefix) 返回所有以该前缀 prefix 开头的键 key 的值的总和。 
// 
//
// 
//
// 示例： 
//
// 
//输入：
//inputs = ["MapSum", "insert", "sum", "insert", "sum"]
//inputs = [[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
//输出：
//[null, null, 3, null, 5]
//
//解释：
//MapSum mapSum = new MapSum();
//mapSum.insert("apple", 3);  
//mapSum.sum("ap");           // return 3 (apple = 3)
//mapSum.insert("app", 2);    
//mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
// 
//
// 
//
// 提示： 
//
// 
// 1 <= key.length, prefix.length <= 50 
// key 和 prefix 仅由小写英文字母组成 
// 1 <= val <= 1000 
// 最多调用 50 次 insert 和 sum 
// 
//
// 
//
// 注意：本题与主站 677 题相同： https://leetcode-cn.com/problems/map-sum-pairs/ 
// Related Topics 设计 字典树 哈希表 字符串 👍 18 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class MapSum {
<<<<<<< HEAD
public:
    /** Initialize your data structure here. */
    MapSum() {

    }
    
    void insert(string key, int val) {

    }
    
    int sum(string prefix) {

=======
private:
struct TrieNode {
    int val;
    TrieNode *next[26];
    TrieNode() {
        this->val = 0;
        for (int i=0; i<26; i++) {
            this->next[i] = nullptr;
        }
    }
};

    TrieNode *root;
    unordered_map<string, int> cnt;
public:
    /** Initialize your data structure here. */
    MapSum() {
        this->root = new TrieNode();
    }
    
    void insert(string key, int val) {
        int delta = val;
        if (cnt.count(key)) {
            delta -= cnt[key];
        }
        cnt[key] = val;
        TrieNode *node = root;
        for (auto c : key) {
            if (node->next[c-'a'] == nullptr) {
                node->next[c-'a'] = new TrieNode();
            }
            node = node->next[c-'a'];
            node->val += delta;
        }
    }
    
    int sum(string prefix) {
        TrieNode *node = root;
        for (auto c : prefix) {
            if (node->next[c-'a'] == nullptr) {
                return 0;
            } else {
                node = node->next[c-'a'];
            }
        }
        return node->val;
>>>>>>> 0cc0f34f5081b86e23effd53b578d35cab26243b
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
//leetcode submit region end(Prohibit modification and deletion)
