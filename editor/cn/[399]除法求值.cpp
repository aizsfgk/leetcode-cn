//给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和 values
//[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。 
//
// 另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj =
// ? 的结果作为答案。 
//
// 返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 -1.0 替
//代这个答案。 
//
// 注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。 
//
// 
//
// 示例 1： 
//
// 
//输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"]
//,["b","a"],["a","e"],["a","a"],["x","x"]]
//输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
//解释：
//条件：a / b = 2.0, b / c = 3.0
//问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
//结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
// 
//
// 示例 2： 
//
// 
//输入：equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], quer
//ies = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
//输出：[3.75000,0.40000,5.00000,0.20000]
// 
//
// 示例 3： 
//
// 
//输入：equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a
//","c"],["x","y"]]
//输出：[0.50000,2.00000,-1.00000,-1.00000]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= equations.length <= 20 
// equations[i].length == 2 
// 1 <= Ai.length, Bi.length <= 5 
// values.length == equations.length 
// 0.0 < values[i] <= 20.0 
// 1 <= queries.length <= 20 
// queries[i].length == 2 
// 1 <= Cj.length, Dj.length <= 5 
// Ai, Bi, Cj, Dj 由小写英文字母与数字组成 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 图 数组 最短路 
// 👍 673 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/*
   并查集：
   解题链接：https://leetcode-cn.com/problems/queue-reconstruction-by-height/solution/xian-pai-xu-zai-cha-dui-dong-hua-yan-shi-suan-fa-g
*/
class UnionFind {
private:
    vector<int> parent;    // 存放父节点
    vector<double> weight; // 指向父节点的权值

public:
    UnionFind(int n) {
        for (int i = 0; i < n; ++i) {
            parent.push_back(i);
            weight.push_back(1.0); // 权重初始化为1
        }
    }
    // 路径压缩。返回根节点id
    int find(int x) {
        // 递归寻找根节点，更新该点到根的权重为该点父节点到根的权重
        if (x != parent[x]) {
            int origin = parent[x];
            parent[x] = find(parent[x]);
            weight[x] *= weight[origin];
        }
        return parent[x];
    }
    // 返回除法结果。如果两个值不存在则-1
    double isConected(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        // 如果两个值有共同的根也就是可以计算，则算结果。否则不在同一个并查集，-1
        if (rootX == rootY) {
            return weight[x] / weight[y];
        } else {
            return -1.00000;
        }
    }
    void myUnion(int x, int y, double value) {
        // 分别找到二者的根节点
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) {
            return; // 二者已经指向同一个根节点
        }
        // 令分子指向分母的根节点，权重为分母到根的权重*分母除分子的值/分子到根的权重。一开始都是1
        parent[rootX] = rootY;
        weight[rootX] = weight[y] * value / weight[x];
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // 初始化并查集
        int equationsSize = equations.size();
        UnionFind unionFind(2 * equationsSize);
        // 第 1 步：预处理，将变量的值与 id 进行映射
        map<string, int> hashMap;
        int id = 0;
        for (int i = 0; i < equationsSize; ++i) {
            // 存分子，分母，值为id
            vector<string> equation = equations[i];
            string var1 = equation[0];
            string var2 = equation[1];
            if (!hashMap.count(var1)) {
                hashMap[var1] = id;
                ++id;
            }
            if (!hashMap.count(var2)) {
                hashMap[var2] = id;
                ++id;
            }
            // 把分子分母用有向边连起来
            unionFind.myUnion(hashMap[var1], hashMap[var2], values[i]);
        }
        // 第 2 步：做查询
        int queriesSize = queries.size();
        vector<double> res(queriesSize, -1.00000);
        for (int i = 0; i < queriesSize; ++i) {
            string var1 = queries[i][0];
            string var2 = queries[i][1];
            int id1, id2;
            // 如果两个值有至少一个不在equations中，结果为-1，否则做除法
            if (hashMap.count(var1) && hashMap.count(var2)) {
                id1 = hashMap[var1];
                id2 = hashMap[var2];
                res[i] = unionFind.isConected(id1, id2);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
