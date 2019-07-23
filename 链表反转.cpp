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
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL){
            return NULL;
        }
        ListNode*  head = pHead;
        ListNode*  newHead = NULL;
        while(head != NULL){
           ListNode*tmp = head->next;
           head->next = newHead;
           newHead = head;
           head = tmp;
        }
        return newHead;
    }
};

int main(){
    ListNode node1(1),node2(2),node3(3);
    node1.val = 1;
    node1.next = &node2;
    node2.next = &node3;

    Solution s;
    ListNode* result =  s.ReverseList(&node1);
    while(result!=NULL){
        printf("%d->",result->val);
        result = result ->next;
    } 
}