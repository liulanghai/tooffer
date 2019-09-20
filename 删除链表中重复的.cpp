#include "common.h"
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode *root = pHead;
        stack<ListNode*> s;
        while (root)
        {
            if(s.empty()){
                s.push(root);
                root = root->next;
            }else{
                    bool flag = false;
                    while( root != NULL&&root->val == s.top()->val){
                        root = root->next;
                        flag = true;
                    }
                    if(flag){
                        s.pop();
                    }else{
                        s.push(root);
                        root = root->next;
                     }
            }
        }
        if(s.empty()){
            return NULL;
        }
        root = NULL;
        while(!s.empty()){ //根据栈重建链表
            ListNode *tmp = s.top();
            tmp->next = root;
            root = tmp;
            s.pop();
        }
        return root;
    }
};

int main(){
    ListNode node1(1);
    ListNode node2(1);
    ListNode node3(1);
    ListNode node4(2);
    ListNode node5(3);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    Solution s;
    ListNode *res = s.deleteDuplication(&node1);
    while (res)
    {
        printf("%d ",res->val);
        res= res->next;
    }
    
}