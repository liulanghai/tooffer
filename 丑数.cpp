#include "common.h"
/*
*/
//
class Solution
{
public:
    int GetUglyNumber_Solution(int index)
    {
        if (index <= 0)
            return 0;
        int *uglyNumbers = new int[index];
        uglyNumbers[0] = 1;
        int nextUglyNumberIndex = 1;
        int multiplyNumber2 = 0;
        int multiplyNumber3 = 0;
        int multiplyNumber5 = 0;
        while (nextUglyNumberIndex < index)
        {
            int m = min(uglyNumbers[multiplyNumber2] * 2,
                        uglyNumbers[multiplyNumber3] * 3,
                        uglyNumbers[multiplyNumber5] * 5);
            uglyNumbers[nextUglyNumberIndex] = m;
            nextUglyNumberIndex++;
            if (uglyNumbers[multiplyNumber2] * 2 == m)
                ++multiplyNumber2;
            if (uglyNumbers[multiplyNumber3] * 3 == m)
                ++multiplyNumber3;
            if (uglyNumbers[multiplyNumber5] * 5 == m)
                ++multiplyNumber5;
        }
        return uglyNumbers[nextUglyNumberIndex - 1];
    }
    int min(int multiplyNumber2, int multiplyNumber3,
            int multiplyNumber5)
    {
        int min = (multiplyNumber2 < multiplyNumber3) ? multiplyNumber2
                                                      : multiplyNumber3;
        return (min < multiplyNumber5) ? min : multiplyNumber5;
    }
};