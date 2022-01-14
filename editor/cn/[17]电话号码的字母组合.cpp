//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。 
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：digits = "23"
//输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 
//
// 示例 2： 
//
// 
//输入：digits = ""
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：digits = "2"
//输出：["a","b","c"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= digits.length <= 4 
// digits[i] 是范围 ['2', '9'] 的一个数字。 
// 
// Related Topics 哈希表 字符串 回溯 
// 👍 1680 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*
        回溯法本质就是穷举，会用到递归函数。
        使用回溯法的几类问题：
        1. 组合问题： N个数⾥⾯按⼀定规则找出k个数的集合
        2. 切割问题：⼀个字符串按⼀定规则有⼏种切割⽅式
        3. 子集问题：⼀个N个数的集合⾥有多少符合条件的⼦集
        4. 排列问题：N个数按⼀定规则全排列，有⼏种排列⽅式
        5. 棋盘问题：N皇后，解数独等等


        组合：不强调元素顺序
        排列：强调元素顺序

        集合的大小构成了树的宽度
        递归的深度构成了数的深度

        void backtrace(参数)

        if (终止条件) {
            存放结果;
            return;
        }

        // for循环可以理解是横向遍历，backtracking（递归）就是纵向遍历
        for (选择：本集合中的元素) {
            处理节点;
            backtrace(路径，选择列表)
            回溯，撤销处理结果；
        }

        // 模板
        void backtracking(参数) {
            if (终⽌条件) {
                存放结果;
                return;
            }
            for (选择：本层集合中元素（树中节点孩⼦的数量就是集合的⼤⼩）) {
                处理节点;
                backtracking(路径，选择列表); // 递归
                回溯，撤销处理结果
            }
        }


    */

    // 2个全局变量
    vector<string> ans;
    string path; // 路径

    // 必须先把映射表定义好
    unordered_map<char, string> myMap = {
        {'2' , "abc"},
        {'3' , "def"},
        {'4' , "ghi"},
        {'5' , "jkl"},
        {'6' , "mno"},
        {'7' , "pqrs"},
        {'8' , "tuv"},
        {'9' , "wxyz"},
    };

    // 全局字符串和起始索引
    void backtracking(string digits, int startIdx) {
        // 结束条件
        if (startIdx == digits.size()) {
            ans.push_back(path);
            return;
        }

        // 找到数字对应的字符串
        string ele = myMap[digits[startIdx]];

        // 遍历每个字符串
        for (int i=0; i<ele.size(); i++) {   // 宽度是映射字符串的长度
           path.push_back(ele[i]);
           backtracking(digits, startIdx+1); // 深度是 digits 的长度
           path.pop_back();
        }
    }


    vector<string> letterCombinations(string digits) {
        // 边界处理
        if (digits.size() == 0)
            return ans;

        // 开始回溯
        backtracking(digits, 0);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
