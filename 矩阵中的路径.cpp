
#include "common.h"
#include <cstring>
/*
题目描述
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/
class Solution
{
public:
    int grows;
    int gcols;
    int strLen;
    char *gmatrix;
    char *gstr;
    bool isOK(int i, int j, int *m, vector<bool> *maps)
    {
        if (*m == strLen)
        {
            return true;
        }
        //范围超了，直接返回
        if (i < 0 || j < 0 || i >= grows || j >= gcols)
        {
            return false;
        }

        if ((*maps)[i * gcols + j] == true)
        {
            return false;
        }

        if (gmatrix[i * gcols + j] == gstr[*m])
        {
            *m = *m + 1;
            (*maps)[i * gcols + j] = true;
        }
        else
        {
            return false;
        }

        bool res = (isOK(i, j + 1, m, maps) || isOK(i + 1, j, m, maps) || isOK(i - 1, j, m, maps) || isOK(i, j - 1, m, maps));
        if (res == false)
        {
            *m = *m - 1;
            (*maps)[i * gcols + j] = false;
        }
        return res;
    }

    bool hasPath(char *matrix, int rows, int cols, char *str)
    {
        grows = rows;
        gcols = cols;
        strLen = strlen(str);
        gmatrix = matrix;
        gstr = str;
        vector<bool> maps;
        maps.reserve(rows * cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                for (int k = 0; k < maps.capacity(); k++)
                {
                    maps[k] = false;
                }
                int m = 0;
                bool res = isOK(i, j, &m, &maps);
                if (res)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    Solution s;
    /*
    abce
    sfcs
    adee
    */
    int res = s.hasPath("ABCESFCSADEE", 3, 4, "ABCCED");
    int res2 = s.hasPath("abcesfcsadee", 3, 4, "abcb");
    int res3 = s.hasPath("abcesfcsadee", 3, 4, "see");
    printf("%d ", res);
    printf("%d ", res2);
    printf("%d ", res3);
}