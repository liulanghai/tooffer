#include "common.h"
/*
题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
*/

class Solution {
public:
  void swap( int *a, int *b){
        int temp;
        temp=*a;
        *a=*b;
        *b=temp;
    }
    bool check(vector<int> nums,int a, int b){ //检查s[a-b]之中是有跟b一样的，如果有
        for(int i = a ;i<b;i++){
            if(nums[i] == nums[b]){
                return false;
            }  
        }
        return true;
    }
    void f( vector<vector<int> > *result, vector<int> nums , int N){ //
        if(N == nums.size()){ // 到达最后一层了
            (*result).push_back(nums);
            return ;
        }
        int i = 0;
        for(i = N;i<nums.size();i++){
            if(check(nums,N,i)){ //因为这里可能重复，检查一下str 的从 N 到 I 之间是否有与I重复的，如果有则不用交换。
                swap(&nums[i],&nums[N]);
			    f(result,nums,N+1);
			    swap(&nums[i],&nums[N]);
            }
        }	
	}
     vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > result;
        if(nums.size()==0){
            return result;
        }
        f(&result,nums,0);
        return result;
    }
};

int main(){
    int a[] = {1,2,3,3};
    Solution s;
    vector<int> nums(a,a+4);
    vector<vector<int> > result = s.permuteUnique(nums);
    for(int i=0;i<result.size();i++){
        PrintIntVecotr(result[i]);
    }
}