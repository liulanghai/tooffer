#include "common.h"
//给定一棵二叉搜索树，请找出其中的第k小的结点。
//例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};
//二叉搜索树中序遍历就是有序的
void R(TreeNode *pRoot, int *k, TreeNode **val)
{

    if (pRoot == NULL || *k < 0)
    {
        return;
    }
    R(pRoot->left, k, val);

    *k = *k - 1;
    printf("%d ", pRoot->val);
    if (*k == 0)
    {
        *val = pRoot;
        return;
    }

    R(pRoot->right, k, val);
}
class Solution
{
public:
    TreeNode *KthNode(TreeNode *pRoot, int k)
    {
        TreeNode *result;
        R(pRoot, &k, &result);
        printf("k = %d", k);
        return result;
    }
};

int main()
{
    Solution s;
    struct TreeNode root(0);
    struct TreeNode node1(1);
    struct TreeNode node2(2);
    struct TreeNode node3(3);
    struct TreeNode node4(4);

    root.left = &node1;
    root.right = &node2;

    node2.right = &node4;
    node1.left = &node3;
    /*
            0
         1       2
       3   -1  -1  4
    */
    if (s.KthNode(&root, 9) == NULL)
    {
        printf("NULL");
    }
}