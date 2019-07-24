#include "common.h"
/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

solution:
在后序遍历得到的序列中，最后一个数字是树的根节点的值。数组中前面的数字可以分为两部分：
（1）第一部分是左子树结点的值，它们都比根结点的值小
（2）第二部分是右子树结点的值，它们都比根结点的值大
*/
class Solution {
public:
    bool checkSub(vector<int> sequence, int start,int end ){
        if(end == start){
            return true;
        }
        int root = sequence[end];
        int mid = end -1;
        while(mid>=start){
            if(sequence[mid] <= root){
                break;
            }
            mid--;
        }
        //只有右子树
        if(mid < start){
            return checkSub(sequence,mid+1,end-1);
        }
        //只有左子树
        if(mid == end -1){
            return checkSub(sequence,start,mid);
        }
        //判断左边的是否全部比他小，有一个不满足就返回false
        for (int i = start ;i < mid;i++){
            if(sequence[i] > root ){
                return false;
            }
        }
        //地柜检查左右子树
        return checkSub(sequence,start,mid) && checkSub(sequence,mid+1,end-1);

    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size() == 0){
            return false;
        }
        return checkSub(sequence,0,sequence.size()-1);
    }
};

int main(){
    Solution s;
    int a[] = {2,4,3,6,8,7,5};
    vector<int> list(a,a+7);
    printf("%d \n",s.VerifySquenceOfBST(list));

    int b[] = {2,4,3,6,8,7,9};//true
    vector<int> list2(b,b+7);
    printf("%d \n",s.VerifySquenceOfBST(list2));
    
    

    int c[] = {4,6,7,5};
    vector<int> list3(c,c+4);
    printf("%d \n",s.VerifySquenceOfBST(list3));
 
    int d[] = {4,3,2,1};
    vector<int> list4(d,d+4); 
   
    printf("%d \n",s.VerifySquenceOfBST(list4));// true

    int e[] = {1,6,2,7,8,5};
    vector<int> list5(e,e+6); 
   
    printf("%d \n",s.VerifySquenceOfBST(list5));// false


    int f[] = {1};
    vector<int> list6(f,f+1); 
   
    printf("%d \n",s.VerifySquenceOfBST(list6));// true

    vector<int> list7; 
   
    printf("%d \n",s.VerifySquenceOfBST(list7));// true
}