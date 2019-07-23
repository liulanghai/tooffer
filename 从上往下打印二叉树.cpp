#include "common.h"
/*从上往下打印出二叉树的每个节点，同层节点从左至右打印。*/


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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode *> waitPrint;
        vector<int> result;
        if(root == NULL){
            return result;
        }
        waitPrint.push(root);
        while(waitPrint.empty() == false){
           TreeNode *tmp = waitPrint.front();
           waitPrint.pop();
           result.push_back(tmp->val);
           if(tmp->left != NULL){
               waitPrint.push(tmp->left);
           }
           if(tmp->right!=NULL){
                 waitPrint.push(tmp->right);
           }
        }
        return result;
    }
};
int main(){
    TreeNode node1(2);
    TreeNode node2(1);
    TreeNode root(0);
    root.left = &node1;
    root.right = &node2;

    TreeNode *r = &root; 
    Solution s;
    vector<int> result = s.PrintFromTopToBottom(r);
    PrintIntVecotr(result);
    return 0;
}