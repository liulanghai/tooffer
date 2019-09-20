#include "common.h"
/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/
//中序遍历就能生成一个链表
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
//parent 为访问前驱
int dovisit(TreeNode *node,TreeNode *Pre){
    node->left = Pre;
    Pre->right = node;
}

//Pre 为Tree这个节点访问的前一个节点。前驱不断更新

void Visit(TreeNode* pRootOfTree,TreeNode** Pre) {

    if(pRootOfTree->left != NULL){
       Visit(pRootOfTree->left,Pre);
    }
    pRootOfTree->left = *Pre;
    if(*Pre != NULL){
        (*Pre)->right = pRootOfTree;
    }
    *Pre = pRootOfTree;

    if(pRootOfTree->right != NULL){
        Visit(pRootOfTree->right,Pre); 
    }
}
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode *last_node = NULL;
        TreeNode *head = pRootOfTree;
        if(pRootOfTree==NULL){
            return NULL;
        }

        while(head->left!=NULL){
            head = head->left;
        }
        Visit(pRootOfTree,&last_node);
        return head;
    }
};