#include "common.h"
class Solution
{
public:
    string PrintMinNumber(vector<int> numbers)
    {
        string s;
        sort(numbers.begin(), numbers.end(), cmp);

        for (int i = 0; i < numbers.size(); i++)
        {
            s = s + to_string(numbers[i]);
        }
        return s;
    }
    static bool cmp(int &a, int &b)
    {
        //   return false;
        string s1 = to_string(a) + to_string(b);
        string s2 = to_string(b) + to_string(a);
        if (s1.length() > s2.length())
        {
            return false;
        }
        if (s1.length() == s2.length())
        {
            if (s1.compare(s2) > 0)
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution s;
    vector<int> a;
    a.push_back(3);
    a.push_back(32);
    a.push_back(321);
    //a.push_back(4);
    printf("%s", s.PrintMinNumber(a).c_str());
}