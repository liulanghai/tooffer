#include "common.h"
/*
题目描述
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
*/
//思路：将字符串钱半部分与后半部分调换位置
class Solution {
public:
    string LeftRotateString(string str, int n) {
        string s;
        if(str.size()==0){
            return s;
        }
        if(n>str.size()){
            n = n%str.size();
        }
        string s1(str,n,str.size());
        string s2(str,0,n-1);
        return s1 + s2 ;
    }
};

int main(){
    Solution s;
    string t("abcXYZ12");
    cout<<s.LeftRotateString(t,10)<<endl;
}