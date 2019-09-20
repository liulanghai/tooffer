#include "common.h"
/*
数组中有一个数字出现的次数超过数组长度的一半，
请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*/
/*由于该数字的出现次数比所有其他数字出现次数的和还要多，因此可以考虑在遍历数组时保存两个值：一个是数组中的一个数字，一个是次数，。当遍历到下一个数字时，如果下一个数字与之前保存的数字相同，则次数加1，如果不同，则次数减1，如果次数为0，则需要保存下一个数字，并把次数设定为1。由于我们要找的数字出现的次数比其他所有数字的出现次数之和还要大，则要找的数字肯定是组后一次把次数设为1时对应的数字。该方法的时间复杂度为O(n)，空间复杂度为O(1)。

开心消消乐
一直消除，跟他不一样的就去消除，最后如果还剩下那么他肯定就是超过一半的
用栈更好理解这个流程，不一样就消除。但是这里是用count来记录的。不是用数据本身。
*/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int val,count;
        count = 0;
        for(int i=0;i<numbers.size();i++){
            if(count == 0 || val == numbers[i]){
                count++;
                val = numbers[i];
            }else{
                count--;
            }
        }
        count = 0;
      
        for(int i=0;i<numbers.size();i++){
            if(numbers[i] == val){
                count++;
            }
        }
        //printf("val = %d count = %d\n",val,count);
        return (count > numbers.size()/2)?val:0;
    }
};
int main(){
    //[1,2,3,2,2,2,5,4,2]
    int a[] = {1,2,2,3,4,5,6};
    vector<int> d(a,a+7);
    Solution s;
    printf("%d\n",s.MoreThanHalfNum_Solution(d));

    int b[] = {1,2,3,4,4,2,5,4,2};
    vector<int> f(b,b+9);
      printf("%d\n",s.MoreThanHalfNum_Solution(f));
}