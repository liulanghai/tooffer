#include "common.h"
//请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
//第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};
//二叉树按层次遍历
class Solution
{
public:
    vector<vector<int> > Print(TreeNode *pRoot)
    {
        vector<TreeNode *> node;
        vector<vector<int> > result;
        bool flag = true;
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
            if (flag)
            {
                flag = false;
                result.push_back(res);
            }
            else
            {
                flag = true;
                reverse(res.begin(), res.end());
                result.push_back(res);
            }
            node = tmp;
        }
        return result;
    }
};
int main()
{
    Solution s;
    struct TreeNode root(1);

    struct TreeNode node1(2);
    struct TreeNode node2(3);
    struct TreeNode node3(4);
    struct TreeNode node4(5);

    root.left = &node1;
    root.right = &node2;

    node2.right = &node4;
    node1.left = &node3;

    vector<vector<int> > res;
    res = s.Print(&root);
    for (int i = 0; i < res.size(); i++)
    {
        PrintIntVecotr(res[i]);
    }
}