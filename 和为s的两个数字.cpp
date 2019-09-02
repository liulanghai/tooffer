#include "common.h"
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        map<int,int> t;
        for(int i = 0;i<array.size();i++){
                t[array[i]] = 1;
        }
        int x = 0;
        vector<int> result;
        for(int i = 0;i<array.size();i++){
            if(t.find(sum-array[i]) != t.end()){
                if((sum-array[i])*array[i] > x){
                    vector<int> tmp;
                    tmp.push_back(sum-array[i]);
                    tmp.push_back(array[i]);
                    result = tmp;
                }
            }
        }
        if(result.size()>0){
            if(result[0]>result[1]){
                int tmp = result[0];
                result[0] = result[1];
                result[1] = tmp;
            }
        }
        return result;
    }
};