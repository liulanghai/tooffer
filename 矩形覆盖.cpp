#include "common.h"
//我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
//请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

class Solution
{
public:
    int rectCover(int number)
    {
        if (number == 1)
        {
            return 1;
        }
        if (number == 2)
        {
            return 2;
        }
        int a = 1;
        int b = 2;
        int result = 0;
        for (int i = 2; i < number; i++)
        {
            result = a + b;
            a = b;
            b = result;
        }
        return result;
    }
};
int main()
{
    Solution s;
    printf("%d ", s.rectCover(0));
}