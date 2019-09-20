#include "common.h"
///给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
//注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next; //父节点
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL)
    {
        int a;
    }
};
//如果节点有右孩子，则找右孩子最左的节点
//如果没有，则找父节点的
class Solution
{
public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode)
    {
        if (pNode == NULL)
        {
            return NULL;
        }
        TreeLinkNode *parent = pNode->next;
        TreeLinkNode *tmp = pNode;
        TreeLinkNode *ch = pNode->right;
        if (ch != NULL)
        {
            while (ch->left != NULL)
            {
                ch = ch->left;
            }
            return ch;
        }
        while (pNode && pNode->next && pNode == pNode->next->right)
            pNode = pNode->next;
        return pNode->next;
    }
};