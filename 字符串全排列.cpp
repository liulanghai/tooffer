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
    void swap( char * a,char * b){
        char temp;
        temp=*a;
        *a=*b;
        *b=temp;
    }
    bool check(string str,int a, int b){ //检查s[a-b]之中是有跟b一样的，如果有
        for(int i = a ;i<b;i++){
            if(str[i] == str[b]){
                return false;
            }  
        }
        return true;
    }
    //f的含义为 如果0-N确定了，那么总共有多少种序列。
    void f(vector<string> *result, string str , int N){ //
        if(N == str.size()){ // 到达最后一层了
            (*result).push_back(str);
            return ;
        }
        int i = 0;
        for(i = N;i<str.size();i++){
            if(check(str,N,i)){ //因为这里可能重复，检查一下str 的从 N 到 I 之间是否有与I重复的，如果有则不用交换。
                swap(&str[i],&str[N]);
			    f(result,str,N+1);
			    swap(&str[i],&str[N]);
            }
        }	
	}
    vector<string> Permutation(string str) {
        vector<string> result;
        if(str.size()==0){
            return result;
        }
        f(&result,str,0);
        sort(result.begin(), result.end());
        return result;
    }
};
int main(){
    string str("aa");
    Solution s;
    vector<string> result = s.Permutation(str);
    for(int i=0;i<result.size();i++){
        printf("%s\n",result[i].c_str());
    }
}