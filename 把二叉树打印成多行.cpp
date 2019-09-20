#include "common.h"

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};
// 按层次遍历
class Solution
{
public:
    vector<vector<int> > Print(TreeNode *pRoot)
    {
        vector<TreeNode *> node;
        vector<vector<int>> result;
        if (pRoot != NULL)
        {
            node.push_back(pRoot);
        }
        while (!node.empty())
        {
            vector<TreeNode *> tmp;
            vector<int> res;
            for (int i = 0; i < node.size(); i++)
            {
                res.push_back(node[i]->val);
                if (node[i]->left != NULL)
                {
                    tmp.push_back(node[i]->left);
                }
                if (node[i]->right != NULL)
                {
                    tmp.push_back(node[i]->right);
                }
            }
            result.push_back(res);
            node = tmp;
        }
        return result;
    }
};