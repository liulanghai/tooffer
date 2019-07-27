#include "common.h"
class Solution {
public:
    void swap( int *a, int *b){
        int temp;
        temp=*a;
        *a=*b;
        *b=temp;
    }

    int fenqu(vector<int>nums,int start ,int end ,int midval) {
        while(start < end){
            //printf("start = %d,end = %d \n",start,end);
            while((start< end) && nums[start] < midval){
                start++;
            }
            while((start < end) && nums[end]>midval){
                end--;
            }
            swap(&nums[start],&nums[end]);
        }
        return start;
    }
    int f(vector<int>nums,int start ,int end ,int k){
        int q = fenqu(nums,start,end,nums[start]);
        //包含k的最小有多少个
        int minCount = q - start + 1;
        printf("start = %d ,end = %d q = %d\n",start,end,q);
        //还需要找 
        if(minCount==k){
            return q;
        }
        if(minCount-k == 1){
            return q-1;
        }

        if(minCount>q){
            return f(nums,start,q-1,k);
        }else{
            return f(nums,q,end,k-minCount);
        }
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if(input.size() == 0){
            return result;
        }
        int count = f(input,0,input.size()-1,k);
        printf("%d count = ",count);
        for(int i=0;i<=count;i++){
            result.push_back(input[i]);
        }
    }
};
int main(){
     //[1,2,3,2,2,2,5,4,2]
    int a[] = {3,2,1,4,5,6};
    vector<int> d(a,a+6);
    Solution s;
    PrintIntVecotr(s.GetLeastNumbers_Solution(d,4));
}