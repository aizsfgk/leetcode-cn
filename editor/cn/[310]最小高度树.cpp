//树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。 
//
// 给你一棵包含 n 个节点的树，标记为 0 到 n - 1 。给定数字 n 和一个有 n - 1 条无向边的 edges 列表（每一个边都是一对标签），其中
// edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条无向边。 
//
// 可选择树中任何一个节点作为根。当选择节点 x 作为根节点时，设结果树的高度为 h 。在所有可能的树中，具有最小高度的树（即，min(h)）被称为 最小高度
//树 。 
//
// 请你找到所有的 最小高度树 并按 任意顺序 返回它们的根节点标签列表。 
//树的 高度 是指根节点和叶子节点之间最长向下路径上边的数量。
//
// 
//
// 示例 1： 
//
// 
//输入：n = 4, edges = [[1,0],[1,2],[1,3]]
//输出：[1]
//解释：如图所示，当根是标签为 1 的节点时，树的高度是 1 ，这是唯一的最小高度树。 
//
// 示例 2： 
//
// 
//输入：n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
//输出：[3,4]
// 
//
// 示例 3： 
//
// 
//输入：n = 1, edges = []
//输出：[0]
// 
//
// 示例 4： 
//
// 
//输入：n = 2, edges = [[0,1]]
//输出：[0,1]
// 
//
// 
//
// 
// 
//
// 提示： 
//
// 
// 1 <= n <= 2 * 104 
// edges.length == n - 1 
// 0 <= ai, bi < n 
// ai != bi 
// 所有 (ai, bi) 互不相同 
// 给定的输入 保证 是一棵树，并且 不会有重复的边 
// 
// Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 
// 👍 442 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        /*
        思路：
        求最小路径，最低高度，可以想到BFS，普通的BFS在数据量很大的情况下，本题测试样例会超时，改用减小度数的方法

        通过遍历 edges ，构建度数表和邻接图
        每次把度数为 1 的节点加入队列
        广度遍历队列，把邻接图中的节点度数减一，当其度数为1时，将其入队
        res数组每一层都更新一次，所以最后一次保留的就是使得高度最小的节点

        ###因为度数越小，以为这高度会越高；度数越大，树会更矮胖，所以这种思想也是逐渐排除度数低的节点，逐层淘汰。

        类似：  两端烧香求中点

        */
        if (edges.empty()) {
            return {0};
        }


        // 1. 建图
        vector<vector<int>> adjList(n); // 邻接表
        vector<int> degree(n, 0); // 出入度
        for (int i=0; i<edges.size(); i++) {
            int v1 = edges[i][0];
            int v2 = edges[i][1];

            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1);

            // 高效算法，还会使用degree
            degree[v1]++;
            degree[v2]++;
        }

        // 图的BFS 和 树的 BFS 很像
        // 2. BSF拓扑排序，初始化
        queue<int> que;
        for (int i=0; i<n; i++) {
            if (degree[i] == 1) { // 入度为1，说明只有一条边
                que.push(i);
            }
        }

        // 3. 遍历队列
        vector<int> ans;
        while (!que.empty()) {
            ans.clear(); // 两端向中间夹逼；最后一层即为根节点列表
            int size = que.size(); // 每层的节点数

            for (int i=0; i<size; i++) {
                int cur = que.front(); que.pop();
                ans.push_back(cur);
                degree[cur]--;

                for (int i : adjList[cur]) {
                    degree[i]--;
                    if (degree[i] == 1) {
                        que.push(i);
                    }
                }
            }
        }

        // 4. 返回的是： 根节点标签列表
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
