#include "common.h"
/*
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
*/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL){
            return;
        }
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        //swap left and right node 
        {
            TreeNode *tmp = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = tmp;
        }
        
    }
};

int main(){
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode root(0);
    root.left = &node1;
    root.right = &node2;

    TreeNode *r = &root; 
    Solution s;
    s.Mirror(r);
    printf("left = %d ,right = %d",r->left->val,r->right->val);
}