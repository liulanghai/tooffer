#include "common.h"
//输入一个链表，按链表从尾到头的顺序返回一个ArrayList。

  struct ListNode {
       int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
 };

//可以采用栈的方式改变顺序，这里直接投机了
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        ListNode *tmp = head;
        while(head!=NULL){
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};