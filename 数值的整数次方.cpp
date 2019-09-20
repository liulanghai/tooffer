#include "common.h"
class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent == 0){
            return 1.0;
        }
        int count = 0;
        count = exponent>0?exponent:exponent*-1;
        double result = 1;
        for(int i =0;i<count;i++){
            result = base*result;
        }

        if(exponent < 0){
            return 1/result;
        }
        return result;
    }
};
int main(){
    Solution s;
    printf("%f",s.Power(2.0,3));
}