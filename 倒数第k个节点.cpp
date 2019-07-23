#include "common.h"

//输入一个链表，输出该链表中倒数第k个结点。
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
       if(k == 0){
           return NULL;
       }
       stack <ListNode*> nodeStack;
       ListNode* head = pListHead;
       while(head != NULL){
           nodeStack.push(head);
           head= head->next;
       }
       if( k > nodeStack.size()){
           return NULL;
       }
       int count = 0;
       ListNode* result;
       while(count < k-1){
           nodeStack.pop();
           count++;
       }
       return nodeStack.top();
    }
};
int main(){
   
    ListNode node1(1),node2(2),node3(3);
    node1.val = 1;
    node1.next = &node2;
    node2.next = &node3;
    Solution s;
    ListNode *list= s.FindKthToTail(&node1,3);
    if(list == NULL){
        printf("NULL");
    }else{
        printf("%d",list->val);
    }
   
}