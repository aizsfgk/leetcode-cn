//在大小为 n x n 的网格 grid 上，每个单元格都有一盏灯，最初灯都处于 关闭 状态。 
//
// 给你一个由灯的位置组成的二维数组 lamps ，其中 lamps[i] = [rowi, coli] 表示 打开 位于 grid[rowi][coli] 
//的灯。即便同一盏灯可能在 lamps 中多次列出，不会影响这盏灯处于 打开 状态。 
//
// 当一盏灯处于打开状态，它将会照亮 自身所在单元格 以及同一 行 、同一 列 和两条 对角线 上的 所有其他单元格 。 
//
// 另给你一个二维数组 queries ，其中 queries[j] = [rowj, colj] 。对于第 j 个查询，如果单元格 [rowj, colj]
// 是被照亮的，则查询结果为 1 ，否则为 0 。在第 j 次查询之后 [按照查询的顺序] ，关闭 位于单元格 grid[rowj][colj] 上及相邻 8 个
//方向上（与单元格 grid[rowi][coli] 共享角或边）的任何灯。 
//
// 返回一个整数数组 ans 作为答案， ans[j] 应等于第 j 次查询 queries[j] 的结果，1 表示照亮，0 表示未照亮。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
//输出：[1,0]
//解释：最初所有灯都是关闭的。在执行查询之前，打开位于 [0, 0] 和 [4, 4] 的灯。第 0 次查询检查 grid[1][1] 是否被照亮（蓝色方框）
//。该单元格被照亮，所以 ans[0] = 1 。然后，关闭红色方框中的所有灯。
//
//第 1 次查询检查 grid[1][0] 是否被照亮（蓝色方框）。该单元格没有被照亮，所以 ans[1] = 0 。然后，关闭红色矩形中的所有灯。
//
// 
//
// 示例 2： 
//
// 
//输入：n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,1]]
//输出：[1,1]
// 
//
// 示例 3： 
//
// 
//输入：n = 5, lamps = [[0,0],[0,4]], queries = [[0,4],[0,1],[1,4]]
//输出：[1,1,0]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 109 
// 0 <= lamps.length <= 20000 
// 0 <= queries.length <= 20000 
// lamps[i].length == 2 
// 0 <= rowi, coli < n 
// queries[j].length == 2 
// 0 <= rowj, colj < n 
// 
// Related Topics 数组 哈希表 
// 👍 65 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {

private:
    // 自身 + 8个方向: 上，下，左，右； 上左，上右，下左，下右
    int dirs[9][2] = {{0,0}, {-1,0}, {1,0}, {0,-1}, {0,1}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};
    // 亮着的灯
    set<pair<int,int>> lampSet;
    // 分别表示 行，列，左对角线，右对角线的灯的数量
    unordered_map<int, int> rowMap, colMap, lDirMap, rDirMap;


public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        /*
         思路：
         因为 1 <= n <= 109 ，暴力会超时，所以使用hashTable记录每个位置的亮灯次数

         1. 分别记录4个方向的灯亮次数；是方向，记住
         2.

         */

        vector<int> ans;

        for (int i=0; i<lamps.size(); i++) {
            int X = lamps[i][0];
            int Y = lamps[i][1];

            if (lampSet.find({X, Y}) == lampSet.end()) {
                lampSet.insert({X, Y});

                rowMap[X]++; // 整个行都亮了
                colMap[Y]++; // 整个列都亮了
                lDirMap[X-Y]++;
                rDirMap[X+Y]++;
            }
        }

        for (int i=0; i<queries.size(); i++) {
            int X = queries[i][0];
            int Y = queries[i][1];

            // 只要有一个就返回1
            if (rowMap[X] || colMap[Y] || lDirMap[X-Y] || rDirMap[X+Y])
                ans.push_back(1);
            else
                ans.push_back(0);

            // 关灯
            for (auto dir : dirs) {
                int newX = X+dir[0];
                int newY = Y+dir[1];

                if (lampSet.find({newX, newY}) != lampSet.end()) {
                    lampSet.erase({newX, newY});
                    rowMap[newX]--;  // 整个行都灭了
                    colMap[newY]--;  // 整个列都灭了
                    lDirMap[newX-newY]--;
                    rDirMap[newX+newY]--;
                }
            }
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
