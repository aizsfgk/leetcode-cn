//你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。 
//
// 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表
//示如果要学习课程 ai 则 必须 先学习课程 bi 。 
//
// 
// 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。 
// 
//
// 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。 
//
// 
//
// 示例 1： 
//
// 
//输入：numCourses = 2, prerequisites = [[1,0]]
//输出：true
//解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。 
//
// 示例 2： 
//
// 
//输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
//输出：false
//解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。 
//
// 
//
// 提示： 
//
// 
// 1 <= numCourses <= 105 
// 0 <= prerequisites.length <= 5000 
// prerequisites[i].length == 2 
// 0 <= ai, bi < numCourses 
// prerequisites[i] 中的所有课程对 互不相同 
// 
// Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 
// 👍 1097 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    // 深度优先搜索
    /*
        思路：
            存在前后依赖关系的处理，使用拓扑排序；
            建立邻接表，入队为0的元素进入队列；
            元素出队，对应的入度为0的元素，进入队列；
    */
    vector<bool> onPath;
    vector<bool> visited;
    bool hasCycle = false;

    // 1. 建图
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for (auto edge : prerequisites) {
            int from = edge[1];
            int to = edge[0];
            graph[from].push_back(to);
        }

        return graph;
    }

    // 2. 开始DFS
    void traverse(const vector<vector<int>> &graph, int s) {
        // 是否已经在路径上了，判断有无环
        if (onPath[s]) {
            hasCycle = true;
            return;
        }

        // 已经访问过这个节点
        if (visited[s]) {
            return;
        }

        // 前序遍历
        visited[s] = true;
        onPath[s] = true;

        for (int t : graph[s]) {
            traverse(graph, t);
        }

        // 后续遍历
        onPath[s] = false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 本质： 判断有向图是否存在环
        //
        // 步骤：
        //      1. 建图
        //      2. 深度优先/广度优先遍历
        //      3. 使用使用判断
        //      4. 是否有环
        //

        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        onPath.resize(numCourses);
        visited.resize(numCourses);

        for (int i=0; i<numCourses; i++) {
            traverse(graph, i);
        }

        return !hasCycle;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
