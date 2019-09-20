#include "common.h"

//如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
//那么中位数就是所有数值排序之后位于中间的数值。
//如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
//用两个堆，最大最小堆，插入数据时候维护一下两个堆差距不要超过2即可。
class Solution
{
    priority_queue<int, vector<int>, less<int>> p;
    priority_queue<int, vector<int>, greater<int>> q;

public:
    void Insert(int num)
    {
        if (p.empty() || num <= p.top())
            p.push(num);
        else
            q.push(num);
        if (p.size() == q.size() + 2)
            q.push(p.top()), p.pop();
        if (p.size() + 1 == q.size())
            p.push(q.top()), q.pop();
    }
    double GetMedian()
    {
        return p.size() == q.size() ? (p.top() + q.top()) / 2.0 : p.top();
    }
};
