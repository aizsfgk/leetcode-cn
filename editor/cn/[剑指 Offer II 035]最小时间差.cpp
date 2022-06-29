//给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。 
//
// 
//
// 示例 1： 
//
// 
//输入：timePoints = ["23:59","00:00"]
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：timePoints = ["00:00","23:59","00:00"]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 2 <= timePoints <= 2 * 10⁴ 
// timePoints[i] 格式为 "HH:MM" 
// 
//
// 
//
// 注意：本题与主站 539 题相同： https://leetcode-cn.com/problems/minimum-time-difference/ 
// Related Topics 数组 数学 字符串 排序 👍 21 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    int time2Num(string t) {
        int cur = 0;
        cur = ((t[0] - '0') * 10 + (t[1] - '0')) * 60 + ((t[3] - '0')*10 + (t[4]-'0') );
        return cur;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        // 时间表的最小时间差
        int n = timePoints.size();

        vector<int> timeNum(2*n);
        for (int i=0; i<timePoints.size(); i++) {
            int num = time2Num(timePoints[i]);
            timeNum[i] = num;
            timeNum[i+n] = num + 1440;
        }

        // circle array
        sort(timeNum.begin(), timeNum.end());

        int ans = timeNum[1] - timeNum[0];
        for (int i=2; i<timeNum.size(); i++) {
            ans = min(ans, timeNum[i] - timeNum[i-1]);
        }


        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
