#include "common.h"
/*
题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，
请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，
序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）
*/
/*solution:
模拟压入 pop出，对比最后结果
 */
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> tmp;
        int popIndex = 0;
        int i;
        for(i=0;i<pushV.size();i++){
            tmp.push(pushV[i]);
            while(tmp.empty() == false && tmp.top() == popV[popIndex]){
                popIndex++;
                tmp.pop();
            }
        }
        if(tmp.empty()){
            return true;
        }
        return false;
    }
};

int main(){
    int a[] = {1,2,3,4,5};
    vector<int> pushV(a,a+5);
    int b[] = {4,5,3,2,1};
    vector<int> popV(b,b+5);
    int c[] = {4,3,5,1,2};
    vector<int> popV2(c,c+5);
    Solution s;
    printf("shoule be 1 , it == %d\n",s.IsPopOrder(pushV,popV));
    printf("shoule be 0 ,it  == %d\n",s.IsPopOrder(pushV,popV2));
}