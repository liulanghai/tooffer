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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *result;
        ListNode *tail;
        if(pHead1 == NULL){
            return pHead2;
        }
        if(pHead2 == NULL){
            return pHead1;
        }
        if(pHead1->val < pHead2->val){
            tail = pHead1;
            pHead1 = pHead1->next;
        }else{
            tail = pHead2;
            pHead2 = pHead2->next;
        }
        result = tail;
        while(pHead1 != NULL && pHead2 != NULL){
            if(pHead1->val < pHead2->val){
                tail->next = pHead1;
                tail = tail->next;
                pHead1 = pHead1->next;
            }else{
                tail->next = pHead2;
                tail = tail->next;
                pHead2 = pHead2->next;
            }
        }
        if(pHead1 == NULL){
            tail->next = pHead2;
        }else{
            tail->next = pHead1;
        }
        return result;
    }
};

int main(){
    ListNode node1(1),node2(2),node3(3);
    node1.next = &node2;
    node2.next = &node3;

    ListNode node4(2),node5(5),node6(6);
    node4.next = &node5;
    node5.next = &node6;

    Solution s;
    ListNode* result =  s.Merge(&node1,NULL);
    while(result!=NULL){
        printf("%d->",result->val);
        result = result ->next;
    }  
}