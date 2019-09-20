#include "common.h"
/*
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
 例如，当k为18时，机器人能够进入方格（35,37），
 因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/
//暴力遍历
class Solution
{
public:
    int weiSum(int a)
    {
        int sum = 0;
        while (a / 10 != 0)
        {
            sum = sum + a % 10;
            a = a / 10;
        }
        return sum + a;
    }
    int check(int i, int j)
    {
        return weiSum(i) + weiSum(j);
    }
    int grows;
    int gcols;
    int visit(int threshold, int i, int j, vector<bool> *maps)
    {
        if (i < 0 || j < 0 || i >= grows || j >= gcols)
        {
            return 0;
        }
        if (check(i, j) > threshold)
        {
            printf("out i = %d j = %d\n", i, j);
            return 0;
        }
        if ((*maps)[i * gcols + j] == true)
        {
            return 0;
        }
        (*maps)[i * gcols + j] = true;
        printf(" i = %d j = %d \n", i, j);
        return 1 + visit(threshold, i, j - 1, maps) + visit(threshold, i, j + 1, maps) + visit(threshold, i + 1, j, maps) + visit(threshold, i - 1, j, maps);
    }
    int movingCount(int threshold, int rows, int cols)
    {
        vector<bool> maps;
        grows = rows;
        gcols = cols;
        maps.reserve(rows * cols);
        for (int i = 0; i < maps.capacity(); i++)
        {
            maps[i] = false;
        }
        return visit(threshold, 0, 0, &maps);
    }
};
int main()
{
    Solution s;

    printf("%d", s.movingCount(5, 10, 10));
    //printf("%d,", s.weiSum(6656));
}