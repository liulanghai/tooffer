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

bool isDui(TreeNode *A, TreeNode *B) // 判断A与B是否对称
{
    if (A == NULL && B == NULL)
    {
        return true;
    }
    if (A != NULL && B != NULL)
    {
        if (A->val != B->val)
        {
            return false;
        }
        return isDui(A->left, B->right) && isDui(A->right, B->left);
    }
    return false;
}
class Solution
{
public:
    bool isSymmetrical(TreeNode *pRoot)
    {
        if (pRoot == NULL)
        {
            return true;
        }
        return isDui(pRoot->left, pRoot->right);
    }
};