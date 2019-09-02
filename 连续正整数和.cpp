#include "common.h"
/*
假设从 X开始 N个数相加最后等于SUM
则 x + x+1 + x+2 + .....+X+n-1 = SUM
(X + X+N-1)/2 *N/2 = SUM ==> X = (SUM - N*(N-1)/2)/N

N从1开始进行迭代，如果能整除说明存在

*/
vector<int> out(int start ,int len){
     vector<int> result;
     for(int i=0;i<len;i++){
         result.push_back(i+start);
     }
     return result;
}
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        int n = sum-1;
        vector<vector<int> > result;
        while(n>1){
            int x = (sum-n*(n-1)/2)/n;
            if (x > 0 && (sum-n*(n-1)/2)%n == 0){
                result.push_back(out(x,n));
            }
            n--;
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<vector<int> > res = s.FindContinuousSequence(100);
    for(int i = 0;i<res.size();i++){
        for(int j = 0;j<res[i].size();j++){
            printf("%d ",res[i][j]);
        }
         printf("\n");
    }
}