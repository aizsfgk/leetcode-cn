//现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。给你一个数组 prerequisites ，其中 prerequ
//isites[i] = [ai, bi] ，表示在选修课程 ai 前 必须 先选修 bi 。 
//
// 
// 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1] 。 
// 
//
// 返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组 。 
//
// 
//
// 示例 1： 
//
// 
//输入：numCourses = 2, prerequisites = [[1,0]]
//输出：[0,1]
//解释：总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。
// 
//
// 示例 2： 
//
// 
//输入：numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
//输出：[0,2,1,3]
//解释：总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
//因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。 
//
// 示例 3： 
//
// 
//输入：numCourses = 1, prerequisites = []
//输出：[0]
// 
//
// 
//提示：
//
// 
// 1 <= numCourses <= 2000 
// 0 <= prerequisites.length <= numCourses * (numCourses - 1) 
// prerequisites[i].length == 2 
// 0 <= ai, bi < numCourses 
// ai != bi 
// 所有[ai, bi] 互不相同 
// 
// Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 
// 👍 565 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/*
class Solution {

private:
    // 深度优先搜索
    // 深度优先搜索不是拓扑排序；
    vector<int> mark;
    vector<int> preOrder;

    bool traverse(const vector<vector<int>> &graph, int i) {
        // true 表示有环
        if (mark[i] == 1) {
            return true;
        }

        if (mark[i] == 2) {
            return false;
        }


        mark[i] = 1;
        for (int t : graph[i]) {
            if (traverse(graph, t)) {
                return true;
            }
        }
        mark[i] = 2;

        preOrder.push_back(i);

        return false;
    }
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph(numCourses);

        for (auto edge : prerequisites) {
            int from = edge[1];
            int to = edge[0];

            graph[from].push_back(to);
        }
        return graph;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        mark.resize(numCourses);


        for (int i=0; i<numCourses; i++) {
            if (traverse(graph, i)) {
                return {};
            }
        }

       reverse(preOrder.begin(), preOrder.end());
       return preOrder;
    }
};

*/
class Solution {
private:
    /*
        使用广度优先搜索。
        思路:


    */
    vector<int> inDegree;

    // 1. 建图
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto edge : prerequisites) {
            int from = edge[1];
            int to = edge[0];

            inDegree[to]++; // 入度
            graph[from].push_back(to);
        }
        return graph;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        inDegree.resize(numCourses);

        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);

        vector<int> ans;

        queue<int> que;
        for (int i=0; i<numCourses; i++) {
            if (inDegree[i] == 0) { // 入度为0；则为开始节点
                que.push(i);
            }
        }

        // 如果队列不为空
        while (!que.empty()) {
            // 拿到头节点
            int head = que.front(); que.pop(); // 只要入队的；入度可定为0

            // 放入
            ans.push_back(head);

            // 依次放入que
            for (auto i : graph[head]) {
                if (--inDegree[i] == 0) { // 通过入度来判断是否需要入队列
                    que.push(i);
                }
            }
        }

        // 总数 一致； 则返回 ans
        if (ans.size() == numCourses) {
            return ans;
        }

        return {};
    }
};
//leetcode submit region end(Prohibit modification and deletion)
