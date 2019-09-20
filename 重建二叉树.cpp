#include "common.h"
/*
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* Create(vector<int> pre,vector<int> vin) {
   
    if(pre.size() == 0){
        return NULL;
    }
    TreeNode *root = new TreeNode(pre[0]);
    int mid;

    vector<int> leftPre;
    vector<int> leftVin;
    vector<int> rightPre;
    vector<int> rightVin;
    bool flag = true;
    for(int i=0;i<=pre.size();i++){
        if(vin[i] == root->val ){
            mid = i;
            break;
        }
    }
    for(int i=0;i<mid;i++){
        leftVin.push_back(vin[i]);
    } 
    for(int i=mid+1;i<vin.size();i++){
        rightVin.push_back(vin[i]);
    } 
    for(int i= 1;i<=mid;i++){
        leftPre.push_back(pre[i]);
    }
    for(int i= mid+1;i<pre.size();i++){
        rightPre.push_back(pre[i]);
    }
    TreeNode *Nodeleft = Create(leftPre,leftVin);
    TreeNode *Noderight = Create(rightPre,rightVin);
    root->left = Nodeleft;
    root->right = Noderight;
    return root;
}
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return Create(pre,vin);
    }
};
void prelist(TreeNode* root){
    if(root == NULL){
        return;
    }
    
    printf("%d \n",root->val);
    prelist(root->left);
    prelist(root->right);
}
int main(){
    Solution s;
    vector<int> pre = {1,2,4,7,3,5,6,8};
    vector<int> vin = {4,7,2,1,5,3,8,6};
    TreeNode*  root =  s.reConstructBinaryTree(pre,vin);
    prelist(root);
}