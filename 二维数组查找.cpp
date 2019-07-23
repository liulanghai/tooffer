#include "head.h"
class Solution {
public:
    int  BS(vector<int> array,int target){
        int start = 0;
        int end = array.size()-1;
        while(start<=end){
            int mid = (start + end) /2;
            if(array[mid] == target){
                return mid;
            }else if(array[mid] > target){
                end = mid -1;
            }else{
                start = mid + 1;
            }
        }
        return -1;
    }
    bool Find(int target, vector<vector<int>> array) {
        int i = 0;
        for(i = 0;i< array.size();i++ ){
            int tmp = BS(array[i],target);
            if(tmp != -1){
                return true;
            }
        }
        return false;
    }
};