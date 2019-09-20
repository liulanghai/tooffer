#include "common.h"
/*
B[i]=A[0]A[1]...A[i-1]A[i+1]...A[n-1]，求A数组的连乘，但不包含A[i];

*/
//计算前半部分与后半部分。
class Solution
{
public:
    vector<int> multiply(const vector<int> &A)
    {
        vector<int> head;
        vector<int> tail;
        vector<int> result;
        if (A.size() == 0)
        {
            return result;
        }
        head.push_back(A[0]);
        for (int i = 1; i < A.size(); i++)
        {
            head.push_back(A[i] * head[i - 1]);
        }
        int len = A.size();
        tail.push_back(A[len - 1]);
        for (int i = len - 2; i > -1; i--)
        {
            tail.push_back(A[i] * tail[tail.size() - 1]);
        }
        reverse(tail.begin(), tail.end());
        int start = 0;
        for (int i = 0; i < len; i++)
        {
            int start = i - 1;
            int end = i + 1;
            int res;
            if (start < 0)
            {
                res = tail[end];
            }
            else if (end > A.size() - 1)
            {
                res = head[start];
            }
            else
            {
                res = head[start] * tail[end];
            }
            result.push_back(res);
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    PrintIntVecotr(s.multiply(a));
}