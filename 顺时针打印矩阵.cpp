#include "common.h"

class Solution
{
public:
    void PrintMatrixInCircle(vector<vector<int>> &matrix, int start, vector<int> &ret)
    {
        int rows = (int)matrix.size();
        int columns = (int)matrix[0].size();
        int endX = (columns - 1) - start;
        int endY = (rows - 1) - start;
        // 从左到右
        for (int i = start; i <= endX; ++i)
        {
            ret.push_back(matrix[start][i]);
        }

        // 从上到下，至少2行
        if (endY > start)
        {
            for (int i = start + 1; i <= endY; ++i)
            {
                ret.push_back(matrix[i][endX]);
            }
        }

        // 从右到左，至少2行2列
        if (endX > start && endY > start)
        {
            for (int i = endX - 1; i >= start; --i)
            {
                ret.push_back(matrix[endY][i]);
            }
        }

        // 从下到上，至少有3行2列
        if (endY > start + 1 && endX > start)
        {
            for (int i = endY - 1; i >= start + 1; i--)
            {
                ret.push_back(matrix[i][start]);
            }
        }
    }

    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        int rows = (int)matrix.size();
        int columns = (int)matrix[0].size();
        vector<int> ret;
        if (matrix.size() == 0 || columns <= 0 || rows <= 0)
            return ret;
        int start = 0;
        while (columns > start * 2 && rows > start * 2)
        {
            PrintMatrixInCircle(matrix, start, ret);
            ++start;
        }

        return ret;
    }
};