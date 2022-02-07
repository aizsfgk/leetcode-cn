//如果字符串中不含有任何 'aaa'，'bbb' 或 'ccc' 这样的字符串作为子串，那么该字符串就是一个「快乐字符串」。 
//
// 给你三个整数 a，b ，c，请你返回 任意一个 满足下列全部条件的字符串 s： 
//
// 
// s 是一个尽可能长的快乐字符串。 
// s 中 最多 有a 个字母 'a'、b 个字母 'b'、c 个字母 'c' 。 
// s 中只含有 'a'、'b' 、'c' 三种字母。 
// 
//
// 如果不存在这样的字符串 s ，请返回一个空字符串 ""。 
//
// 
//
// 示例 1： 
//
// 输入：a = 1, b = 1, c = 7
//输出："ccaccbcc"
//解释："ccbccacc" 也是一种正确答案。
// 
//
// 示例 2： 
//
// 输入：a = 2, b = 2, c = 1
//输出："aabbc"
// 
//
// 示例 3： 
//
// 输入：a = 7, b = 1, c = 0
//输出："aabaa"
//解释：这是该测试用例的唯一正确答案。 
//
// 
//
// 提示： 
//
// 
// 0 <= a, b, c <= 100 
// a + b + c > 0 
// 
// Related Topics 贪心 字符串 堆（优先队列） 
// 👍 88 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 最长快乐数
    // 思路：
    //      1. 使用贪心算法，每次取出元素个数最多的元素; 这里使用大根堆
    //      2. 取出堆顶元素，看是否可以拼接到当前字符串最后；可以拼接直接拼接
    //      3. 不可以则取出次大元素，拼接；如果次大元素字母个数为空，则输出答案
    //
    // time: O(n∗k∗log3) # n == a + b + c; k 表示出队入队平均次数
    // space: O(3) # 大根堆中只有3个元素
    string longestDiverseString(int a, int b, int c) {

        auto my_cmp = [](const pair<int, char> &l1, const pair<int, char> &l2) {
            return l1.first < l2.first; // 大根堆; 这里正好和 sort 函数相反
        };

        priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(my_cmp)> pQue {my_cmp};
        if (a > 0 ) pQue.push({a, 'a'});
        if (b > 0 ) pQue.push({b, 'b'});
        if (c > 0 ) pQue.push({c, 'c'});

        string  ans;
        while (!pQue.empty()) {
            auto ele = pQue.top();pQue.pop();
            int n = ans.size();
            // n-1 和 n-2求最后两个字符
            if (n >=2 && ele.second == ans[n-1] && ele.second == ans[n-2]) {

                if (pQue.empty()) break; // 此时返回最终答案

                // 推入次大元素字母
                auto ele2 = pQue.top(); pQue.pop();
                ans.push_back(ele2.second);
                ele2.first--;
                if (ele2.first != 0) {
                    pQue.push(ele2);
                }

                pQue.push(ele);
            } else {

                // 直接放入
                ans.push_back(ele.second);
                ele.first--;
                if (ele.first != 0) {
                    pQue.push(ele);
                }

            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
