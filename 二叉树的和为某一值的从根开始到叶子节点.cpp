#include "common.h"

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
   //这个结构可以找到
struct C{
    struct TreeNode* Node;
    struct C* Parent;
    int sum;
};

vector<int> getRoad(struct C *root){
    vector<int> res;
    while(root!=NULL){
        res.push_back(root->Node->val);
        root = root->Parent;
    }
    reverse(res.begin(), res.end());
    return res;
}
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {

        vector<vector<int> > result;

        vector<struct C*> record; //遍历列表
        struct C* lu  = (struct C*)malloc(sizeof(struct C));
        TreeNode* r = root;
        if(root == NULL){
            return result;
        }
       
        lu->Node = root;
        lu->Parent = NULL;
        lu->sum = root->val;
        record.push_back(lu);

        if(lu->sum == expectNumber){
            result.push_back(getRoad(lu));
        }

        while(record.size()>0){
            vector<struct C*> tmp ;
            for(int i=0;i<record.size();i++){
                if(record[i]->Node->left != NULL){
                    struct C* node  = (struct C*)malloc(sizeof(struct C));
                    node->Node = record[i]->Node->left;
                    node->Parent = record[i];
                    node->sum = node->Parent->sum + node->Node->val;
                    if(node->sum == expectNumber &&  node->Node->left == NULL &&  node->Node->right == NULL){
                        result.push_back(getRoad(node));
                    }
                    tmp.push_back(node);
                }
                 if(record[i]->Node->right != NULL){
                    struct C* node  = (struct C*)malloc(sizeof(struct C));
                    node->Node = record[i]->Node->right;
                    node->Parent = record[i];
                    node->sum = node->Parent->sum + node->Node->val;
                    if(node->sum == expectNumber &&  node->Node->left == NULL &&  node->Node->right == NULL){
                        result.push_back(getRoad(node));
                    }
                    tmp.push_back(node);
                }
            }
            record = tmp;
        }
        reverse(result.begin(),result.end());
        return result;
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

    vector<vector<int> > res;
    res = s.FindPath(&root,6);
    for(int i=0;i<res.size();i++){
        PrintIntVecotr(res[i]);
    }
   
    
}