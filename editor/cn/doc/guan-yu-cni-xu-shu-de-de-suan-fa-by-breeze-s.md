### 解题思路
首先要知道这个题的逆序算法：把最后的一个数字相继的提出然后通过依次的乘十累加还原逆序数，
这里注意设定的余数和累加数的数据类型，防止溢出。最后按照题目要求把溢出的逆序数输出为0即可。

### 代码
#include<iostream>
using namespace std;
```cpp
class Solution {
public:
    int reverse(int x) {
        long temp = 0, sum = 0;
        while (x != 0) {
            temp = x % 10;
            sum = sum * 10 + temp;
            x = x / 10;
        }
        if (sum >= INT_MAX || sum <= INT_MIN)
            sum = 0;
        return sum;
    }
};
int main() {
    int x;
    cin >> x;
    Solution a;
    cout << a.reverse(x);
    return 0;
}