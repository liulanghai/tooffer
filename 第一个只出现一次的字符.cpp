#include "common.h"
class Solution
{
public:
    int FirstNotRepeatingChar(string str)
    {
        map<char, int> res;
        for (int i = 0; i < str.length(); i++)
        {
            map<char, int>::iterator iter;
            iter = res.find(str[i]);

            if (iter != res.end())
            {
                res[str[i]]++;
            }
            else
            {
                res[str[i]] = 1;
            }
        }
        for (int i = 0; i < str.length(); i++)
        {
            if (res[str[i]] == 1)
            {
                return i;
            }
        }
    }
};