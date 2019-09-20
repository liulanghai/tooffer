#include "common.h"
/*
题目描述
请实现两个函数，分别用来序列化和反序列化二叉树

二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，从而使得内存中建立起来的二叉树可以持久保存。序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#），以 ！ 表示一个结点值的结束（value!）。

二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。
*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

struct StrNode {
    int LeftIndex;
    int RightIndex;
    int ParentIndex;
    int Vai;
};
void Pre(TreeNode *root,vector<int> *res){
    if(root == NULL){
        return ;
    }
    (*res).push_back(root->val);
    
    Pre(root->left,res);
    Pre(root->right,res);
}
void Mid(TreeNode *root,vector<int> *res){
    if(root == NULL){
        return ;
    }
    Mid(root->left,res);
    (*res).push_back(root->val);
    Mid(root->right,res);
}
class Solution {
public:
    char* Serialize(TreeNode *root) {    
        int elmnSize = sizeof(struct StrNode);
        TreeNode *head = root;
        vector<int> preList;
        vector<int> midlist;
        Pre(head,&preList);
        head = root;
        Mid(head,&midlist);
        for(int i=0;i<preList.size();i++){
            
        }
        return "";
    }
    TreeNode* Deserialize(char *str) {
    
    }
};

int main(){
    Solution s;
     struct TreeNode root(1);
  

    struct TreeNode node1(2);
    struct TreeNode node2(3);
    struct TreeNode node3(3);
    struct TreeNode node4(2);

    root.left = &node1;
    root.right = &node2;

    node2.right = &node4;
    node1.left = &node3;
    s.Serialize(&root);
}