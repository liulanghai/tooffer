#include "common.h"
//统计一个数字在排序数组中出现的次数。
//二分查找找到位置，然后统计次数
class Solution
{
public:
    int binsearch(vector<int> data, int val)
    {
        int start = 0;
        int end = data.size() - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (data[mid] > val)
            {
                end = mid - 1;
            }
            else if (data[mid] < val)
            {
                start = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
    int GetNumberOfK(vector<int> data, int k)
    {
        int index = binsearch(data, k);
        printf("%d", index);
        if (index == -1)
        {
            return 0;
        }
        int count = 0;
        int i = index;
        while (i > -1 && data[i] == k)
        {
            count++;
            i = i - 1;
        }
        i = index + 1;
        while (i < data.size() && data[i] == k)
        {
            count++;
            i = i + 1;
        }
        return count;
    }
};
int main()
{
    Solution s;
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(2);
    a.push_back(2);
    a.push_back(2);
    a.push_back(3);
    printf("%d ", s.GetNumberOfK(a, 2));
}