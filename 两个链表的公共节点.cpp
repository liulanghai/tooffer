#include "common.h"
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};
//两个链表公共一个节点，说明后面的全都是公共的
//对比两个链表的长度，去除长的以后，一起遍历，第一个相同的就是公共节点。
class Solution
{
public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        int len1 = 0;
        int len2 = 0;
        ListNode *tmp1 = pHead1;
        ListNode *tmp2 = pHead2;
        while (tmp1 != NULL)
        {
            len1++;
            tmp1 = tmp1->next;
        }
        while (tmp2 != NULL)
        {
            len2++;
            tmp2 = tmp2->next;
        }
        printf("len1 = %d ,len2 = %d", len1, len2);
        if (len1 > len2)
        {
            tmp1 = pHead1;
            tmp2 = pHead2;
            int s = len1 - len2;
            while (s)
            {
                tmp1 = tmp1->next;
                s--;
            }
        }
        else
        {
            tmp1 = pHead1;
            tmp2 = pHead2;
            int s = len2 - len1;
            while (s)
            {
                tmp2 = tmp2->next;
                s--;
            }
        }
        while (tmp1 != NULL)
        {
            if (tmp1 == tmp2)
            {
                return tmp1;
            }
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        return NULL;
    }
};
int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    a.next = &c;
    b.next = &c;
    c.next = &d;
    Solution s;

    ListNode *res = s.FindFirstCommonNode(&a, &b);
    printf("%d", res->val);
}